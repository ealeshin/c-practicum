/*
Лабораторная работа №14.
За основу берется выполненное задание предыдущей лабораторной работы.
К реализованному функционалу добавить следующие возможности:
считывание массива из файла;
сохранение массива в другой файл после выполненных с ним преобразований
(если такой файл есть, его предыдущее содержимое перезаписывается).
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Заполнение массива с клавиатуры.
В качестве аргументов принимается указатель на переменную array и длина массива n.
Функция ничего не возвращает, т. к. изменяет оригинал переменной по её адресу.
*/
void enterElements(int *array, int n) {
  for (int i = 0; i < n; i++) {
    // Так как первый элемент массива имеет индекс 0, к i прибавляется единица,
    // чтобы запрашивать элемент с индексом 0 как первый:
    printf("Введите %d-й элемент массива: ", i + 1);
    scanf("%d", &array[i]);
  }
}

/*
Заполнение массива случайными числами.
В качестве аргументов принимается указатель на переменную array и длина массива n.
Функция ничего не возвращает, т. к. изменяет оригинал переменной по её адресу.
*/
void generateElements(int *array, int n) {
  int a = 0, b = 0; // границы диапазона случайных чисел для способа 2
  /*
  Ввод границ диапазона случайных чисел, которыми будет заполняться массив.
  Конечная граница диапазона должна быть больше начальной:
  */
  while (a >= b) {
    printf("Введите начальную границу диапазона случайных чисел: ");
    scanf("%d", &a);
    printf("Введите конечную границу диапазона случайных чисел: ");
    scanf("%d", &b);
  }
  for (int i = 0; i < n; i++) {
    /*
    Элементу массива присваивается значение - случайное число от a до b.
    Случайным числом является остаток от деления случайной величины на длину
    диапазона + 1, к которому прибавляется начальная граница диапазона:
    */
    array[i] = rand() % (b - a + 1) + a;
  }
}

// Заполнение массива из файла:
void inputFromFile(int *array, int n) {
  FILE *ft;
  ft = fopen("input.txt", "rt");
  fscanf(ft, "%d", &n);
  for (int i = 0; i < n; i++) {
    fscanf(ft, "%d", &array[i]);
  }
  fclose(ft);
}

// Сохранение массива в файл:
void saveToFile(int *array, int n) {
  FILE *f = fopen("output.txt", "w+");
  fprintf(f, "%d\n", n);
  for (int i = 0; i < n; i++) {
    fprintf(f, "%d\n", array[i]);
  }
  fclose(f);
}

// Вывод массива:
void printArray(int *array, int n) {
  printf("\nМассив: {");
  for (int i = 0; i < n; i++) {
    printf("%d", array[i]);
    if (n - i > 1) printf(", ");
  }
  printf("}\n");
}

// Умножение положительных элементов массива на 3:
void triplePosElements(int *array, int n) {
  for (int i = 0; i < n; i++) {
    if (array[i] > 0) array[i] *= 3;
  }
}

int main()
{
  setbuf(stdout, NULL);
  srand(time(NULL));

  int array[100];     // массив с максимальным размером 100
  int n = 0;          // размер массива, вводится с клавиатуры
  int method = 0;     // способ заполнения массива (1, 2, 3)

  /*
  Ввод длины массива.
  Длина должна быть натуральным числом и не должна превышать максимальную длину:
  */
  while (n <= 0 || n > 100) {
    printf("Введите размер массива: ");
    scanf("%d", &n);
  }

  // Ввод способа заполнения массива. Принимается число 1, 2 или 3:
  while (method < 1 || method > 3) {
    printf("Для заполнения массива с клавиатуры введите 1.\n");
    printf("Для заполнения массива случайными числами введите 2.\n");
    printf("Для заполнения массива из файла введите 3.\n> ");
    scanf("%d", &method);
  }

  switch (method) {
    // Если выбран метод 1, вызывается функция заполнения массива с клавиатуры:
    case 1:
      enterElements(array, n);
      break;
    // Если выбран метод 2, вызывается функция заполнения массива случайными числами:
    case 2:
      generateElements(array, n);
      break;
    // Если выбран метод 3, вызывается функция заполнения массива из файла:
    case 3:
      inputFromFile(array, n);
      break;
    default:
      printf("Введено недопустимое значение\n");
      exit(0);
  }

  // Вывод массива:
  printArray(array, n);

  // Умножение положительных элементов массива на 3:
  printf("\nУмножение положительных элементов массива на 3...\n");
  triplePosElements(array, n);

  // Сохранение полученного изменённого массива в файл:
  saveToFile(array, n);

  // Вывод изменённого массива:
  printArray(array, n);

  // Ожидание нажатия любой клавиши для завершения программы:
  system("read -n 1 -s -p \"\nДля завершения нажмите любую клавишу...\"");
  return 0;
}
