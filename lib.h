#ifndef _LIB_H_INCLUDED_
#define _LIB_H_INCLUDED_

void* memset(void* b, int c,
             long len);                                // fill the memory with a specific byte of data
void* memcpy(void* dst, const void* src, long len);    // copy memory
int memcmp(const void* b1, const void* b2, long len);  // memory comparison
int strlen(const char* s);                             // retrun length of string
char* strcpy(char* dst, const char* src);              // copy string
int strcmp(const char* s1, const char* s2);            // string comparison
int strlncmp(const char* s1, const char* s2, int len); // comparing strings by length

int putc(unsigned char c);                    // send one character
int puts(unsigned char* str);                 // send string
int putxval(unsigned long value, int column); // display hexadecimal of numbers
#endif
