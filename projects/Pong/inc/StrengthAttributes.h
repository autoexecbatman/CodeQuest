#pragma once

#include <string>
#include <vector>

struct StrengthAttributes
{
    int hitProb{};
    int dmgAdj{};
    int wgtAllow{};
    int maxPress{};
    int openDoors{};
    double BB_LG{};
    std::string notes{};
};

void print_chart(); // prints the strength chart to the console
std::vector<StrengthAttributes> loadStrengthAttributes(); // loads the strength chart from a json file

// Example usage:
// std::vector<StrengthAttributes> attrs = loadStrengthAttributes();
// StrengthAttributes strength = attrs[str];
// int adjDmg = dmg + strength.dmgAdj; // Adjusted damage
