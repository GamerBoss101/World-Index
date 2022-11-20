#pragma once

#include <cstdint>
#include <ratio>
#include <concepts>

namespace unit { 


    template <std::integral T>
        constexpr bool constexpr_power_of_10(T whole_number) {
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
        } && constexpr_power_of_10(T::num) && constexpr_power_of_10(T::den) ||
        std::same_as<T, no_prefix>;


    enum QuantitativeType { 
        Whole = std::uintmax_t,
        Integer = std::intmax_t,
        Continuous = long double,
    };

    template <typename derived, QuantitativeType T, metric_prefix_ratio R = no_prefix>
        struct unit {
        using metrix_prefix = R;

        T value {};
        int base_10_compensator {};

        template <typename T> derived operator+(const T&);
        template <typename T> derived operator-(const T&);
        template <typename T> derived operator*(const T&);
        template <typename T> derived operator/(const T&);
    };
}

