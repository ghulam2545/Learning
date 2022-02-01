/*
 * "this" is a local object pointer of every instance member func
 * containing address of caller object.
 *
 */

#include <iostream>
using std::cout;

// It's has no need of template, but no problem

template <typename T>
class Room {
   private:
    T width;
    T height;

   public:
    /*
    (initializer list will work as usual)
    Room(const T& width, const T& height) : width(width), height(height) {}
     */

    Room() = default;
    Room(const Room<T>&) = default;            // copy
    constexpr Room(const Room<T>&&) = delete;  // move
    constexpr Room(const T& width, const T& height) {
        /*
        auto ptr = this;  // Room* ptr = this;
        ptr->width = width;
        ptr->height = height;
        */

        this->width = width;
        this->height = height;
    }

    void setDimension(const T& width, const T& height) {
        this->width = width;
        this->height = height;
    }

    void show() { cout << "width : " << this->width << ", height : " << this->height << "\n"; }

    Room<T>& operator++() {
        ++(this->width);
        ++(this->height);
        // returning refernce of next object
        return *this;
    }

    // friend is not a instance member func so no "this pointer"
    // friend Room<T>& operator++(Room<T>& r) {
    //     ++r.width;
    //     ++r.height;
    //     return r;
    // }
};

int main() {
    // caller obj is r1
    Room<int> r1(10, 20);
    r1.show();

    /*
     * Here memory will be reserved for room instance but we have no name of that instance
     * we only refer that room by his pointer(aka room2)
     */

    // so caller object is the one that room2 is pointing
    Room<int>* room2 = new Room<int>();
    room2->setDimension(50, 60);
    room2->show();

    // for this one caller obj is same as above
    ++(*room2);
    room2->show();

    // caller object is that, room2 pointing
    // auto ans = operator++(*room2);
    // ans.show();
    return 0;
}