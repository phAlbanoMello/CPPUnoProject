#pragma once
#include "Service.h"

class InputService : public Service{
public:
    void Init() override;
    static char GetPlayerInput();

    template <typename T>
    static T GetPlayerInputOfType() {
        T userInput;
        while (true) {
            if (std::cin >> userInput) {
                // Input succeeded
                break;
            }
            else {
                // Input failed, clear the error state and discard invalid input
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please try again." << std::endl;
            }
        }
        return userInput;
    }
};
