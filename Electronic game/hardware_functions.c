/*
 * hardware_functions.c
 *
 * Created: 22.07.2015 13:43:14
 *  Author: Ne0n
 */ 

#include "hardware_defines.h"
#include "hardware_functions.h"
#include "software_defines.h"

void init_ddr() {
	DDR_LED_FIELD_0 |= (1 << PIN_LED_FIELD_0);
	DDR_LED_FIELD_1 |= (1 << PIN_LED_FIELD_1);
	DDR_LED_FIELD_2 |= (1 << PIN_LED_FIELD_2);
	DDR_LED_FIELD_3 |= (1 << PIN_LED_FIELD_3);
	DDR_LED_FIELD_4 |= (1 << PIN_LED_FIELD_4);
	DDR_LED_FIELD_5 |= (1 << PIN_LED_FIELD_5);
	DDR_LED_FIELD_6 |= (1 << PIN_LED_FIELD_6);
	DDR_LED_FIELD_7 |= (1 << PIN_LED_FIELD_7);
	
	DDR_LED_MODE_GREEN |= (1 << PIN_LED_MODE_GREEN);
	DDR_LED_MODE_RED   |= (1 << PIN_LED_MODE_RED);
	
	DDR_LED_DISPLAY_LOSS |= (1 << PIN_LED_DISPLAY_LOSS);
	DDR_LED_DISPLAY_8    |= (1 << PIN_LED_DISPLAY_8);
	DDR_LED_DISPLAY_16   |= (1 << PIN_LED_DISPLAY_16);
	DDR_LED_DISPLAY_32   |= (1 << PIN_LED_DISPLAY_32);
	DDR_LED_DISPLAY_64   |= (1 << PIN_LED_DISPLAY_64);
	DDR_LED_DISPLAY_WIN  |= (1 << PIN_LED_DISPLAY_WIN);
	
	DDR_BUTTON_START  &= (~(1 << PIN_BUTTON_START));
	DDR_BUTTON_MODE   &= (~(1 << PIN_BUTTON_MODE));
	DDR_BUTTON_RED    &= (~(1 << PIN_BUTTON_RED));
	DDR_BUTTON_BLUE   &= (~(1 << PIN_BUTTON_BLUE));
	DDR_BUTTON_GREEN  &= (~(1 << PIN_BUTTON_GREEN));
	DDR_BUTTON_YELLOW &= (~(1 << PIN_BUTTON_YELLOW));
	
	PORT_BUTTON_START  |= (1 << PIN_BUTTON_START);
	PORT_BUTTON_MODE   |= (1 << PIN_BUTTON_MODE);
	PORT_BUTTON_RED    |= (1 << PIN_BUTTON_RED);
	PORT_BUTTON_BLUE   |= (1 << PIN_BUTTON_BLUE);
	PORT_BUTTON_GREEN  |= (1 << PIN_BUTTON_GREEN);
	PORT_BUTTON_YELLOW |= (1 << PIN_BUTTON_YELLOW);
};

void led_field_on  (uchar_t number) {
	switch (number) {
	case 0:
		DDR_LED_FIELD_0 |= (1 << PIN_LED_FIELD_0);
		PORT_LED_FIELD_0 |= (1 << PIN_LED_FIELD_0);
		break;
	case 1:
		DDR_LED_FIELD_1 |= (1 << PIN_LED_FIELD_1);
		PORT_LED_FIELD_1 |= (1 << PIN_LED_FIELD_1);
		break;		
	case 2:
		DDR_LED_FIELD_2 |= (1 << PIN_LED_FIELD_2);
		PORT_LED_FIELD_2 |= (1 << PIN_LED_FIELD_2);
		break;
	case 3:
		DDR_LED_FIELD_3 |= (1 << PIN_LED_FIELD_3);
		PORT_LED_FIELD_3 |= (1 << PIN_LED_FIELD_3);
		break;
	case 4:
		DDR_LED_FIELD_4 |= (1 << PIN_LED_FIELD_4);
		PORT_LED_FIELD_4 |= (1 << PIN_LED_FIELD_4);
		break;
	case 5:
		DDR_LED_FIELD_5 |= (1 << PIN_LED_FIELD_5);
		PORT_LED_FIELD_5 |= (1 << PIN_LED_FIELD_5);
		break;
	case 6:
		DDR_LED_FIELD_6 |= (1 << PIN_LED_FIELD_6);
		PORT_LED_FIELD_6 |= (1 << PIN_LED_FIELD_6);
		break;
	case 7:	
		DDR_LED_FIELD_7 |= (1 << PIN_LED_FIELD_7);
		PORT_LED_FIELD_7 |= (1 << PIN_LED_FIELD_7);
		break;
	}
};

