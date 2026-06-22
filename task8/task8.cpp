#include "Adafruit_NeoPixel.h" // подключаем библиотеку


#define PIN  3              // указываем пин для подключения ленты
#define NUMPIXELS 16*16     // указываем количество светодиодов в ленте

// создаем объект strip с нужными характеристиками
Adafruit_NeoPixel strip (NUMPIXELS, PIN, NEO_KHZ800 + NEO_GRB); // первый параметр - количество светодиоидов
                                                                // второй параметр - пин к которому подключен ряд
                                                                // третий параметр - частота с которой посылаются сигналы
                                                                // и какие цвета в очереди светодиоида
void setup() {
  strip.begin();                           // инициализируем ленту
  strip.setBrightness(50);                 // указываем яркость светодиодов (максимум 255)

  uint32_t matrix[16][16];                 // Т.к светодиоиды расположены змейкой то и обращение к ним очень неудобное
  uint32_t count = 0;                      // Я же сделаю чуть по-проще
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

  // таймер от 6 до 1

  // Цифра 6
  strip.clear();
  for (uint32_t i = 6; i <= 9; ++i) {
    strip.setPixelColor(matrix[4][i], strip.Color(255, 0, 0));
    strip.setPixelColor(matrix[8][i], strip.Color(255, 0, 0));
    strip.setPixelColor(matrix[12][i], strip.Color(255, 0, 0));
  }
  for (uint32_t i = 4; i <= 12; ++i) {
    strip.setPixelColor(matrix[i][6], strip.Color(255, 0, 0));
  }
  for (uint32_t i = 8; i <= 12; ++i) {
    strip.setPixelColor(matrix[i][9], strip.Color(255, 0, 0));
  }
  strip.show();
  delay(1000);
  
  // Цифра 5
  strip.clear();
  for (uint32_t i = 6; i <= 9; ++i) {
    strip.setPixelColor(matrix[4][i], strip.Color(255, 0, 0));
    strip.setPixelColor(matrix[8][i], strip.Color(255, 0, 0));
    strip.setPixelColor(matrix[12][i], strip.Color(255, 0, 0));
  }
  for (uint32_t i = 4; i <= 8; ++i) {
    strip.setPixelColor(matrix[i][6], strip.Color(255, 0, 0));
  }
  for (uint32_t i = 8; i <= 12; ++i) {
    strip.setPixelColor(matrix[i][9], strip.Color(255, 0, 0));
  }
  strip.show();
  delay(1000);

  // Цифра 4
  strip.clear();
  for (uint32_t i = 6; i <= 9; ++i) {
    strip.setPixelColor(matrix[8][i], strip.Color(255, 0, 0));
  }
  for (uint32_t i = 4; i <= 8; ++i) {
    strip.setPixelColor(matrix[i][6], strip.Color(255, 0, 0));
    strip.setPixelColor(matrix[i][9], strip.Color(255, 0, 0));
  }
  for (uint32_t i = 8; i <= 12; ++i) {
    strip.setPixelColor(matrix[i][9], strip.Color(255, 0, 0));
  }
  strip.show();
  delay(1000);

  // Цифра 3
  strip.clear();
  for (uint32_t i = 6; i <= 9; ++i) {
    strip.setPixelColor(matrix[4][i], strip.Color(255, 0, 0));
    strip.setPixelColor(matrix[8][i], strip.Color(255, 0, 0));
    strip.setPixelColor(matrix[12][i], strip.Color(255, 0, 0));
  }
  for (uint32_t i = 4; i <= 12; ++i) {
    strip.setPixelColor(matrix[i][9], strip.Color(255, 0, 0));
  }
  strip.show();
  delay(1000);

  // Цифра 2
  strip.clear();
  for (uint32_t i = 6; i <= 9; ++i) {
    strip.setPixelColor(matrix[4][i], strip.Color(255, 0, 0));
    strip.setPixelColor(matrix[8][i], strip.Color(255, 0, 0));
    strip.setPixelColor(matrix[12][i], strip.Color(255, 0, 0));
  }
  for (uint32_t i = 4; i <= 8; ++i) {
    strip.setPixelColor(matrix[i][9], strip.Color(255, 0, 0));
  }
  for (uint32_t i = 8; i <= 12; ++i) {
    strip.setPixelColor(matrix[i][6], strip.Color(255, 0, 0));
  }
  strip.show();
  delay(1000);

  // Цифра 1
  strip.clear();
  for (uint32_t i = 4; i <= 12; ++i) {
    strip.setPixelColor(matrix[i][9], strip.Color(255, 0, 0));
  }
  strip.show();
  delay(1000);

}

void loop() {

}