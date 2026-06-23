#include "Adafruit_NeoPixel.h" // подключаем библиотеку


#define PIN  3              // указываем пин для подключения ленты
#define NUMPIXELS 16*16     // указываем количество светодиодов в ленте

// создаем объект strip с нужными характеристиками
Adafruit_NeoPixel strip (NUMPIXELS, PIN, NEO_KHZ800 + NEO_GRB); // первый параметр - количество светодиоидов
                                                                // второй параметр - пин к которому подключен ряд
                                                                // третий параметр - частота с которой посылаются сигналы
                                                                // и какие цвета в очереди светодиоида

uint32_t matrix[16][16];                 // Т.к светодиоиды расположены змейкой то и обращение к ним очень неудобное

void zero(uint32_t x, uint32_t y, uint32_t c) { // отрисовка цифр от заданной координаты
  for (uint32_t i = y; i <= y + 3; ++i) {
    strip.setPixelColor(matrix[x][i], strip.Color(c, 0, 0));
  }
  for (uint32_t i = x; i <= x + 7; ++i) {
    strip.setPixelColor(matrix[i][y], strip.Color(c, 0, 0));
  }
  for (uint32_t i = y; i <= y + 3; ++i) {
    strip.setPixelColor(matrix[x + 7][i], strip.Color(c, 0, 0));
  }
  for (uint32_t i = x; i <= x + 7; ++i) {
    strip.setPixelColor(matrix[i][y + 3], strip.Color(c, 0, 0));
  }
}

void one(uint32_t x, uint32_t y, uint32_t c) {
  for (uint32_t i = x; i <= x + 7; ++i) {
    strip.setPixelColor(matrix[i][y + 3], strip.Color(c, 0, 0));
  }
}

void two(uint32_t x, uint32_t y, uint32_t c) {
  for (uint32_t i = y; i <= y + 3; ++i) {
    strip.setPixelColor(matrix[x][i], strip.Color(c, 0, 0));
  }
  for (uint32_t i = y; i <= y + 3; ++i) {
    strip.setPixelColor(matrix[x + 7][i], strip.Color(c, 0, 0));
  }
  for (uint32_t i = y; i <= y + 3; ++i) {
    strip.setPixelColor(matrix[x + 4][i], strip.Color(c, 0, 0));
  }
  for (uint32_t i = x + 4; i <= x + 7; ++i) {
    strip.setPixelColor(matrix[i][y], strip.Color(c, 0, 0));
  }
  for (uint32_t i = x; i <= x + 3; ++i) {
    strip.setPixelColor(matrix[i][y + 3], strip.Color(c, 0, 0));
  }
}

void three(uint32_t x, uint32_t y, uint32_t c) {
  for (uint32_t i = y; i <= y + 3; ++i) {
    strip.setPixelColor(matrix[x][i], strip.Color(c, 0, 0));
  }
  for (uint32_t i = y; i <= y + 3; ++i) {
    strip.setPixelColor(matrix[x + 7][i], strip.Color(c, 0, 0));
  }
  for (uint32_t i = y; i <= y + 3; ++i) {
    strip.setPixelColor(matrix[x + 4][i], strip.Color(c, 0, 0));
  }
  for (uint32_t i = x + 4; i <= x + 7; ++i) {
    strip.setPixelColor(matrix[i][y + 3], strip.Color(c, 0, 0));
  }
  for (uint32_t i = x; i <= x + 3; ++i) {
    strip.setPixelColor(matrix[i][y + 3], strip.Color(c, 0, 0));
  }
}

void four(uint32_t x, uint32_t y, uint32_t c) {
  for (uint32_t i = y; i <= y + 3; ++i) {
    strip.setPixelColor(matrix[x + 4][i], strip.Color(c, 0, 0));
  }
  for (uint32_t i = x + 4; i <= x + 7; ++i) {
    strip.setPixelColor(matrix[i][y + 3], strip.Color(c, 0, 0));
  }
  for (uint32_t i = x; i <= x + 3; ++i) {
    strip.setPixelColor(matrix[i][y + 3], strip.Color(c, 0, 0));
  }
  for (uint32_t i = x; i <= x + 3; ++i) {
    strip.setPixelColor(matrix[i][y], strip.Color(c, 0, 0));
  }
}

