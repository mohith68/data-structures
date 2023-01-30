#include <stdio.h>

#define ARRSIZE 6

int array[ARRSIZE];

int front = -1, rear = -1;

int checkFull() {

if ((front == rear + 1) || (front == 0 && rear == ARRSIZE - 1)) return 1;

return 0;

}

int checkEmpty() {

if (front == -1) return 1;

return 0;

}

void enQueue(int ele) {

if (checkFull())

printf("\n Can't enter more. Queue Full \n");

else {

if (front == -1) front = 0;

rear = (rear + 1) % ARRSIZE;

array[rear] = ele;

printf("\n Pushed -> %d", ele);

}

}

int deQueue() {

int ele;

if (checkEmpty()) {

printf("\n Queue is empty !! \n");

return (-1);

} else {

ele = array[front];

if (front == rear) {

front = -1;

rear = -1;

}

else {

front = (front + 1) % ARRSIZE;

}

printf("\n Popped out -> %d \n", ele);

return (ele);

}

}
void display() {

int i;

if (checkEmpty())

printf(" \n The queue is Empty\n");

else {

printf("\n Pointer for first element -> %d ", front);

printf("\n Items -> ");

for (i = front; i != rear; i = (i + 1) % ARRSIZE) {

printf("%d ", array[i]);

}

printf("%d ", array[i]);

printf("\n Pointer for Last element -> %d \n", rear);

}

}

int main() {

deQueue();

enQueue(10);

enQueue(15);

enQueue(20);

enQueue(30);

enQueue(50);

enQueue(60);

enQueue(1);

display();

deQueue();

display();

enQueue(2);

display();

enQueue(100);

return 0;

}
