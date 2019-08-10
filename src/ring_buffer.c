#include "../include/ring_buffer.h"
#include <stdio.h>

void ring_buffer_init(ring_buffer* rb)
{
    rb->size = sizeof(rb->data_array) / sizeof(rb->data_array[0]);
    printf("data array size: %lu\n", rb->size);
    // set all the elements to 0?
    // there's probably a C memory management function that does something like this
    for (int i = 0; i < rb->size; ++i) {
        rb->data_array[i] = 0;
    }    
    rb->write_index = 0;
    rb->read_index = 0;
}

void ring_buffer_enqueue(ring_buffer *rb, uint8_t element)
{
    if (!ring_buffer_full(rb)) {
        rb->data_array[rb->write_index] = element;        
        rb->write_index = (rb->write_index + 1) % rb->size;    
    }
    else {
        printf("ERROR: buffer full!");
    }
}

uint8_t ring_buffer_dequeue(ring_buffer *rb)
{
    uint8_t element;

    // should probably do something other than setting the dequeued spot to 0
    // probably some sort of C memory management function?
    if (!ring_buffer_empty(rb)) {
        element = rb->data_array[rb->read_index];
        rb->data_array[rb->read_index] = 0;
        rb->read_index = (rb->read_index + 1) % rb->size;
    }
    else {
        prinf("ERROR: buffer empty!");
        element = -1;
    }
    return element;
}

// it seems like there are two options for determining fullness/emptiness:
// 1. Keeping a "count" that increments/decrements for each enqueue/dequeue call
// 2. Not allowing data to be overwritten: if write index is one behind the read index
// then the buffer is full and we won't allow anymore writes to happen, thus preventing
// the write index to increment again, becoming equal to the read index; and we can
// use r/w index equality to determine emptiness

bool ring_buffer_full(ring_buffer *rb)
{   
    return (rb->write_index == (rb->read_index - 1));
}

bool ring_buffer_empty(ring_buffer *rb)
{
    return (rb->write_index == rb->read_index);
}