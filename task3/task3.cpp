#include <iostream>
#include <cstdint>
#include <vector>

// Задание 3. Суммарное выпавшее снега на улицах

struct Request {
  uint32_t request_type;
  uint32_t street;
  uint32_t other_info;  // Либо по какую улицу нужно смотреть, либо сколько миллиметров снега
  explicit Request(uint32_t a, uint32_t b, uint32_t c) : request_type(a), street(b), other_info(c) {
  }
};

int main() {
  uint32_t n = 0; 
  uint32_t k = 0;
  std::cin >> n >> k;
  
  std::vector<uint32_t> snow_on_streets(n + 1, 0);
  std::vector<Request> requests;
  
  uint32_t a = 0;
  uint32_t b = 0;
  uint32_t c = 0;
  for (uint32_t i = 0; i < k; ++i) {
    std::cin >> a >> b >> c;
    requests.emplace_back(a, b, c);
  }
  
  uint32_t snow_count = 0;
  for (uint32_t i = 0; i < requests.size(); ++i) {
    if (requests[i].request_type == 1) {
      snow_on_streets[requests[i].street] += requests[i].other_info;
    } else {
      snow_count = 0;
      for (uint32_t j = requests[i].street; j < requests[i].other_info + 1; ++j) {
        snow_count += snow_on_streets[j];
      }
      std::cout << snow_count << std::endl;
    }
    
  }
  
  std::cout << std::endl;
  return 0;
}