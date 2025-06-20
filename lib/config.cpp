#include <fstream>
#include <iostream>
#include "input_schema.h"
#include "config.h"
#include "json.hpp"

using namespace std;

std::vector<std::pair<int, std::string>> database_list = {
    {0, "none"},
    {1, "mysql"},
    {2, "postgresql"},
    {3, "oracle"},
    {4, "mssql"},
    {5, "sqlite"},
    {6, "mariadb"},
    {7, "mongodb"},
    {8, "redis"},
};

bool setConfig(Config &config)
{
    std::cout << "\n"
              << BOLD << CYAN << "╔══════════════════════════════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << CYAN << "║                    DATABASE CONFIGURATION                        ║" << RESET << std::endl;
    std::cout << BOLD << CYAN << "╠══════════════════════════════════════════════════════════════╣" << RESET << std::endl;
    std::cout << BOLD << CYAN << "║" << RESET << "  " << GREEN << "Database:" << RESET << " " << BOLD << config.database << RESET << "                                    " << BOLD << CYAN << "║" << RESET << std::endl;
    std::cout << BOLD << CYAN << "║" << RESET << "  " << GREEN << "Host:" << RESET << " " << BOLD << config.db_host << RESET << "                                        " << BOLD << CYAN << "║" << RESET << std::endl;
    std::cout << BOLD << CYAN << "║" << RESET << "  " << GREEN << "Port:" << RESET << " " << BOLD << config.port << RESET << "                                          " << BOLD << CYAN << "║" << RESET << std::endl;
    std::cout << BOLD << CYAN << "║" << RESET << "  " << GREEN << "Database Name:" << RESET << " " << BOLD << config.database_name << RESET << "                        " << BOLD << CYAN << "║" << RESET << std::endl;
    std::cout << BOLD << CYAN << "║" << RESET << "  " << GREEN << "Username:" << RESET << " " << BOLD << config.username << RESET << "                                " << BOLD << CYAN << "║" << RESET << std::endl;
    std::cout << BOLD << CYAN << "║" << RESET << "  " << GREEN << "Password:" << RESET << " " << BOLD << "********" << RESET << "                                    " << BOLD << CYAN << "║" << RESET << std::endl;
    std::cout << BOLD << CYAN << "╚══════════════════════════════════════════════════════════════╝" << RESET << std::endl;
    std::cout << "\n"
              << YELLOW << "💡 Configuration details displayed above!" << RESET << std::endl;

    try
    {
        // Store config in json file
        nlohmann::json jsonConfig;
        jsonConfig["database"] = config.database;
        jsonConfig["db_host"] = config.db_host;
        jsonConfig["port"] = config.port;
        jsonConfig["database_name"] = config.database_name;
        jsonConfig["username"] = config.username;
        jsonConfig["password"] = config.password;

        std::ofstream file("./config.json");
        file << jsonConfig.dump(4);
        file.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }

    return true;
}

bool getConfig(Config &config)
{
    return true;
}

bool isConfigValid(Config &config)
{
    return true;
}