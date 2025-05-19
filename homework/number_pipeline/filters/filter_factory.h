#pragma once
#include "number_filters.h"
#include <functional>
#include <memory>
#include <unordered_map>
#include <string>

class FilterFactory {
public:
    using FilterCreator = std::function<std::unique_ptr<INumberFilter>(const std::string&)>;

    static std::unique_ptr<INumberFilter> create_filter(const std::string& filter_str);
    static void register_filter(const std::string& name, FilterCreator creator);

private:
    static std::unordered_map<std::string, FilterCreator>& get_registry();
};

template <typename FilterType>
struct FilterRegistrar {
    explicit FilterRegistrar(const std::string& name) {
        FilterFactory::register_filter(name, [](const std::string&) {
            return std::make_unique<FilterType>();
        });
    }
};
