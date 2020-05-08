#include "lib.h"
#include "defines.h"
#include "serial.h"

// send one character
int putc(unsigned char c) {
  if (c == '\n') {
    serial_send_byte(SERIAL_DEFAULT_DEVICE, '\r');
  }
  return serial_send_byte(SERIAL_DEFAULT_DEVICE, c);
}

// send string
int puts(unsigned char* str) {
  while (*str) {
    putc(*(str++));
  }
  return 0;
}