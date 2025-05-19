#include "number_processor.h"

NumberProcessor::NumberProcessor(INumberReader& reader, 
                                 INumberFilter& filter, 
                                 const std::vector<INumberObserver*>& observers)
                               : reader(reader),
                                 filter(filter),
                                 observers(observers) {}

void NumberProcessor::run(const std::string& filename) {
    std::vector<int> numbers = reader.read_numbers(filename);

    for (int& number : numbers) {
        if (filter.keep(number)) {
            for (auto observer : observers) {
                observer->on_number(number);
            }
        }
    }

    for (auto& observer : observers) {
        observer->on_finished();
    }
}
