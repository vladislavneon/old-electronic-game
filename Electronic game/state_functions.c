#include "state_functions.h"
#include "software_defines.h"
#include "software_functions.h"
#include "hardware_functions.h"

void begin() {
	extern struct Enable_state enable_state;
	extern enum   State        state;
	enable_state.check_start = 1;
	enable_state.game_led_on = 1;
	enable_state.init_all    = 1;
	enable_state.init_mode   = 1;
	enable_state.time_over   = 0;
	init_ddr();
	state = INIT_MODE;
};

void init_mode() {
	extern struct Enable_state enable_state;
	extern enum   State        state;
	if (enable_state.init_mode) {           // if init mode enabled
		extern enum Mode mode;
		if (check_button_mode() ) {            // if mode button pressed

			switch (mode) {         
			case REG_SLOW:
				mode = REG_FAST;
				led_mode_change();
				break;
			case REG_FAST:
				mode = SURV;
				led_mode_change();
				break;
			case SURV:
				mode = REG_SLOW;
				led_mode_change();
				break;
			}
			enable_state.init_mode = 0;
			//set_timer_init_mode
		}
	}
	state = CHECK_START;                    // to check_start
};

void check_start() {
	extern struct Enable_state enable_state;
	extern enum   State        state;
	if (enable_state.check_start) {
		if (check_button_start() ) {
			//set_timer_init_all
			state = INIT_ALL;
		}
		else {
			enable_state.check_start = 0;
			//set_timer_check_start
			state = INIT_MODE;
		}
	}
	else {
		state = INIT_MODE;
	}
};

void init_all() {
	extern struct Enable_state enable_state;
	if (enable_state.init_all) {
		extern uint_t  time_0;
		extern uint_t  time_8 ;
		extern uint_t  time_16;
		extern uint_t  time_32;
		extern uint_t  time_64;
		extern uchar_t display;
		extern uchar_t result;
		extern uchar_t mistake;
	
		extern enum Mode mode;
		extern enum State state;

		switch (mode) {
			//init times
		}

		display = 0;
		result  = 0;
		mistake = 0;

		led_display_all_off();

		state = GAME_LED_ON;
	}
};

void game_led_on() {
	extern struct Enable_state enable_state;
	if (enable_state.game_led_on) {
		extern uchar_t cur_led;
		extern enum Color   cur_color;
		//take cur_led and its' color from random
		led_field_on(cur_led);
		//set timeover timer
		extern struct Button button;
		button.blue = 0;
		button.green = 0;
		button.red = 0;
		button.yellow = 0;
		extern enum State state;
		state = CHECK_BUTTON;
	}
};

void check_button() {
	extern struct Enable_state enable_state;
	extern enum   State state;
	if (enable_state.time_over) {	
		enable_state.time_over = 0;
		state = TIME_OVER;
	}
	else {
		extern struct Button button;
		//read all buttons signals
		if ( (check_button_red()   ) || 
			 (check_button_blue()  ) || 
			 (check_button_green() ) || 
			 (check_button_yellow())  ) 
		{
			//shutdown_timer_timeover
			enable_state.game_led_on = 0;
			extern uchar_t cur_led;
			extern enum Color   cur_color;
			led_field_off(cur_led);
			if (check_color) {
				state = RIGHT_BUTTON;
			}
			else {
				state = WRONG_BUTTON;
			}
		}
	}
};



void time_over() {
	extern uchar_t cur_led;
	led_field_off(cur_led);          //led_field_off(cur_led)
	extern enum State state;
	state = WRONG_BUTTON;
};

void right_button() {
	extern uchar_t display;
	extern uchar_t result;

	extern enum State state;

	++result;
	switch (result) {
	case 8:
		display = 8;
		led_display_change(display);     //led_display(display)
		state = GAME_LED_ON;
		break;
	case 16:
		display = 16;
		led_display_change(display);  //led_display_8 off
		//led_display_16 on
		state = GAME_LED_ON;
		break;
	case 32:
		display = 32;
		led_display_change(display);       //led_display_8 off
		//led_display_16 on
		state = GAME_LED_ON;
		break;
	case 64:
		display = 64;
		led_display_change(display);     //led_display_8 off
		//led_display_16 on
		state = WIN;
		break;
	}
};

void wrong_button() {
	extern uchar_t display;
	extern uchar_t result;
	extern uchar_t mistake;
	
	extern enum Mode mode;
	extern enum State state;
	if (mode == SURV) {
		display = 0;
		result = 0;
		state = LOSS;
	}
	else {
		switch (display) {
		case 0:
			result = 0;
			state = LOSS;
			break;
		case 8:
			switch (mistake) {
			case 0:
				display = 0;
				led_display_change(display);//led_display
				result = 0;
				++mistake;
				state = GAME_LED_ON;
				break;
			default:
				display = 0;
				led_display_change(display);//led_display
				result = 0;
				mistake = 0;
				state = LOSS;
			}
			break;
		case 16:
			switch (mistake) {
			case 0:
				display = 8;
				led_display_change(display);     //led_display
				result = 8;
				++mistake;
				state = GAME_LED_ON;
				break;
			case 1:
				display = 0;
				led_display_change(display);     //led_display
				result = 0;
				++mistake;
				state = GAME_LED_ON;
				break;
			default:
				display = 0;
				led_display_change(display);     //led_display
				result = 0;
				mistake = 0;
				state = LOSS;
			}
		case 32:
			switch (mistake) {
			case 0:
				display = 16;
				led_display_change(display);      //led_display
				result = 16;
				++mistake;
				state = GAME_LED_ON;
				break;
			case 1:
				display = 8;
				led_display_change(display);       //led_display
				result = 8;
				++mistake;
				state = GAME_LED_ON;
				break;
			case 2:
				display = 0;
				led_display_change(display);       //led_display
				result = 0;
				++mistake;
				state = GAME_LED_ON;
				break;
			default:
				display = 0;    
				led_display_change(display);       //led_display
				result = 0;
				mistake = 0;
				state = LOSS;
			}
		}
	}
};

void loss() {
	led_display_loss_on();    //led_display_loss_on
	extern enum State state;
	state = INIT_MODE;
};

void win() {
	led_display_win_on();   //led_display_win_on
	extern enum State state;
	state = INIT_MODE;
};