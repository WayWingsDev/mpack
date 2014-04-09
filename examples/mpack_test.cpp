#include "mpack.h"

#define MAX_DATA 100

int main(void) {
    unsigned char data[MAX_DATA];
    MPackObject obj(data, MAX_DATA);
    obj.packFloat("temp", 23.3);
    int size = obj.packFloat("hum", 56.3);
    for (int i = 0; i < size; i++) {
      printf("0x%02X\n", data[i]);
    }

    return 1;
}
