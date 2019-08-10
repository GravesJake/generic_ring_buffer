#include "../include/ring_buffer.h"
#include <stdio.h>

int main()
{
    struct ring_buffer rb;

    int x = rb.size;
    printf("data array size before init: %d\n", x);
    ring_buffer_init(&rb);
    ring_buffer_enqueue(&rb, 65);
    ring_buffer_enqueue(&rb, 66);
    ring_buffer_enqueue(&rb, 67);
    ring_buffer_enqueue(&rb, 68);
    ring_buffer_enqueue(&rb, 69);
    ring_buffer_enqueue(&rb, 70);
    ring_buffer_enqueue(&rb, 71);
    ring_buffer_enqueue(&rb, 72);
    ring_buffer_enqueue(&rb, 73);
    
    // printf("data array[0]: %d\n", rb.data_array[0]);
    // printf("rb.size: %d\n", rb.size);
    // printf("rb write index: %d\n", rb.write_index);
    // printf("rb size: %lu\n", rb.size);
    printf("data array:\n");
    // printf(&rb.data_array);
    // printf("\n");
    for (int i = 0; i < rb.size; ++i) {
        // printf(&rb.data_array + i / sizeof(rb.data_array[0]));
        printf("%u\n", rb.data_array[i]);
    }

    int y = ring_buffer_dequeue(&rb);

    printf("dequeued: %d\n", y);

    printf("data array:\n");
    // printf(&rb.data_array);
    // printf("\n");
    for (int i = 0; i < rb.size; ++i) {
        // printf(&rb.data_array + i / sizeof(rb.data_array[0]));
        printf("%u\n", rb.data_array[i]);
    }
    
    return 0;
}