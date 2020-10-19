#include "defines.h"
#include "lib.h"
#include "serial.h"

int main(void) {
  // initialize serial device
  serial_init(SERIAL_DEFAULT_DEVICE);
  // output "Hello world!"
  puts("Hello World!\n");

  // output number
  putxval(0x10, 2);
  puts("\n");
  putxval(0x11, 2);
  puts("\n");
  putxval(0x1a, 1);
  puts("\n");
  putxval(0xffff, 4);
  puts("\n");

  while (1) {
    ;
  }
  return 0;
}
