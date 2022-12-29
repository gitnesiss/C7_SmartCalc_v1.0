#include <iostream>
using namespace std;

// int vivod_err(int err_numb) {
//   cout << "Ошибка №" << err_numb << " :" << endl;

// }

void print_err(int err);

int main() {
  int i = 0;
  for (int i = 1; i < 52; i++) {
    print_err(i);
  }
  return 0;
}

void print_err(int err) {
  int i = err;
  if (i == 1) {  // err_incorrect_value
    printf("Error: %d - err_incorrect_value.\n", i);
  } else if (i == 2) {  // err_not_correct_x
    printf("Error: %d - err_not_correct_x.\n", i);
  } else if (i == 3) {  // err_after_point_no_value
    printf("Error: %d - err_after_point_no_value.\n", i);
  } else if (i == 4) {  // err_before_point_no_value
    printf("Error: %d - err_before_point_no_value.\n", i);
  } else if (i == 5) {  // err_a_b_point_no_value
    printf("Error: %d - err_a_b_point_no_value.\n", i);
  } else if (i == 6) {  // err_points_greater_once
    printf("Error: %d - err_points_greater_once.\n", i);
  } else if (i == 7) {  // err_after_function_is_not_bracket
    printf("Error: %d - err_after_function_is_not_bracket.\n", i);
  } else if (i == 8) {  // err_skipped_operator
    printf("Error: %d - err_skipped_operator.\n", i);
  } else if (i == 9) {  // err_after_open_bracket_not_correct_symbol
    printf("Error: %d - err_after_open_bracket_not_correct_symbol.\n", i);
  } else if (i == 10) {  // err_wrong_closing_bracket
    printf("Error: %d - err_wrong_position_closing_bracket.\n", i);
  } else if (i == 11) {  // err_after_close_bracket_not_correct_symbol
    printf("Error: %d - err_after_close_bracket_not_correct_symbol.\n", i);
  } else if (i == 12) {  // err_not_correct_modulo
    printf("Error: %d - err_not_correct_modulo.\n", i);
  } else if (i == 13) {  // err_wrong_name_function
    printf("Error: %d - err_wrong_name_function.\n", i);
  } else if (i == 14) {  // err_open_bracker_in_end_string
    printf("Error: %d - err_open_bracker_in_end_string.\n", i);
  } else if (i == 15) {  // err_wrong_number_of_brackets
    printf("Error: %d - err_wrong_number_of_brackets.\n", i);
  } else if (i == 16) {  // err_in_start_string_after_plus_not_correct_symbol
    printf("Error: %d - err_in_start_string_after_plus_not_correct_symbol.\n",
     i);
  } else if (i == 17) {  // err_plus_in_end_string
    printf("Error: %d - err_plus_in_end_string.\n", i);
  } else if (i == 18) {  // err_after_plus_action_modulo
    printf("Error: %d - err_after_plus_action_modulo.\n", i);
  } else if (i == 19) {  // err_in_string_have_not_correct_symbol
    printf("Error: %d - err_in_string_have_not_correct_symbol.\n", i);
  } else if (i == 20) {  // err_after_minus_action_modulo
    printf("Error: %d - err_after_minus_action_modulo.\n", i);
  } else if (i == 21) {  // err_in_start_string_after_minus_not_correct_symbol
    printf("Error: %d - err_in_start_string_after_minus_not_correct_symbol.\n",
     i);
  } else if (i == 22) {  // err_minus_in_end_string
    printf("Error: %d - err_minus_in_end_string.\n", i);
  } else if (i == 23) {  // err_in_start_string_symbol_mult
    printf("Error: %d - err_in_start_string_symbol_mult.\n", i);
  } else if (i == 24) {  // err_in_end_string_symbol_mult
    printf("Error: %d - err_in_end_string_symbol_mult.\n", i);
  } else if (i == 25) {  // err_after_mult_not_correct_symbol
    printf("Error: %d - err_after_mult_not_correct_symbol.\n", i);
  } else if (i == 26) {  // err_in_start_string_symbol_div
    printf("Error: %d - err_in_start_string_symbol_div.\n", i);
  } else if (i == 27) {  // err_in_end_string_symbol_div
    printf("Error: %d - err_in_end_string_symbol_div.\n", i);
  } else if (i == 28) {  // err_after_div_not_correct_symbol
    printf("Error: %d - err_after_div_not_correct_symbol.\n", i);
  } else if (i == 29) {  // err_pow_in_start_string
    printf("Error: %d - err_pow_in_start_string.\n", i);
  } else if (i == 30) {  // err_pow_in_end_string
    printf("Error: %d - err_pow_in_end_string.\n", i);
  } else if (i == 31) {  // err_before_pow_not_correct_symbol
    printf("Error: %d - err_before_pow_not_correct_symbol.\n", i);
  } else if (i == 32) {  // err_after_pow_not_correct_symbol
    printf("Error: %d - err_after_pow_not_correct_symbol.\n", i);
  } else if (i == 33) {  // err_in_start_string_after_number_not_correct_symbol
    printf("Error: %d - err_in_start_string_after_number_not_correct_symbol.\n", i);
  } else if (i == 34) {  // err_in_end_string_before_number_not_correct_symbol
    printf("Error: %d - err_in_end_string_before_number_not_correct_symbol.\n", i);
  } else if (i == 35) {  // err_after_number_not_correct_symbol
    printf("Error: %d - err_after_number_not_correct_symbol.\n", i);
  } else if (i == 36) {  // err_before_number_not_correct_symbol
    printf("Error: %d - err_before_number_not_correct_symbol.\n", i);
  } else if (i == 37) {  // err_in_start_string_after_x_not_correct_symbol
    printf("Error: %d - err_in_start_string_after_x_not_correct_symbol.\n", i);
  } else if (i == 38) {  // err_in_end_string_before_x_not_correct_symbol
    printf("Error: %d - err_in_end_string_before_x_not_correct_symbol.\n", i);
  } else if (i == 39) {  // err_after_x_not_correct_symbol
    printf("Error: %d - err_after_x_not_correct_symbol.\n", i);
  } else if (i == 40) {  // err_two_mathematical_operations_in_a_row
    printf("Error: %d - err_two_mathematical_operations_in_a_row.\n", i);
  } else if (i == 41) {  // err_missing_value_between_brackets
    printf("Error: %d - err_missing_value_between_brackets.\n", i);
  } else if (i == 42) {  // err_in_start_string_modulo
    printf("Error: %d - err_in_start_string_modulo.\n", i);
  } else if (i == 43) {  // err_in_end_string_modulo
    printf("Error: %d - err_in_end_string_modulo.\n", i);
  } else if (i == 44) {  // err_after_modulo_not_correct_symbol
    printf("Error: %d - err_after_modulo_not_correct_symbol.\n", i);
  } else if (i == 45) {  // err_stack_is_full
    printf("Error: %d - err_stack_is_full.\n", i);
  } else if (i == 46) {  // err_stack_is_empty_in_pop
    printf("Error: %d - err_stack_is_empty_in_pop.\n", i);
  } else if (i == 47) {  // err_stack_is_empty_in_peek
    printf("Error: %d - err_stack_is_empty_in_peek.\n", i);
  } else if (i == 48) {  // err_RPN_expression_not_correctly_formed
    printf("Error: %d - err_RPN_expression_not_correctly_formed.\n", i);
  } else if (i == 49) {  // err_this_is_the_last_node
    printf("Error: %d - err_this_is_the_last_node.\n", i);
  } else if (i == 50) {  // err_division_by_zero
    printf("Error: %d - err_division_by_zero.\n", i);
  } else if (i == 51) {  // err_NAN_remainder_of_division_by_zero
    printf("Error: %d - err_NAN_remainder_of_division_by_zero.\n", i);
  }
}