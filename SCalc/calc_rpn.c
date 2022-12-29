#include "calc.h"

int rpn(Stack *rpn_sta, Node *rpn_str, Node *arr_node) {
  int err = OK;
  // текущий элемент выходной строки с обратной польской нотацией
  int curr_rpn_str = 0;
  Node tmp_node;
  int size = num_of_elem_in_arr_node(arr_node);
  for (int i = 0; i < size; i++) {
//    printf("В rpn. Цикл № %d. arr_node[%d].value = %lf\n", i, i, arr_node[i].value);  //
    if (arr_node[i].priority == p_number) {
      push(rpn_sta, arr_node, i);
      pop(rpn_sta, rpn_str, &curr_rpn_str);
    } else if (arr_node[i].priority == p_function) {
      push(rpn_sta, arr_node, i);
    } else if (arr_node[i].priority == p_sum || arr_node[i].priority == p_mul
               /* || arr_node[i].priority == p_pow */) {  // sum, mul
      while (peek(*rpn_sta, &tmp_node) == 0 &&
             tmp_node.type != t_bracket_open &&
             tmp_node.priority >= arr_node[i].priority) {
        pop(rpn_sta, rpn_str, &curr_rpn_str);
      }
      push(rpn_sta, arr_node, i);
    } else if (arr_node[i].priority == p_pow) {  // pow
      while (peek(*rpn_sta, &tmp_node) == 0 &&
             tmp_node.type != t_bracket_open &&
             tmp_node.priority > arr_node[i].priority) {
        pop(rpn_sta, rpn_str, &curr_rpn_str);
      }
      push(rpn_sta, arr_node, i);
    } else if (arr_node[i].priority == p_unary) {  // u+ u-
      push(rpn_sta, arr_node, i);
    } else if (arr_node[i].priority == p_brackets) {  // ()
      if (arr_node[i].type == t_bracket_open) {       // (
        push(rpn_sta, arr_node, i);
      } else {  // arr_node[i].type == t_bracket_close
        while (rpn_sta->node_data[rpn_sta->next - 1].type != t_bracket_open) {
          pop(rpn_sta, rpn_str, &curr_rpn_str);
        }
        if (peek(*rpn_sta, &tmp_node) == 0 && tmp_node.type == t_bracket_open) {
          reset_stack_node(rpn_sta);
        }
        if (peek(*rpn_sta, &tmp_node) == 0 && tmp_node.priority == p_function) {
          pop(rpn_sta, rpn_str, &curr_rpn_str);
        }
      }
    }
  }
  while (rpn_sta->next != 0) {
    pop(rpn_sta, rpn_str, &curr_rpn_str);
    if (peek(*rpn_sta, &tmp_node) == 0 && tmp_node.type == t_bracket_open) {
      reset_stack_node(rpn_sta);
    }
  }

  return err;
}

// функция для определения заполненых элементов в массиве структур
int num_of_elem_in_arr_node(Node *arr_node) {
  int stop_cycle = 0;
  int count_elem_in_arr_node = 0;
  for (int i = 0; i < MAX_SIZE && stop_cycle == 0; i++) {
    if (arr_node[i].priority == p_null) {
      stop_cycle = 1;
    } else {
      count_elem_in_arr_node++;
    }
  }
  return count_elem_in_arr_node;
}

// очистка всего стека перед использованием
void reset_stack(Stack *rpn_sta) {
  rpn_sta->next = 0;
  for (int i = 0; i < MAX_SIZE; i++) {
    rpn_sta->node_data[i].priority = 0;
    rpn_sta->node_data[i].type = 0;
    rpn_sta->node_data[i].value = 0;
  }
}

// очистка узла стека
void reset_stack_node(Stack *stack) {
  stack->next--;
  stack->node_data[stack->next].priority = 0;
  stack->node_data[stack->next].type = 0;
  stack->node_data[stack->next].value = 0;
}
