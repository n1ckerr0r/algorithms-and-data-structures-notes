#include <iostream>
#include <initializer_list>
#include <stdexcept>

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head_ = nullptr;
    Node* tail_ = nullptr;
    size_t size_ = 0;

public:
    DoublyLinkedList() noexcept: head_(nullptr), tail_(nullptr) {}

    DoublyLinkedList(std::initializer_list<T> inil_list) : head_(nullptr), tail_(nullptr), size_(0) {
        for (const auto& value : inil_list) push_back(value);
    }

    ~DoublyLinkedList() noexcept {
        clear();
    }

    void push_back(const T& value) {
        Node* node = new Node(value);

        if (!tail_) { 
            head_ = tail_ = node;
        } else {
            tail_->next = node;
            node->prev = tail_;
            tail_ = node;
        }
        ++size_;
    }

    void push_front(const T& value) {
        Node* node = new Node(value);

        if (!head_) {
            head_ = tail_ = node;
        } else {
            node->next = head_;
            head_->prev = node;
            head_ = node;
        }
        ++size_;
    }

    void pop_back() noexcept {
        if (!tail_) return;

        if (head_ == tail_) {
            delete tail_;
            head_ = tail_ = nullptr;
            size_ = 0;
            return;
        }

        Node* tmp = tail_;
        tail_ = tail_->prev;
        tail_->next = nullptr;
        delete tmp;

        --size_;
    }

    void pop_front() noexcept {
        if (!head_) return;

        if (head_ == tail_) {
            delete head_;
            head_ = tail_ = nullptr;
            size_ = 0;
            return;
        }

        Node* tmp = head_;
        head_ = head_->next;
        head_->prev = nullptr;
        delete tmp;
        --size_;
    }

    void insert(const T& value, size_t index) {
        if (index > size_) throw std::out_of_range("Index is out of range");

        if (index == 0) {
            push_front(value);
            return;
        }
        if (index == size_) {
            push_back(value);
            return;
        }

        Node* current = nullptr;
        if (index <= size_ / 2) {
            current = head_;
            for (size_t i = 0; i < index; ++i) current = current->next;
        } else { 
            current = tail_;
            for (size_t i = size_ - 1; i > index; --i) current = current->prev;
        }

        Node* node = new Node(value);
        Node* prev = current->prev;

        node->next = current;
        node->prev = prev;
        current->prev = node;
        if (prev) prev->next = node;
        else head_ = node;

        ++size_;
    }

    void erase(size_t index) {
        if (index >= size_) throw std::out_of_range("Index is out of range");

        if (index == 0) {
            pop_front();
            return;
        }
        if (index + 1 == size_) {
            pop_back();
            return;
        }

        Node* current = nullptr;

        if (index <= size_ / 2) {
            current = head_;
            for (size_t i = 0; i < index; ++i) current = current->next;
        } else {
            current = tail_;
            for (size_t i = size_ - 1; i > index; --i) current = current->prev;
        }

        Node* p = current->prev;
        Node* n = current->next;
        if (p) p->next = n;
        if (n) n->prev = p;
        delete current;

        --size_;
    }

    void clear() noexcept {
        Node* current = head_;

        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head_ = tail_ = nullptr;
        size_ = 0;
    }

    void print() const {
        Node* current = head_;
        while (current) {
            std::cout << current->data << ' ';
            current = current->next;
        }
        std::cout << '\n';
    }

    size_t size() const noexcept { return size_; }
    bool empty() const noexcept { return size_ == 0; }
};

int main(){
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_front(2);
    list.insert(3, 1);

    std::cout << "list:\n";
    list.print();

    DoublyLinkedList<int> other_list{1, 2, 3, 4, 5};
    list.pop_back();
    list.pop_front();
    list.erase(0);

    std::cout << "list:\n";
    list.print();

    std::cout << other_list.size() << '\n';
    std::cout << other_list.empty() << '\n';

    return 0;
}