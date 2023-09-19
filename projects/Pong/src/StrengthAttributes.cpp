#include <iostream>
#include <fstream>
#include <sstream> // included for std::ostringstream to work for some compilers
#include <vector>
#include <string>
#include <nlohmann/json.hpp>

#include "Game.h"
#include "StrengthAttributes.h"

using json = nlohmann::json;

void from_json(const json& j, StrengthAttributes& p)
{
	j.at("Hit").get_to(p.hitProb);
	j.at("Dmg").get_to(p.dmgAdj);
	j.at("Wgt").get_to(p.wgtAllow);
	j.at("MaxPress").get_to(p.maxPress);
	j.at("OpenDoors").get_to(p.openDoors);
	j.at("BB_LG").get_to(p.BB_LG);
	j.at("Notes").get_to(p.notes);
}

std::vector<StrengthAttributes> loadStrengthAttributes()
{
	std::ifstream i("strength.json");

	if (!i.is_open()) // Check if file is open
	{
		game.log("Error: Unable to open strength.json. Error " + std::to_string(errno));
		throw std::runtime_error("Error: Unable to open strength.json. Error " + std::to_string(errno));
	}

	json j; // Create json object
	try
	{
		i >> j; // Read from file
	}
	catch (const json::parse_error& e)
	{
		std::ostringstream oss;
		oss << "Error: Unable to parse strength.json. Exception details: " << e.what();
		throw std::runtime_error(oss.str());
	}

	try
	{
		// Convert json to vector<StrengthAttributes>
		std::vector<StrengthAttributes> strengthChart = j.get<std::vector<StrengthAttributes>>();
		return strengthChart;
	}
	catch (const json::type_error& e)
	{
		std::ostringstream oss;
		oss << "Error: Unable to convert JSON to vector<StrengthAttributes>. Exception details: " << e.what();
		throw std::runtime_error(oss.str());
	}
}

void print_chart()
{
	auto strengthChart = loadStrengthAttributes();
	for (const auto& strength : strengthChart)
	{
		std::cout << "----" << std::endl;
		std::cout << "strength.hitProb: " << strength.hitProb << std::endl;
		std::cout << "strength.dmgAdj: " << strength.dmgAdj << std::endl;
		std::cout << "strength.wgtAllow: " << strength.wgtAllow << std::endl;
		std::cout << "strength.maxPress: " << strength.maxPress << std::endl;
		std::cout << "strength.openDoors: " << strength.openDoors << std::endl;
		std::cout << "strength.BB_LG: " << strength.BB_LG << std::endl;
		std::cout << "strength.notes: " << strength.notes << std::endl;
		std::cout << "----" << std::endl;
	}
}
