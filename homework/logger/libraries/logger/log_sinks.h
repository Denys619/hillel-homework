#pragma once

#include <iostream>

struct LogSink {
    virtual void write(const std::string& msg) = 0;
    virtual ~LogSink() = default;
};

//----------------------------------------------------

class ConsoleSink : public LogSink {
public:
    void write(const std::string& msg) override;
};

//----------------------------------------------------

class FileSink : public LogSink {
public:
    void write(const std::string& msg) override;
};

//----------------------------------------------------

class NullSink : public LogSink {
public:
    void write (const std::string& msg) override;
};
