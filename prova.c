#include <stdio.h>

#include "queue.h"

int main(){
    printf("Hello World!\n");

    Queue queue;
    Queue_init(&queue, sizeof(int));
    Queue_push(&queue, 50);

    return 0;
}