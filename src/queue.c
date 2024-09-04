#include "queue.h"

#include<stdlib.h>

typedef struct StQueueNode{
    void * box;
    struct StQueueNode * next;
} * QueueNode;

typedef struct StQueue {
    int length;
    QueueNode head, tail;
} * QueueType;


Queue createQueue ()
{
    QueueType q = malloc(sizeof(struct StQueue));
    q->length   = 0;
    q->head     = NULL;
    q->tail     = q->head;

    return (Queue) q;
}
// void removeQueue (Queue);

void insertInQueue (Queue q, void * p)
{
    QueueNode n = malloc(sizeof(struct StQueueNode));
    n->box      = p;
    n->next     = NULL;

    if (isEmpty(q))
    {
        ((QueueType) q)->tail = n;
        ((QueueType) q)->head = n;
    }
    else
    {
        ((QueueType) q)->tail->next = n;
        ((QueueType) q)->tail = ((QueueType) q)->tail->next;
    }
    
    ((QueueType) q)->length++;
}

void * popInQueue (Queue q)
{
    if (!isEmpty(q))
    {
        QueueNode n = ((QueueType) q)->head;
        ((QueueType) q)->head = ((QueueType) q)->head->next;
        void * w = n->box;
        free(n);
        ((QueueType) q)->length--;

        return w;
    }
    else return NULL;
}
int getQueueLength (Queue q) { return ((QueueType) q)->length; }

void * seekInQueue (Queue q, int n)
{
    QueueNode p = ((QueueType) q)->head;
    if (n >= ((QueueType) q)->length)
        return NULL;
    {
        for (int i = 0; i < n; i++)
            p = p->next;
        return p->box;
    }
}

int isEmpty (Queue q){ return (((QueueType) q)->length <= 0); }