#include <stdio.h>
#include <stdlib.h>

struct Queue{
	int a[100];
	int front, rear;
	int length;
};

void init(struct Queue* q, int length){
	q->front = 0;
	q->rear = -1;
	q->length =length;
}

int isEmpty(struct Queue* q){
	if(q->front > q->rear) return 1;
	else return 0;
}

int isFull(struct Queue* q){
	if(q->rear == q->length-1) return 1;
	else return 0;
}

void enqueue(struct Queue* q, int x){
	if(isFull(q)){
		printf("Queue full!!\n");
	} else{
		q->a[++q->rear] = x;
	}
}

int dequeue(struct Queue* q){
	if(isEmpty(q)){
		return -1;
	} else {
		return q->a[q->front++];
	}
}

