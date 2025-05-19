#include "number_observer.h"

#include <iostream>

void PrintObserver::on_number(int number) {
    std::cout << number << '\t';
}

void PrintObserver::on_finished() {
    std::cout << std::endl << "========>> Printing finished" << std::endl;
}

void CountObserver::on_number(int number) {
    ++count;
}

void CountObserver::on_finished() {
    std::cout << "========>> Counted " << count << " numbers passed the filter." << std::endl;
}
