#include <iostream>
#include <filesystem>
#include <vector>
#include "lib/input_schema.h"
#include "lib/config.h"
#include "lib/util.h"
using namespace std;

vector<string> parameter = {
    "config",
    "storage",
    "source",
    "output",
    "verify_config"};

vector<string> config_parameter = {
    "database",
    "db_host",
    "port",
    "database_name",
    "username",
    "password"};

vector<string> mergeArray(
    vector<string> inputArray1,
    vector<string> inputArray2)
{
  vector<string> finalArray;

  for (int i = 0; i < inputArray1.size(); i++)
  {
    finalArray.push_back(inputArray1[i]);
  }

  for (int i = 0; i < inputArray2.size(); i++)
  {
    finalArray.push_back(inputArray2[i]);
  }

  return finalArray;
}

int main(int argc, char *args[])
{
  // std::cout << RED << "This is red text." << RESET << std::endl;
  // std::cout << BOLD << GREEN << "This is bold green text." << RESET << std::endl;
  // std::cout << UNDERLINE << YELLOW << "Underlined yellow text." << RESET << std::endl;
  // std::cout << BLUE << WHITE << "White text on blue background." << RESET << std::endl;
  // std::cout << "Back to default." << std::endl;

  // std::cout << ON_RED << "Red background text." << RESET << std::endl;
  // std::cout << ON_GREEN << "Green background text." << RESET << std::endl;
  // std::cout << BOLD << GREEN << "This is bold green text." << RESET << std::endl;
  // std::cout << UNDERLINE << YELLOW << "Underlined yellow text." << RESET << std::endl;
  // std::cout << "Back to default." << std::endl;

  vector<string> finalArray = mergeArray(parameter, config_parameter);

  int inputCount = 1;
  while (inputCount < argc - 1)
  {
    bool isFailed = false;

    for (int finalArrayCount = 0; finalArrayCount < finalArray.size(); finalArrayCount++)
    {
      if (finalArray[finalArrayCount] != args[inputCount])
      {
        std::cout << RED << "Invalid param : " << args[inputCount] << RESET << endl;
        isFailed = true;
        break;
      }
    }

    if (isFailed)
    {
      break;
    }
    inputCount++;
  }

  string firstInput = args[1];

  if (firstInput == "config")
  {
    std::cout << "\n"
              << BOLD << CYAN << "╔══════════════════════════════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD << CYAN << "║                    POPULAR SQL DATABASES                    ║" << RESET << std::endl;
    std::cout << BOLD << CYAN << "╠══════════════════════════════════════════════════════════════╣" << RESET << std::endl;
    std::cout << BOLD << CYAN << "║" << RESET << "  " << GREEN << "1." << RESET << " " << BOLD << "MySQL" << RESET << " - Open source, widely used for web applications" << "  " << BOLD << CYAN << "║" << RESET << std::endl;
    std::cout << BOLD << CYAN << "║" << RESET << "  " << GREEN << "2." << RESET << " " << BOLD << "PostgreSQL" << RESET << " - Advanced open source database" << "        " << BOLD << CYAN << "║" << RESET << std::endl;
    std::cout << BOLD << CYAN << "║" << RESET << "  " << GREEN << "3." << RESET << " " << BOLD << "Oracle" << RESET << " - Enterprise-grade database management" << "      " << BOLD << CYAN << "║" << RESET << std::endl;
    std::cout << BOLD << CYAN << "║" << RESET << "  " << GREEN << "4." << RESET << " " << BOLD << "Microsoft SQL Server" << RESET << " - Microsoft's database solution" << "  " << BOLD << CYAN << "║" << RESET << std::endl;
    std::cout << BOLD << CYAN << "║" << RESET << "  " << GREEN << "5." << RESET << " " << BOLD << "SQLite" << RESET << " - Lightweight, serverless database" << "          " << BOLD << CYAN << "║" << RESET << std::endl;
    std::cout << BOLD << CYAN << "║" << RESET << "  " << GREEN << "6." << RESET << " " << BOLD << "MariaDB" << RESET << " - MySQL fork with enhanced features" << "        " << BOLD << CYAN << "║" << RESET << std::endl;
    std::cout << BOLD << CYAN << "║" << RESET << "  " << GREEN << "7." << RESET << " " << BOLD << "MongoDB" << RESET << " - NoSQL document database" << "                " << BOLD << CYAN << "║" << RESET << std::endl;
    std::cout << BOLD << CYAN << "║" << RESET << "  " << GREEN << "8." << RESET << " " << BOLD << "Redis" << RESET << " - In-memory data structure store" << "            " << BOLD << CYAN << "║" << RESET << std::endl;
    std::cout << BOLD << CYAN << "╚══════════════════════════════════════════════════════════════╝" << RESET << std::endl;
    std::cout << "\n"
              << YELLOW << "💡 Tip: Choose the database that best fits your project requirements!" << RESET << std::endl;

    success("Enter the number of the database you want to use or enter 0 for none: ");
    string databaseInput;
    cin >> databaseInput;

    int databaseInputInt = stoi(databaseInput);
    string dbName = database_list[databaseInputInt].second;
    if (dbName == "none")
    {
      warning("You did not enter any database");
      return 1;
    }
    else if (dbName.length() == 0)
    {
      error("Invalid database");
      return 1;
    }

    string dbHost;
    success("Enter the host of the database: ");
    cin >> dbHost;

    string port;
    success("Enter the port of the database: ");
    cin >> port;

    string dbDatabaseName;
    success("Enter the name of the database: ");
    cin >> dbDatabaseName;

    string username;
    success("Enter the username of the database: ");
    cin >> username;

    string password;
    success("Enter the password of the database: ");
    cin >> password;

    Config config;
    config.database = dbName;
    config.db_host = dbHost;
    config.port = port;
    config.database_name = dbDatabaseName;
    config.username = username;
    config.password = password;

    bool isConfigSet = setConfig(config);
    if (isConfigSet)
    {
      success("Config set successfully");
    }
    else
    {
      error("Config set failed");
    }

    return 0;
  }
  else if (firstInput == "verify_config")
  {
    bool isConfigValid = verifyConfig();
    if (isConfigValid)
    {
      success("Config is valid");
    }
    else
    {
      error("Config is invalid");
      return 1;
    }
  }
  else if (firstInput == "source")
  {
    // Handle source case
  }
  else if (firstInput == "output")
  {
    // Handle output case
  }

  return 0;
}
