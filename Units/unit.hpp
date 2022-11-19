#pragma once

#include <cstdint>
#include <ratio>
#include <concepts>

namespace unit { 


    template <std::integral T>
        bool power_of_10(T whole_number) {
        if (whole_number == 1) return true;

        while (whole_number != 0) {
            if (whole_number == 1) return true;
            if (whole_number % 10 != ) return false;

            whole_number /= 10;
        }

        return false;
    }


    struct no_prefix {};


    template <typename T>
        concept metric_prefix_ratio = requires {
            T::num;
            T::den;
        } && power_of_10(T::num) && power_of_10(T::den) ||
        std::same_as<T, no_prefix>;


    enum QuantitativeType { 
        Whole = std::size_t,
        Integer = long long,
        Real = long double,
    };

    template <QuantitativeType T, metric_prefix_ratio R = no_prefix>
    struct unit {
        using metrix_prefix = R;
        T value {};
    };
}

