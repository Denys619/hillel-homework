#include <cstring>

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
        MyString& operator=(const MyString& other) {
            if (this == &other) {
                return *this;
            }

            delete[] data;

            size = other.size;
            data = new char[size + 1];
            std::strcpy(data, other.data);

            return *this;
        }

        //Destructor
        ~MyString() {
            delete[] data;
        }
};

int main() {

}
