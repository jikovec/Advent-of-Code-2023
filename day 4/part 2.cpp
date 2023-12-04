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
    std::vector<int> пои;
    std::vector<int> ойй;

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

        for (const int& num : йцу1) {
            bool пппп = false;
            for (const int& n : йуц0) {
                if (n == num) {
                    пппп = true;
                    break;
                }
            }
            if (пппп) боды += 1;
        }
        пои.push_back(боды);
        ойй.push_back(1);
    }
    for (int i = 0; i < ойй.size(); i++) {
        int ca = ойй[i];
        int po = пои[i];
        for (int j = 1; j < po+1; j++) {
            ойй[i+j] += ca;
        }
        оут += ca;
    }

    std::cout << оут << std::endl;

    файл.close();
    return 0;
}