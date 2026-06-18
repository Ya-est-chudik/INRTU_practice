#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

// Задание 4. расшифровка зашифрованного слова по шаблону

void Untr_p(std::string& tr_aim, std::vector<uint32_t> tr_array) {
  std::string buffer(tr_aim.size(), ' ');
  for (uint32_t i = 0; i < tr_aim.size(); ++i) {
    buffer[tr_array[i]] = tr_aim[i];
  }
  tr_aim = buffer;
}

int main() {
  uint32_t n = 0;
  uint32_t k = 0;
  std::cin >> n >> k;
  
  std::string tr_word;
  std::vector<uint32_t> tr_array;
  
  uint32_t enter_number = 0;
  for (uint32_t i = 0; i < n; ++i) {
    std::cin >> enter_number;
    tr_array.push_back(enter_number - 1);
  }
  
  std::cin >> tr_word;
  
  for (uint32_t i = 0; i < k; ++i) {
    Untr_p(tr_word, tr_array);
  }
  
  std::cout << tr_word << std::endl;
  
  std::cout << std::endl;
  return 0;
}