#pragma once

#include <iostream>
#include <cstdint>
#include <string_view>

namespace energy { namespace unit {


    struct money {
        std::string_view currency_name;
        
        private:

        std::size_t whole_subdivision; // ex: cents
    };

    enum QuantitativeType { 
        Whole = std::size_t,
        Integer = int,
        Real = long double
    };


    template <QuantitativeType T>
    struct unit {
        T value {};
    };
}}

