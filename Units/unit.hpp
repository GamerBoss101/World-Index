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
        } &&
        constexpr_power_of_10(T::num) && constexpr_power_of_10(T::den) ||
        std::same_as<T, no_prefix>;

    enum QuantitativeType { 
        Whole = std::uintmax_t,
        Integer = std::intmax_t,
        Continuous = long double,
    };

    template <
        template <metric_prefix_ratio>,
        metric_prefix_ratio
    > struct is_unit_specialization_of : std::false_type {};

    template <
        template <metric_prefix_ratio> struct unit_template,
        metric_prefix_ratio M
    > struct is_unit_specialization_of <unit_template, unit_template<M>> : std::true_type {};
    
    template <
        typename T,
        template <metric_prefix_ratio> struct unit_template
    > concept unit_instantiation_of =
    is_unit_specialization_of<unit_template, T>;

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

        public:

        template <typename T>
            struct is_same_unit : std::false_type {};

        template <metric_prefix_ratio matched_prefix>
            struct is_same_unit<derived_template<matched_prefix>> : std::true_type {};

        template <number_or_same_unit T> derived_specialization operator+(const T&);
        template <number_or_same_unit T> derived_specialization operator-(const T&);
        template <number_or_same_unit T> derived_specialization operator*(const T&);
        template <number_or_same_unit T> derived_specialization operator/(const T&);

        template <metric_prefix_ratio P> operator derived_template<P> ();
    };
}



