

/**
 * main.c
 */
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "emp_type.h"
#include "systick_frt.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
//#include "keypad.h"
#include "lcd.h"
#include "semphr.h"

#define USERTASK_STACK_SIZE (5 * configMINIMAL_STACK_SIZE)
#define IDLE_PRIO 0
#define LOW_PRIO  1
#define MED_PRIO  2
#define HIGH_PRIO 3
#define QUEUE_SIZE 50


//QueueHandle_t LCDQueue;

static void setupHardware(void)

{
    init_systick();
    status_led_init();
    init_lcd();
  //keypad_init();


}

int main(void)
{
    setupHardware();
    //LCDQueue = xQueueCreate(QUEUE_SIZE, sizeof(char));
    //xTaskCreate( keypad_task, "keypad", USERTASK_STACK_SIZE, (void *)LCDQueue, HIGH_PRIO, NULL );
    xTaskCreate(lcd_task, "LCD Write Task", USERTASK_STACK_SIZE, NULL, MED_PRIO, NULL);

    vTaskStartScheduler();
    return 0;
}
