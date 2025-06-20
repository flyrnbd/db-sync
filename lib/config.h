#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <vector>

struct Config
{
    std::string database;
    std::string db_host;
    std::string port;
    std::string database_name;
    std::string username;
    std::string password;
};

bool setConfig(Config &config);
bool getConfig(Config &config);
bool isConfigValid(Config &config);

extern std::vector<std::pair<int, std::string>> database_list;

#endif // CONFIG_H