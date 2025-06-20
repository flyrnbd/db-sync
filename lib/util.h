#pragma once // A common preprocessor directive to ensure the header is included only once

#include <string>
#include <iostream>

void success(const std::string &name);
void error(const std::string &name);
void warning(const std::string &name);
void info(const std::string &name);
void debug(const std::string &name);
void fatal(const std::string &name);
void trace(const std::string &name);
void log(const std::string &name);
void print(const std::string &name);
void loadingSign();