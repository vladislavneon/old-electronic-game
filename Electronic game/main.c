#include "software_defines.h"
#include "state_functions.h"

//Initialization

	uint_t  time_0  = 0;
	uint_t  time_8  = 0;
	uint_t  time_16 = 0;
	uint_t  time_32 = 0;
	uint_t  time_64 = 0;

	uchar_t display = 0;

	uchar_t result  = 0;

	uchar_t cur_led = 0;

	enum Color   cur_color;

	uchar_t mistake = 0;

	struct Button  button;

	struct Enable_state enable_state;

	enum State state = INIT_MODE;

	enum Mode mode  = REG_SLOW;


int main() {

	while (1) {
		switch (state) {
		case BEGIN:
			begin();
			break;
		case SKIP:
			//Empty event
			break;
		case INIT_MODE:
			init_mode();
			break;
		case CHECK_START:
			check_start();
			break;
		case INIT_ALL:
			init_all();
			break;
		case GAME_LED_ON:
			game_led_on();
			break;
		case CHECK_BUTTON:
			check_button();
			break;
		case WRONG_BUTTON:
			wrong_button();
			break;
		case RIGHT_BUTTON:
			right_button();
			break;
		case TIME_OVER:
			time_over();
			break;
		case LOSS:
			loss();
			break;
		case WIN:
			win();
			break;
		}
	}
}