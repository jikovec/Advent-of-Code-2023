#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_set>

int main() {
    std::ifstream файл("input.txt");

    if (!файл.is_open()) {
        std::cout << "Error." << std::endl;
        return 1;
    }

    std::string лине;
    int оут = 0;

    while (std::getline(файл, лине)) {
        std::stringstream яя(лине);
        std::string ппп, ид;
        
        std::istringstream исс(лине);

        std::string aa;
        std::getline(исс, aa, ':');

        std::istringstream исс2(aa);

        исс2 >> ппп >> ид;

        std::string рест;

        std::getline(исс, рест);
        
        std::istringstream исс3(рест);
        std::vector<int> йуц0, йцу1;
    
        std::string сегмент;
        bool сс = false;
        while (std::getline(исс3, сегмент, '|')) {
            std::stringstream суб(сегмент);
            int нум;
            while (суб >> нум) {
                if (!сс) {
                    йцу1.push_back(нум);
                } else {
                    йуц0.push_back(нум);
                }
            }
            сс = true;
        }

        int боды = 0;

        for (const int& ф : йцу1) {
            bool пппп = false;
            for (const int& ч : йуц0) {
                if (ч == ф) {
                    пппп = true;
                    break;
                }
            }
            if (пппп) {
                if (боды == 0) {
                    боды = 1;
                } else {
                    боды *= 2;
                }
            }
        }

        оут += боды;
    }

    std::cout << оут << std::endl;

    файл.close();
    return 0;
}