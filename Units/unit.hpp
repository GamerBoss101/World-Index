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

    struct unit;

    template <
        template <metric_prefix_ratio> struct derived_template,
        QuantitativeType Qt,
        metric_prefix_ratio R = no_prefix
    >   
    struct basic_unit {
        private:

        using metric_prefix = R;
        using derived_specialization = derived_template<metric_prefix>;

        protected:

        Qt value {};
        int base_10_compensator {};

        template <typename T>
            concept number_or_same_unit =
            same_unit<T> ||
            std::integral<T> ||
            std::floating_point<T>;

        public:

        template <typename T>
            static constexpr struct is_same_unit : std::false_type {};

        template <metric_prefix_ratio matched_prefix>
            static constexpr struct is_same_unit<derived_template<matched_prefix>> : std::true_type {};

        template <typename U>
            concept same_unit =
            is_same_unit<T>::value;

        template <number_or_same_unit T> derived_specialization operator+(const T&);
        template <number_or_same_unit T> derived_specialization operator-(const T&);
        template <number_or_same_unit T> derived_specialization operator*(const T&);
        template <number_or_same_unit T> derived_specialization operator/(const T&);

        template <metric_prefix_ratio P> operator derived_template<P> ();
    };
}



