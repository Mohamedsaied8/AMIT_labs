/*
 * keypad_config.c
 *
 * Created: 10/11/2016 11:30:42 AM
 *  Author: Master
 */ 
 #include "keypad_config.h"


 const Keypad_config_t g_Keypad_Col_Config[Col_numbers] =
 {
	 {PT3,3},	//COL1
	 {PT3,4},   //COL2
	 {PT3,5},   //COL3
	 {PT3,6}	//COL4
 };

 const Keypad_config_t g_Keypad_Row_Config[Row_numbers] =
 {
	 {PT2,5},	//ROW1
	 {PT2,6},	//ROW2
	 {PT2,7},	//ROW3
	 {PT1,0}	//ROW4
 };
 /*
-----------------
| 1 | 2 | 3 | A |
-----------------
| 4 | 5 | 6 | B |
-----------------
| 7 | 8 | 9 | C |
-----------------
| * | 0 | # | D |
-----------------
 */

 const uint8_t g_Keypad_Map[Row_numbers][Col_numbers] =
 {
 {'1','2','3','A'},
 {'4','5','6','B'},
 {'7','8','9','C'},
 {'*','0','#','D'}
 /*
	{'1','2','3','A'},
	{'4','5','6','B'},
	{'7','8','9','C'},
	{'*','0','#','D'}
*/
 };