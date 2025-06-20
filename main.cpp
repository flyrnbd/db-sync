#include <iostream>
#include <filesystem>
#include <vector>
#include "lib/input_schema.h"
using namespace std;

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

  std::string argument = args[0];
  int inputLenght = argc;
  // cout << args[1] << endl;
  // cout << "Count : " << inputLenght << endl;
  return 0;
}
