#include <iostream>
#include <cstdint>
#include <vector>

// Задание 1. минимальный спуск в пирамиде
// Первое что пришло в голову - дин. прога где в dp[i][j] i - номер строки, j - элемент на котором мы находимся 
// на строке i
// Для первой строки в примере по идее - dp[0][0] = 18 элемент в этой строке(там он адын)
// Вторая строка - min(dp[1][0], dp[1][1]) = dp[1][0] = 43
// Третья строка - min(dp[2][0], dp[2][1]) = dp[2][0] = 34
// По итогу суммарный путь - dp[0][0] + dp[1][0] + dp[2][0]

void Print_matrix(std::vector<std::vector<uint32_t>>& a) { // Просто для вывода матрицы dp
  for (auto i = 0; i < a.size(); ++i) {                    // для дебаггинга
    for (auto j = 0; j < a[i].size(); ++j) {
      if (j < a[i].size() - 1) {
        std::cout << a[i][j] << " ";
      } else {
        std::cout << a[i][j];
      }
    }
    std::cout << std::endl;
  }
}

void Initalization_matrix(std::vector<std::vector<uint32_t>>& a, uint32_t n) { // Просто для инициализации матрицы dp
  a.resize(n);                                                                 // для дебаггинга
  for (uint32_t i = 0; i < n; ++i) {
    a[i].resize(i + 1);
    for (uint32_t j = 0; j < a[i].size(); ++j) {
      a[i][j] = 0;
    }
  }
}

int main() {
  uint32_t n = 0;
  uint32_t j_p = 0;
  uint32_t min_path = 0;
  std::cin >> n;
  
  std::vector<uint32_t> save_path;
  std::vector<std::vector<uint32_t>> dp;
  
  Initalization_matrix(dp, n);
  
  for (uint32_t i = 0; i < n; ++i) {
    for (uint32_t j = 0; j < i + 1; ++j) {
      std::cin >> dp[i][j];
    }
  }
  
  for (uint32_t i = 0; i < n; ++i) {
    if (i == 0) {
      min_path += dp[0][0];
      save_path.push_back(dp[0][0]);
    } else {
      min_path += std::min(dp[i][j_p], dp[i][j_p + 1]);
      save_path.push_back(std::min(dp[i][j_p], dp[i][j_p + 1]));
      if (std::min(dp[i][j_p], dp[i][j_p + 1]) == dp[i][j_p + 1]) {
        ++j_p;
      }
    }
  }
  std::cout << min_path << std::endl;
  
  for (uint32_t i = 0; i < save_path.size(); ++i) {
    std::cout << save_path[i] << " ";
  }
  
  std::cout << std::endl;
  return 0;
}