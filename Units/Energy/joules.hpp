#pragma once

#include <ratio>

#include "unit.hpp"

namespace unit { namespace energy {
    template <metric_prefix_ratio Prefix = no_prefix>
        struct basic_joule : public basic_unit<basic_joule<Prefix>, QuantitativeType::Continuous, Prefix> {};

    using joule = basic_joule<>;

    using yocto_joule = basic_joule<std::yocto>;
    using zepto_joule = basic_joule<std::zepto>;
    using atto_joule = basic_joule<std::atto>;
    using femto_joule = basic_joule<std::femto>;
    using pico_joule = basic_joule<std::pico>;
    using nano_joule = basic_joule<std::nano>;
    using micro_joule = basic_joule<std::micro>;
    using milli_joule = basic_joule<std::milli>;
    using centi_joule = basic_joule<std::centi>;
    using deci_joule = basic_joule<std::deci>;
    using deca_joule = basic_joule<std::deca>;
    using hecto_joule = basic_joule<std::hecto>;
    using kilo_joule = basic_joule<std::kilo>;
    using mega_joule = basic_joule<std::mega>;
    using giga_joule = basic_joule<std::giga>;
    using tera_joule = basic_joule<std::tera>;
    using peta_joule = basic_joule<std::peta>;
    using exa_joule = basic_joule<std::exa>;
    using zetta_joule = basic_joule<std::zetta>;
    using yotta_joule = basic_joule<std::yotta>;
}}
