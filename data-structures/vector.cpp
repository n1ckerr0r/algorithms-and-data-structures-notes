#include <iostream>
#include <stdexcept>
#include <initializer_list>

template<typename T>
class Vector {
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
    Vector() = default;

    Vector(size_t size) {
        resize(size);
    }

    Vector(std::initializer_list<T> init_list) {
        size_ = init_list.size();
        capacity_ = size_;
        data_ = new T[capacity_];
        size_t i = 0;

        for (const auto& item : init_list) {
            data_[i++] = item;
        }
    }

    ~Vector() {
        delete[] data_;
    }

    T& operator[](size_t index) {
        return data_[index];
    }

    const T& operator[](size_t index) const {
        return data_[index];
    }

    T& at(size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    const T& at(size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    bool empty() const {
        return size_ == 0;
    }

    size_t size() const {
        return size_;
    }

    size_t capacity() const {
        return capacity_;
    }

    void resize(size_t new_size) {
        if (new_size > capacity_) {
            reallocate(new_size);
        }
        size_ = new_size;
    }

    void clear() {
        delete[] data_;
        data_ = nullptr;
        size_ = 0;
        capacity_ = 0;
    }

    void push_back(const T& value) {
        if (size_ >= capacity_) {
            reallocate(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        data_[size_++] = value;
    }

    void pop_back() {
        if (size_ == 0) {
            throw std::out_of_range("Vector is empty");
        }
        --size_;
    }

    void print() const {
        for (size_t i = 0; i < size_; i++) {
            std::cout << data_[i] << ' ';
        }
        std::cout << '\n';
    }
};

int main(){
    Vector<int> array;
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);

    array.print();

    array.pop_back();
    array.print();
}