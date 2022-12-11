#include <avr/io.h>
#include <stdlib.h>
 
#include <util/delay.h>
 
#include "logicAnalyzer.h"
#include "../Lib/USART/uart.h"
#include "../Lib/TIMER/timer1.h"
#include "../LED/LED.h"

#define _CMD_START_CNT 1
#define _CMD_END_CNT   1
#define _CMD_SPACING   1
#define _CMD_PINS_ST   1
#define _CMD_TIME_SNAP 4
 
#define FULL_SAMPLE_CNT (_CMD_START_CNT + _CMD_PINS_ST +  _CMD_TIME_SNAP + _CMD_END_CNT)
 
#define _SAMPLE_PIN  (_CMD_START_CNT)
#define _SAMPLE_TIME (_CMD_START_CNT + _CMD_PINS_ST)
 
#define MARKER_END   (FULL_SAMPLE_CNT - 1)
#define MARKER_START (0)
 
// Send the following frame for each sample:
// @PIN TIME3 TIME2 TIME1 TIME0;
 
#define _SAMPLES_NUM 3
#define LOGIC_DDR  DDRA
#define LOGIC_PORT PINA
 
typedef enum {MONITOR, SAMPLING, SENDING, IDLE} states_t;
 
 
static uint8_t logic_port_state = 0;
static uint8_t logic_port_pre_state;
static states_t currentState = SAMPLING;
static uint8_t  pin_states[_SAMPLES_NUM];
static uint32_t time_snap[_SAMPLES_NUM];
 
static uint32_t getTime(void)
{
    // TODO: Place your code here, to compute the elapsed time.
	// 0xFFFF -> 2^16 =65536 -> Clks= 65535
	// Prescaler 64 -> Ft= 125k Hz / Tt = 8x10^-6 second
	// Time = timerOVFs * 65535 * 8x10^-6
	// TCNT1L & TCNT1H
	uint32_t timerValue = 0;
	timerValue |= (TCNT1 & 0x00FF);
	timerValue |= ((TCNT1 & 0xFF00)*0x100);
    return (((timerOVFs*clks_number)+timerValue)*clk_time);
}
 
void LOGIC_Init(void)
{   
	TIMER_Init();
    /* Start with getting which wave to generate. */ 
    currentState = MONITOR;    
}
 
void LOGIC_MainFunction(void)
{    
    static volatile uint8_t samples_cnt = 0;
    static char _go_signal_buf = 'N';
    // Main function must have two states,
    // First state is command parsing and waveform selection.
    // second state is waveform executing.
    switch(currentState)
    {
        case MONITOR:
        {
            LOGIC_DDR = 0;
            logic_port_pre_state = logic_port_state;
            logic_port_state     = LOGIC_PORT; 
            currentState = (logic_port_pre_state != logic_port_state) ? SAMPLING : MONITOR;
            break;
        }
        case SAMPLING:
        {
            // DO here sampling.
			if(samples_cnt==0) TIMER_Reset();
            LOGIC_DDR = 0;
            pin_states[samples_cnt] = LOGIC_PORT; 
            time_snap[samples_cnt]  = getTime();
            
            // Increment sample count.
            samples_cnt++;
			
            // Start sending the collected _SAMPLES_NUM samples.
            currentState = (samples_cnt >= _SAMPLES_NUM) ? SENDING : MONITOR;
            break;
        }
        case SENDING:
        {
			//LED_Blink();
            // For _SAMPLES_NUM samples send the construct the buffer.
			static uint8_t _sample_buf[FULL_SAMPLE_CNT];
            for(uint8_t i = 0; i < _SAMPLES_NUM; ++i)
            {
                // Construct the buffer.
                
                // Add buffer marker
                _sample_buf[MARKER_START] = '@';
				
                // Add pin value.
                _sample_buf[_SAMPLE_PIN]  = pin_states[i]+0x30;
 
                // Add time snap value.
                _sample_buf[_SAMPLE_TIME + 0] = ((time_snap[i] & 0xFF000000) >> 24)+0x30;
                _sample_buf[_SAMPLE_TIME + 1] = ((time_snap[i] & 0x00FF0000) >> 16)+0x30;
                _sample_buf[_SAMPLE_TIME + 2] = ((time_snap[i] & 0x0000FF00) >> 8)+0x30;
                _sample_buf[_SAMPLE_TIME + 3] = ((time_snap[i] & 0x000000FF) >> 0)+0x30;

                _sample_buf[MARKER_END]   = ';';
				
                // Send sample.
                UART_SendPayload(_sample_buf, FULL_SAMPLE_CNT);
                while (0 == UART_IsTxComplete());
				LED_On();
			}
			samples_cnt=0; //Extra
            // Trigger receiving for go signal.
            //UART_ReceivePayload((uint8_t *)_go_signal_buf, 1);   
        }
        case IDLE:
        {
			//LED_Blink();
            //currentState = ((1 == UART_IsRxComplete())&&(_go_signal_buf == 'G')) ? MONITOR : IDLE;
			currentState = MONITOR;
            if(currentState == MONITOR)
            {
                // TODO: Place your code here to reset the timer value.
				TIMER_Reset();
            }
 
            break;
        }
        default: {/* Do nothing.*/}
    }
}
