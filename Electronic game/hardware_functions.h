#pragma once

#include "software_defines.h"

void init_ddr();

void led_field_on  (uchar_t number);

void led_field_off (uchar_t number);

void led_mode_change ();

void led_display_all_off ();

void led_display_change (uchar_t display);

void led_display_loss_on ();

void led_display_win_on ();

uchar_t check_button_start();

uchar_t check_button_mode();

uchar_t check_button_red();

uchar_t check_button_blue();

uchar_t check_button_green();

uchar_t check_button_yellow();