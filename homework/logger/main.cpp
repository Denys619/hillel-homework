#include "libraries/logger/logger.h"
#include <algorithm>

int main(int argc, char* argv[]) {
    SinkType type = SinkType::CONSOLE;
    
    if (argc > 1) {
        std::string arg = argv[1];
        std::transform(arg.begin(), arg.end(), arg.begin(), ::tolower);

        if (arg == "file") type = SinkType::FILE;
        else if (arg == "none") type = SinkType::NONE;
        else if (arg != "console") std::cerr << "Unknown sink type. Using console.\n";
    }
    
    Logger::instance().set_sink(type);
    Logger::instance().log("This is the first test log");
    Logger::instance().log("And this is the second test log");
    Logger::instance().log("Third log...");
}
