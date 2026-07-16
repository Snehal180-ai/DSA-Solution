class MyCircularQueue {
    vector<int> queue;
    int front, rear;
    int max_size;

public:
    MyCircularQueue(int k) {
        queue.resize(k);
        max_size = k;
        front = -1;
        rear = -1;
    }

    bool enQueue(int value) {
        if ((rear + 1) % max_size == front)
            return false;

        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % max_size;
        }

        queue[rear] = value;
        return true;
    }

    bool deQueue() {
        if (front == -1)
            return false;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % max_size;
        }

        return true;
    }

    int Front() {
        if (isEmpty())
            return -1;

        return queue[front];
    }

    int Rear() {
        if (isEmpty())
            return -1;

        return queue[rear];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % max_size == front;
    }
};