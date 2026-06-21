#include <iostream>
#include <cstdint>
#include <string>
#include <cctype>

// Задание 7. соответствие строки маске
// 1, 5, 6 символы - буквы
// 2, 3, 4 символы - цифры

int main() {
  std::string enter;
  std::cin >> enter;
  
  if (enter.size() == 6) { // На вход хоть и подается 6 символов это так на всяк случай
    if (isalpha(enter[0]) && isdigit(enter[1]) && isdigit(enter[2]) && isdigit(enter[3]) &&isalpha(enter[4]) && isalpha(enter[5])) {
      std::cout << "Yes" << std::endl;
    } else {
      std::cout << "No" << std::endl;
    }
  } else {
    std::cout << "No" << std::endl;
  }
  
  std::cout << std::endl;
  return 0;
}