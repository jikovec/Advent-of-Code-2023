#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    std::ifstream файл("input.txt");

    if (!файл.is_open()) {
        std::cout << "Error!" << std::endl;
        return 1;
    }

    std::vector<std::string> енгин;
    std::string лине;
    while (std::getline(файл, лине)) {
        енгин.push_back(лине);
    }
    файл.close();

    int оут = 0;
    for (int i = 0; i < енгин.size(); i++) {
        for (int j = 0; j < енгин[i].size(); j++) {
            if (енгин[i][j] == '*') {
                int число1 = -1, число2 = -1;
                //left
                if (isdigit(енгин[i][j-1])) {
                    if (isdigit(енгин[i][j-2])) {
                        if (isdigit(енгин[i][j-3])) {
                            if (число1 == -1) {
                                число1 = std::stoi(енгин[i].substr(j-3, 3));
                            } else {
                                число2 = std::stoi(енгин[i].substr(j-3, 3));
                            }
                        } else {
                            if (число1 == -1) {
                                число1 = std::stoi(енгин[i].substr(j-2, 2));
                            } else {
                                число2 = std::stoi(енгин[i].substr(j-2, 2));
                            }
                        }
                    } else {
                        if (число1 == -1) {
                            число1 = std::stoi(енгин[i].substr(j-1, 1));
                        } else {
                            число2 = std::stoi(енгин[i].substr(j-1, 1));
                        }
                    }
                }
                //right
                if (isdigit(енгин[i][j+1])) {
                    if (isdigit(енгин[i][j+2])) {
                        if (isdigit(енгин[i][j+3])) {
                            if (число1 == -1) {
                                число1 = std::stoi(енгин[i].substr(j+1, 3));
                            } else {
                                число2 = std::stoi(енгин[i].substr(j+1, 3));
                            }
                        } else {
                            if (число1 == -1) {
                                число1 = std::stoi(енгин[i].substr(j+1, 2));
                            } else {
                                число2 = std::stoi(енгин[i].substr(j+1, 2));
                            }
                        }
                    } else {
                        if (число1 == -1) {
                            число1 = std::stoi(енгин[i].substr(j+1, 1));
                        } else {
                            число2 = std::stoi(енгин[i].substr(j+1, 1));
                        }
                    }
                }
                //top
                if (isdigit(енгин[i-1][j-3]) && isdigit(енгин[i-1][j-2]) && isdigit(енгин[i-1][j-1])) {
                    if (число1 == -1) {
                        число1 = std::stoi(енгин[i-1].substr(j-3, 3));
                    } else {
                        число2 = std::stoi(енгин[i-1].substr(j-3, 3));
                    }
                } else if (isdigit(енгин[i-1][j-2]) && isdigit(енгин[i-1][j-1])) {
                    if (isdigit(енгин[i-1][j])) {
                        if (число1 == -1) {
                            число1 = std::stoi(енгин[i-1].substr(j-2, 3));
                        } else {
                            число2 = std::stoi(енгин[i-1].substr(j-2, 3));
                        }
                    } else {
                        if (число1 == -1) {
                            число1 = std::stoi(енгин[i-1].substr(j-2, 2));
                        } else {
                            число2 = std::stoi(енгин[i-1].substr(j-2, 2));
                        }
                    }
                } else if (isdigit(енгин[i-1][j-1])) {
                    if (isdigit(енгин[i-1][j+1]) && isdigit(енгин[i-1][j])) {
                        if (число1 == -1) {
                            число1 = std::stoi(енгин[i-1].substr(j-1, 3));
                        } else {
                            число2 = std::stoi(енгин[i-1].substr(j-1, 3));
                        }
                    } else if (isdigit(енгин[i-1][j])) {
                        if (число1 == -1) {
                            число1 = std::stoi(енгин[i-1].substr(j-1, 2));
                        } else {
                            число2 = std::stoi(енгин[i-1].substr(j-1, 2));
                        }
                    } else {
                        if (число1 == -1) {
                            число1 = std::stoi(енгин[i-1].substr(j-1, 1));
                        } else {
                            число2 = std::stoi(енгин[i-1].substr(j-1, 1));
                        }
                    }
                } else if (isdigit(енгин[i-1][j])) {
                    if (isdigit(енгин[i-1][j+2]) && isdigit(енгин[i-1][j+1])) {
                        if (число1 == -1) {
                            число1 = std::stoi(енгин[i-1].substr(j, 3));
                        } else {
                            число2 = std::stoi(енгин[i-1].substr(j, 3));
                        }
                    } else if (isdigit(енгин[i-1][j+1])) {
                        if (число1 == -1) {
                            число1 = std::stoi(енгин[i-1].substr(j, 2));
                        } else {
                            число2 = std::stoi(енгин[i-1].substr(j, 2));
                        }
                    } else {
                        if (число1 == -1) {
                            число1 = std::stoi(енгин[i-1].substr(j, 1));
                        } else {
                            число2 = std::stoi(енгин[i-1].substr(j, 1));
                        }
                    }
                }
                if (!isdigit(енгин[i-1][j]) && isdigit(енгин[i-1][j+1])) {
                    if (isdigit(енгин[i-1][j+3]) && isdigit(енгин[i-1][j+2])) {
                        if (число1 == -1) {
                            число1 = std::stoi(енгин[i-1].substr(j+1, 3));
                        } else {
                            число2 = std::stoi(енгин[i-1].substr(j+1, 3));
                        }
                    } else if (isdigit(енгин[i-1][j+2])) {
                        if (число1 == -1) {
                            число1 = std::stoi(енгин[i-1].substr(j+1, 2));
                        } else {
                            число2 = std::stoi(енгин[i-1].substr(j+1, 2));
                        }
                    } else {
                        if (число1 == -1) {
                            число1 = std::stoi(енгин[i-1].substr(j+1, 1));
                        } else {
                            число2 = std::stoi(енгин[i-1].substr(j+1, 1));
                        }
                    }
                }
                //bottom
                if (isdigit(енгин[i+1][j-3]) && isdigit(енгин[i+1][j-2]) && isdigit(енгин[i+1][j-1])) {
                    if (число1 == -1) {
                        число1 = std::stoi(енгин[i+1].substr(j-3, 3));
                    } else {
                        число2 = std::stoi(енгин[i+1].substr(j-3, 3));
                    }
                } else if (isdigit(енгин[i+1][j-2]) && isdigit(енгин[i+1][j-1])) {
                    if (isdigit(енгин[i+1][j])) {
                        if (число1 == -1) {
                            число1 = std::stoi(енгин[i+1].substr(j-2, 3));
                        } else {
                            число2 = std::stoi(енгин[i+1].substr(j-2, 3));
                        }
                    } else {
                        if (число1 == -1) {
                            число1 = std::stoi(енгин[i+1].substr(j-2, 2));
                        } else {
                            число2 = std::stoi(енгин[i+1].substr(j-2, 2));
                        }
                    }
                } else if (isdigit(енгин[i+1][j-1])) {
                    if (isdigit(енгин[i+1][j+1]) && isdigit(енгин[i+1][j])) {
                        if (число1 == -1) {
                            число1 = std::stoi(енгин[i+1].substr(j-1, 3));
                        } else {
                            число2 = std::stoi(енгин[i+1].substr(j-1, 3));
                        }
                    } else if (isdigit(енгин[i+1][j])) {
                        if (число1 == -1) {
                            число1 = std::stoi(енгин[i+1].substr(j-1, 2));
                        } else {
                            число2 = std::stoi(енгин[i+1].substr(j-1, 2));
                        }
                    } else {
                        if (число1 == -1) {
                            число1 = std::stoi(енгин[i+1].substr(j-1, 1));
                        } else {
                            число2 = std::stoi(енгин[i+1].substr(j-1, 1));
                        }
                    }
                } else if (isdigit(енгин[i+1][j])) {
                    if (isdigit(енгин[i+1][j+2]) && isdigit(енгин[i+1][j+1])) {
                        if (число1 == -1) {
                            число1 = std::stoi(енгин[i+1].substr(j, 3));
                        } else {
                            число2 = std::stoi(енгин[i+1].substr(j, 3));
                        }
                    } else if (isdigit(енгин[i+1][j+1])) {
                        if (число1 == -1) {
                            число1 = std::stoi(енгин[i+1].substr(j, 2));
                        } else {
                            число2 = std::stoi(енгин[i+1].substr(j, 2));
                        }
                    } else {
                        if (число1 == -1) {
                            число1 = std::stoi(енгин[i+1].substr(j, 1));
                        } else {
                            число2 = std::stoi(енгин[i+1].substr(j, 1));
                        }
                    }
                }
                if (!isdigit(енгин[i+1][j]) && isdigit(енгин[i+1][j+1])) {
                    if (isdigit(енгин[i+1][j+3]) && isdigit(енгин[i+1][j+2])) {
                        if (число1 == -1) {
                            число1 = std::stoi(енгин[i+1].substr(j+1, 3));
                        } else {
                            число2 = std::stoi(енгин[i+1].substr(j+1, 3));
                        }
                    } else if (isdigit(енгин[i+1][j+2])) {
                        if (число1 == -1) {
                            число1 = std::stoi(енгин[i+1].substr(j+1, 2));
                        } else {
                            число2 = std::stoi(енгин[i+1].substr(j+1, 2));
                        }
                    } else {
                        if (число1 == -1) {
                            число1 = std::stoi(енгин[i+1].substr(j+1, 1));
                        } else {
                            число2 = std::stoi(енгин[i+1].substr(j+1, 1));
                        }
                    }
                }
                if (число1 > -1 && число2 > -1) {
                    оут += число1*число2;
                }
            }
        }
    }

    std::cout << оут << std::endl;

    return 0;
}
