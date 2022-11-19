#pragma once

#include <iostream>
#include <sstream>
#include <locale>
#include <string>
#include <string_view>
#include <concepts>
#include <string.h>


namespace unit {


    struct money {
        using cents = long long;
        std::string_view currency_name;
        const char* locale_name {"en_US.UTF-8"};

        template <std::floating_point T> operator T () requires std::convertable_to<cents, T>;
        template <std::integral T> operator T () requires std::convertable_to<cents, T>;

        operator const char* ();
        operator std::string ();
        operator std::string_view ();

        friend std::ostream& operator<<(std::ostream&, const money&); friend bool operator==(const money&, const money&);
        template <typename T> friend money operator+(const money&, const T&);
        template <typename T> friend money operator+(const T&, const money&);

        template <typename T> money operator-(const T&);
        template <typename T> friend money operator-(const T&, const money&);

        template <typename T> friend money operator*(const money&, const T&);
        template <typename T> friend money operator*(const T&, const money&);
        template <typename T> money operator/(const T&);
        
        private:

        cents whole_subdivision; // ex: cents
    };

    template <std::floating_point T>
        money::operator T () requires std::convertable_to<cents, T> {
        return static_cast<T>(whole_subdivision) / 100;
    }

    template <std::integral T>
        money::operator T () requires std::convertable_to<cents, T> {
        return static_cast<T>(whole_subdivision);
    }

    money::operator std::string () { return (std::stringstream() << *this).str(); }
    money::operator const char* () { return static_cast<std::string>(*this).c_str(); }
    money::operator std::string_view () { return std::string_view(static_cast<const char*>(*this)); }

    bool operator==(const money& money1, const money& money2) {
        return (
                (money1.whole_subdivision == money2.whole_subdivision) &&
                (strcmp(money1.locale_name, money2.locale_name) == 0)
            );
    }

    template <std::integral T>
        money operator+(const money& money_value, const T& cent_count) {
        return money {money_value.whole_subdivision + cent_count};
    }

    template <std::integral T>
        money operator+(const T& cent_count, const money& money_value) {
        return money_value + cent_count;
    }

    template <>
        money operator+ <money> (const money& money1, const money& money2) {
        return money {money1.whole_subdivision + money2.whole_subdivision};
    }

    template <std::integral T>
        money money::operator-(const T& cent_count) {
        return money {whole_subdivision - cent_count};
    }

    template <>
        money money::operator- <money> (const money& money_value) {
        return money {whole_subdivision - money_value.whole_subdivision};
    }
    
    template <std::integral T>
        operator-(const T& cent_count, const money& money_value) {
        return money {cent_count - money_value.whole_subdivision};
    }

    template <std::integral T>
        money operator*(const money& money_value, const T& multiple) {
        return money {money_value.whole_subdivision * multiple};
    }

    template <std::integral T>
        money operator*(const T& multiple, const money& money_value) {
        return money_value * multiple;
    }

    template <std::floating_point T>
        money operator*(const T& floating_point_multiple, const money& money_value) {
        return money {static_cast<money::cents>(floating_point_multiple * money_value.whole_subdivision)};
    }

    template <std::floating_point T>
        money operator*(const money& money_value, const T& floating_point_multiple) {
        return floating_point_multiple * money_value;
    }

    template <std::integral T>
        money money::operator/(const T& divisor) {
            return money {whole_subdivision / divisor};
    }

    template <std::floating_point T>
        money money::operator/(const T& divisor) {
        return money {static_cast<money::cents>(whole_subdivision / divisor)};
    }
}

std::ostream& operator<<(std::ostream& out, const money& money_object) {
    out.imbue(std::locale(locale_name));
    out
        << money_object.whole_subdivision / 100
        << '.'
        << money_object.whole_subdivision % 100
    return out;
}


