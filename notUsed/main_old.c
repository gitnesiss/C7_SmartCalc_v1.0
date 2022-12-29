#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX_SIZE 255

typedef enum { ZERO, FIRST, SECOND, THIRD, FOURTH, FIFTH, SIXTH } priority;

// структура узла
typedef struct {
  char type;  // тип данных: число, действие, функция
  double value;  // значение переменной
  int priority;  // приоритет выполнения
} node;

// структура стека
typedef struct {
  node data[STACK_MAX_SIZE];  // данные текущего узла стека
  int size;  // кол-во элементов и указатель на следующую вершину стека
} stack;

int push(stack *stack, node element);
int pop(stack *stack, node *element);
int peek(stack stack, node *element);
void reset_stack(stack *stack);
void reset_node(node *element);
void print_stack(stack stack, int index);
void print_node(node element);

int main() {
  stack stack;
  node node_stack;
  node tmp_node;
  reset_stack(&stack);

  // внесение данных в стек
  printf("\npush (внесение данных в стек):\n");
  node_stack.value = 45;
  node_stack.priority = SECOND;
  node_stack.type = 'n';
  push(&stack, node_stack);

  node_stack.value = 3;
  node_stack.priority = ZERO;
  node_stack.type = 'c';
  push(&stack, node_stack);

  node_stack.value = 34;
  node_stack.priority = FOURTH;
  node_stack.type = 'f';
  push(&stack, node_stack);
  // вывод стека на экран
  for (int i = 1; i <= stack.size; i++) {
    print_stack(stack, i);
  }

  // не вынемая "верхнего" элемента из стека, вывести его на экран
  printf(
      "\npeek (не вынимая \"верхнего\" элемента из стека, вывести его на "
      "экран):\n");
  peek(stack, &tmp_node);
  print_node(tmp_node);
  printf("size %d\n", stack.size);
  reset_node(&tmp_node);

  // вынуть "верхний" элемент из стека и вывести его на экран
  printf(
      "\npop (вынуть \"верхний\" элемент из стека и вывести его на экран)\n");
  pop(&stack, &tmp_node);
  print_node(tmp_node);
  printf("size %d\n", stack.size);
  for (int i = 1; i <= stack.size; i++) {
    print_stack(stack, i);
  }

  printf("\nreset_stack\n");
  // reset_stack(&stack);
  for (int i = 1; i <= stack.size; i++) {
    print_stack(stack, i);
  }
  printf("size %d\n", stack.size);
  // print_stack(stack, 3);
  return 0;
}

// вставить данные в новый узел стека (кладём новый элемент на стек)
int push(stack *stack, node element) {
  int err = 0;
  if (stack->size < STACK_MAX_SIZE) {
    stack->data[stack->size].type = element.type;
    stack->data[stack->size].value = element.value;
    stack->data[stack->size].priority = element.priority;
    stack->size++;
  } else {
    err = 1;
  }
  return err;
}

// вынуть данные из узла стека и удалить текущий узел (возвращает элемент с
// вершины и переходит к следующему)
int pop(stack *stack, node *element) {
  int err = 0;
  if (stack->size > 0) {
    element->type = stack->data[stack->size - 1].type;
    element->value = stack->data[stack->size - 1].value;
    element->priority = stack->data[stack->size - 1].priority;
    reset_stack(stack);
    stack->size--;
  } else {
    err = 1;
  }
  return err;
}

// посмотреть данные лежащие в узле стека, но не удалять узел
// (возвращает текущий элемент с вершины)
int peek(stack stack, node *element) {
  int err = 0;
  if (stack.size > 0) {
    element->type = stack.data[stack.size - 1].type;
    element->value = stack.data[stack.size - 1].value;
    element->priority = stack.data[stack.size - 1].priority;
  } else {
    err = 1;
  }
  return err;
}

void reset_stack(stack *stack) {
  stack->size = 0;
  for (int i = 0; i < STACK_MAX_SIZE; i++) {
    stack->data[i].type = 0;
    stack->data[i].value = 0;
    stack->data[i].priority = 0;
  }
}

void reset_node(node *element) {
  element->type = 0;
  element->value = 0;
  element->priority = 0;
}

void print_stack(stack stack, int index) {
  if (index > 0) {
    printf("stack type: %c\n", stack.data[index - 1].type);
    printf("stack value: %f\n", stack.data[index - 1].value);
    printf("stack priority: %d\n", stack.data[index - 1].priority);
  } else {
    printf("Неверно указан индекс в функции print_stack.\n");
  }
}

void print_node(node element) {
  printf("node type: %c\n", element.type);
  printf("node value: %f\n", element.value);
  printf("node priority: %d\n", element.priority);
}
