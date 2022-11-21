#pragma once

#include "unit.hpp"

namespace unit { namespace energy {
    template <metric_prefix_ratio Prefix>
        struct basic_joule : public basic_unit<basic_joule<Prefix>, QuantitativeType::Continuous, Prefix> {};
}}
