#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define MAX_SIZE 50

typedef struct ring_buffer {
    uint8_t read_index;
    uint8_t write_index;
    uint8_t data_array[MAX_SIZE];
    size_t size;
} ring_buffer;

void ring_buffer_init(ring_buffer *rb);
void ring_buffer_enqueue(ring_buffer *rb, uint8_t element);
uint8_t ring_buffer_dequeue(ring_buffer *rb);
bool ring_buffer_full(ring_buffer *rb);
bool ring_buffer_empty(ring_buffer *rb);


#endif