/*
Лабораторная работа №5. Задание 1.
Дано целое число. Проверить, является ли оно отрицательным трехзначным.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n; // число, вводится с клавиатуры

  // Ввод данных:
  printf("Введите число: ");
  scanf("%d", &n);

  // Вывод результата:
  if (n < -99) {
    printf("> Да\n");
  } else {
    printf("> Нет\n");
  }

  // Ожидание нажатия любой клавиши для завершения программы:
  system("read -n 1 -s -p \"Для завершения нажмите любую клавишу...\"");
  return 0;
}
