#include "number_reader.h"

#include <iostream>
#include <fstream>
#include <stdexcept>

std::vector<int> FileNumberReader::read_numbers(const std::string& filename) {
    std::ifstream ifs(filename);
    if(!ifs.is_open()) {
        throw std::runtime_error("Couldn't open file: " + filename);
    }

    int number;
    std::vector<int> numbers;
    while (ifs >> number) {
        numbers.emplace_back(number);
    }

    return numbers;
}
