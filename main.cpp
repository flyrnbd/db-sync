#include<iostream>
#include<filesystem>
#include<vector>
// ANSI escape codes for colors and styles
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define UNDERLINE   "\033[4m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"
#define ON_RED      "\033[41m"
#define ON_GREEN    "\033[42m"


using namespace std;
int main(int argc,char* args[]){
    //std::cout << RED << "This is red text." << RESET << std::endl;
    //std::cout << BOLD << GREEN << "This is bold green text." << RESET << std::endl;
    //std::cout << UNDERLINE << YELLOW << "Underlined yellow text." << RESET << std::endl;
    //std::cout << BLUE << WHITE << "White text on blue background." << RESET << std::endl;
    //std::cout << "Back to default." << std::endl;

  
  const int baseParamLength = 4;
  const int configParamLength = 6;


  std::string parameter[baseParamLength] = {
    "config",
    "storage",
    "source",
    "output"
  };

  std::string config_parameter[configParamLength] = {
    "database",
    "db_host",
    "port",
    "database_name",
    "username",
    "password"
  };

  int inputCount = 1;
  while(inputCount < argc-1){
    bool isFailed = false;

    for(int parameterCount = 0;parameterCount < baseParamLength;parameterCount++){
      if(parameter[parameterCount] != args[inputCount]){
        std::cout << RED << "Invalid param :" << args[inputCount]<< RESET << endl;
        isFailed = true;
        break;
      }
      cout << "parameterCount: "<< parameterCount << endl;
    }

    if(isFailed){
      break;
    }

    cout << "Input Count : " << inputCount << endl;
    inputCount++;
  }


  std::string argument = args[0];
  int inputLenght = argc;
  //cout << args[1] << endl;
  //cout << "Count : " << inputLenght << endl;
  return 0;

}
