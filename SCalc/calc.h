#ifndef SRC_CALC_H
#define SRC_CALC_H

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#define MAX_SIZE 255
#define PI 3.14159265358979
#define ANGLE_IN_DEGREE 0  // угол в градусах 0 - нет, 1 - да

enum priority {
  p_null,
  p_number,    // t_x, t_number
  p_sum,       // t_sum, t_sub
  p_mul,       // t_mul, t_div, t_mod
  p_pow,       // t_pow
  p_function,  // t_sin,t_cos,t_tan,t_asin,t_acos,t_atan,t_sqrt,t_ln,t_log
  p_unary,     // t_unary_plus, t_unary_minus
  p_brackets,  // t_bracket_open, t_bracket_close
};

enum type {
  t_null,
  t_x,
  t_number,
  t_sum,
  t_sub,
  t_mul,
  t_div,
  t_mod,
  t_pow,
  t_unary_plus,
  t_unary_minus,
  t_sin = 20,
  t_cos,
  t_tan,
  t_asin,
  t_acos,
  t_atan,
  t_sqrt,
  t_ln,
  t_log,
  t_bracket_open = 30,
  t_bracket_close,
};

enum errors {
  OK,
  err_incorrect_value,
  err_not_correct_x,
  err_after_point_no_value,
  err_before_point_no_value,
  err_a_b_point_no_value,
  err_points_greater_once,
  err_after_function_is_not_bracket,
  err_skipped_operator,
  err_after_open_bracket_not_correct_symbol,
  err_wrong_position_closing_bracket,
  err_after_close_bracket_not_correct_symbol,
  err_not_correct_modulo,
  err_wrong_name_function,
  err_open_bracker_in_end_string,
  err_wrong_number_of_brackets,
  err_in_start_string_after_plus_not_correct_symbol,
  err_plus_in_end_string,
  err_after_plus_action_modulo,
  err_in_string_have_not_correct_symbol,
  err_after_minus_action_modulo,
  err_in_start_string_after_minus_not_correct_symbol,
  err_minus_in_end_string,
  err_in_start_string_symbol_mult,
  err_in_end_string_symbol_mult,
  err_after_mult_not_correct_symbol,
  err_in_start_string_symbol_div,
  err_in_end_string_symbol_div,
  err_after_div_not_correct_symbol,
  err_pow_in_start_string,
  err_pow_in_end_string,
  err_before_pow_not_correct_symbol,
  err_after_pow_not_correct_symbol,
  err_in_start_string_after_number_not_correct_symbol,
  err_in_end_string_before_number_not_correct_symbol,
  err_after_number_not_correct_symbol,
  err_before_number_not_correct_symbol,
  err_in_start_string_after_x_not_correct_symbol,
  err_in_end_string_before_x_not_correct_symbol,
  err_after_x_not_correct_symbol,
  err_two_mathematical_operations_in_a_row,
  err_missing_value_between_brackets,
  err_in_start_string_modulo,
  err_in_end_string_modulo,
  err_after_modulo_not_correct_symbol,
  err_stack_is_full,
  err_stack_is_empty_in_pop,
  err_stack_is_empty_in_peek,
  err_RPN_expression_not_correctly_formed,
  err_this_is_the_last_node,
  err_division_by_zero,
  err_NAN_remainder_of_division_by_zero,
  err_near_number_not_correct_symbol
};

typedef struct coordinates {
  double point_coord[1024][2];
} Coord;

// структура узла
typedef struct node {
  double value;
  int type;
  int priority;
} Node;

// структура односвязаного списка
typedef struct stack {
  Node node_data[MAX_SIZE];
  int next;
} Stack;

int calc(const char *str, double x, double *result);
int parser(char *str, Node *arr_node);
int pars_digit(char *str, int *i, Node *node_number, int *node_number_pos);
int pars_alpha(char *str, int *i, Node *arr_node, int *arr_node_pos);
int pars_punct(char *str, int *position, Node *arr_node, int *arr_node_pos,
               int *count_brackets);

int rpn(Stack *rpn_sta, Node *rpn_str, Node *arr_node);
int solve_rpn(Stack *res_sta, Node *rpn_str, double x_input);
int solve_two_operators(Stack *res_sta, Node *rpn_str, int i);
int solve_one_operator(Stack *res_sta, Node *rpn_str, int i);

// int print_err(int err);
int num_of_elem_in_arr_node(Node *arr_node);
void output(Node *arr_node);

void reset_arr_node(Node *arr_node);
void reset_stack(Stack *stack);
void reset_stack_node(Stack *rpn_sta);
void reset_node(Node *arr_node, int i);

int push(Stack *rpn_sta, Node *arr_node, int i);
int pop(Stack *rpn_sta, Node *rpn_str, int *curr_rpn_str);
int peek(Stack rpn_sta, Node *tmp_node);

int del_one_node_in_stack(Stack *res_sta);
int presence_of_x_in_expression(Node *arr_node);

int my_10_pow(int count);

#endif  // SRC_CALC_H

// Информация о структурах и односвязном списке
// https://learnc.info/c/structures.html
// https://learnc.info/adt/stack.html
// https://www.bestprog.net/ru/2017/05/19/
// https://habr.com/ru/post/341586/
// https://intellect.icu/steki-na-primere-yazyka-si-4497
// https://learnc.info/adt/linked_list.html - односвязный список
// https://codechick.io/tutorials/dsa/dsa-stack

// Калькулятор обратоной польской нотации
// https://www.semestr.online/informatics/polish.php

// Библиотека для графиков
// https://www.qcustomplot.com/index.php/tutorials/settingup

// Внутренняя и внешняя линковка в C++
// https://habr.com/ru/company/otus/blog/432834/

// Учебник по QT
// https://www.opennet.ru/docs/RUS/qt3_prog/qt3.html
