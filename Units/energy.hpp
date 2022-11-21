#pragma once

#include "unit.hpp"

namespace unit { namespace energy {
    template <metric_prefix_ratio P>
        struct basic_joule : public unit<basic_joule<P>, QuantitativeType::Continuous, P> {};
}}
