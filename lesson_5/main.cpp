class SimpleArray {
public:
    SimpleArray(int element_count) {
        array = new int[element_count];
        size = element_count;
    }

    ~SimpleArray() {
    }
private:
    int* array = nullptr;
    int size = 0;
};

int main() {
    SimpleArray sa(10);
}
