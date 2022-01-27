#include <iostream>
#include <iterator>
#include <cassert>
#include <vector>

namespace std {
    template <class T>
    class container {
       public:
        class iterator {
           public:
            using iterator_category = std::forward_iterator_tag;
            using difference_type = std::ptrdiff_t;
            using value_type = T;
            using pointer = T*;
            using referece = T&;

            iterator(pointer ptr = nullptr) : m_ptr(ptr) {}

            referece operator*() { return *m_ptr; }
            pointer operator->() { return m_ptr; }

            constexpr iterator operator++() { m_ptr++; return *this; }
            constexpr iterator operator++(int) { auto tmp = *this; m_ptr++; return tmp; }
            constexpr iterator operator--() { m_ptr--; return *this; }
            constexpr iterator operator--(int) { auto tmp = *this; m_ptr--; return tmp; }
            constexpr bool operator==(const iterator& other) { return m_ptr == other.m_ptr; }
            constexpr bool operator!=(const iterator& other) { return m_ptr != other.m_ptr; }

           private:
            pointer m_ptr;
        };

        constexpr size_t size() const { return _size; }
        constexpr T& operator[](const size_t& index) const { return _data[index]; }
        constexpr T& operator[](const size_t& index) { return _data[index]; }

        constexpr iterator begin() { return iterator(_data); }        // cast in class type
        constexpr iterator end() { return iterator(_data + _size); }  // cast in class type


        // deleted
        container(container<T>&&) = delete;
        container(const container<T>&) = delete;
        container<T>& operator=(container<T>&&) = delete;
        container<T>& operator=(const container<T>&) = delete;

        // construction
        constexpr container() : _size(0) {}
        constexpr container(const size_t& len) : _size(len) { _data = new T[_size]; }

        // more members...


       private:
        T* _data;
        size_t _size;
    };
}  // namespace std

int main() {
    std::container<double> cc;
    std::container<double>::iterator it;

    if(cc.begin() == cc.end()) {
        std::cout << "same\n";
    }

    it = cc.end();

    return 0;
}