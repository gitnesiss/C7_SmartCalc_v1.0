#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// https://learnc.info/c/structures.html
// https://learnc.info/adt/stack.html
// https://www.bestprog.net/ru/2017/05/19/
// https://habr.com/ru/post/341586/
// https://intellect.icu/steki-na-primere-yazyka-si-4497
// https://learnc.info/adt/linked_list.html - односвязный список

// https://codechick.io/tutorials/dsa/dsa-stack

#define YEAR_OFFSET 1890

typedef struct model {
  int id;
  struct {
    int id;
    char *name;
  } make;
  char *name;
  unsigned char year;
  ;
} Model;

char *mallocByString(const char *str) {
  char *p = (char *)malloc(strlen(str) + 1);
  strcpy(p, str);
  return p;
}

void freeModel(Model *model) {
  free(model->make.name);
  free(model->name);
}

void xmlModel(Model *model) {
  printf(
      "<model id=\"%d\">\n"
      "  <make id=\"%d\">\n"
      "    <name>%s</name>\n"
      "  </make>\n"
      "  <year>%d</year>\n"
      "  <name>%s</name>\n"
      "</model>",
      model->id, model->make.id, model->make.name, model->year, model->name);
}

int main() {
  Model cl;
  cl.id = 1;
  // cl.make.id

  return 0;
}