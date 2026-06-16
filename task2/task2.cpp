#include <iostream>
#include <cstdint>
#include <vector>

// Задание 2. Несвязный граф нужно сделат связным
// Впринципе нужно просто найти в графе компоненты связности и чтобы сделать граф нужно провести
// Ребер (кол-во компонент связности - 1)

class SNM { // Самое простое пойти через систему непересекающихся множеств(СНМ(SNM))
 public:
  SNM(uint32_t n) : parent_(n + 1) {
    for (uint32_t i = 0; i < n + 1; ++i) {
      parent_[i] = i;
    }
  }
  
  uint32_t Leader(uint32_t x) {
    if (parent_[x] == x) {
      return x;
    } 
    return Leader(parent_[x]);
  }
  
  void Unite(uint32_t a, uint32_t b) {
    a = Leader(a);
    b = Leader(b);
    if (a != b) {
      parent_[b] = a;
    }
  }
  
  uint32_t CountComponents(uint32_t count = 0) {
    for (uint32_t i = 1; i < parent_.size(); ++i) {
      if (parent_[i] == i) {
        ++count;
      }
    }
    return count;
  }
  
 private:
  std::vector<int> parent_;
};

int main() {
  uint32_t n = 0;
  uint32_t edge_count = 0;
  std::cin >> n >> edge_count;
  
  uint32_t from = 0;
  uint32_t to = 0;
  SNM graph(n);
  
  for (uint32_t i = 0; i < edge_count; ++i) {
    std::cin >> from >> to;
    graph.Unite(from, to);
  }
  
  std::cout << graph.CountComponents() - 1 << std::endl;
  
  std::cout << std::endl;
  return 0;
}