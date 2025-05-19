#include "filter_factory.h"
#include <stdexcept>

std::unordered_map<std::string, FilterFactory::FilterCreator>& FilterFactory::get_registry() {
    static std::unordered_map<std::string, FilterCreator> registry;
    return registry;
}

void FilterFactory::register_filter(const std::string& name, FilterCreator creator) {
    get_registry()[name] = creator;
}

std::unique_ptr<INumberFilter> FilterFactory::create_filter(const std::string& filter_str) {
    if (filter_str.rfind("GT", 0) == 0) {
        try {
            int threshold = std::stoi(filter_str.substr(2));
            return std::make_unique<GreaterFilter>(threshold);
        } catch (...) {
            throw std::runtime_error("Invalid GT filter: " + filter_str);
        }
    }

    auto it = get_registry().find(filter_str);
    if (it != get_registry().end()) {
        return it->second(filter_str);
    }

    throw std::runtime_error("Unknown filter: " + filter_str);
}

namespace {
    FilterRegistrar<EvenFilter> even_registrar("EVEN");
    FilterRegistrar<OddFilter> odd_registrar("ODD");
}
