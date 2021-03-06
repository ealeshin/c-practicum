/*
Лабораторная работа №17. Двумерные массивы.

Программа должна предоставить пользователю следующие возможности:
- ввод массива с клавиатуры;
- ввод массива из файла;
- заполнение массива случайными числами из указанного диапазона;
- заполнение массива по заданной формуле;
- вывод массива на экран;
- вывод массива в текстовый файл;
- вывод массива в бинарный файл.

Формула:
i + j, i > j
i / j, i = j
i - j, i < j
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  setbuf(stdout, NULL);
  srand(time(NULL));

  int array[100][100];        // массив с максимальным размером 100x100
  unsigned short rows = 0;    // количество строк массива
  unsigned short cols = 0;    // количество столбцов массива
  unsigned short method = 0;  // способ заполнения массива (1, 2, 3, 4)

  // Ввод количества строк двумерного массива:
  while (rows <= 0 || rows > 100) {
    printf("Введите количество строк массива: ");
    scanf("%hu", &rows;
  }

  // Ввод количества столбцов двумерного массива:
  while (cols <= 0 || cols > 100) {
    printf("Введите количество столбцов массива: ");
    scanf("%hu", &cols);
  }

  // Ввод способа заполнения массива. Принимается число от 1 до 4:
  while (method < 1 || method > 4) {
    printf("Для заполнения массива с клавиатуры введите 1.\n");
    printf("Для заполнения массива случайными числами введите 2.\n");
    printf("Для заполнения массива из файла введите 3.\n");
    printf("Для заполнения массива по формуле введите 5.\n> ");
    scanf("%hu", &method);
  }

  switch (method) {
    // Если выбран метод 1, вызывается функция заполнения массива с клавиатуры:
    case 1:
      promptInput(array, rows, cols);
      break;
    // Если выбран метод 2, вызывается функция заполнения массива случайными числами:
    case 2:
      randomInput(array, rows, cols);
      break;
    // Если выбран метод 3, вызывается функция заполнения массива из файла:
    case 3:
      fileInput(array, rows, cols);
      break;
    // Если выбран метод 4, вызывается функция заполнения массива по формуле:
    case 4:
      formulaInput(array, rows, cols);
      break;
    default:
      printf("Введено недопустимое значение\n");
      exit(0);
  }
}
