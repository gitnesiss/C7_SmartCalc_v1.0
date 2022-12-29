#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../calc.h"

typedef struct tt {
  double value;
  int func;
  int prioritet;
} node;

int s21_chislo(const char *dest, const char *src) {
  int k = 0;
  for (int i = 0; i < (int)strlen(dest); i++) {
    if (strchr(src, dest[i])) {
      k = 1;
    }
  }
  return k;
}

int main(int argc, char **argv) {  //возможно main должен быть void
  printf("-------------------------------\n");
  printf("В элементе %d находится строка:\n", argc);
  printf("%s\n", argv[1]);
  printf("-------------------------------\n");

  const char *chislo = "0123456789.";
  // printf("длинна строки = %d\nстрока  = %s\n", (int)strlen(argv[1]),
  // argv[1]);
  int j = 0;
  node train[256];
  char *str = argv[1];
  j = 0;
  double num = 0;
  // printf("длинна строки = %d, строка  = %s\n", strlen(str), str);
  while (strlen(str) > 0) {
    // printf("Текущая строка = %s\n", str);
    if (!strncmp(str, "sin", 3)) {
      // printf("Вхождение sin in = %s\n", str);
      train[j].value = 0;
      train[j].func = 10;
      train[j].prioritet = p_function;
      str += 3;
      // printf("Вхождение sin out = %s\n", str);
      j += 1;
    } else if (!strncmp(str, "cos", 3)) {
      // printf("Вхождение cos in = %s\n", str);
      train[j].value = 0;
      train[j].func = 11;
      train[j].prioritet = 3;
      str += 3;
      // printf("Вхождение cos out = %s\n", str);
      j += 1;
    } else if (!strncmp(str, "+", 1)) {
      // printf("Вхождение + = %s\n", str);
      train[j].value = 0;
      train[j].func = 4;
      train[j].prioritet = 4;
      str += 1;
      j += 1;
    } else if (!strncmp(str, "-", 1)) {  //
      // printf("Вхождение - = %s\n", str);
      train[j].value = 0;
      train[j].func = 5;
      train[j].prioritet = 4;
      str += 1;
      j += 1;
    } else if (!strncmp(str, "*", 1)) {  //
      // printf("Вхождение * = %s\n", str);
      train[j].value = 0;
      train[j].func = 6;
      train[j].prioritet = 4;
      str += 1;
      j += 1;
    } else if (!strncmp(str, "/", 1)) {  //
      // printf("Вхождение / = %s\n", str);
      train[j].value = 0;
      train[j].func = 7;
      train[j].prioritet = 4;
      str += 1;
      j += 1;
    } else if (!strncmp(str, "(", 1)) {  //
      // printf("Вхождение ( = %s\n", str);
      train[j].value = 0;
      train[j].func = 2;
      train[j].prioritet = 4;
      str += 1;
      j += 1;
    } else if (!strncmp(str, ")", 1)) {  //
      // printf("Вхождение ) = %s\n", str);
      train[j].value = 0;
      train[j].func = 3;
      train[j].prioritet = 4;
      str += 1;
      j += 1;
    } else if (s21_chislo(chislo, str) > 0) {
      char *pEnd;
      // printf("in j = %d\n", j);
      num = strtod(str, &pEnd);
      train[j].value = num;
      train[j].func = 1;
      train[j].prioritet = 0;
      str = pEnd;
      j += 1;
      // printf("out j = %d\n", j);
    }

    // printf("j = %d\n", j);
    str++;
  }

  for (int i = 0; i < j; i++) {
    printf("%3g - func %2d - prior %2d\n", train[i].value, train[i].func,
           train[i].prioritet);
  }

  return 0;
}

/* Значенеие oper:
  0 - начало стека;
  1 - число - нет оператора;
  2 - открывающая скобка;
  3 - закрывающая скобка;
  4 - сложение;
  5 - вычетание;
  6 - умножение;
  7 - деление;
  8 - возведение в степень;
  9 - остаток от деления mod;
  10 - sin;
  11 - cos;
  12 - tan;
  13 - acos;
  14 - asin;
  15 - atan;
  16 - sqrt;
  17 - ln;
  18 - log;
  19 - X, переменная;
  20 - резерв (унарный плюс);
  21 - резерв (унарный минус);
  22 - конец стека;
  */

//  #include "stdio.h"
//  #include "stdlib.h"

//  int sp = 0;
//  int stack[1000];
//  int pop(void) {
//      if (sp > 0) {
//           return stack[--sp];
//      } else {
//           fprintf(stderr, "Невозможно выполнить POP для пустого стека.\n");
//           return 0;
//      }
//  };
//  void push(int a) {
//      stack[sp++] = a;
//  };
//  int empty() {
//      return (sp == 0);
//  }

//  int main() {
//      int i;
//      while (!feof(stdin)) {
//          int c = getchar();
//          int x;
//          switch (c) {
//              case '\n':
//              case ' ' : break;
//              case '=' : printf("Result = %d\n", pop()); break;
//             //  case '\n' : printf("Result = %d\n", pop()); break;
//              case 27  : goto RESULT;
//              case '+' : push(pop() + pop()); break;
//              case '-' : push(-pop() + pop()); break;
//              case '*' : push(pop() * pop()); break;
//              default:
//                  ungetc(c, stdin);
//                  if (scanf("%d", &x) != 1) {
//                      fprintf(stderr, "Can't read integer\n");
//                      return -1;
//                  } else {
//                      push(x);
//                  }
//                  break;
//           }
//     }
//  RESULT:
//      i = 0;
//      while ( !empty() ){
//          printf("Stack[%d] = %d\n", i,  pop());
//          i++;
//      }
//      return 0;
//  }
