#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {
private:
    struct Node {
        T value;
        Node* next;
        Node(const T& val) : value(val), next(nullptr) {}
    };

    Node* head_;
    Node* tail_;
    size_t size_;

public:
    Queue() : head_(nullptr), tail_(nullptr), size_(0) {}

    ~Queue() {
        clear();
    }

    void push(const T& value) {
        Node* new_node = new Node(value);

        if (tail_) {
            tail_->next = new_node;
        }
        tail_ = new_node;

        if (!head_) {
            head_ = new_node;
        }
        ++size_;
    }

    void pop() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }

        Node* temp = head_;
        head_ = head_->next;
        delete temp;
        --size_;

        if (!head_) {
            tail_ = nullptr;
        }
    }

    T& front() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return head_->value;
    }

    const T& front() const {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return head_->value;
    }

    void clear() {
        while (head_) {
            Node* temp = head_;
            head_ = head_->next;
            delete temp;
        }
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
    }

    bool empty() const noexcept {
        return size_ == 0;
    }
};

int main() {
    Queue<int> queue; 

    queue.push(1);
    queue.push(2);
    queue.push(3);

    while (!queue.empty()) {
        std::cout << queue.front() << " ";
        queue.pop();
    }
}
