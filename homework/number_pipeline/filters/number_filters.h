#pragma once

struct INumberFilter {
    virtual bool keep(int number) const = 0;
    virtual ~INumberFilter() = default;
};

struct EvenFilter: INumberFilter {
    bool keep(int number) const override;
};

struct OddFilter: INumberFilter {
    bool keep(int number) const override;
};

struct GreaterFilter: INumberFilter {
    explicit GreaterFilter(int n): threshold(n) {};
    bool keep(int number) const override;

private:
    int threshold;
};