void led_field_off (uchar_t number) {
	switch (number) {
	case 0:
		DDR_LED_FIELD_0 |= (1 << PIN_LED_FIELD_0);
		PORT_LED_FIELD_0 &= (~(1 << PIN_LED_FIELD_0));
		break;
	case 1:
		DDR_LED_FIELD_1 |= (1 << PIN_LED_FIELD_1);
		PORT_LED_FIELD_1 &= (~(1 << PIN_LED_FIELD_1));
		break;
	case 2:
		DDR_LED_FIELD_2 |= (1 << PIN_LED_FIELD_2);
		PORT_LED_FIELD_2 &= (~(1 << PIN_LED_FIELD_2));
		break;
	case 3:
		DDR_LED_FIELD_3 |= (1 << PIN_LED_FIELD_3);
		PORT_LED_FIELD_3 &= (~(1 << PIN_LED_FIELD_3));
		break;
	case 4:
		DDR_LED_FIELD_4 |= (1 << PIN_LED_FIELD_4);
		PORT_LED_FIELD_4 &= (~(1 << PIN_LED_FIELD_4));
		break;
	case 5:
		DDR_LED_FIELD_5 |= (1 << PIN_LED_FIELD_5);
		PORT_LED_FIELD_5 &= (~(1 << PIN_LED_FIELD_5));
		break;
	case 6:
		DDR_LED_FIELD_6 |= (1 << PIN_LED_FIELD_6);
		PORT_LED_FIELD_6 &= (~(1 << PIN_LED_FIELD_6));
		break;
	case 7:
		DDR_LED_FIELD_7 |= (1 << PIN_LED_FIELD_7);
		PORT_LED_FIELD_7 &= (~(1 << PIN_LED_FIELD_7));
		break;
	}	
};

void led_mode_change () {
	extern enum Mode mode;
	switch (mode) {
	case REG_SLOW: 
		PORT_LED_MODE_GREEN |= (1 << PIN_LED_MODE_GREEN);
		PORT_LED_MODE_RED   &= (~(1 << PIN_LED_MODE_RED));
		break;
	case REG_FAST:
		PORT_LED_MODE_GREEN |= (1 << PIN_LED_MODE_GREEN);
		PORT_LED_MODE_RED   |= (1 << PIN_LED_MODE_RED);
		break;
	case SURV:
		PORT_LED_MODE_RED   |= (1 << PIN_LED_MODE_RED);
		PORT_LED_MODE_GREEN &= (~(1 << PIN_LED_MODE_GREEN));
		break;	
	}
};

void led_display_all_off () {
	PORT_LED_DISPLAY_LOSS &= (~(1 << PIN_LED_DISPLAY_LOSS));
	PORT_LED_DISPLAY_8    &= (~(1 << PIN_LED_DISPLAY_8));
	PORT_LED_DISPLAY_16   &= (~(1 << PIN_LED_DISPLAY_16));
	PORT_LED_DISPLAY_32   &= (~(1 << PIN_LED_DISPLAY_32));
	PORT_LED_DISPLAY_64   &= (~(1 << PIN_LED_DISPLAY_64));
	PORT_LED_DISPLAY_WIN  &= (~(1 << PIN_LED_DISPLAY_WIN));
};

