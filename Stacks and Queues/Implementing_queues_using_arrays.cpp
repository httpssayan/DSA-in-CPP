#include<bits/stdc++.h>
using namespace std;

class ArrayQueue {
    int *arr;
    int front, rear, size;
public:
    ArrayQueue(int s) {
        size = s;
        arr = new int[size];
        front = rear = -1;
    }

    void enqueue(int x) {
        if ((rear + 1) % size == front) {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % size;
        arr[rear] = x;
        if (front == -1)
            front = rear;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    int peek() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return -1; // Return -1 to indicate the queue is empty
        }
        return arr[front];
    }

    bool isEmpty() {
        return front == -1;
    }
};
int main() {
    ArrayQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // This will show "Queue is full"

    cout << "Front element: " << q.peek() << endl; // Should print 10

    q.dequeue();
    cout << "Front element after dequeue: " << q.peek() << endl; // Should print 20

    return 0;
}