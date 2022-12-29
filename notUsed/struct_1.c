#include <stdio.h>
#include <stdlib.h>

// https://learnc.info/c/structures.html
// https://habr.com/ru/company/first/blog/672464/

#define MAX_SIZE 255

//Определяем новую структуру
struct processor {
  char processor_producer[MAX_SIZE];
  char processor_model[MAX_SIZE];
  int processor_frequency;
  int processor_number_of_cores;
};

//Определяем новую структуру
typedef struct videocard {
  char *videocard_producer;
  char *videocard_model;
  int video_memory;
} videocard_t;

//Определяем новый тип
typedef struct processor Proc;

int main() {
  //Обращение через имя структуры
  struct processor intel = {"Intel", "Core i9 13900K", 5800, 24};

  printf("--------------------\n");
  printf("\033[107m\033[1;91mПроцессор - инфо:\033[0m\n");
  printf("\033[35mПроизводитель:\033[0m %s.\n", intel.processor_producer);
  printf("\033[35mМодель:\033[0m %s.\n", intel.processor_model);
  printf("\033[35mЧастота процессора:\033[0m %d МГц.\n",
         intel.processor_frequency);
  printf("\033[35mКоличество ядер:\033[0m %d.\n",
         intel.processor_number_of_cores);
  printf("--------------------\n");

  //Обращение через имя структуры
  videocard_t video = {.videocard_producer = "Asus",
                       .videocard_model = "GeForce 1660",
                       .video_memory = 12};

  printf("--------------------\n");
  printf("\033[40m\033[1;97mВидеокарта - инфо:\033[0m\n");
  printf("Производитель: %s.\n", video.videocard_producer);
  printf("Модель: %s.\n", video.videocard_model);
  printf("Частота процессора: %d ГГц.\n", video.video_memory);
  printf("--------------------\n");

  getchar();

  //Обращение через новый тип
  Proc amd = {"AMD", "Ryzen 9 7900X", 5600, 12};

  printf("--------------------\n");
  printf("\033[107m\033[1;97mПроцессор - инфо:\033[0m\n");
  printf("Производитель: %s.\n", amd.processor_producer);
  printf("Модель: %s.\n", amd.processor_model);
  printf("Частота процессора: %d МГц.\n", amd.processor_frequency);
  printf("Количество ядер: %d.\n", amd.processor_number_of_cores);
  printf("--------------------\n");

  Proc mediatek = {"Mediatek", "Helio G99", 2200, 8};

  printf("--------------------\n");
  printf("\033[107m\033[1;92mПроцессор - инфо:\033[0m\n");
  printf("Производитель: %s.\n", mediatek.processor_producer);
  printf("Модель: %s.\n", mediatek.processor_model);
  printf("Частота процессора: %d МГц.\n", mediatek.processor_frequency);
  printf("Количество ядер: %d.\n", mediatek.processor_number_of_cores);
  printf("--------------------\n");

  return 0;
}
