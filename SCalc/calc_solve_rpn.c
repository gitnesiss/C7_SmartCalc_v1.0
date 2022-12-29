#include "calc.h"

int solve_rpn(Stack *res_sta, Node *rpn_str, double x_input) {
  int err = OK;
  int size = num_of_elem_in_arr_node(rpn_str);
  for (int i = 0; i < size && err == OK; i++) {
//    printf("В solve_rpn. Цикл № %d. rpn_str[%d].value = %lf\n", i, i, rpn_str[i].value);  //
    if (rpn_str[i].priority == p_number) {  // t_x, t_number
      push(res_sta, rpn_str, i);
      if (res_sta->node_data[res_sta->next - 1].type == t_x) {
        res_sta->node_data[res_sta->next - 1].value = x_input;
      }
    } else if (rpn_str[i].priority == p_sum || rpn_str[i].priority == p_mul ||
               rpn_str[i].priority == p_pow) {  // t_sum, t_sub
      err = solve_two_operators(res_sta, rpn_str, i);
    } else if (rpn_str[i].priority == p_unary ||
               rpn_str[i].priority ==
                   p_function) {  // t_unary_plus,t_unary_minus
      err = solve_one_operator(res_sta, rpn_str, i);
    }
  }
  // print_stack(*res_sta);
  return err;
}
