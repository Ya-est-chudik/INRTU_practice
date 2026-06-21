#include <iostream>
#include <cstdint>
#include <vector>

// Задание 6. Несовместимы микроконтроллеры
// Ввод - (a, b, x, y)
// a - количество контролеров типа A
// b - количество контролеров типа B
// x - количество модулей упр типа 1
// y - количество модулей упр типа 2
// b не совместимо с y
struct Input {
  uint32_t a;
  uint32_t b;
  uint32_t x;
  uint32_t y;
  Input(int a1, int b1, int x1, int y1) : a(a1), b(b1), x(x1), y(y1) {
  }

  Input() : a(0), b(0), x(0), y(0) {
  }

};

std::istream& operator>>(std::istream& in, Input& input) {
  in >> input.a >> input.b >> input.x >> input.y;
  return in;
}

int main() {
  uint32_t n = 0;
  std::cin >> n;
  
  std::vector<uint32_t> output;
  
  Input enter;

  for (uint32_t i = 0; i < n; ++i) {
    std::cin >> enter;
    
    uint32_t result = 0;
    
    uint32_t b_with_1 = std::min(enter.b, enter.x); // Соединяем B с 1
    result += b_with_1;
    enter.b -= b_with_1;
    enter.x -= b_with_1;
    
    uint32_t a_with_1 = std::min(enter.a, enter.x); // Соединяем оставшиеся модули 1 с a
    result += a_with_1;
    enter.a -= a_with_1;
    enter.x -= a_with_1;
    
    uint32_t a_with_2 = std::min(enter.a, enter.y); // Соединяем оставшиеся модули 2 с b
    result += a_with_2;
    enter.a -= a_with_2;
    enter.y -= a_with_2;
    
    output.push_back(result);
  }
  
  for (size_t i = 0; i < output.size(); ++i) {
    std::cout << output[i] << " ";
  }
  
  std::cout << std::endl;
  return 0;
}