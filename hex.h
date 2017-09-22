#ifndef _HEX_H_
#define _HEX_H_

char *bin2hex(unsigned char *data, int size);

unsigned char *hex2bin(const char *data, int size, int *outlen);

#endif
