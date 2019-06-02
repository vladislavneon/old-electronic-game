#pragma once

typedef unsigned char uchar_t;
typedef unsigned int  uint_t;

enum State {BEGIN, SKIP, INIT_MODE, CHECK_START, INIT_ALL, GAME_LED_ON, 
				CHECK_BUTTON, WRONG_BUTTON, RIGHT_BUTTON ,
	            TIME_OVER, LOSS, WIN};

enum Mode  {REG_SLOW, REG_FAST, SURV};

enum Color {BLUE, RED, GREEN, YELLOW};

struct Button {
	uchar_t blue   : 1;
	uchar_t red    : 1;
	uchar_t green  : 1;
	uchar_t yellow : 1;
	uchar_t        : 0;
};

struct Enable_state {
	uchar_t init_mode ;
	uchar_t check_start;
	uchar_t game_led_on;
	uchar_t init_all;
	uchar_t time_over;
};