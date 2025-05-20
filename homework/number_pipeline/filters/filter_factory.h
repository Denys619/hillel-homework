#pragma once
#include "number_filters.h"
#include <memory>
#include <string>
#include <unordered_map>

// Interface for filter factories
class IFilterFactory {
public:
    virtual std::unique_ptr<INumberFilter> create(const std::string& filter_str) const = 0;
    virtual ~IFilterFactory() = default;
};

// Template factory for filters without parameters (e.g., EVEN, ODD)
template <typename FilterT>
class SimpleFilterFactory : public IFilterFactory {
public:
    std::unique_ptr<INumberFilter> create(const std::string&) const override {
        return std::make_unique<FilterT>();
    }
};

// Factory for GreaterFilter
class GreaterFilterFactory : public IFilterFactory {
public:
    std::unique_ptr<INumberFilter> create(const std::string& filter_str) const override;
};

// Main factory to create filters based on registered prefixes
class FilterFactory {
public:
    using Registry = std::unordered_map<std::string, std::unique_ptr<IFilterFactory>>;

    // Register a filter type with its prefix
    static void register_filter(const std::string& prefix, std::unique_ptr<IFilterFactory> factory);

    // Create a filter by parsing the filter string
    static std::unique_ptr<INumberFilter> create_filter(const std::string& filter_str);

private:
    // Access the static registry
    static Registry& get_registry();
};
