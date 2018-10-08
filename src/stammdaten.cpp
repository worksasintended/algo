//this is c only, no c++
#include"stammdaten.h"
#include"stdlib.h"
#include"stdio.h"
#include"string.h"

void listPrintElement(stammdaten list){
  printf("Name: %s, %s\nGeburtstag: %i\nIdentifikationsnummer: %04d\n", list->last_name, list->first_name, list->birth, list->id);
}


stammdaten listInsertElement(list list, char const *_last_name, char const *_first_name, int _id, int _birth){
  stammdaten newUser = (stammdaten)malloc(sizeof(list_stammdaten));
  // if not a new list 
  if ( list->first ){
    newUser->prev = list->last;
    newUser->next = nullptr;
    list->last->next = newUser;
    list->last = newUser;
  }
  else{
    newUser->next = nullptr;
    newUser->prev = nullptr;
    list->first = newUser;
    list->last = newUser;
  } 
  strcpy(newUser->last_name, _last_name);
  strcpy(newUser->first_name, _first_name);
  newUser->id = _id;
  newUser->birth = _birth;

  return newUser;
}
void listDeleteElement(list list, stammdaten elem){
  //check for nullptr
  if(list && elem){
    //if in middle
    if(elem->next && elem->prev){
      elem->prev->next = elem->next;
      elem->next->prev = elem->prev;
    }
    //if last
    else if(elem->prev){
      elem->prev->next = nullptr;
      list->last = elem->prev;
    }
    //if fist
    else{
      elem->next->prev = nullptr;
      list->first = elem->next;
    }
  }
  free(elem);
}
//free complete list
void listFree(list list){
  stammdaten elem = list->first;
  while(elem){
    stammdaten next = elem->next;
    free(elem);
    elem = next;
  }
  free(list);
}
//print complete list
void listPrintList(list list){
  stammdaten elem = list->first;
  while( elem ){
    listPrintElement(elem);
    elem = elem->next;
  }
}


int listCountElements(list list){
  stammdaten elem = list->first;
  int counter = 0;
  while( elem ){
    counter++;
    elem = elem->next;
  }
  return counter;
}


//returns nullptr if element with id does not exist
stammdaten listFindElement(list list, int id){
  stammdaten elem = list->first;
  while(elem && elem->id != id){
    elem=elem->next;
  }
  return elem;
}

int listWriteToDisk(list list, const char *filename){
  FILE *file = fopen(filename, "w");
  if( !file ){
    printf("Error opening file!\n");
    return 1;
  }
  stammdaten elem = list->first;
  while(elem){
    fprintf(file, "%s,%s,%d,%d\n",elem->last_name, elem->first_name, elem->birth, elem->id);
  elem = elem->next;
  }
  fclose(file);
  return 0;
}

list listReadFromDisk(const char *filename){
  FILE *file = fopen(filename, "r");
  list myList  = (list)malloc(sizeof(list_S));
  myList->last = nullptr;
  myList->first = nullptr;
  if( !file ){
    printf("Error opening file!\n");
    return myList;
  }
  char *line;
  size_t len;
  //getline(&buffer,&size,stdin);
  while ( (getline(&line, &len,file)) != -1 ){
    char first_name[64];
    char last_name[64];
    int birth;
    int id;
    sscanf(line, "%[^,],%[^,],%d,%d", first_name, last_name, &birth, &id);
    listInsertElement(myList, last_name, first_name, id, birth);
  }
  //tidy up!
  free(line);
  fclose(file);
  return myList;
}





