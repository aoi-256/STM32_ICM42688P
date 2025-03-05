/*
 * ICM42688P_HAL.cpp
 *
 *  Created on: Mar 6, 2025
 *      Author: Sezakiaoi
 */

#include "ICM42688P_HAL.h"

/* @brief I2cのピンデータの受け取り
 *
 * @param I2C_HandleTypeDef* 使用するピンの情報
 *
 * @return None
 */
ICM42688P_HAL::ICM42688P_HAL(I2C_HandleTypeDef* I2cPin) {

	this->I2cPin = I2cPin;
}

/* @brief ICM42688Pへの書き込み
 *
 * ICM42688Pの特定のレジスタに指定した値を書き込みます
 *
 * @param ICM42688P_HAL::BANK0 レジスタアドレス
 * @param Command 書き込むデータのポインタ
 * @param Len 書き込むデータのサイズ
 *
 * @return HAL_StatusTypeDef
 */
HAL_StatusTypeDef ICM42688P_HAL::Write(ICM42688P_HAL::BANK0 REGISTER_ADDR, uint8_t* Command, uint8_t Len){

	return HAL_I2C_Mem_Write(I2cPin, I2CADDR, uint8_t(REGISTER_ADDR), 1, Command, Len, 1);
}

/* @brief ICM42688Pへの読み取り
 *
 * ICM42688Pの特定のレジスタの値を読み取ります
 *
 * @param ICM42688P_HAL::BANK0 レジスタアドレス
 * @param Command 読み取ったデータの保存先
 * @param Len 読み取るデータのサイズ
 *
 * @return HAL_StatusTypeDef
 */
HAL_StatusTypeDef ICM42688P_HAL::Read(ICM42688P_HAL::BANK0 REGISTER_ADDR, uint8_t* Receive_Buffer, uint8_t Len){

	return  HAL_I2C_Mem_Read(I2cPin, I2CADDR, uint8_t(REGISTER_ADDR), 1, Receive_Buffer, Len, 1);
}

