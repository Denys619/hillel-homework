#include <iostream>

template <typename T>
class UniquePtr {
private:
    T* ptr;
public:
    //Constructors
    UniquePtr() : ptr(nullptr) {}
    explicit UniquePtr(T* value) : ptr(value) {}

    //Move constructor
    UniquePtr(UniquePtr&& other) noexcept {
        ptr = other.ptr;
        other.ptr = nullptr;
    }
    
    //Move assignment constructor
    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if (this == &other) return *this;
        delete ptr;
        ptr = other.ptr;
        other.ptr = nullptr;
        return *this;
    }

    ~UniquePtr() {
        if (ptr) {
            delete ptr;
        }
    }

    //Access operators
    T& operator*() const {
        return *ptr;
    }
    T* operator->() const {
        return ptr;
    }

    //Conversion to bool operator
    explicit operator bool() const {
        return ptr != nullptr;
    }

    UniquePtr(const UniquePtr& other) = delete;
    UniquePtr& operator=(const UniquePtr& other) = delete;

};

//--------------------------------------------------------------------

struct TestStruct {
    int x = 42;

    void hello() const {
        std::cout << "Hello from TestStruct\n";
    }
};

//--------------------------------------------------------------------

int main() {
    UniquePtr<int> p1(new int(10));
    std::cout << "*p1 = " << *p1 << '\n';

    UniquePtr<TestStruct> p2(new TestStruct());
    std::cout << "p2->x = " << p2->x << '\n';
    p2->hello();

    UniquePtr<int> p3(std::move(p1));
    std::cout << "p1: " <<(p1 ? "has something\n" : "is empty\n");
    std::cout << "p3: " <<(p3 ? "has something\n" : "is empty\n");
    
    UniquePtr<int> p4;
    p4 = std::move(p3);
    std::cout << "p3: " <<(p3 ? "has something\n" : "is empty\n");
    std::cout << "p4: " <<(p4 ? "has something\n" : "is empty\n");

    return 0;
}
