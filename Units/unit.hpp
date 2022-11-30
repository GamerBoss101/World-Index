#pragma once

#include <cstdint>
#include <ratio>
#include <concepts>


namespace unit {

    /* Enum of quantative unit types */
    enum QuantitativeType { 
        Whole = std::uintmax_t,
        Integer = std::intmax_t,
        Continuous = long double,
    };


    /* Checks if a integer is a integer power of 10 */
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


    /* Indicator for no metric prefix */
    struct no_prefix {};


    /* Metric prefix ratio concept (ex: std::milli, std::tera) */
    template <typename T>
        concept metric_prefix_ratio = requires {
            T::num;
            T::den;
        } &&
        constexpr_power_of_10(T::num) && constexpr_power_of_10(T::den) ||
        std::same_as<T, no_prefix>;


    /* Checks if a type is a specialization of a unit template */
    template <
        template <metric_prefix_ratio>,
        metric_prefix_ratio
    > struct is_unit_specialization_of : std::false_type {};

    /* is_unit_specialization_of true case */
    template <
        template <metric_prefix_ratio> struct unit_template,
        metric_prefix_ratio M
    > struct is_unit_specialization_of <unit_template, unit_template<M>> : std::true_type {};
    
    /* Concept implementation of is_unit_specialization_of */
    template <
        typename T,
        template <metric_prefix_ratio> struct unit_template
    > concept unit_specialization_of =
    is_unit_specialization_of<unit_template, T>::value;


    // Checks if a type 'T' is a unit
    template <typename T>
        struct is_unit {
            static const bool value {
                requires { requires T::is_unit }
            };
        };

    // Concept implementation of 'is_unit'
    template <typename T>
        concept unit = is_unit<T>;

    
    // For Integer or Whole number units. Helps with addition accuracy for different unit prefixes
    struct no_include_base_10_compensator {};
    struct include_base_10_compensator {
        protected: int base_10_compensator {};
    };

    /* Inheritable template struct for units */
    template <
        template <metric_prefix_ratio> struct derived_template,
        QuantitativeType Qt,
        int exp_power = 1,
        metric_prefix_ratio R = no_prefix
    >
    struct basic_unit :
        std::conditional<
            Qt == QuantitativeType::Continuous,
            no_include_base_10_compensator,
            include_base_10_compensator
        > {
        private:

        using metric_prefix = R;
        using derived_specialization = derived_template<metric_prefix>;
        using quantative_type = Qt;

        protected:

        Qt value {};

        public:

        static const int power {exp_power};
        static const bool is_unit {true};

        template <typename T>
            struct is_same_unit : std::false_type {};

        template <metric_prefix_ratio matched_prefix>
            struct is_same_unit<derived_template<matched_prefix>> : std::true_type {};

        template <typename T> derived_specialization operator+(const T&);
        template <unit T> derived_specialization operator+(const T&) requires T::power == power;
        template <unit_specialization_of<derived_template> T> derived_specialization operator+(const T&);
        template <> derived_specialization operator+ <derived_specialization> (const derived_specialization&);
        template <unit T> derived_specialization operator-(const T&);
        template <unit T> derived_specialization operator*(const T&);
        template <unit T> derived_specialization operator/(const T&);

        template <unit T> derived_specialization operator+=(const T&);
        template <unit T> derived_specialization operator-=(const T&);
        template <unit T> derived_specialization operator*=(const T&);
        template <unit T> derived_specialization operator/=(const T&);

        template <metric_prefix_ratio P> operator derived_template<P> ();
    };
}

