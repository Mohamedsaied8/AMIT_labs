/*
 * keypad_cfg.c
 *
 *  Created on: Apr 9, 2020
 *      Author: Mohamed
 */


#include "keypad_cfg.h"
#include "STD_Types.h"

 const Keypad_Type keypad_cfg_cols[COL_NUM]=
		{
			{COL1_PORT,COL1_PIN},
			{COL2_PORT,COL2_PIN},
			{COL3_PORT,COL3_PIN},
			{COL4_PORT,COL4_PIN}
		};
 const Keypad_Type keypad_cfg_rows[ROW_NUM]=
	{
		{ROW1_PORT,ROW1_PIN},
		{ROW2_PORT,ROW2_PIN},
		{ROW3_PORT,ROW3_PIN},
		{ROW4_PORT,ROW4_PIN}
	};
//define key map
 const uint8 Keypad_Map[16] =
{
	'1','2','3','A',
	'4','5','6','B',
	'7','8','9','C',
	'*','0','#','D'
};
