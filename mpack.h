#ifndef MPACK_H__
#define MPACK_H__

#include <stdio.h>
#include <string.h>

union UFloat {
    unsigned char bytes[4];
    float fval;
};

class MPackObject {
private:
  unsigned char* data;
  unsigned int size;
  unsigned int maxSize;
public:
  MPackObject(unsigned char* data, int maxSize);

  int packFloat(char* name, float value);
};

#endif
