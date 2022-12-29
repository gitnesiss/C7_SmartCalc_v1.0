#include "calc.h"

int pars_punct(char *str, int *position, Node *arr_node, int *arr_node_pos,
               int *count_brackets) {
  int err = OK;
  int pos = *position;
  int count_br = *count_brackets;
  int str_len = (int)strlen(str);
  char prev_symbol;
  char next_symbol;
  const char operator[7] = "+-*/m^\0";

  char curr_symbol = str[pos];
  if (pos == 0) {
    next_symbol = str[pos + 1];
  } else if (pos == str_len - 1) {
    prev_symbol = str[pos - 1];
  } else {
    prev_symbol = str[pos - 1];
    next_symbol = str[pos + 1];
  }
  if (pos != 0) {
    if (strchr(operator, curr_symbol) && strchr(operator, prev_symbol)) {
      err = err_two_mathematical_operations_in_a_row;
    }
  }
  if (curr_symbol == '(') {
    count_br++;
    if (next_symbol == ')') {
      err = err_missing_value_between_brackets;
    } else if (next_symbol == '*' || next_symbol == '/' || next_symbol == 'm' ||
               next_symbol == '^') {
      err = err_after_open_bracket_not_correct_symbol;
    } else if (pos == str_len - 1) {
      err = err_open_bracker_in_end_string;
    } else {
      if (isalpha(next_symbol) || isdigit(next_symbol) || next_symbol == '.' ||
          next_symbol == '+' || next_symbol == '-' || next_symbol == '(') {
        // printf(" (\n");
        arr_node[*arr_node_pos].priority = p_brackets;
        arr_node[*arr_node_pos].type = t_bracket_open;
        arr_node[*arr_node_pos].value = 0;
      } else {
        err = err_after_open_bracket_not_correct_symbol;
      }
    }
  } else if (curr_symbol == ')') {
    count_br--;
    if (count_br < 0) {
      err = err_wrong_position_closing_bracket;
    } else {
      if (pos == str_len - 1) {
        //  printf(" )\n");
        arr_node[*arr_node_pos].priority = p_brackets;
        arr_node[*arr_node_pos].type = t_bracket_close;
        arr_node[*arr_node_pos].value = 0;
      } else if (next_symbol == ')' || next_symbol == '+' ||
                 next_symbol == '-' || next_symbol == '*' ||
                 next_symbol == '/' || next_symbol == '^' ||
                 next_symbol == 'm') {
        //  printf(" )\n");
        arr_node[*arr_node_pos].priority = p_brackets;
        arr_node[*arr_node_pos].type = t_bracket_close;
        arr_node[*arr_node_pos].value = 0;
      } else {
        err = err_after_close_bracket_not_correct_symbol;
      }
    }
  } else if (curr_symbol == '+') {
    if (pos == 0) {  // в начале строки
      if (next_symbol == '(' || isdigit(next_symbol) || next_symbol == '.' ||
          isalpha(next_symbol)) {
        if (next_symbol == 'm') {
          err = err_after_plus_action_modulo;
        } else {
          //  printf(" u+\n");
          arr_node[*arr_node_pos].priority = p_unary;
          arr_node[*arr_node_pos].type = t_unary_plus;
          arr_node[*arr_node_pos].value = 0;
        }
      } else {
        err = err_in_start_string_after_plus_not_correct_symbol;
      }
    } else if (pos == str_len - 1) {  // в конце строки
      err = err_plus_in_end_string;
    } else {  // по середине строки
      if (prev_symbol == '(') {
        if (next_symbol == '(' || isdigit(next_symbol) || next_symbol == '.' ||
            isalpha(next_symbol)) {
          if (next_symbol == 'm') {
            err = err_after_plus_action_modulo;
          } else {
            //  printf(" u+\n");
            arr_node[*arr_node_pos].priority = p_unary;
            arr_node[*arr_node_pos].type = t_unary_plus;
            arr_node[*arr_node_pos].value = 0;
          }
        }
      } else {
        if (next_symbol == 'm') {
          err = err_after_plus_action_modulo;
        } else {
          //  printf(" +\n");
          arr_node[*arr_node_pos].priority = p_sum;
          arr_node[*arr_node_pos].type = t_sum;
          arr_node[*arr_node_pos].value = 0;
        }
      }
    }
  } else if (curr_symbol == '-') {
    if (pos == 0) {  // в начале строки
      if (next_symbol == '(' || isdigit(next_symbol) || next_symbol == '.' ||
          isalpha(next_symbol)) {
        if (next_symbol == 'm') {
          err = err_after_minus_action_modulo;
        } else {
          //  printf(" u-\n");
          arr_node[*arr_node_pos].priority = p_unary;
          arr_node[*arr_node_pos].type = t_unary_minus;
          arr_node[*arr_node_pos].value = 0;
        }
      } else {
        err = err_in_start_string_after_minus_not_correct_symbol;
      }
    } else if (pos == str_len - 1) {  // в конце строки
      err = err_minus_in_end_string;
    } else {  // по середине строки
      if (prev_symbol == '(') {
        if (next_symbol == '(' || isdigit(next_symbol) || next_symbol == '.' ||
            isalpha(next_symbol)) {
          if (next_symbol == 'm') {
            err = err_after_minus_action_modulo;
          } else {
            //  printf(" u-\n");
            arr_node[*arr_node_pos].priority = p_unary;
            arr_node[*arr_node_pos].type = t_unary_minus;
            arr_node[*arr_node_pos].value = 0;
          }
        }
      } else {
        if (next_symbol == 'm') {
          err = err_after_minus_action_modulo;
        } else {
          //  printf(" -\n");
          arr_node[*arr_node_pos].priority = p_sum;
          arr_node[*arr_node_pos].type = t_sub;
          arr_node[*arr_node_pos].value = 0;
        }
      }
    }
  } else if (curr_symbol == '*') {
    if (pos == 0) {  // в начале строки
      err = err_in_start_string_symbol_mult;
    } else if (pos == str_len - 1) {  // в конце строки
      err = err_in_end_string_symbol_mult;
    } else {  // по середине строки
      if (!strchr(operator, next_symbol)) {
        //  printf(" *\n");
        arr_node[*arr_node_pos].priority = p_mul;
        arr_node[*arr_node_pos].type = t_mul;
        arr_node[*arr_node_pos].value = 0;
      } else {
        err = err_after_mult_not_correct_symbol;
      }
    }
  } else if (curr_symbol == '/') {
    if (pos == 0) {  // в начале строки
      err = err_in_start_string_symbol_div;
    } else if (pos == str_len - 1) {  // в конце строки
      err = err_in_end_string_symbol_div;
    } else {  // по середине строки
      if (!strchr(operator, next_symbol)) {
        //  printf(" /\n");
        arr_node[*arr_node_pos].priority = p_mul;
        arr_node[*arr_node_pos].type = t_div;
        arr_node[*arr_node_pos].value = 0;
      } else {
        err = err_after_div_not_correct_symbol;
      }
    }
  } else if (curr_symbol == '^') {
    if (pos == 0) {
      err = err_pow_in_start_string;
    } else if (pos == str_len - 1) {
      err = err_pow_in_end_string;
    } else {
      if (prev_symbol == ')' || isdigit(prev_symbol) || prev_symbol == '.' ||
          prev_symbol == 'x') {
        if (strchr(operator, next_symbol) || next_symbol == ')') {
          err = err_after_pow_not_correct_symbol;
        } else {
          //  printf(" ^\n");
          arr_node[*arr_node_pos].priority = p_pow;
          arr_node[*arr_node_pos].type = t_pow;
          arr_node[*arr_node_pos].value = 0;
        }
      } else {
        err = err_before_pow_not_correct_symbol;
      }
    }
  }
  *count_brackets = count_br;
  *position += 1;
  *arr_node_pos += 1;
  return err;
}
