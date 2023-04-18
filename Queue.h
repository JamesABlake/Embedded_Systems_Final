#ifndef QUEUE_H
#define QUEUE_H

template<typename T, int maxSize> class Queue {
public:
  void Enqueue(T item) {
    (back = back + 1) % maxSize;
    data[back] = item;
  }

  T Dequeue() {
    T item = data[front];
    (front = front + 1) % maxSize;
    return item;
  }

  T PeekFront() {
    return data[front];
  }

  T PeekBack() {
    return data[back];
  }

private:
  T data[maxSize];
  int front = 0;
  int back = 0;
};
#endif