/*
 * timer.h
 *
 *  Created on: Apr 16, 2020
 *      Author: Mohamed
 */

#ifndef TIMER_H_
#define TIMER_H_

typedef enum{
No_clock,
PRESLACE_NONE,
PRESCALE_8,
PRESCALE_64,
PRESCALE_256,
PRESCALE_1024,
}prescaler_type;

typedef enum{
NORMAL,
CTC_MODE,
OC_MODE,
PWM_FAST,
PWM_PHASE_CORRECT
}Mode_type;

#endif /* TIMER_H_ */
