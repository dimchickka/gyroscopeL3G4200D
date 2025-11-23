#include "l3g4200d.h"


float sensitivity = 8.75e-3f; // dps per LSB for 250 dps full scale

uint8_t Gyro_Init(I2C_HandleTypeDef *hi2c, UART_HandleTypeDef* huart){
	uint8_t dataReg = 0;
	uint8_t size = 1;  //1 байт
	
	
	HAL_I2C_Mem_Read(hi2c, L3G4200D_ADDRESS, L3G4200D_WhO_AM_I, I2C_MEMADD_SIZE_8BIT, &dataReg, size, I2C_TIMEOUT_MS);
	if(dataReg == 0xD3){
		static const char msg[] = "Sensor is ready for work\r\n";
        HAL_UART_Transmit(huart, (uint8_t*)msg, strlen(msg), I2C_TIMEOUT_MS);
		return SUCCESS;
	}
	
	else{
        char buf[32];
        snprintf(buf, sizeof(buf), "WHO_AM_I = 0x%02X\r\n", dataReg);
        HAL_UART_Transmit(huart, (uint8_t*)buf, strlen(buf), I2C_TIMEOUT_MS);
		HAL_UART_Transmit(huart, (uint8_t*)"Error in connecting sensor\r\n", 6, 100);
		return ERROR;
	}
	
}


void Gyro_Configure(I2C_HandleTypeDef *hi2c){
    uint8_t config;
    
    // Configure CTRL_REG1: Normal mode, all axes, 800Hz, 100Hz cutoff
    config = L3G4200D_CTRL_REG1_CONFIG;
    HAL_I2C_Mem_Write(hi2c, L3G4200D_ADDRESS, L3G4200D_CTRL_REG1, 
                     I2C_MEMADD_SIZE_8BIT, &config, 1, I2C_TIMEOUT_MS);
    
    // Configure CTRL_REG4: 500 dps full scale
    config = L3G4200D_CTRL_REG4_CONFIG;
    HAL_I2C_Mem_Write(hi2c, L3G4200D_ADDRESS, L3G4200D_CTRL_REG4, 
                     I2C_MEMADD_SIZE_8BIT, &config, 1, I2C_TIMEOUT_MS);
    
    HAL_Delay(100);
}




void Gyro_Read_Velocity(I2C_HandleTypeDef *hi2c, GyroData_t* data){
	
	uint8_t buf[6];
	uint8_t sizeToRead = 6; //6 bytes need to be read
	
	HAL_I2C_Mem_Read(
			hi2c,
			L3G4200D_ADDRESS,
			L3G4200D_OUT_X_L | 0x80,
			I2C_MEMADD_SIZE_8BIT,
			buf,
			sizeToRead,
			I2C_TIMEOUT_MS
	);
	
	data->x_current = (uint16_t)((buf[1] << 8) | buf[0]);
	data->y_current = (int16_t)((buf[3] << 8) | buf[2]);
    data->z_current = (int16_t)((buf[5] << 8) | buf[4]);
  
}

void prepareStructure(GyroData_t* data){
    data->x_prev = data->x_current;
	data->y_prev = data->y_current;
    data->z_prev = data->z_current;
}

void calculateAcceleration(GyroData_t* data, float DT){
    float x_prev_deg_s = data->x_prev * sensitivity;
    float y_prev_deg_s = data->y_prev * sensitivity;
    float z_prev_deg_s = data->z_prev * sensitivity;
    
    float x_current_deg_s = data->x_current * sensitivity;
    float y_current_deg_s = data->y_current * sensitivity;
    float z_current_deg_s = data->z_current * sensitivity;
    
    data->ax = (x_current_deg_s - x_prev_deg_s) / DT;
    data->ay = (y_current_deg_s - y_prev_deg_s) / DT;
    data->az = (z_current_deg_s - z_prev_deg_s) / DT;
}

void startGettingData(I2C_HandleTypeDef *hi2c,UART_HandleTypeDef* huart, GyroData_t* data){
    if(isFirstStep){
        Gyro_Configure(hi2c);
        Gyro_Read_Velocity(hi2c,data);
        prepareStructure(data);
        isFirstStep = false;
    }
    else{
        Gyro_Read_Velocity(hi2c,data);
        
         char buf_uart[120];
         snprintf(buf_uart, sizeof(buf_uart),
         "X: prev=%d current=%d | "
         "Y: prev=%d current=%d | "
         "Z: prev=%d current=%d\r\n",
         data->x_prev, data->x_current,
         data->y_prev, data->y_current,
         data->z_prev, data->z_current);

HAL_UART_Transmit(huart, (uint8_t*)buf_uart, strlen(buf_uart), UART_TIMEOUT_MKS);
        
        calculateAcceleration(data, STEP_TO_READ_S);
        prepareStructure(data);
       
        
        char buf[80];
        snprintf(buf, sizeof(buf),
             "ax=%.2f deg/s2, ay=%.2f deg/s2, az=%.2f deg/s2\r\n",
             data->ax, data->ay, data->az);
        HAL_UART_Transmit(huart, (uint8_t*)buf, strlen(buf), UART_TIMEOUT_MKS);
    }
}