#include <iostream>
#include <stdexcept>

// Stack on the linked lists
template<typename T>
class StackOnList {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head_ = nullptr;

public:
    StackOnList() noexcept = default;

    ~StackOnList() noexcept {
        clear();
    }

    void clear() noexcept {
        while (!empty()) {
            pop();
        }
    }

    bool empty() const noexcept {
        return head_ == nullptr;
    }

    void push(const T& value) {
        Node* new_node = new Node(value);
        new_node->next = head_;
        head_ = new_node;
    }

    void pop() {
        if (empty()) {
            throw std::runtime_error("Stack is empty");
        }
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
    }

    T& top() {
        if (empty()) {
            throw std::runtime_error("Stack is empty");
        }
        return head_->data;
    }

    const T& top() const {
        if (empty()) {
            throw std::runtime_error("Stack is empty");
        }
        return head_->data;
    }
};

// Stack on the arrays
template<typename T>
class StackOnArray {
private:
    T* data_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;

    void reallocate(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size_; i++) {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

public:
    StackOnArray() = default;

    ~StackOnArray() {
        delete[] data_;
    }

    void clear() noexcept {
        delete[] data_;
        data_ = nullptr;
        size_ = 0;
        capacity_ = 0;
    }

    void push(const T& value) {
        if (size_ >= capacity_) {
            reallocate(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        data_[size_++] = value;
    }

    void pop() {
        if (size_ == 0) {
            throw std::out_of_range("Stack is empty");
        }
        --size_;
    }

    T& top() {
        if (size_ == 0) {
            throw std::out_of_range("Stack is empty");
        }
        return data_[size_ - 1];
    }

    const T& top() const {
        if (size_ == 0) {
            throw std::out_of_range("Stack is empty");
        }
        return data_[size_ - 1];
    }

    bool empty() const noexcept {
        return size_ == 0;
    }
};

int main() {
    StackOnList<int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    for (int i = 0; i < 3; i++) {
        std::cout << stack1.top() << " ";
        stack1.pop();
    }
    std::cout << "\n";

    StackOnArray<int> stack2;
    stack2.push(1);
    stack2.push(2);
    stack2.push(3);

    for (int i = 0; i < 3; i++) {
        std::cout << stack2.top() << " ";
        stack2.pop();
    }
    std::cout << "\n";
}
