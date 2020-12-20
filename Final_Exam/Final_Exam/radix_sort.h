
#ifndef radix_sort_h
#define radix_sort_h

#include "queue.h"

#define BUCKETS 10
#define DIGITS 4

void radix_sort(int list[], int n) {
    int i,b,d,factor = 1;
    
    QueueType queues[BUCKETS];
    
    for(b=0;b<BUCKETS;b++) {
        queue_init(&queues[b]);
    }
    
    for(d=0;d<DIGITS;d++) {
        for(i=0;i<n;i++) {
            enqueue(&queues[(list[i] / factor) % 10], list[i]);
        }
        
        for(b=i=0;b<BUCKETS;b++) {
            while (!queue_is_empty(&queues[b])) {
                list[i++] = dequeue(&queues[b]);
            }
        }
        factor *= 10;
    }
}


#endif /* radix_sort_h */
