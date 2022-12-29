#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calc.h"

#define MAX_STRING 255

int main(int argc, char **argv) {
  // char string[255] = {0};
  // char string_in[] = "22/(3+2)*5";
  // //                         0      1      2      3       4       5       6
  // // char spec_symb[19][5] = {"sin", "cos", "tan", "asin", "acos", "atan",
  // "sqrt",
  // // // 7      8     9     10    11   12   13   14   15   16    17    18
  // //   "ln", "log", "u+", "u-", "(", "+", "-", "*", "/", "^", "mod", ")"};
  // // //                        0    1    2    3    4    5    6    7    8    9
  // // char numb_symb[11][2] = {"0", "1", "2", "3", "4", "5", "6", "7", "8",
  // "9",
  // // // 10
  // //   "."};
  // printf("%ld\n", strlen(string_in));s
  // printf("Исходная входящая строка: ");
  // for (long unsigned int i = 0; i < MAX_STRING; i++) {
  //   if (i < strlen(string_in)) {
  //     string[i] = string_in[i];
  //     printf("%c", string_in[i]);
  //   }
  //   /*
  //   else {
  //     string[i] = '0';
  //   }
  //   */
  // }
  // printf("\n");
  // // int count = 0;
  // for (int i = 0; i <= 255; i++) {
  //   if (string[i] != 0) {
  //     printf("%c ", string[i]);
  //   }
  //   // if (i % 40 == 0) {
  //   //   if (i != 0) {
  //   //     printf("\n");
  //   //   }
  //   // }
  // }
  // printf("\n");
  // printf("\n");
  puts("");
  printf("Элементов в командной строке %d\n", argc);
  printf("%s", argv[1]);
  printf("\t <= %ld - кол-во символов в строке.\n", strlen(argv[1]));
  // for (int i = 0; i < (int)strlen(argv[1]); i++) {
  //   // if (i == )
  // }

  char m1[80] = "Первая строка.";
  char m2[80] = "Вторая строка.";
  // char m3[80];
  printf("Количество содержащихся в строке символов: %d\n", (int)strlen(m1));
  for (int i = 0; i < (int)strlen(m1); i++) {
    printf("%c", m1[i]);
  }
  strcpy(m1, m2);
  for (int i = 0; i < (int)strlen(m1); i++) {
    printf("%c", m1[i]);
  }
  puts("");
  puts(m2);

  printf("\n");
  char m3[80] = "first_string";
  char m4[80] = "second_string";
  for (int i = 0; i < (int)strlen(m4); i++) {
    printf("%c", m4[i]);
  }
  printf("\n");
  strncpy(m3, m4, 4);
  for (int i = 0; i < (int)strlen(m3); i++) {
    printf("%c", m3[i]);
  }
  printf("\n");

  printf("\n");
  char m5[80] = "first str";
  char m6[80] = "second ing";
  memcpy(m5, m6, 3);
  for (int i = 0; i < (int)strlen(m5); i++) {
    printf("%c", m5[i]);
  }
  printf("\n");

  printf("\n");
  char m7[80] = "0123456789";
  char m8[80] = "45";
  char *result_01 = strstr(m7, m8);
  if (result_01 == NULL) {
    printf("Строка не найдена\n");
  } else {
    printf("result = %s\n", m7);
    printf("result = %s\n", result_01);
    printf("Искомая строка начинается с символа %ld\n", result_01 - m7 + 1);
  }
  strcpy(m8, "631");  // эта строка не найдётся в m7
  result_01 = strstr(m7, m8);
  if (result_01 == NULL) {
    printf("Строка не найдена\n");
  } else {
    printf("result = %s\n", m7);
    printf("result = %s\n", result_01);
    printf("Искомая строка начинается с символа %ld\n", result_01 - m7 + 1);
  }
  printf("\n");

  printf("\n");
  char m9[80] = "0123456789";
  char m10[80] = "631";  // каждый из этих символов ищется в исходной строке
  char *result_02 = strpbrk(m9, m10);
  if (result_02 == NULL) {
    printf("Строка не найдена\n");
  } else {
    printf("result = %s\n", m9);
    printf("result = %s\n", result_02);
    printf("Искомая строка начинается с символа %ld\n", result_02 - m9 + 1);
  }
  printf("\n");

  printf("\n");
  char string_01[80];
  char delim_01[80] = "0123456789.";
  strcpy(string_01, argv[1]);
  printf("result = %s", string_01);
  char *result_03 = strtok(string_01, delim_01);
  printf("\nЛексемы:");
  while (result_03 != NULL) {
    printf("%s", result_03);
    result_03 = strtok(NULL, delim_01);
  }
  printf("\n");

  char string_10[100] =
      "Hello Roman. Where are you? sin and cos(10) this is a sin function. "
      "tank + mod.";
  char string_11[100] = "Roma";
  char *position = strstr(string_10, string_11);
  printf("%s\n", position);
  printf("%d\n", (int)(position - string_10));

  // position = strstr(string_10, operation[0]);
  printf("%s\n", position);
  printf("%d\n", (int)(position - string_10));
  printf("\n");

  char str_src[256];
  strcpy(str_src, argv[1]);
  printf("--------------------------------------------------------\n");
  printf(
      "Исходная строка   0.5   0.15  22   5   5.5   0.5   +1    2 .  == 13\n");
  printf("Исходная строка %s\n", str_src);
  printf("Длинна исходной строки %d.\n", (int)strlen(str_src));
  printf("--------------------------------------------------------\n");
  char mas_dig[256];
  int mas_dig_pos = 0;
  int flag_digit = 1;
  // int flag_alpha = 1;
  for (int i = 0; i < (int)strlen(str_src); i++) {
    if (isdigit(str_src[i]) != 0 || str_src[i] == '.') {
      // flag_alpha = 0;
      if (flag_digit == 1) {
        mas_dig[mas_dig_pos] = str_src[i];
        mas_dig_pos++;
        printf(
            "%02d символ.                       Здесь записанно число "
            "продолжение токена в массив.\n",
            i + 1);
      } else {
        if (mas_dig_pos != 0) {
          mas_dig[mas_dig_pos] = ' ';
          mas_dig_pos++;
        }
        mas_dig[mas_dig_pos] = str_src[i];
        mas_dig_pos++;
        flag_digit = 1;
        printf(
            "%02d символ.                 Здесь записанно новое число - новый "
            "токен в массив.\n",
            i + 1);
      }
    } else {
      printf("%02d символ. Это не число. Это функция.\n", i + 1);
      flag_digit = 0;
      if (isalpha(str_src[i]) != 0) {
      }
      // flag_alpha = 1;
    }
  }
  printf("\n");
  for (int i = 0; i < (int)strlen(mas_dig); i++) {
    printf("%c", mas_dig[i]);
  }
  printf("\n\n");

  char *nstr = mas_dig;
  char *tstr;
  double d = 0;
  while (1) {
    printf("    Not change: %s \n", nstr);
    tstr = nstr;
    d = strtod(nstr, &nstr);
    if (d == 0 && tstr == nstr) break;
    printf("%f\n", d);
  }

  // 5+5
  // ct +
  // post 5 5 +

  // 4*(1+(4-5))
  // ct *
  // post 4 1 4 5 - + *

  // isdigit () {
  //   if '.'
  //   post += ' '
  // }
  // strtod() \ stod = double

  // double 5 4 -1 6 -1 7
  //  char * & - & +

  return 0;
}
