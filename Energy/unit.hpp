#pragma once

#include <cstdint>

namespace unit { 
    enum QuantitativeType { 
        Whole = std::size_t,
        Integer = int,
        Real = long double
    };

    template <QuantitativeType T>
    struct unit {
        T value {};
    };
}

