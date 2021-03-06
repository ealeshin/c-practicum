/*
Лабораторная работа №8. Задание 1.
Написать программу для вычисления среднего геометрического последовательности
положительных чисел, вводимых с клавиатуры. Ввод данных завершить после того,
как пользователь введет 0 или любое отрицательное число.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  setbuf(stdout, NULL);

  int a;          // число, вводится с клавиатуры
  int m = 1;      // произведение чисел
  int i = 0;      // счётчик

  do {
    // Ввод чисел, пока не введено отрицательное число или ноль:
    printf("Введите число: ");
    scanf("%d", &a);
    if (a > 0) {
      // Умножение произведения чисел на введённое число:
      m *= a;
      // Прибавление единицы к счётчику:
      i++;
    }
  } while (a > 0);

  // Среднее геометрическое - корень степени i из произведения чисел:
  printf("\nСреднее геометрическое: %.2f\n", pow(m, 1.0/i));

  // Ожидание нажатия любой клавиши для завершения программы:
  system("read -n 1 -s -p \"Для завершения нажмите любую клавишу...\"");

  return 0;
}
