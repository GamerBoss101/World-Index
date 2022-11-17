#pragma once

#include <iostream>
#include <cstdint>
#include <string_view>
#include <string>
#include <sstream>
#include <locale>


struct money {
    std::string_view currency_name;
    auto locale_name {"en_US.UTF-8"};

    operator float ();
    operator double ();
    operator const char* ();
    operator std::string ();
    operator std::string_view ();

    friend std::ostream& operator<<(std::ostream&, const money&);
    
    private:

    std::size_t whole_subdivision; // ex: cents
};

std::ostream& operator<<(std::ostream& out, const money& money_object) {
    out.imbue(std::locale(locale_name));
    out
        << money_object.whole_subdivision / 100
        << '.'
        << money_object.whole_subdivision % 100
    return out;
}


money::operator float () { return static_cast<float>(whole_subdivision) / 100; }
money::operator double () { return static_cast<double>(whole_subdivision) / 100; }
money::operator std::string () { return (std::stringstream() << *this).str(); }
money::operator const char* () { return static_cast<std::string>(*this).c_str(); }
money::operator std::string_view () { return std::string_view(static_cast<const char*>(*this)); }


namespace energy { namespace unit {


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

