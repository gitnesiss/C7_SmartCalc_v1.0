#include "calc.h"

// вставить данные в новый узел стека (кладём новый элемент на стек)
int push(Stack *rpn_sta, Node *arr_node, int i) {
  int err = 0;
  if (rpn_sta->next < MAX_SIZE) {
    rpn_sta->node_data[rpn_sta->next].priority = arr_node[i].priority;
    rpn_sta->node_data[rpn_sta->next].type = arr_node[i].type;
    rpn_sta->node_data[rpn_sta->next].value = arr_node[i].value;
    rpn_sta->next += 1;
  } else {
    err = err_stack_is_full;
  }
  return err;
}

// вынуть данные из узла стека и удалить текущий узел (возвращает элемент с
// вершины и переходит к следующему)
int pop(Stack *rpn_sta, Node *rpn_str, int *curr_rpn_str) {
  int err = 0;
  if (rpn_sta->next > 0) {
    rpn_sta->next--;
    rpn_str[*curr_rpn_str].priority =
        rpn_sta->node_data[rpn_sta->next].priority;
    rpn_str[*curr_rpn_str].type = rpn_sta->node_data[rpn_sta->next].type;
    rpn_str[*curr_rpn_str].value = rpn_sta->node_data[rpn_sta->next].value;
    rpn_sta->node_data[rpn_sta->next].priority = 0;
    rpn_sta->node_data[rpn_sta->next].type = 0;
    rpn_sta->node_data[rpn_sta->next].value = 0;
    *curr_rpn_str += 1;
  } else {
    err = err_stack_is_empty_in_pop;
  }
  return err;
}

// посмотреть данные лежащие в узле стека, но не удалять узел
int peek(Stack rpn_sta, Node *tmp_node) {
  int err = 0;
  if (rpn_sta.next > 0) {
    tmp_node->priority = rpn_sta.node_data[rpn_sta.next - 1].priority;
    tmp_node->type = rpn_sta.node_data[rpn_sta.next - 1].type;
    tmp_node->value = rpn_sta.node_data[rpn_sta.next - 1].value;
  } else {
    err = err_stack_is_empty_in_peek;
  }
  return err;
}

// void print_stack(Stack stack) {
//   int size = num_of_elem_in_arr_node(stack.node_data);
//   for (int i = 0; i < size; i++) {
//     printf("Stack el %2d: priority: %1d,", i + 1,
//     stack.node_data[i].priority); printf(" type: %2d,",
//     stack.node_data[i].type); printf(" value: %3g\n",
//     stack.node_data[i].value);
//   }
//   printf("\n");
// }
