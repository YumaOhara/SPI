#include <main.h>

extern SPI_HandleTypeDef hspi2;

//8bit分の値を読む関数
uint8_t read8bit(uint8_t reg){
	uint8_t rx_data[2];
	uint8_t tx_data[2];

    //読み込みの際は上位1bitを1にする
	tx_data[0] = reg | 0x80;
    //受信する分を開けておく
	tx_data[1] = 0x00;

    //CS_Pinをどこにするかで以下の文をかえる。
	HAL_GPIO_WritePin(GPIOB,SPI2_CS_Pin,GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(&hspi2, tx_data, rx_data, 2, 1);
	HAL_GPIO_WritePin(GPIOB,SPI2_CS_Pin,GPIO_PIN_SET);

	return rx_data[1];
}

//16bit分の値を読む関数

//8bit分書き込む関数