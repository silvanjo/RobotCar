#ifndef RCDATA_STRUCT_HEADER
#define RCDATA_STRUCT_HEADER

#define BUTTON_NOT_PRESSED 0
#define BUTTON_PRESSED 1

struct RCData
{

    uint8_t button1;
    uint8_t button2;
    uint8_t button3;
    uint8_t button4;
    uint8_t button5;
    uint8_t button6;

    uint32_t joy_x_val;
    unt32_t joy_y_val;

    int32_t rotary_switch_val = 0;

};


#endif