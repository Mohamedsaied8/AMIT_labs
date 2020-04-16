/*
 * keypad.c
 *
 *  Created on: Apr 9, 2020
 *      Author: Mohamed
 *
 *  -----------------
	| 1 | 2 | 3 | A |
	-----------------
	| 4 | 5 | 6 | B |
	-----------------
	| 7 | 8 | 9 | C |
	-----------------
	| * | 0 | # | D |
	-----------------
 *
 */

#include "STD_Types.h"

#include "keypad.h"
#include "dio.h"

extern const uint8 Keypad_Map[16];
uint8 keypressed=KEY_RELEASE;

static void checkCols(uint8 row){

	if(DioReadChannel(COL1_PIN)==STD_low){
		keypressed= row*COL_NUM;
	}
	else if(DioReadChannel(COL2_PIN)==STD_low){
		keypressed= (row*COL_NUM)+COL2;
	}
	else if(DioReadChannel(COL3_PIN)==STD_low){
			keypressed= (row*COL_NUM)+COL3;
		}
	else if(DioReadChannel(COL4_PIN)==STD_low){
				keypressed= (row*COL_NUM)+COL4;
	   }


}//function

uint8 GetKeypressed(){
	 keypressed=KEY_RELEASE;
	Dio_WriteChannel(ROW1_PIN,STD_low);
	Dio_WriteChannel(ROW2_PIN,STD_high);
	Dio_WriteChannel(ROW3_PIN,STD_high);
	Dio_WriteChannel(ROW4_PIN,STD_high);
	checkCols(ROW1);
	Dio_WriteChannel(ROW1_PIN,STD_high);
	Dio_WriteChannel(ROW2_PIN,STD_low);
	Dio_WriteChannel(ROW3_PIN,STD_high);
	Dio_WriteChannel(ROW4_PIN,STD_high);
	checkCols(ROW2);
	Dio_WriteChannel(ROW1_PIN,STD_high);
	Dio_WriteChannel(ROW2_PIN,STD_high);
	Dio_WriteChannel(ROW3_PIN,STD_low);
	Dio_WriteChannel(ROW4_PIN,STD_high);
	checkCols(ROW3);
	Dio_WriteChannel(ROW1_PIN,STD_high);
	Dio_WriteChannel(ROW2_PIN,STD_high);
	Dio_WriteChannel(ROW3_PIN,STD_high);
	Dio_WriteChannel(ROW4_PIN,STD_low);
	checkCols(ROW4);

return keypressed==KEY_RELEASE? KEY_RELEASE:Keypad_Map[keypressed];
}
