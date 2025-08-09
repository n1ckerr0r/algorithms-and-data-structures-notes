#include <iostream>
#include <initializer_list>
#include <stdexcept>

template <typename T>
class SinglyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head_;
    size_t size_ = 0;

public:
    SinglyLinkedList() : head_(nullptr), size_(0) {}

    SinglyLinkedList(std::initializer_list<T> other) : head_(nullptr), size_(0) {
        for (const auto& value : other) {
            push_back(value);
        }
    }

    ~SinglyLinkedList() noexcept {
        clear();
    }

    void push_back(const T& value) {
        Node* new_node = new Node(value);

        if (head_) {
            Node* temp = head_;
            while (temp->next) temp = temp->next;
            temp->next = new_node;
        } else {
            head_ = new_node;
        }
        ++size_;
    }

    void pop_back() noexcept {
        if (!head_) return;

        if (!head_->next) {
            delete head_;
            head_ = nullptr;
            size_ = 0;
            return;
        }

        Node* prev = head_;
        while (prev->next && prev->next->next) {
            prev = prev->next;
        }

        delete prev->next;
        prev->next = nullptr;
        --size_;
    }

    void push_front(const T& value) {
        Node* new_node = new Node(value);
        new_node->next = head_;
        head_ = new_node;
        ++size_;
    }

    void pop_front() noexcept {
        if (!head_) return;
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
        --size_;
    }

    void print() const {
        Node* temp = head_;
        while (temp) {
            std::cout << temp->data << ' ';
            temp = temp->next;
        }
        std::cout << '\n';
    }

    void insert(const T& value, size_t index) {
        if (index > size_) {
            throw std::out_of_range("Index is out of range");
        }

        Node* new_node = nullptr;
        try {
            new_node = new Node(value);
        } catch (const std::bad_alloc&) {
            throw;
        }

        if (index == 0) {
            new_node->next = head_;
            head_ = new_node;
        } else {
            Node* current = head_;
            size_t count = 0;

            while (count < index - 1) {
                if (!current) {
                    delete new_node;
                    throw std::out_of_range("Index is out of range");
                }
                current = current->next;
                ++count;
            }

            new_node->next = current->next;
            current->next = new_node;
        }
        ++size_;
    }

    void erase(size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index is out of range");
        }

        if (index == 0) {
            Node* temp = head_;
            head_ = head_->next;
            delete temp;
        } else {
            Node* current = head_;
            size_t count = 0;

            while (count < index - 1) {
                current = current->next;
             }
             ++count;
  
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        --size_;
    }

    void clear() noexcept {
        while (head_) {
            pop_front();
        }
    }

    size_t size() const noexcept { return size_; }
    bool empty() const noexcept { return head_ == nullptr; }
};

int main() {
    SinglyLinkedList<int> list;
    list.push_back(1);
    list.push_front(2);
    list.insert(3, 1);

    list.print();

    SinglyLinkedList<int> other_list{1, 2, 3, 4, 5};
    list.pop_back();
    list.pop_front();
    list.erase(0);

    list.print();

    return 0;
}
