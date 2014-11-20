#ifndef RINGBUFFER_H
#define	RINGBUFFER_H

#define BUFFER_SIZE     32

typedef struct {
    unsigned char buffer[BUFFER_SIZE];
    unsigned char head;
    unsigned char tail;
} RingBuffer_t;

RingBuffer_t    interruptDataBuf;
RingBuffer_t*   interruptDataBuf_p;

void RingBufferInit();
void RingBufferPush(RingBuffer_t *buffer, unsigned char data);
unsigned char RingBufferPull(RingBuffer_t *buffer);
void RingBufferSync(RingBuffer_t* buffer);

#endif	/* RINGBUFFER_H */

