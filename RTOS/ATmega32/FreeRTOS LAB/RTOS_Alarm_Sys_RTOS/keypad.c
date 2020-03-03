/*
 * keypad.c
 *
 * Created: 10/11/2016 11:42:21 AM
 *  Author: Master
 */ 
 #include "keypad.h"
 #include "LCD_Lib.h"
 extern const Keypad_config_t g_Keypad_Col_Config[Col_numbers];
 extern const Keypad_config_t g_Keypad_Row_Config[Row_numbers];
 extern const uint8_t g_Keypad_Map[Row_numbers][Col_numbers];
 void Keypad_Init(void)
 {
	uint8_t index;
	GPIO_Init_Param_t keypadParam;
	
for (index=0;index<Col_numbers;index++)
	{
		/* Columns are output */
		keypadParam.Direction = (1U<<g_Keypad_Col_Config[index].PIN_Number);
		/* Columns are output, they initialized high */
		keypadParam.IsPulledUp= (1U<<g_Keypad_Col_Config[index].PIN_Number);
		keypadParam.Port_Name = g_Keypad_Col_Config[index].PORT_Name;
		keypadParam.Mask = (1U<<g_Keypad_Col_Config[index].PIN_Number);
		GPIO_Init(&keypadParam);
	}

	for (index=0;index<Row_numbers;index++)
	{
		/* Rows are input */
		keypadParam.Direction = 0U;
		/* Rows are input, they are internally pulled up */
		keypadParam.IsPulledUp=(1U<<g_Keypad_Row_Config[index].PIN_Number);;
		keypadParam.Port_Name = g_Keypad_Row_Config[index].PORT_Name;
		keypadParam.Mask = (1U<<g_Keypad_Row_Config[index].PIN_Number);
		GPIO_Init(&keypadParam);
	}
 }
 uint8_t Keypad_getkey(void)
 {
   uint8_t volatile col_index=0;
   uint8_t volatile row_index=0;
   uint8_t volatile read_value=0;
   uint8_t volatile read_key=0xFF;
   GPIO_Read_Param_t  keypadRowParam;
   GPIO_Write_Param_t keypadColParam;
   //char x[10]={0};
  
   for (col_index=0;col_index<Col_numbers;col_index++)
   {
	
	
	 /* Put high on the last column */
	 keypadColParam.Port_Name =  g_Keypad_Col_Config[((col_index+Col_numbers)-1)%Col_numbers].PORT_Name;
	 keypadColParam.Mask = (1U<<g_Keypad_Col_Config[((col_index+Col_numbers)-1)%Col_numbers].PIN_Number);
	 keypadColParam.Data = (1U<<g_Keypad_Col_Config[((col_index+Col_numbers)-1)%Col_numbers].PIN_Number);
	 GPIO_Write(&keypadColParam);

	  /* Put low on the current column */
	  keypadColParam.Port_Name =  g_Keypad_Col_Config[col_index].PORT_Name;
	  keypadColParam.Mask = (1U<<g_Keypad_Col_Config[col_index].PIN_Number);
	  keypadColParam.Data = 0U;
	  
	  GPIO_Write(&keypadColParam);
		 
	  read_value =0;
	  for (row_index=0;row_index<Row_numbers;row_index++)
	  {
		
		keypadRowParam.Port_Name = g_Keypad_Row_Config[row_index].PORT_Name;
		keypadRowParam.PIN_Number = g_Keypad_Row_Config[row_index].PIN_Number;
		/* read each row and collect rows status in read_key variable
		   row status is x-ored to be read as 0000 instead of 1111 if now key is pressed
		   and this will make it easy to check each of the rows status individually 
		*/
		read_value |= (uint8_t)(((GPIO_Read(&keypadRowParam))^(1U<<0))<<row_index);
	  }
	 
	  
	    /* get key value from user's keypad map */
		for (row_index=0;row_index<Row_numbers;row_index++)
		{
			 if (read_value == (1U<<row_index))
			 {
				read_key = g_Keypad_Map[row_index][col_index];
				
				keypadColParam.Port_Name =  g_Keypad_Col_Config[col_index].PORT_Name;
				keypadColParam.Mask = (1U<<g_Keypad_Col_Config[col_index].PIN_Number);
				keypadColParam.Data = (1U<<g_Keypad_Col_Config[col_index].PIN_Number);
				GPIO_Write(&keypadColParam);
				row_index = Row_numbers;
				col_index= Col_numbers;
			 }
			
		
		}
	   
		
		

		

	 
    }

	return read_key;
 }