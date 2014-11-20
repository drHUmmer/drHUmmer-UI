#include "ringbuffer.h"

void RingBufferInit() {
    unsigned char counter;
    for (counter = 0; counter < BUFFER_SIZE; counter ++) {
        interruptDataBuf.buffer[counter] = 0;
    }

    interruptDataBuf.head = 0;
    interruptDataBuf.tail = 0;

    interruptDataBuf_p = &interruptDataBuf;
}

void RingBufferPush(RingBuffer_t *buffer, unsigned char data) {
    unsigned char next = (unsigned char)(buffer->head + 1) % BUFFER_SIZE;

//    if(next != buffer->tail)
//    {
        buffer->buffer[buffer->head] = data;
        buffer->head = next;
//    }
}

unsigned char RingBufferPull(RingBuffer_t *buffer) {
    if (buffer->head == buffer->tail) {
        return 0;
    }
    else
    {
        unsigned char returnValue = buffer->buffer[buffer->tail];
        buffer->tail = (unsigned char)(buffer->tail + 1) % BUFFER_SIZE;
        return returnValue;
    }
}

void RingBufferSync(RingBuffer_t* buffer) {
    buffer->tail = buffer->head;
}