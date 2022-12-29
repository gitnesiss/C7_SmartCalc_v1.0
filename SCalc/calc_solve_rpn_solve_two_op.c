#include "calc.h"

int solve_two_operators(Stack *res_sta, Node *rpn_str, int i) {
  int err = OK;
  if (res_sta->next >= 2 &&
      res_sta->node_data[res_sta->next - 1].priority == p_number &&
      res_sta->node_data[res_sta->next - 2].priority == p_number) {
    if (rpn_str[i].type == t_sum) {
      // printf("В функции solve_two_operators +:\n");
      res_sta->node_data[res_sta->next - 2].value +=
          res_sta->node_data[res_sta->next - 1].value;
    } else if (rpn_str[i].type == t_sub) {
      // printf("В функции solve_two_operators -:\n");
      res_sta->node_data[res_sta->next - 2].value -=
          res_sta->node_data[res_sta->next - 1].value;
    } else if (rpn_str[i].type == t_mul) {
      // printf("В функции solve_two_operators *:\n");
      res_sta->node_data[res_sta->next - 2].value *=
          res_sta->node_data[res_sta->next - 1].value;
    } else if (rpn_str[i].type == t_div) {
      if (res_sta->node_data[res_sta->next - 1].value != 0) {
        // printf("В функции solve_two_operators /:\n");
        res_sta->node_data[res_sta->next - 2].value /=
            res_sta->node_data[res_sta->next - 1].value;
      } else {
        err = err_division_by_zero;
      }
    } else if (rpn_str[i].type == t_mod) {
      if (res_sta->node_data[res_sta->next - 1].value != 0) {
        // printf("В функции solve_two_operators mod:\n");
        res_sta->node_data[res_sta->next - 2].value =
            fmod(res_sta->node_data[res_sta->next - 2].value,
                 res_sta->node_data[res_sta->next - 1].value);
      } else {
        err = err_NAN_remainder_of_division_by_zero;
      }
    } else if (rpn_str[i].priority == p_pow) {  // t_pow
      // printf("В функции solve_two_operators ^:\n");
      res_sta->node_data[res_sta->next - 2].value =
          pow(res_sta->node_data[res_sta->next - 2].value,
              res_sta->node_data[res_sta->next - 1].value);
    } else {
      err = err_RPN_expression_not_correctly_formed;
    }
    del_one_node_in_stack(res_sta);
  }
  return err;
}

int del_one_node_in_stack(Stack *res_sta) {
  int err = OK;
  if (res_sta->next >= 1) {
    res_sta->node_data[res_sta->next - 1].priority = 0;
    res_sta->node_data[res_sta->next - 1].type = 0;
    res_sta->node_data[res_sta->next - 1].value = 0;
    res_sta->next -= 1;
  } else {
    err = err_this_is_the_last_node;
  }
  return err;
}
