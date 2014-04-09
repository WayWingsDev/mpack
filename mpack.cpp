#include "mpack.h"

union UFloat ufloat;

MPackObject::MPackObject(unsigned char* data, int maxSize)
  : data(data), size(1) {
    this->data[0] = 0x80;
}

int MPackObject::packFloat(char* name, float value) {
  size_t name_len = strlen(name);
  ufloat.fval = value;

  this->data[0]++;

  this->data[this->size] = 0xA0 + name_len;
  this->size++;
  memcpy(this->data + this->size, name, name_len);
  this->size += name_len;

  this->data[this->size] = 0xCA;
  this->size++;
  memcpy(this->data + this->size, ufloat.bytes, 4);
  this->size += 4;

  return this->size;
}
