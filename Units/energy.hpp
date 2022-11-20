#pragma once

#include "unit.hpp"

namespace unit { namespace energy {
    template <metric_prefix_ratio P>
        struct joule : public unit<joule, QuantitativeType::Continuous> {};
}}
