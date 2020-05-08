#ifndef _SERIAL_H_INCLUDED_
#define _SERIAL_H_INCLUDED_

int serial_init(int index); // initilize device
int serial_is_send_enable(int index); // wheater enable to send or not
int serial_send_byte(int index, unsigned char b); // send one character
#endif
