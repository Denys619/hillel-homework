#include <iostream>
#include <vector>
#include <functional>

void for_each(std::vector<int>& num, std::function<void(int)> f);
bool all(std::vector<int>& num, std::function<bool(int)> p);
int count_if(std::vector<int>& num, std::function<bool(int)> f);

bool is_odd(int elem) {
    return elem % 2 != 0;
}

int main() {
    std::vector<int> num{2,4,8,4,5,2,1,5,3};

    std::cout << "Vector elements: ";
    for_each(num, [](int elem) {std::cout << elem << '\t'; });
    std::cout << '\n';

    //Checking diferent conditions
    std::cout << "\nAre all elements even? -> " 
              << (all(num, [](int elem) {return elem % 2 == 0; }) ? "yes" : "no");
    
    std::cout << "\nAre all elements less than 10? -> " 
              << (all(num, [](int elem) {return elem < 10; }) ? "yes" : "no");

    std::cout << "\nCount of even numbers: " 
              << count_if(num, [](int elem) {return elem % 2 == 0; });

    std::cout << "\nCount of numbers > 3: " 
              << count_if(num, [](int elem) {return elem > 3; });

    std::cout << "\nCount of odd numbers: "
              << count_if(num, is_odd) << '\n';

    return 0;
}

//------------------------------------------------------------------------------

void for_each(std::vector<int>& num, std::function<void(int)> f) {
    for(const auto& elem : num) {
        f(elem);
    }
}

//------------------------------------------------------------------------------

bool all(std::vector<int>& num, std::function<bool(int)> p) {
    for(const auto& elem : num) {
       if (p(elem) == false) return false;
    }

    return true;
}

//------------------------------------------------------------------------------

int count_if(std::vector<int>& num, std::function<bool(int)> f) {
    int counter = 0;

    for(const auto& elem : num) {
        if (f(elem) == true) ++counter;
    }

    return counter;
}
