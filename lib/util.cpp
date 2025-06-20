#include "util.h"
#include <iostream>
#include "input_schema.h"
#include <thread>
#include <chrono>

using namespace std;

void success(const std::string &name)
{
    std::cout << GREEN << name << RESET << std::endl;
}

void error(const std::string &name)
{
    std::cout << RED << name << RESET << std::endl;
}

void warning(const std::string &name)
{
    std::cout << YELLOW << name << RESET << std::endl;
}

void info(const std::string &name)
{
    std::cout << BLUE << name << RESET << std::endl;
}

void debug(const std::string &name)
{
    std::cout << MAGENTA << name << RESET << std::endl;
}

void fatal(const std::string &name)
{
    std::cout << RED << name << RESET << std::endl;
}

void trace(const std::string &name)
{
    std::cout << CYAN << name << RESET << std::endl;
}

void log(const std::string &name)
{
    std::cout << WHITE << name << RESET << std::endl;
}

class LoadingSpinner
{
private:
    const char *spinner[10] = {"⠋", "⠙", "⠹", "⠸", "⠼", "⠴", "⠦", "⠧", "⠇", "⠏"};
    const int spinnerSize = 10;
    std::thread spinnerThread;
    // atomic is used to make the variable thread safe
    // that can be accessed by multiple threads
    std::atomic<bool> stopSpinner{false};
    std::string message;

public:
    LoadingSpinner(const std::string &msg = "Loading") : message(msg) {}

    void start()
    {
        stopSpinner = false;
        spinnerThread = std::thread([this]()
                                    {
            int i = 0;
            std::cout << CYAN << message << " " << RESET;
            
            while (!stopSpinner) {
                std::cout << "\b" << YELLOW << spinner[i % spinnerSize] << RESET;
                std::cout.flush();
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                i++;
            } });
    }

    void stop()
    {
        stopSpinner = true;
        if (spinnerThread.joinable())
        {
            spinnerThread.join();
        }
        std::cout << "\b" << GREEN << "✓" << RESET << std::endl;
    }

    ~LoadingSpinner()
    {
        if (spinnerThread.joinable())
        {
            stopSpinner = true;
            spinnerThread.join();
        }
    }
};

void loadingSign()
{
    LoadingSpinner spinner("Loading");
    spinner.start();

    // Simulate some work
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    spinner.stop();
}