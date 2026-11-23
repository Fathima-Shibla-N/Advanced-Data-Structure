#include <stdio.h>
#define SIZE 5

int q[SIZE], front = 0, rear = -1, count = 0;

void enqueue(int x) {
    if (count == SIZE) { printf("Overflow\n"); return; }
    rear = (rear + 1) % SIZE;
    q[rear] = x;
    count++;
}

void dequeue() {
    if (count == 0) { printf("Underflow\n"); return; }
    printf("Deleted %d\n", q[front]);
    front = (front + 1) % SIZE;
    count--;
}

void display() {
    for (int i = 0, j = front; i < count; i++, j = (j + 1) % SIZE)
        printf("%d ", q[j]);
    printf("\n");
}

int main() {
    int ch, x;
    while (1) {
        printf("1.Enqueue 2.Dequeue 3.Display 4.Exit: ");
        scanf("%d", &ch);
        if (ch == 1) { scanf("%d", &x); enqueue(x); }
        else if (ch == 2) dequeue();
        else if (ch == 3) display();
        else break;
    }
    return 0;
}

