#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PER        \
  struct {         \
    int age;       \
    char name[20]; \
  }

typedef struct {
  int age;
  char *name;
} personage;

struct date {
  int day_num;
  char month_name[20];
  int year_num;
};

struct person {
  char first_name[20];
  char second_name[20];
  struct date bd;
};

struct company {
  char name[20];
  char country[30];
};
struct smartphone {
  char title[20];
  int price;
  struct company manufacturer;
};

struct personal {
  int age;
  char name[20];
};

struct time {
  int hour;
  int minute;
  int second;
};
struct time addminutes(struct time, int);

// прототип функции
void addminutes_new(struct time *, int);

// прототип функции
struct time *input(void);

int main() {
  struct person p = {"Rom", "Tom-tom", {5, "july", 1990}};
  printf("First name: %s Second name: %s \t Birthday: %d - %s - %d.\n",
         p.first_name, p.second_name, p.bd.day_num, p.bd.month_name,
         p.bd.year_num);

  personage bottom = {20, "Bottom"};
  printf("Name: %s \t Age: %d\n", bottom.name, bottom.age);
  PER alice = {23, "Alice"};
  printf("Name: %s \t Age: %d\n", alice.name, alice.age);

  // struct smartphone phone;  // = {"iPhone 8", 56000, {"Apple", "USA"}};
  // printf("Enter phone title: ");
  // scanf("%20s", phone.title);
  // printf("Enter price: ");
  // scanf("%d", &phone.price);
  // printf("Enter manufacturer: ");
  // scanf("%s", phone.manufacturer.name);
  // printf("Enter country: ");
  // scanf("%s", phone.manufacturer.country);
  // printf("\nPhone: %s \n", phone.title);
  // printf("Price: %d \n", phone.price);
  // printf("Manufacturer: %s \n", phone.manufacturer.name);

  printf("\n\n");
  struct personal people[] = {
      {23, "Tom"}, {32, "Bob"}, {26, "Alice"}, {41, "Sam"}};
  int n = sizeof(people) / sizeof(people[0]);
  printf("n = %d\n", n);
  for (int i = 0; i < n; i++) {
    printf("Name:%s \t Age: %d \n", people[i].name, people[i].age);
  }
  printf("\n");
  for (struct personal *p = people; p < people + n; p++) {
    printf("Name:%s \t Age: %d \n", p->name, p->age);
  }

  printf("\n\n");
  struct time current_time = {17, 38, 10};
  int minutes = 21;

  struct time result_time = addminutes(current_time, minutes);
  printf("%02d:%02d:%02d \n", result_time.hour, result_time.minute,
         result_time.second);

  result_time = addminutes(current_time, 23);
  printf("%02d:%02d:%02d \n", result_time.hour, result_time.minute,
         result_time.second);

  result_time = addminutes(current_time, 382);
  printf("%02d:%02d:%02d \n", result_time.hour, result_time.minute,
         result_time.second);

  printf("\n\n");
  // struct time current_time = {17, 38, 10};
  struct time *p_time = &current_time;
  addminutes_new(p_time, 21);
  printf("В функцию передаётся указатель на структуру.\n");
  printf("In main \t %02d:%02d:%02d \n", current_time.hour, current_time.minute,
         current_time.second);

  printf("\n\n");
  struct time *p_time_n = input();
  printf("%02d:%02d:%02d \n", p_time_n->hour, p_time_n->minute,
         p_time_n->second);

  free(p_time_n);  // освобождаем память

  return 0;
}

struct time addminutes(struct time t, int minutes) {
  struct time result = {t.hour, t.minute, t.second};
  int h, d;
  // прибавляем минуты
  result.minute += minutes;
  // если минут больше 59, делим на 60
  if (result.minute >= 60) {
    h = result.minute / 60;
    // от минут вычитаем 60 * h
    result.minute -= 60 * h;
    // к часам прибавляем h
    result.hour += h;
  }
  // если часов больше 23, делим на 24
  if (result.hour >= 24) {
    d = result.hour / 24;
    // от часов вычитаем d * 24
    result.hour -= 24 * d;
  }
  return result;
}

void addminutes_new(struct time *t, int minutes) {
  int h, d;
  // прибавляем минуты
  t->minute += minutes;
  // если минут больше 59, делим на 60
  if (t->minute >= 60) {
    h = t->minute / 60;
    // от минут вычитаем 60 * h
    t->minute -= 60 * h;
    // к часам прибавляем h
    t->hour += h;
  }
  // если часов больше 23, делим на 24
  if (t->hour >= 24) {
    d = t->hour / 24;
    // от часов вычитаем d * 24
    t->hour -= 24 * d;
  }
  printf("In addminutes \t %02d:%02d:%02d \n", t->hour, t->minute, t->second);
}

struct time *input() {
  // выделяем память для структуры
  struct time *p_time = (struct time *)malloc(sizeof(struct time));
  // ввод значений
  printf("Enter hour: ");
  scanf("%d", &p_time->hour);
  printf("Enter minutes: ");
  scanf("%d", &p_time->minute);
  printf("Enter seconds: ");
  scanf("%d", &p_time->second);

  return p_time;
}