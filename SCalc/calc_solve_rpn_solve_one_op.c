#include "calc.h"

int solve_one_operator(Stack *res_sta, Node *rpn_str, int i) {
  int err = OK;
  double radian = pow((double)180 / PI, ANGLE_IN_DEGREE);
  if (res_sta->next >= 1 &&
      res_sta->node_data[res_sta->next - 1].priority == p_number) {
    if (rpn_str[i].type == t_unary_minus) {
      // printf("В функции solve_rpn u-:\n");
      res_sta->node_data[res_sta->next - 1].value *= -1;
    } else if (rpn_str[i].type == t_unary_plus) {
      // printf("В функции solve_rpn u+:\n");
    } else if (rpn_str[i].type == t_sin) {
      // printf("В функции solve_rpn sin:\n");
      res_sta->node_data[res_sta->next - 1].value =
          sin(res_sta->node_data[res_sta->next - 1].value / radian);
    } else if (rpn_str[i].type == t_cos) {
      // printf("В функции solve_rpn cos:\n");
      res_sta->node_data[res_sta->next - 1].value =
          cos(res_sta->node_data[res_sta->next - 1].value / radian);
    } else if (rpn_str[i].type == t_tan) {
      // printf("В функции solve_rpn tan:\n");
      res_sta->node_data[res_sta->next - 1].value =
          tan(res_sta->node_data[res_sta->next - 1].value / radian);
    } else if (rpn_str[i].type == t_asin) {
      // printf("В функции solve_rpn asin:\n");
      res_sta->node_data[res_sta->next - 1].value =
          asin(res_sta->node_data[res_sta->next - 1].value / radian);
    } else if (rpn_str[i].type == t_acos) {
      // printf("В функции solve_rpn acos:\n");
      res_sta->node_data[res_sta->next - 1].value =
          acos(res_sta->node_data[res_sta->next - 1].value / radian);
    } else if (rpn_str[i].type == t_atan) {
      // printf("В функции solve_rpn atan:\n");
      res_sta->node_data[res_sta->next - 1].value =
          atan(res_sta->node_data[res_sta->next - 1].value / radian);
    } else if (rpn_str[i].type == t_sqrt) {
      // printf("В функции solve_rpn sqrt:\n");
      res_sta->node_data[res_sta->next - 1].value =
          sqrt(res_sta->node_data[res_sta->next - 1].value);
    } else if (rpn_str[i].type == t_ln) {
      // printf("В функции solve_rpn ln:\n");
      res_sta->node_data[res_sta->next - 1].value =
          log10(res_sta->node_data[res_sta->next - 1].value);
    } else if (rpn_str[i].type == t_log) {
      // printf("В функции solve_rpn log:\n");
      res_sta->node_data[res_sta->next - 1].value =
          log(res_sta->node_data[res_sta->next - 1].value);
    } else {
      err = err_RPN_expression_not_correctly_formed;
    }
  }
  return err;
}
