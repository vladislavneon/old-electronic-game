#include "software_functions.h"
#include "state_functions.h"
#include "software_defines.h"

uchar_t check_color () {
	extern struct Button button;
	extern enum   Color  cur_color;
	switch (cur_color) {
	case BLUE:
		if ((button.blue) && (!button.red) && (!button.green) && (!button.yellow)) {
			return 1;
		}
		else {
			return 0;
		}
		break;
	case RED:
		if ((!button.blue) && (button.red) && (!button.green) && (!button.yellow)) {
			return 1;
		}
		else {
			return 0;
		}
		break;
	case GREEN:
		if ((!button.blue) && (!button.red) && (button.green) && (!button.yellow)) {
			return 1;
		}
		else {
			return 0;
		}
		break;
	case YELLOW:
		if ((!button.blue) && (!button.red) && (!button.green) && (button.yellow)) {
			return 1;
		}
		else {
			return 0;
		}
		break;
	}
};