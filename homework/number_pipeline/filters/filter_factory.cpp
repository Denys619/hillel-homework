#include "filter_factory.h"
#include <stdexcept>
#include <string>

std::unique_ptr<INumberFilter> GreaterFilterFactory::create(const std::string& filter_str) const {
    if (filter_str.size() <= 2) {
        throw std::runtime_error("Invalid GT filter: " + filter_str);
    }

    try {
        int threshold = std::stoi(filter_str.substr(2));
        return std::make_unique<GreaterFilter>(threshold);
    } catch (const std::exception& e) {
        throw std::runtime_error("Invalid GT filter: " + filter_str + " (" + e.what() + ")");
    }
}

// FilterFactory methods
void FilterFactory::register_filter(const std::string& prefix, std::unique_ptr<IFilterFactory> factory) {
    get_registry().emplace(prefix, std::move(factory));
}

std::unique_ptr<INumberFilter> FilterFactory::create_filter(const std::string& filter_str) {
    for (const auto& [prefix, factory] : get_registry()) {
        // Check if the filter string starts with the prefix
        if (filter_str.rfind(prefix, 0) == 0) {
            return factory->create(filter_str);
        }
    }
    throw std::runtime_error("Unknown filter: " + filter_str);
}

FilterFactory::Registry& FilterFactory::get_registry() {
    static Registry registry;
    return registry;
}

namespace {
    struct FilterRegistrar {
        FilterRegistrar() {
            FilterFactory::register_filter("EVEN", std::make_unique<SimpleFilterFactory<EvenFilter>>());
            FilterFactory::register_filter("ODD", std::make_unique<SimpleFilterFactory<OddFilter>>());
            FilterFactory::register_filter("GT", std::make_unique<GreaterFilterFactory>());
        }
    } registrar;
}
