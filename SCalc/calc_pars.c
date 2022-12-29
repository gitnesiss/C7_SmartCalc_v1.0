#include "calc.h"

int parser(char *str, Node *arr_node) {
  int err = OK;
  if (*str != '\0') {
    //  printf("-------------------------------\n");
    //  printf("Парсим строку:\n");
    //  printf("%s\n", str);
    //  printf("-------------------------------\n");
    int arr_node_pos = 0;
    int count_brackets = 0;
    for (int i = 0; i < (int)strlen(str) && err == OK;) {
      reset_node(arr_node, i);
      if (isdigit(str[i]) || str[i] == '.') {
        err = pars_digit(str, &i, arr_node, &arr_node_pos);
      } else if (isalpha(str[i])) {
        err = pars_alpha(str, &i, arr_node, &arr_node_pos);
      } else if ((str[i] >= 40 && str[i] <= 43) || str[i] == 45 ||
                 str[i] == 47 || str[i] == 94) {
        err = pars_punct(str, &i, arr_node, &arr_node_pos, &count_brackets);
      } else {
        err = err_in_string_have_not_correct_symbol;
      }
    }

    // проверка на верное количество скобок
    if (err == OK && count_brackets != 0) {
      err = err_wrong_number_of_brackets;
    }
    if (err == OK) {
      // printf("\nОшибка отсутствует: %d.\n", err);
    } else {
      // Раскоментить для вывода ошибки
      // print_err(err);
    }
  } else {
    err = err_incorrect_value;
  }
  return err;
}

void reset_node(Node *arr_node, int element) {
  arr_node[element].type = 0;
  arr_node[element].value = 0;
  arr_node[element].priority = 0;
}
