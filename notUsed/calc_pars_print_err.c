#include "calc.h"

int print_err(int err) {
  int i = err;
  if (i == 1) {  // err_incorrect_value
    printf(" err_incorrect_value.\nОшибка: %d - ", i);
    printf("Некорректные данные на входе.\n");
  } else if (i == 2) {  // err_not_correct_x
    // printf(" err_not_correct_x.\nОшибка: %d - ", i);
    // printf("Неверно указан x.\n");
  } else if (i == 3) {  // err_after_point_no_value
    printf(" err_after_point_no_value.\nОшибка: %d - ", i);
    printf("Неверно указан разделитель десятичной дроби. ");
    printf("В начале выражения после точки нет числа.\n");
  } else if (i == 4) {  // err_before_point_no_value
    printf(" err_before_point_no_value.\nОшибка: %d - ", i);
    printf("Неверно указан разделитель десятичной дроби. ");
    printf("В конце выражения перед точкой нет числа.\n");
  } else if (i == 5) {  // err_a_b_point_no_value
    printf(" err_a_b_point_no_value.\nОшибка: %d - ", i);
    printf("Неверно указан разделитель десятичной дроби. ");
    printf("Рядом с точкой нет чисел.\n");
  } else if (i == 6) {  // err_points_greater_once
    printf(" err_points_greater_once.\nОшибка: %d - ", i);
    printf("Неверно указан разделитель десятичной дроби. ");
    printf("Точек в числе больше одной.\n");
  } else if (i == 7) {  // err_after_function_is_not_bracket
    printf(" err_after_function_is_not_bracket.\nОшибка: %d - ", i);
    printf("Неверно записана функция.");
    printf("После функции отсутствует открывающаяся скобка.\n");
  } else if (i == 8) {  // err_skipped_operator
    printf(" err_skipped_operator.\nОшибка: %d - ", i);
    printf("После числа отсутствует оператор.\n");
  } else if (i == 9) {  // err_after_open_bracket_not_correct_symbol
    printf(" err_after_open_bracket_not_correct_symbol.\nОшибка: %d - ", i);
    printf("Неверный знак после открывающейся скобки.\n");
  } else if (i == 10) {  // err_wrong_closing_bracket
    printf(" err_wrong_position_closing_bracket.\nОшибка: %d - ", i);
    printf("Неверно установлена закрывающая скобка.\n");
  } else if (i == 11) {  // err_after_close_bracket_not_correct_symbol
    printf(" err_after_close_bracket_not_correct_symbol.\nОшибка: %d - ", i);
    printf("Неверный знак после закрывающейся скобки.\n");
  } else if (i == 12) {  // err_not_correct_modulo
    printf(" err_not_correct_modulo.\nОшибка: %d - ", i);
    printf("Неверноый остаток от деления.\n");
  } else if (i == 13) {  // err_wrong_name_function
    printf(" err_wrong_name_function.\nОшибка: %d - ", i);
    printf("Неправильное имя функции.\n");
  } else if (i == 14) {  // err_open_bracker_in_end_string
    printf(" err_open_bracker_in_end_string.\nОшибка: %d - ", i);
    printf("Открывающая скобка в конце выражения.\n");
  } else if (i == 15) {  // err_wrong_number_of_brackets
    printf(" err_wrong_number_of_brackets.\nОшибка: %d - ", i);
    printf("Неправильное количество скобок в выражении.\n");
  } else if (i == 16) {  // err_in_start_string_after_plus_not_correct_symbol
    printf(
        " err_in_start_string_after_plus_not_correct_symbol.\n \
           \nОшибка: %d - ",
        i);
    printf("В начале строки после знака + не корректный символ.\n");
  } else if (i == 17) {  // err_plus_in_end_string
    printf(" err_plus_in_end_string.\nОшибка: %d - ", i);
    printf(" + в конце строки.\n");
  } else if (i == 18) {  // err_after_plus_action_modulo
    printf(" err_after_plus_action_modulo.\nОшибка: %d - ", i);
    printf("После знака + стоит действие остаток от деления.\n");
  } else if (i == 19) {  // err_in_string_have_not_correct_symbol
    printf(" err_in_string_have_not_correct_symbol.\nОшибка: %d - ", i);
    printf("В строке есть некорректный символ.\n");
  } else if (i == 20) {  // err_after_minus_action_modulo
    printf(" err_after_minus_action_modulo.\nОшибка: %d - ", i);
    printf("После знака - стоит действие остаток от деления.\n");
  } else if (i == 21) {  // err_in_start_string_after_minus_not_correct_symbol
    printf(
        " err_in_start_string_after_minus_not_correct_symbol.\n \
          Ошибка: %d - ",
        i);
    printf("В начале строки после знака - не корректный символ.\n");
  } else if (i == 22) {  // err_minus_in_end_string
    printf(" err_minus_in_end_string.\nОшибка: %d - ", i);
    printf(" - в конце строки.\n");
  } else if (i == 23) {  // err_in_start_string_symbol_mult
    printf(" err_in_start_string_symbol_mult.\nОшибка: %d - ", i);
    printf("Знак умножения в начале строки.\n");
  } else if (i == 24) {  // err_in_end_string_symbol_mult
    printf(" err_in_end_string_symbol_mult.\nОшибка: %d - ", i);
    printf("Знак умножения в конце строки.\n");
  } else if (i == 25) {  // err_after_mult_not_correct_symbol
    printf(" err_after_mult_not_correct_symbol.\nОшибка: %d - ", i);
    printf("После знака умножения некорректный символ.\n");
  } else if (i == 26) {  // err_in_start_string_symbol_div
    printf(" err_in_start_string_symbol_div.\nОшибка: %d - ", i);
    printf("Знак деления в начале строки.\n");
  } else if (i == 27) {  // err_in_end_string_symbol_div
    printf(" err_in_end_string_symbol_div.\nОшибка: %d - ", i);
    printf("Знак деления в конце строки.\n");
  } else if (i == 28) {  // err_after_div_not_correct_symbol
    printf(" err_after_div_not_correct_symbol.\nОшибка: %d - ", i);
    printf("После знака деления некорректный символ.\n");
  } else if (i == 29) {  // err_pow_in_start_string
    printf(" err_pow_in_start_string.\nОшибка: %d - ", i);
    printf("Степень в начале строки.\n");
  } else if (i == 30) {  // err_pow_in_end_string
    printf(" err_pow_in_end_string.\nОшибка: %d - ", i);
    printf("Степень в конце строки.\n");
  } else if (i == 31) {  // err_before_pow_not_correct_symbol
    printf(" err_before_pow_not_correct_symbol.\n\nОшибка: %d - ", i);
    printf("Перед знаком степени неверный знак.\n");
  } else if (i == 32) {  // err_after_pow_not_correct_symbol
    printf(" err_after_pow_not_correct_symbol.\nОшибка: %d - ", i);
    printf("После знака степень неверный знак.\n");
  } else if (i == 33) {  // err_in_start_string_after_number_not_correct_symbol
    printf(
        " err_in_start_string_after_number_not_correct_symbol.\n \
          Ошибка: %d - ",
        i);
    printf("В начале строки после числа не корректный символ.\n");
  } else if (i == 34) {  // err_in_end_string_before_number_not_correct_symbol
    printf(
        " err_in_end_string_before_number_not_correct_symbol.\n \
          Ошибка: %d - ",
        i);
    printf("В конце строки перед числом не корректный символ.\n");
  } else if (i == 35) {  // err_after_number_not_correct_symbol
    printf(" err_after_number_not_correct_symbol.\nОшибка: %d - ", i);
    printf("После числа не корректный символ.\n");
  } else if (i == 36) {  // err_before_number_not_correct_symbol
    printf(" err_before_number_not_correct_symbol.\nОшибка: %d - ", i);
    printf("Перед числом не корректный символ.\n");
  } else if (i == 37) {  // err_in_start_string_after_x_not_correct_symbol
    printf(
        " err_in_start_string_after_x_not_correct_symbol.\n \
          Ошибка: %d - ",
        i);
    printf("В начале строки после x не корректный символ.\n");
  } else if (i == 38) {  // err_in_end_string_before_x_not_correct_symbol
    printf(
        " err_in_end_string_before_x_not_correct_symbol.\n \
          Ошибка: %d - ",
        i);
    printf("В конце строки перед x не корректный символ.\n");
  } else if (i == 39) {  // err_after_x_not_correct_symbol
    printf(" err_after_x_not_correct_symbol.\nОшибка: %d - ", i);
    printf("После x не корректный символ.\n");
  } else if (i == 40) {  // err_two_mathematical_operations_in_a_row
    printf(" err_two_mathematical_operations_in_a_row.\nОшибка: %d - ", i);
    printf("Два математических оператора подряд.\n");
  } else if (i == 41) {  // err_missing_value_between_brackets
    printf(" err_missing_value_between_brackets.\nОшибка: %d - ", i);
    printf("Между скобок пропущено значение.\n");
  } else if (i == 42) {  // err_in_start_string_modulo
    printf(" err_in_start_string_modulo.\nОшибка: %d - ", i);
    printf("В начале строки действие остаток от деления.\n");
  } else if (i == 43) {  // err_in_end_string_modulo
    printf(" err_in_end_string_modulo.\nОшибка: %d - ", i);
    printf("В конце строки действие остаток от деления.\n");
  } else if (i == 44) {  // err_after_modulo_not_correct_symbol
    printf(" err_after_modulo_not_correct_symbol.\nОшибка: %d - ", i);
    printf("После действия остаток от деления не корректный символ.\n");
  } else if (i == 45) {  // err_stack_is_full
    printf(" err_stack_is_full.\nОшибка: %d - ", i);
    printf("Стек переполнен.\n");
  } else if (i == 46) {  // err_stack_is_empty_in_pop
    printf(" err_stack_is_empty_in_pop.\nОшибка: %d - ", i);
    printf("В функции pop стек уже пустой.\n");
  } else if (i == 47) {  // err_stack_is_empty_in_peek
    printf(" err_stack_is_empty_in_peek.\nОшибка: %d - ", i);
    printf("В функции peek стек уже пустой.\n");
  } else if (i == 48) {  // err_RPN_expression_not_correctly_formed
    printf(" err_RPN_expression_not_correctly_formed.\nОшибка: %d - ", i);
    printf("В функции решения,\n");
    printf("определено что не корректно сформировано выражение RPN.\n");
  } else if (i == 49) {  // err_this_is_the_last_node
    printf(" err_this_is_the_last_node.\nОшибка: %d - ", i);
    printf("Невозможно удалить последний узел стека.\n");
  } else if (i == 50) {  // err_division_by_zero
    printf(" err_division_by_zero.\nОшибка: %d - ", i);
    printf("Деление на ноль.\n");
  } else if (i == 51) {  // err_NAN_remainder_of_division_by_zero
    printf(" err_NAN_remainder_of_division_by_zero.\nОшибка: %d - ", i);
    printf("Остаток от деления на ноль.\n");
  } else if (i == 52) {  // err_near_number_not_correct_symbol
    printf(" err_near_number_not_correct_symbol.\nОшибка: %d - ", i);
    printf("Рядом с числом неверный символ.\n");
  }
  return 0;
}
