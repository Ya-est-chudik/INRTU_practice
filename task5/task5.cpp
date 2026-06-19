#include <iostream>
#include <cstdint>
#include <vector>

// Задание 5. Определение границ фигуры в матрице

int main() {
  uint32_t h = 0; // Высота матрицы
  uint32_t w = 0; // Длина каждой строки 
  std::cin >> h >> w;
  
  std::vector<std::vector<bool>> matrix(h);
  
  for (uint32_t i = 0; i < h; ++i) {
    matrix[i].resize(w);
  }
  
  uint32_t enter = 0;
  uint32_t start = 0;
  uint32_t p_1 = 0;
  uint32_t p_2 = 0;
  uint32_t p_3 = 0;
  uint32_t p_4 = 0;
  for (uint32_t i = 0; i < h; ++i) {
    for (uint32_t j = 0; j < w; ++j) { 
      std::cin >> enter;                 // Я хотел изначально просто отдельно ввод и проверку сделать, а потом понял что можно
      matrix[i][j] = enter;              // Сэкономить на асимптотике времени исполнения(при добавлении циклов
      if (matrix[i][j] && start == 0) {  // на проверку T(N) = O(N^4) было бы а это больно хвхвхв)
        ++start;
      }
      if (start == 1) {
        p_1 = i - 1;
        p_2 = j - 1;
        ++start;
      }
      if (i != 0 && j != 0) {
        if (!matrix[i][j] && matrix[i - 1][j]) {
          p_3 = i;
        }
        if (!matrix[i][j] && matrix[i][j - 1]) {
          p_4 = j;
        }
      }
    }
  }
  
  std::cout << p_1 << " " << p_2 << " " << p_3 << " " << p_4 << std::endl;
  
  std::cout << std::endl;
  return 0;
}