void five(uint32_t x, uint32_t y, uint32_t c) {
  for (uint32_t i = y; i <= y + 3; ++i) {
    strip.setPixelColor(matrix[x][i], strip.Color(c, 0, 0));
  }
  for (uint32_t i = y; i <= y + 3; ++i) {
    strip.setPixelColor(matrix[x + 7][i], strip.Color(c, 0, 0));
  }
  for (uint32_t i = y; i <= y + 3; ++i) {
    strip.setPixelColor(matrix[x + 4][i], strip.Color(c, 0, 0));
  }
  for (uint32_t i = x + 4; i <= x + 7; ++i) {
    strip.setPixelColor(matrix[i][y + 3], strip.Color(c, 0, 0));
  }
  for (uint32_t i = x; i <= x + 3; ++i) {
    strip.setPixelColor(matrix[i][y], strip.Color(c, 0, 0));
  }
}

void six(uint32_t x, uint32_t y, uint32_t c) {
  for (uint32_t i = y; i <= y + 3; ++i) {
    strip.setPixelColor(matrix[x][i], strip.Color(c, 0, 0));
  }
  for (uint32_t i = y; i <= y + 3; ++i) {
    strip.setPixelColor(matrix[x + 7][i], strip.Color(c, 0, 0));
  }
  for (uint32_t i = y; i <= y + 3; ++i) {
    strip.setPixelColor(matrix[x + 4][i], strip.Color(c, 0, 0));
  }
  for (uint32_t i = x + 4; i <= x + 7; ++i) {
    strip.setPixelColor(matrix[i][y + 3], strip.Color(c, 0, 0));
  }
  for (uint32_t i = x; i <= x + 7; ++i) {
    strip.setPixelColor(matrix[i][y], strip.Color(c, 0, 0));
  }
}

void seven(uint32_t x, uint32_t y, uint32_t c) {
  for (uint32_t i = y; i <= y + 3; ++i) {
    strip.setPixelColor(matrix[x][i], strip.Color(c, 0, 0));
  }
  for (uint32_t i = x; i <= x + 7; ++i) {
    strip.setPixelColor(matrix[i][y + 3], strip.Color(c, 0, 0));
  }
}

void eight(uint32_t x, uint32_t y, uint32_t c) {
  for (uint32_t i = y; i <= y + 3; ++i) {
    strip.setPixelColor(matrix[x][i], strip.Color(c, 0, 0));
  }
  for (uint32_t i = x; i <= x + 7; ++i) {
    strip.setPixelColor(matrix[i][y], strip.Color(c, 0, 0));
  }
  for (uint32_t i = y; i <= y + 3; ++i) {
    strip.setPixelColor(matrix[x + 7][i], strip.Color(c, 0, 0));
  }
  for (uint32_t i = x; i <= x + 7; ++i) {
    strip.setPixelColor(matrix[i][y + 3], strip.Color(c, 0, 0));
  }
  for (uint32_t i = y; i <= y + 3; ++i) {
    strip.setPixelColor(matrix[x + 4][i], strip.Color(c, 0, 0));
  }
}

void nine(uint32_t x, uint32_t y, uint32_t c) {
  for (uint32_t i = y; i <= y + 3; ++i) {
    strip.setPixelColor(matrix[x][i], strip.Color(c, 0, 0));
  }
  for (uint32_t i = y; i <= y + 3; ++i) {
    strip.setPixelColor(matrix[x + 7][i], strip.Color(c, 0, 0));
  }
  for (uint32_t i = y; i <= y + 3; ++i) {
    strip.setPixelColor(matrix[x + 4][i], strip.Color(c, 0, 0));
  }
  for (uint32_t i = x; i <= x + 7; ++i) {
    strip.setPixelColor(matrix[i][y + 3], strip.Color(c, 0, 0));
  }
  for (uint32_t i = x; i <= x + 3; ++i) {
    strip.setPixelColor(matrix[i][y], strip.Color(c, 0, 0));
  }
}

