#include<iostream>
#include<filesystem>
#include<vector>
#include"lib/input_schema.h"
using namespace std;


std::vector<std::string> mergeArray(){
  std::vector<std::string> names;
  names.push_back("Sajjad Ahmed");
  return names;
}

int main(int argc,char* args[]){
    //std::cout << RED << "This is red text." << RESET << std::endl;
    //std::cout << BOLD << GREEN << "This is bold green text." << RESET << std::endl;
    //std::cout << UNDERLINE << YELLOW << "Underlined yellow text." << RESET << std::endl;
    //std::cout << BLUE << WHITE << "White text on blue background." << RESET << std::endl;

  int inputCount = 1;
  while(inputCount < argc-1){
    bool isFailed = false;

    for(int parameterCount = 0;parameterCount < baseParamLength;parameterCount++){
      if(parameter[parameterCount] != args[inputCount]){
        std::cout << RED << "Invalid param :" << args[inputCount]<< RESET << endl;
        isFailed = true;
        break;
      }
    }

    // break program if any mis input value entered
    if(isFailed){
      break;
    }
    inputCount++;
  }


  std::string argument = args[0];
  int inputLenght = argc;
  //cout << args[1] << endl;
  //cout << "Count : " << inputLenght << endl;
  return 0;

}
