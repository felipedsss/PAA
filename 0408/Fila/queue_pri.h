#include "queue_pub.h"

typedef struct Queue {
    int enqueued;
    int size;
    int sizedata;
    void *data;
    int inicio;
    int fim;
} Queue;