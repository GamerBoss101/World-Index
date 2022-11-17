#pragma once

#include <string_view>
#include <iostream>
#include <iomanip>


struct food_ingredient {
    const std::string_view name;
    float price_per_pound;

    friend std::ostream& operator<<(std::ostream&, const food_ingredient&)
};

std::ostream& operator<<(std::ostream& stdout, const food_ingredient& ingredient) {
    stdout
        << std::quoted(ingredient.name) << ' '
        << std::put_money(ingredient.price_per_pound)
    return stdout;
}

