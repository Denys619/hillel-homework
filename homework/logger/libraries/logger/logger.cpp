#include "logger.h"
#include "log_sinks.h"
#include <memory>

Logger& Logger::instance() {
    static Logger instance;
    return instance;
}

Logger::Logger() {
    // Initialize with default console sink
    set_sink(SinkType::CONSOLE);
}

void Logger::set_sink(SinkType type) {
    switch (type) {
        case SinkType::CONSOLE:
            sink_ = std::make_unique<ConsoleSink>();
            break;
        case SinkType::FILE:
            sink_ = std::make_unique<FileSink>();
            break;
        case SinkType::NONE:
            sink_ = std::make_unique<NullSink>();
            break;
    }
}

void Logger::log(const std::string& msg) {
    if (sink_) {
        sink_->write(msg);
    }
}
