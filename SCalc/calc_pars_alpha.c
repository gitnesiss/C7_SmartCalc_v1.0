#include "calc.h"

int pars_alpha(char *str, int *position, Node *arr_node, int *arr_node_pos) {
  int err = err_wrong_name_function;
  int pos = *position;
  int str_len = (int)strlen(str);
  char temp_func[255] = "\0";
  const char function[10][5] = {"sin",  "cos",  "tan", "asin", "acos",
                                "atan", "sqrt", "ln",  "log",  "\0"};
  const char operator[7] = "+-*/m^\0";

  if (str[pos] == 'x' || str[pos] == 'X') {
    err = OK;
    if (pos == 0) {
      if (str[pos + 1] == '(' || str[pos + 1] == ')' || isalpha(str[pos + 1])) {
        if (str[pos + 1] != 'm') {
          err = err_in_start_string_after_x_not_correct_symbol;
        }
      }
    } else if (pos == str_len - 1) {
      if (str[pos - 1] == '(' || str[pos - 1] == ')' || isalpha(str[pos - 1])) {
        if (str[pos - 1] != 'd') {
          err = err_in_end_string_before_x_not_correct_symbol;
        }
      }
    } else {
      if (!strchr(operator, str[pos + 1]) && str[pos + 1] != ')') {
        err = err_after_x_not_correct_symbol;
      }
    }
    if (err == OK) {
      arr_node[*arr_node_pos].priority = p_number;
      arr_node[*arr_node_pos].type = t_x;
      arr_node[*arr_node_pos].value = 0;
      *position += 1;
    }
  } else if (str[pos] == 'm') {
    for (int i = pos; i < pos + 3 && isalpha(str[i]); i++) {
      temp_func[i - pos] = str[i];
      *position += 1;
    }
    if (!strcmp("mod", temp_func)) {
      if (pos == 0) {
        err = err_in_start_string_modulo;
      } else if (pos == str_len - 3) {
        err = err_in_end_string_modulo;
      } else {
        if (strchr(operator, str[*position])) {
          err = err_after_modulo_not_correct_symbol;
        } else {
          arr_node[*arr_node_pos].priority = p_mul;
          arr_node[*arr_node_pos].type = t_mod;
          arr_node[*arr_node_pos].value = 0;
          err = OK;
        }
      }
    }
  } else {
    for (int i = pos; isalpha(str[i]); i++) {
      temp_func[i - pos] = str[i];
      *position += 1;
    }
    for (int j = 0; j < 9 && err == err_wrong_name_function; j++) {
      if (!strcmp(function[j], temp_func)) {
        arr_node[*arr_node_pos].priority = p_function;
        arr_node[*arr_node_pos].type = 20 + j;
        arr_node[*arr_node_pos].value = 0;
        err = OK;
        if (str[*position] != '(') {
          err = err_after_function_is_not_bracket;
        }
      }
    }
  }
  *arr_node_pos += 1;
  return err;
}
