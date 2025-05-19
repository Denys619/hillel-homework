#pragma once

#include <vector>
#include <string>

struct INumberReader {
    virtual std::vector<int> read_numbers(const std::string& filename) = 0;
    virtual ~INumberReader() = default;
};

struct FileNumberReader: INumberReader {
    std::vector<int> read_numbers(const std::string& filename) override;
};
