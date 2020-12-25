/*
Лабораторная работа №16.
Пусть задано N прямоугольников, каждый из них задан с помощью координат
его левого верхнего угла, ширины и высоты. Определить прямоугольник
наименьшего периметра, вывести координаты его вершин и периметр.
Программа должна предоставить пользователю возможность выбора одного
из двух способов заполнения массива: с клавиатуры или из текстового файла.

Добавить сохранение в бинарный файл массива структур, введенного с клавиатуры.
Добавить считывание массива структур из бинарного файла
(количество элементов массива хранится в начале файла).
*/
#include <stdio.h>
#include <stdlib.h>

struct Rect {
  int   x, // координата X левого верхнего угла
        y, // координата Y левого верхнего угла
        h, // высота прямоугольника
        w; // ширина прямоугольника
};

// Заполнение координат вершины и размеров прямоугольников с клавиатуры:
void enterElements(struct Rect *array, int n) {
  for (int i = 0; i < n; i++) {
    printf("Введите координату X вершины %d-го прямоугольника: ", i + 1);
    scanf("%d", &array[i].x);
    printf("Введите координату Y вершины %d-го прямоугольника: ", i + 1);
    scanf("%d", &array[i].y);
    printf("Введите высоту %d-го прямоугольника: ", i + 1);
    scanf("%d", &array[i].h);
    printf("Введите ширину %d-го прямоугольника: ", i + 1);
    scanf("%d", &array[i].w);
  }
}

// Заполнение координат вершины и размеров прямоугольников с клавиатуры
// с сохранением в бинарный файл:
void saveToBin(struct Rect *array, int n) {
  FILE *iofile = NULL;
  unsigned int i = 0;
  iofile = fopen("output.bin", "w+b");
  if (iofile == NULL) {
    printf("Ошибка при открытии файла");
    exit(-3);
  }
  // Запись количества элементов массива структур в начало бинарного файла:
  fwrite(&n, sizeof(int), 1, iofile);
  // &n - адрес переменной n, содержащей количество элементов массива
  // sizeof(int) - размер в байтах записываемых данных
  // 1 - количество записываемых элементов
  // iofile - указатель на бинарный файл, в который производится запись

  // Запись координат и размеров прямоугольников в бинарный файл:
  for (int i = 0; i < n; i++) {
    fwrite(&array[i].x, sizeof(int), 1, iofile);
    fwrite(&array[i].y, sizeof(int), 1, iofile);
    fwrite(&array[i].h, sizeof(int), 1, iofile);
    fwrite(&array[i].w, sizeof(int), 1, iofile);
  }
  fclose(iofile);
}

// Чтение массива структур из бинарного файла:
void readFromBin() {
  FILE *iofile = NULL;
  unsigned int i = 0;
  unsigned int n;
  struct Rect tmp;

  iofile = fopen("output.bin", "rb");
  if (iofile == NULL) {
    printf("Ошибка при открытии файла");
    exit(-3);
  }
  // Чтение количества элементов массива структур из бинарного файла:
  fread(&n, sizeof(int), 1, iofile);

  printf("\nПрямоугольники:\n");
  for (int i = 0; i < n; i++) {
    // Чтение четырех чисел в переменную типа Rect:
    fread(&tmp, sizeof(int), 4, iofile);
    printf("%d. Вершина (%d; %d), высота %d, ширина %d\n",
      i + 1, tmp.x, tmp.y, tmp.h, tmp.w);
  }
  fclose(iofile);
}

int main()
{
  setbuf(stdout, NULL);

  struct Rect array[100];     // массив с максимальным размером 100
  int n = 0;                  // размер массива, вводится с клавиатуры

  /*
  Ввод количества прямугольников - длины массива структур.
  Длина должна быть натуральным числом и не должна превышать максимальную длину:
  */
  while (n <= 0 || n > 100) {
    printf("Введите количество прямоугольников: ");
    scanf("%d", &n);
  }

  // Заполнение массива структур с клавиатуры:
  enterElements(array, n);

  // Сохранение массива структур в бинарный файл:
  saveToBin(array, n);

  // Вывод данных из бинарного файла:
  readFromBin();

  // Ожидание нажатия любой клавиши для завершения программы:
  system("read -n 1 -s -p \"\nДля завершения нажмите любую клавишу...\"");
  return 0;
}