void led_display_change (uchar_t display) {
	switch (display) {
	case 0:
		PORT_LED_DISPLAY_8    &= (~(1 << PIN_LED_DISPLAY_8));
		PORT_LED_DISPLAY_16   &= (~(1 << PIN_LED_DISPLAY_16));
		PORT_LED_DISPLAY_32   &= (~(1 << PIN_LED_DISPLAY_32));
		PORT_LED_DISPLAY_64   &= (~(1 << PIN_LED_DISPLAY_64));
		break;
	case 8:
		PORT_LED_DISPLAY_8    |= (1 << PIN_LED_DISPLAY_8);
		PORT_LED_DISPLAY_16   &= (~(1 << PIN_LED_DISPLAY_16));
		PORT_LED_DISPLAY_32   &= (~(1 << PIN_LED_DISPLAY_32));
		PORT_LED_DISPLAY_64   &= (~(1 << PIN_LED_DISPLAY_64));
		break;
	case 16:
		PORT_LED_DISPLAY_8    &= (~(1 << PIN_LED_DISPLAY_8));
		PORT_LED_DISPLAY_16   |= (1 << PIN_LED_DISPLAY_16);
		PORT_LED_DISPLAY_32   &= (~(1 << PIN_LED_DISPLAY_32));
		PORT_LED_DISPLAY_64   &= (~(1 << PIN_LED_DISPLAY_64));
		break;
	case 32:
		PORT_LED_DISPLAY_8    &= (~(1 << PIN_LED_DISPLAY_8));
		PORT_LED_DISPLAY_16   &= (~(1 << PIN_LED_DISPLAY_16));
		PORT_LED_DISPLAY_32   |= (1 << PIN_LED_DISPLAY_32);
		PORT_LED_DISPLAY_64   &= (~(1 << PIN_LED_DISPLAY_64));
		break;
	case 64:
		PORT_LED_DISPLAY_8    &= (~(1 << PIN_LED_DISPLAY_8));
		PORT_LED_DISPLAY_16   &= (~(1 << PIN_LED_DISPLAY_16));
		PORT_LED_DISPLAY_32   &= (~(1 << PIN_LED_DISPLAY_32));
		PORT_LED_DISPLAY_64   |= (1 << PIN_LED_DISPLAY_64);
		break;	
	}
};

void led_display_loss_on () {
	PORT_LED_DISPLAY_LOSS |= (1 << PIN_LED_DISPLAY_LOSS);
};

void led_display_win_on () {
	PORT_LED_DISPLAY_WIN |= (1 << PIN_LED_DISPLAY_WIN);
};

uchar_t check_button_start() {
	if (!(STATE_BUTTON_START & (1 << PIN_BUTTON_START))) {
		return 1;
	}
	else {
		return 0;	
	}
};

uchar_t check_button_mode() {
	if (!(STATE_BUTTON_MODE & (1 << PIN_BUTTON_MODE))) {
		return 1;
	}
	else {
		return 0;
	}
};

uchar_t check_button_red() {
	if (!(STATE_BUTTON_RED & (1 << PIN_BUTTON_RED))) {
		return 1;
	}
	else {
		return 0;
	}
};

uchar_t check_button_blue() {
	if (!(STATE_BUTTON_BLUE & (1 << PIN_BUTTON_BLUE))) {
		return 1;
	}
	else {
		return 0;
	}
};

uchar_t check_button_green() {
	if (!(STATE_BUTTON_GREEN & (1 << PIN_BUTTON_GREEN))) {
		return 1;
	}
	else {
		return 0;
	}
};

uchar_t check_button_yellow() {
	if (!(STATE_BUTTON_YELLOW & (1 << PIN_BUTTON_YELLOW))) {
		return 1;
	}
	else {
		return 0;
	}
};