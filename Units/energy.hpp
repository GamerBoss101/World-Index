#pragma once

#include <ratio>

#include "unit.hpp"

namespace unit { namespace energy {
    template <metric_prefix_ratio Prefix = no_prefix>
        struct basic_joule : public basic_unit<basic_joule<Prefix>, QuantitativeType::Continuous, Prefix> {};

    using joule = basic_joule<no_prefix>;
    
    using djoule = std::basic_joule<std::deca>;
}}
