#include <iostream>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* front; // 队首指针
    Node* rear;  // 队尾指针

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(const T& item) {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            std::cerr << "Error: Queue is empty. Cannot dequeue.\n";
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            rear = nullptr; // 队列为空，将 rear 指针置为 nullptr
        }
    }

    T peek() const {
        if (isEmpty()) {
            std::cerr << "Error: Queue is empty. Cannot peek.\n";
            exit(1);
        }
        return front->data;
    }

    bool isEmpty() const {
        return front == nullptr;
    }
};

int main() {
    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Front element of queue: " << q.peek() << std::endl;

    q.dequeue();
    std::cout << "Front element of queue after dequeue: " << q.peek() << std::endl;

    return 0;
}