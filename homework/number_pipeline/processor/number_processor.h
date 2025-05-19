#pragma once

#include "number_reader.h"
#include "number_filters.h"
#include "number_observer.h"

struct NumberProcessor {
    NumberProcessor(INumberReader& reader, 
                    INumberFilter& filter, 
                    const std::vector<INumberObserver*>& observers);
    void run(const std::string& filename);
private:
    INumberReader& reader;
    INumberFilter& filter;
    std::vector<INumberObserver*> observers;

};
