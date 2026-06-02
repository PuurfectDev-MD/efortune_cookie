#include <avr/pgmspace.h>

const char string_0[] PROGMEM = "This is a text..."
const char string_1[] PROGMEM = "This is a text..."
const char string_3[] PROGMEM = "This is a text..."
const char string_4[] PROGMEM = "You can store all the fortune cookies here"
const char string_5[] PROGMEM = "All the text you want...."
const char string_6[] PROGMEM = "All the text you want...."
const char string_7[] PROGMEM = "All the text you want...."
const char string_8[] PROGMEM = "All the text you want...."
const char string_7[] PROGMEM = "till forever and ever and ever...."

const char* const fortuneTable[] PROGMEM = {
  string_0,
  string_1,
  string_2,
  string_3,
  string_4
};


const int totalFortunes = 5