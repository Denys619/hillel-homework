#include "log_sinks.h"
#include <fstream>

void ConsoleSink::write(const std::string& msg) {
    std::cout << msg << std::endl;
}

//----------------------------------------------------

void FileSink::write(const std::string& msg) {
    std::ofstream file("app.log", std::ios::app);
    if (file) {
        file << msg << '\n';
    } else {
        std::cerr << "Failed to open log file\n";
    }
}

//----------------------------------------------------

void NullSink::write(const std::string& msg) {
    (void)msg; // Explicitly ignore parameter for avoidinf Warning
}
