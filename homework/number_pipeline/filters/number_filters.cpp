#include "number_filters.h"

bool EvenFilter::keep(int number) const {
    return number % 2 == 0;
}

bool OddFilter::keep(int number) const {
    return number % 2 != 0;
}

bool GreaterFilter::keep(int number) const {
    return number > threshold;
}
