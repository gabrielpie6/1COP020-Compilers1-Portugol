#ifndef QUEUE_H
#define QUEUE_H

typedef void * Queue;

Queue  createQueue    ();
void   removeQueue    (Queue);

void   insertInQueue  (Queue, void *);
void * popInQueue     (Queue);
int    getQueueLength (Queue);
void * seekInQueue    (Queue, int);

int    isEmpty        (Queue);



#endif