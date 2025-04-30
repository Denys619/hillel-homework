#pragma once

#include "log_sinks.h"

#include <string>
#include <memory>

enum class SinkType { CONSOLE, FILE, NONE };

class Logger {
public:
    static Logger& instance();
    void set_sink(SinkType type);
    void log(const std::string& msg);
private:
    std::unique_ptr<LogSink> sink_;
    
    Logger();
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};
