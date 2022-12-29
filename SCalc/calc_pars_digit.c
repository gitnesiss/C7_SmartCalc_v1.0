#include "calc.h"

int pars_digit(char *str, int *position, Node *arr_node, int *arr_node_pos) {
  int err = OK;
  int pos = *position;  // позиция начала числа в строке
  int flag_stop = 1;    // флаг что число продолжается
  int count_point = 0;         // счётчик точек в числе
  int str_number_pos = 0;      // позиция в массиве числа
  char str_number[256] = {0};  // массив числа
  char prev_symbol;
  char curr_symbol;
  char next_symbol;
  double number = 0;

  int str_len = (int)strlen(str);
  for (int i = pos; i < str_len && flag_stop == 1 && err == OK; i++) {
//    printf("В pars_digit. Цикл № %d. str = %c\n", i, str[i]);  //
    curr_symbol = str[i];
    if (i == 0) {
      next_symbol = str[i + 1];
    } else if (i == str_len - 1) {
      prev_symbol = str[i - 1];
    } else {
      prev_symbol = str[i - 1];
      next_symbol = str[i + 1];
    }
    if (curr_symbol == '.') {  // текущий символ точка
      *position += 1;
      count_point++;
      if (count_point <= 1) {  // счётчик точек в числе
        if (i == 0) {
          if (!isdigit(next_symbol)) {
            err = err_after_point_no_value;
          }
        } else if (i == str_len - 1) {
          if (!isdigit(prev_symbol)) {
            err = err_before_point_no_value;
          }
        } else {
          if (!isdigit(prev_symbol) && !isdigit(next_symbol)) {
            err = err_a_b_point_no_value;
          }
        }
        str_number[str_number_pos] = curr_symbol;
        str_number_pos++;
      } else {
        err = err_points_greater_once;
      }
    } else if (isdigit(curr_symbol)) {  // текущий символ число
      *position += 1;
      if (i == 0) {
        if (next_symbol == '(' || next_symbol == ')' || isalpha(next_symbol)) {
          if (next_symbol != 'm') {
            err = err_in_start_string_after_number_not_correct_symbol;
          }
        }
      } else if (i == str_len - 1) {
        if (prev_symbol == '(' || prev_symbol == ')' || isalpha(prev_symbol)) {
          if (prev_symbol != 'd') {
            err = err_in_end_string_before_number_not_correct_symbol;
          }
        }
      } else {
        if (prev_symbol == ')' || next_symbol == '(') {
          err = err_near_number_not_correct_symbol;
        } else {
          if (!isdigit(next_symbol) && next_symbol != '.') {
            flag_stop = 0;
          }
        }
      }
      str_number[str_number_pos] = curr_symbol;
      str_number_pos++;
    } else {
      flag_stop = 0;
    }
  }
  if (err == OK) {
    double num_drob = 0;
    double num_int = 0;
    int pos_point = 0;

    int str_number_len = (int)strlen(str_number);
    if (err == OK) {
      if (count_point > 0) {  // Определяем положение точки если она есть
        for (int i = 0; i < str_number_pos; i++) {
          if (str_number[i] == '.') {
            pos_point = i;
          }
        }
        if (str_number_len > pos_point) {  // Определяем величину десятичной дроби
          int count_pos_drob = 0;
          for (int i = str_number_len - 1; i > pos_point; i--) {
            if (count_pos_drob != 0) {
              num_drob = num_drob + (str_number[i] - 48) * 10 * count_pos_drob;
            } else {
              num_drob = str_number[i] - 48;
            }
            count_pos_drob++;
          }
          int razryad_drobi = my_10_pow(count_pos_drob);
          num_drob = num_drob / razryad_drobi;
        }
        int count_pos_int = 0;
        for (int i = pos_point - 1; i >= 0; i--) {
          if (count_pos_int != 0) {
            num_int = num_int + (str_number[i] - 48) * 10 * count_pos_int;
          } else {
            num_int = str_number[i] - 48;
          }
        }
      } else {
        int count_pos_int = 0;
        for (int i = str_number_len - 1; i >= 0; i--) {
          if (count_pos_int != 0) {
            num_int = num_int + (str_number[i] - 48) * my_10_pow(count_pos_int);
          } else {
            num_int = str_number[i] - 48;
          }
          count_pos_int++;
        }
      }
    }
    number = num_int + num_drob;
  }
  arr_node[*arr_node_pos].priority = p_number;
  arr_node[*arr_node_pos].type = t_number;
  arr_node[*arr_node_pos].value = number;
  *arr_node_pos += 1;
  if (isalpha(str[*position]) && (str[*position] != 'm')) {
    err = err_skipped_operator;
  }
  return err;
}

int my_10_pow(int count_pos_drob) {
  int num = 1;
  for (int i = 1; i <= count_pos_drob; i++) {
    num *= 10;
  }
  return num;
}
