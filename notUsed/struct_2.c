#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// https://learnc.info/c/structures.html

#define MAX_SIZE 256

typedef struct node {
  int count_node;
  char type_variable[MAX_SIZE];
  double value;
  char title[MAX_SIZE];
} Node;

int main() {
  // 1-й вид объявления и инициализации структуры
  struct node node_0 = {0, "Длинна, м", 23, ""};

  // 2-й вид объявления и инициализации структуры
  Node node_1 = {
      .count_node = 1, .type_variable = "Число", .value = 4.3, .title = ""};

  // 3-й вид объявления и инициализации структуры
  Node node_2 = {2, "Название", 0, "Мороженное"};

  printf("\n");
  printf("---------------------------------------------\n");
  printf("Длина строки внутри элемента .title: %d.\n",
         (int)strlen(node_0.title));
  printf("Узел № %d содержит следующую информацию:\n", node_0.count_node);
  printf("Тип переменной: %s. Значение переменной: %2g.\n",
         node_0.type_variable, node_0.value);
  printf("---------------------------------------------\n");
  printf("\n");
  printf("---------------------------------------------\n");
  printf("Длина строки внутри элемента .title: %d.\n",
         (int)strlen(node_1.title));
  printf("Узел № %d содержит следующую информацию:\n", node_1.count_node);
  printf("Тип переменной: %s. Значение переменной: %2g.\n",
         node_1.type_variable, node_1.value);
  printf("---------------------------------------------\n");
  printf("\n");
  printf("---------------------------------------------\n");
  printf("Длина строки внутри элемента .title: %d.\n",
         (int)strlen(node_2.title));
  printf("Узел № %d содержит следующую информацию:\n", node_2.count_node);
  printf("Тип переменной: %s. Значение переменной: %2g.\n",
         node_2.type_variable, node_2.value);
  printf("---------------------------------------------\n");

  return 0;
}