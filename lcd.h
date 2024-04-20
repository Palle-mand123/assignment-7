#ifndef LCD_H
#define LCD_H

#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"
#include "emp_type.h"
#include "portmacro.h"
#include "semphr.h"
#define LCD_CLEAR        0x01 // Clear display
#define LCD_RETURN_HOME  0x02 // Return home command: Returns the cursor to the top left corner of the display
#define LCD_FUNCTION_SET 0x28 // Function set: 4-bit mode, 2 lines, 5x8 dots
#define LCD_ENTRY_MODE   0x06 // Entry mode: Increment cursor, no display shift
#define LCD_DISPLAY_ON   0x0C // Display on/off control command

extern uint8_t LCD_D4_PIN; // PC4 for LCD D4
extern uint8_t LCD_D5_PIN; // PC5 for LCD D5
extern uint8_t LCD_D6_PIN; // PC6 for LCD D6
extern uint8_t LCD_D7_PIN; // PC7 for LCD D7

extern uint8_t LCD_RS_PIN; // PD2 for LCD RS
extern uint8_t LCD_E_PIN;  // PD3 for LCD E

void delay_ms(TickType_t ms);
void pulse_e_pin(void); // Pulsing LCD E pin, with micro delays
void lcd_send_command(uint8_t command);
void lcd_send_data(uint8_t data);
void init_lcd(void);
void lcd_clear(void);
void lcd_set_cursor(int row, int col);
void lcd_print(char *str);
void lcd_task(void *pvParameters);
void status_led_init(void);

#endif /* LCD_H */
