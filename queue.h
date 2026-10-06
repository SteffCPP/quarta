#ifndef QUEUE_H
#define QUEUE_H
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _QueueNodeS{
    void* data;
    struct _QueueNodeS* next;
} _QueueNode;

typedef struct {
    _QueueNode* front;
    _QueueNode* back;
    size_t elementSize;
} Queue;

void Queue_init(Queue* queue, size_t elementSize){
    queue->front = NULL;
    queue->back = NULL;
    queue->elementSize = elementSize;
}

bool Queue_push(Queue* queue, const void* value){
    _QueueNode* node = (_QueueNode*)malloc(sizeof(queue->elementSize));
    if(!node){ return false; }

    node->data = malloc(sizeof(queue->elementSize));
    if(!node->data){ free(node); return false; }

    memcpy(node->data, value, queue->elementSize);

    node->next = NULL;

    if(queue->back == NULL){
        queue->front = node;
        queue->back = node;
    }else{
        queue->back->next = node;
        queue->back = node;
    }

    return true;
}

bool Queue_pop(Queue* queue, const void* container){
    if(queue->front == NULL) return false;

    _QueueNode* node = queue->front;

    memcpy(container, node->data, queue->elementSize);

    queue->front = node->next;

    if(queue->front == NULL){ queue->back = NULL; }

    free(queue->front->data);
    free(queue->front);
    return true;
}

#endif