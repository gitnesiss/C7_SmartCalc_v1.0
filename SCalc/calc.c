#include "calc.h"

const char operation[19][5] = {
    //    0      1      2       3       4       5
    "sin", "cos", "tan", "asin", "acos", "atan",
    // 6      7     8      9    10    11   12   13   14   15   16     17   18
    "sqrt", "ln", "log", "u+", "u-", "(", "+", "-", "*", "/", "mod", "^", ")"};
const char function[9][5] = {"sin",  "cos",  "tan", "asin", "acos",
                             "atan", "sqrt", "ln",  "log"};
const char operator[6] = "+-*/m^";

int calc(const char *str_input, double x, double *result) {
  int err = OK;
  // Строка с распарсенной входной строкой, но элементы не обработаны в
  // обратную польскую нотацию.
  Node arr_node[MAX_SIZE];
  reset_arr_node(arr_node);
  char str[MAX_SIZE] = {0};
  strncpy(str, str_input, MAX_SIZE);
  err = parser(str, arr_node);
//  printf("\nВывод arr_node:");
//  output(arr_node);
  if (err == 0) {
    // Cтрока с готовой обратной польской нотацией (массив, в каждом элементе
    // которого лежит структура Node);
    Node rpn_str[MAX_SIZE];  // rpn - vegas
    reset_arr_node(rpn_str);
    Stack rpn_sta;  // стек - texas
    reset_stack(&rpn_sta);
    err = rpn(&rpn_sta, rpn_str, arr_node);
//    printf("\nВывод rpn_string:");
//    output(rpn_str);
    if (err == 0) {
      Stack res_sta;
      reset_stack(&res_sta);
      err = solve_rpn(&res_sta, rpn_str, x);
      if (err == 0) {
        *result = res_sta.node_data[0].value;
      }
    }
  }
  return err;
}

// функция для установка нулей в элементах массива структур
// (необработанных узлов)
void reset_arr_node(Node *arr_node) {
  for (int i = 0; i < MAX_SIZE; i++) {
    arr_node[i].priority = 0;
    arr_node[i].type = 0;
    arr_node[i].value = 0;
  }
}

// void output(Node *arr_node) {
//     int i = 0;
//     printf("\n");
//     while (arr_node[i].type != 0) {
//         printf("el %2d: priority: %1d,", i + 1, arr_node[i].priority);
//         printf(" type: %2d,", arr_node[i].type);
//         printf(" value: %3g\n", arr_node[i].value);
//         i++;
//     }
// }

// int copy_from_str_to_node(char str, Node *arr_node) {
//   int err = OK;
//   for (int i = 0; i < MAX_SIZE; i++) {

//   }
// }
