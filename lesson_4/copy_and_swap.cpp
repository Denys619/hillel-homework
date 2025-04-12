#include <cstring>
#include <utility>

class MyString {
    private:
        char* data = nullptr;
        size_t size = 0;
    public:

        //Common Constructor
        MyString(const char* str) {
            size = std::strlen(str);
            data = new char[size + 1];
            std::strcpy(data, str);
        }

        //Copy constructor
        MyString(const MyString& other) {
            size = other.size;
            data = new char[size + 1];
            std::strcpy(data, other.data);
        }

        //Copy operator
        MyString& operator=(MyString other) {
            swap(other);
            return *this;
        }

        //Destructor
        ~MyString() {
            delete[] data;
        }

        //Swap function
        void swap(MyString& other) {
            std::swap(size, other.size);
            std::swap(data, other.data);
        }
};

int main() {

}
