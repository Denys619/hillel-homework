#include "number_reader.h"
#include "number_filters.h"
#include "number_observer.h"
#include "number_processor.h"
#include "filter_factory.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <memory>

int main (int argc, char** argv) {
    try {
        if (argc != 3) {
            std::cerr << "Usage " << argv[0] << " <filter> <file name>\n\n"
                      << "<filter> - name of a filter (even, odd, gt<n>)\n"
                      << "<file name> - name of a text file with numbers";
            return 1;
        }

        std::string filter_type = argv[1];
        std::transform(filter_type.begin(), filter_type.end(), filter_type.begin(), ::toupper);
        std::string filename = argv[2];

        FileNumberReader reader;

        std::unique_ptr<INumberFilter> filter = FilterFactory::create_filter(filter_type);

        PrintObserver print_observer;
        CountObserver count_observer;

        std::vector<INumberObserver*> observers = { &print_observer, &count_observer };

        NumberProcessor processor(reader, *filter, observers);
        processor.run(filename);

        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }
}