void print_number(uint32_t num, uint32_t x, uint32_t y, uint32_t c) {
  if (num == 0) {
    zero(x, y, c);
  } else if (num == 1) {
    one(x, y, c);
  } else if (num == 2) {
    two(x, y, c);
  } else if (num == 3) {
    three(x, y, c);
  } else if (num == 4) {
    four(x, y, c);
  } else if (num == 5) {
    five(x, y, c);
  } else if (num == 6) {
    six(x, y, c);
  } else if (num == 7) {
    seven(x, y, c);
  } else if (num == 8) {
    eight(x, y, c);
  } else if (num == 9) {
    nine(x, y, c);
  }
}

void del_num(uint32_t num, uint32_t x, uint32_t y) {
  print_number(num, x, y, 0);
}


void setup() {
  strip.begin();                           // инициализируем ленту
  strip.setBrightness(50);                 // указываем яркость светодиодов (максимум 255)

  uint32_t count = 0;
  for (int i = 0; i < 16; i++) {
    if (i % 2 == 0) {
      for (int j = 16 - 1; j >= 0; j--) {  // Теперь можна обращаться к светодиоидам matrix[строка][столбец]
        matrix[i][j] = count++;
      }
    } else {
      for (int j = 0; j < 16; j++) {
        matrix[i][j] = count++;
      }
    }
  }

  for (uint32_t i = 0; i < NUMPIXELS; ++i) {        // Тест: зажигание каждого светодиоида
    strip.setPixelColor(i, strip.Color(150, 0, 0)); // Отправляет команду в буфер на изменение цвета светодиоида
  }
  strip.show();
  delay(1000);
  strip.clear();                                    // Команда на очистку всех светодиоидов
  strip.show();                                     // Выполняет команды в буфере все которые есть - одновременно

  strip.setPixelColor(matrix[7][7], strip.Color(255, 0, 0)); // Квадрат в центре матрички
  strip.setPixelColor(matrix[7][8], strip.Color(255, 0, 0));
  strip.setPixelColor(matrix[8][7], strip.Color(255, 0, 0));
  strip.setPixelColor(matrix[8][8], strip.Color(255, 0, 0));
  strip.show();
  delay(1000);
  
  
  
  // смайлик
  strip.clear();
  strip.setPixelColor(matrix[4][4], strip.Color(255, 0, 0));
  strip.setPixelColor(matrix[4][5], strip.Color(255, 0, 0));
  strip.setPixelColor(matrix[4][10], strip.Color(255, 0, 0));
  strip.setPixelColor(matrix[4][11], strip.Color(255, 0, 0));
  strip.setPixelColor(matrix[5][3], strip.Color(255, 0, 0));
  strip.setPixelColor(matrix[5][6], strip.Color(255, 0, 0));
  strip.setPixelColor(matrix[5][9], strip.Color(255, 0, 0));
  strip.setPixelColor(matrix[5][12], strip.Color(255, 0, 0));
  strip.setPixelColor(matrix[7][6], strip.Color(255, 0, 0));
  strip.setPixelColor(matrix[7][7], strip.Color(255, 0, 0));
  strip.setPixelColor(matrix[7][8], strip.Color(255, 0, 0));
  strip.setPixelColor(matrix[7][9], strip.Color(255, 0, 0));
  strip.setPixelColor(matrix[8][5], strip.Color(255, 0, 0));
  strip.setPixelColor(matrix[8][10], strip.Color(255, 0, 0));
  strip.setPixelColor(matrix[9][6], strip.Color(255, 0, 0));
  strip.setPixelColor(matrix[9][9], strip.Color(255, 0, 0));
  strip.setPixelColor(matrix[10][7], strip.Color(255, 0, 0));
  strip.setPixelColor(matrix[10][8], strip.Color(255, 0, 0));
  strip.show();
  delay(1000);

  // таймер от 0 до 99
  strip.clear();
  for(uint32_t q = 0; q < 10; ++q) {
    print_number(q, 3, 3, 255);
    for(uint32_t z = 0; z < 10; ++z) {
      print_number(z, 3, 8, 255);
      strip.show();
      del_num(z, 3, 8);
      delay(1000);
    }
    del_num(q, 3, 3);
  }
}

void loop() {

}