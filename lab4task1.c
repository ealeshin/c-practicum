#include <stdio.h>
#include <stdlib.h>

int main()
{
  // объявление переменных
  int cm;         // длина в сантиметрах, вводится с клавиатуры
  int m;          // длина в полных метрах, вычисляется
  int dm;         // длина в полных дециметрах, вычисляется

  // ввод данных
  printf("Введите длину в сантиметрах: ");
  scanf("%d", &cm);

  // вычисление длины в полных метрах
  m = cm / 100;

  // вычисление длины в полных дециметрах
  dm = cm / 10;

  // вывод результата
  printf("\nДлина в полных метрах: %d\n", m);
  printf("\nДлина в полных дециметрах: %d\n", dm);

  // ожидание нажатия любой клавиши для завершения программы
  system("read -n 1 -s -p \"Для завершения нажмите любую клавишу...\"");
  return 0;
}
