#include"stammdaten.h"
#include<iostream>
#include<string>
int main(int argc, char** argv){
#if TASK1_1
  std::cout << "TASK 1_1" << std::endl;
  struct list_stammdaten user1; //funktioniert
  struct list_stammdaten* user2 = (struct list_stammdaten*)malloc(sizeof(struct list_stammdaten)); //memory leak??
#endif
  return 0;
}
