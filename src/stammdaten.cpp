//this is c only, no c++
#include"stammdaten.h"
#include"stdlib.h"
#include"stdio.h"
#include"string.h"

void listPrintElement(stammdaten list){
  printf("Name: %s, %s\nGeburtstag: %i\nIdentifikationsnummer: %04d\n", list->last_name, list->first_name, list->birth, list->id);
}


stammdaten listInsertElement(stammdaten list, char const *_last_name, char const *_first_name, int _id, int _birth){
  stammdaten newUser = (stammdaten)malloc(sizeof(list_stammdaten));
  // if not a new list 
  if ( list ){
    newUser->prev = list;
    newUser->next = list->next;
    list->next = newUser;
    //if not last
    if( newUser->next ){
      newUser->next->prev = newUser;
    }
    else{
      newUser->next = nullptr;
    }
  }
  else{
    newUser->next = nullptr;
    newUser->prev = nullptr;
  } 
  strcpy(newUser->last_name, _last_name);
  strcpy(newUser->first_name, _first_name);
  newUser->id = _id;
  newUser->birth = _birth;

  return newUser;
}

//find first element in list
stammdaten listFirstElement(stammdaten list){
  while( list->prev ){
    list = list->prev;
  }
  return list;
}

void listDeleteElement(stammdaten date){
  //if middle
  if( date->next && date->prev){
    date->prev->next = date->next;
    date->next->prev = date->prev;
 }
  //if last 
  else if( date->prev ){
    date->prev->next = nullptr;
  }
  //if first
  else if( date->next ){
    date->next->prev = nullptr;
  }
  free(date);
}

//free complete list
void listFree(stammdaten list){
  //jump to first element
  list = listFirstElement(list);
  //delete all elements from left to right
  while(list){
    stammdaten next = list->next;
    free(list);
    list = next;
  }
}

//print complete list
void listPrintList(stammdaten list){
  list = listFirstElement(list);
  while( list ){
    listPrintElement(list);
    list = list->next;
  }
}

int listCountElements(stammdaten list){
  list = listFirstElement(list);
  int counter = 0;
  while( list ){
    counter++;
    list = list->next;
  }
  return counter;
}

//returns nullptr if element with id does not exist
stammdaten listFindElement(stammdaten list, int id){
  list = listFirstElement(list);
  while(list && list->id != id){
    list=list->next;
  }
  return list;
}

int listWriteToDisk(stammdaten list, const char *filename){
  FILE *file = fopen(filename, "w");
  if( !file ){
    printf("Error opening file!\n");
    return 1;
  }
  list = listFirstElement(list);
  while(list){
    fprintf(file, "%s,%s,%d,%d\n",list->last_name, list->first_name, list->birth, list->id);
  list = list->next;
  }
  fclose(file);
  return 0;
}

stammdaten listReadFromDisk(const char *filename){
  FILE *file = fopen(filename, "r");
  stammdaten stammdatenList = nullptr;
  if( !file ){
    printf("Error opening file!\n");
    return stammdatenList;
  }
  char *line;
  size_t len;
  //getline(&buffer,&size,stdin);
  while ( (getline(&line, &len,file)) != -1 ){
    char first_name[50];
    char last_name[50];
    int birth;
    int id;
    sscanf(line, "%[^,],%[^,],%d,%d", first_name, last_name, &birth, &id);
    stammdatenList = listInsertElement(stammdatenList, last_name, first_name, id, birth);
  }
  //tidy up!
  free(line);
  fclose(file);
  //as we dont call free() it is ok to just return one of the list
  return listFirstElement(stammdatenList);
}






