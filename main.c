#include "defines.h"
#include "serial.h"
#include "lib.h"

int main(void)
{
  // initialize serial device
  serial_init(SERIAL_DEFAULT_DEVICE);
  // output "Hello world!"
  puts("Hello World!\n");
  while (1) {
    ;
  }
  return 0;
}
