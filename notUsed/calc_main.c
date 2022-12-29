#include "calc.h"

int main() {
  double result = 0;
  double x = 12;
  // char str_start[MAX_SIZE] = "(3+5)";
  // char str_start[MAX_SIZE] = "((3+5)-2)";  // 6
  // char str_start[MAX_SIZE] = "-(((10+10)*(+2)/4mod8)^8)";  // -256
  // char str_start[MAX_SIZE] = "sin(320/2+(-2))";  // 0.795824
  // char str_start[MAX_SIZE] = "(3+5)+(1*sin(x)-3)";
  // char str_start[MAX_SIZE] = "(3+5)+(1*sin(2*x)-3)";
  // char str_start[MAX_SIZE] = "sin(2*x)";
  // char str_start[MAX_SIZE] = "9+3*sin(3)";
  // char str_start[MAX_SIZE] = "sincos";
  // char str_start[MAX_SIZE] = "9/0";
  // char str_start[MAX_SIZE] = "9sin(30)";
  // char str_start[MAX_SIZE] = "9+3";
  // char str_start[MAX_SIZE] = "3+9";
  // char str_start[MAX_SIZE] = "sin(x)";
  // char str_start[MAX_SIZE] = "cos(x)";
  // char str_start[MAX_SIZE] = "tan(x)";
  // char str_start[MAX_SIZE] = "3+4*2/(1-5)^2^3";
  // char str_start[MAX_SIZE] = "5+x^2";
  char str_start[MAX_SIZE] = "4+5(4+6)";
  // char str_start[MAX_SIZE] = "sin(cos(tan(x)))";
  // char str_start[MAX_SIZE] = "asin(acos(atan(x)))";
  // char str_start[MAX_SIZE] =
  // "x*cos(x)+(+1)+(22*11-(3+2)*5.5+(-1)*sin(30)-2.+.3)/2.*x";
  // const char str_start[MAX_SIZE] =
  // "xmodcos(x)+(+1)+(22mod11-(3+2)*5.5+(-1)modsin(30)-2.+.3)/2.modx";
  // char *str = *(&str_start);

  int err = OK;
  err = calc(str_start, x, &result);

  printf("\033[107m\033[1;92mresult\033[0m = \033[1;92m%g\033[0m\n", result);
  if (err != 0) {
    printf("\033[107m\033[1;91merror \033[0m = \033[1;91m%d\033[0m\n", err);
  }
  return 0;
}
