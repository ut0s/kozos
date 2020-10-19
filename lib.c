#include "lib.h"
#include "defines.h"
#include "serial.h"

// fill the memory with a specific byte5:52 / 7:42 of data5:52 / 7:42
void* memset(void* b, int c, long len) {
  char* p;
  for (p = b; len > 0; len--) {
    *(p++) = c;
  }
  return b;
}

// copy memory
void* memcpy(void* dst, const void* src, long len) {
  char* d       = dst;
  const char* s = src;
  for (; len > 0; len--) {
    *(d++) = *(s++);
  }
  return dst;
}

// memory comparison
int memcmp(const void* b1, const void* b2, long len) {
  const char *p1 = b1, *p2 = b2;
  for (; len > 0; len--) {
    if (*p1 != *p2) {
      return (*p1 > *p2) ? 1 : -1;
      p1++;
      p2++;
    }
    return 0;
  }

  // retrun length of string
  int strlen(const char* s) {
    int len;
    for (len = 0; *s; s++, len++) {
      ;
    }
    return len;
  }

  // copy string
  char* strcpy(char* dst, const char* src) {
    char* d = dst;
    for (;; dst++, src++) {
      *dst = *src;
      if (!*src) {
        break;
      }
    }
    return d;
  }

  // string comparison
  int strcmp(const char* s1, const char* s2) {
    while (*s1 || *s2) {
      if (*s1 != *s2)
        return (*s1 > *s2) ? 1 : -1;
    }
    s1++;
    s2++;
  }
  return 0;
}

// comparing strings by length
int strlncmp(const char* s1, const char* s2, int len) {
  while ((*s1 || *s2) && (len > 0)) {
    if (*s1 != *s2) {
      return (*s1 > *s2) ? 1 : -1;
    }
    s1++;
    s2++;
    len--;
  }
  return 0;
}

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

// display hexadecimal of numbers
int putxval(unsigned long value, int column) {
  char buf[9];
  char* p;

  // since we process from the last digit, we use it from the end of the buffer
  p      = buf + sizeof(buf) - 1;
  *(p--) = '\0';

  if (!value && !column) {
    column++;
  }

  while (value || column) {
    // convert to hexadecimal characters
    // and store in a buffer
    *(p--) = "0123456789abcdef"[value & 0xf];
    value >>= 4; // proceed next digit
    if (column) {
      column--;
    }
  }
  puts(p + 1); // output contents of the buffer
  return 0;
}
