#include "stack_pub.h"

typedef struct Stack {
    int size;
    int sizedata;
    void *data;
} Stack;