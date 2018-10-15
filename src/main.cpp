#include<iostream>

#if TASK1_1
#include"stammdaten.h"
#endif
#if TASK1_2
#include"stammdaten_array.h"
#endif
int main(int argc, char** argv){

#if TASK1_1
  //c style solution called in c++
  std::cout << "TASK 1_1" << std::endl << "-------------------------------------" << std::endl;
  //create list
  list myList = (list)malloc(sizeof(list_S));
  myList->first = nullptr;
  myList->last = nullptr;
  //add first element to list
  stammdaten initUser = listInsertElement(myList, "Marschall", "Marc", 1, 19001114);
  std::cout << "This is the first element of the list:" << std::endl ;
  listPrintElement(initUser);
  //append element 
  listInsertElement(myList, "Marschall", "Pia", 2, 19940108);
  listInsertElement(myList, "Marschall", "Jul", 3, 20151224);
  listInsertElement(myList, "Marschall", "Kevin", 4, 20151224);
  listInsertElement(myList, "Marschall", "Tom", 5, 20151224);
  std::cout << std::endl << "These are all elements after adding additional users" << std::endl;
  listPrintList(myList); 
  //print number of elements
  std::cout << std::endl << "Current number of elements in the list: " << listCountElements(myList) << std::endl;

  //search for element containing id
  std::cout << std::endl << "Searching for user with id 0002: " << std::endl;
  listPrintElement(listFindElement(myList, 2));
  //delete elemente
  listDeleteElement(myList, initUser);
  listDeleteElement(myList, listFindElement(myList, 5));
  listDeleteElement(myList, listFindElement(myList, 3));
  listDeleteElement(myList, listFindElement(myList, 3));
  std::cout << std::endl << "These are all elements after removing first list element" << std::endl;
  listPrintList(myList);

  //write on disk
  const char* filename = "list_stammdaten.dat";
  if(!listWriteToDisk(myList, filename)){
    std::cout << std::endl << "List has been written to " << filename << std::endl; 
  }

  //readFromDisk
  list newList = listReadFromDisk("list_stammdaten.dat");
  std::cout << std::endl << "List read from 'list_stammdaten.dat' at disk: " << std::endl;
  listPrintList(newList); 

  //free lists
  std::cout << std::endl << "Free the lists!" << std::endl;
  listFree(myList);
  listFree(newList);
#endif

#if TASK1_2
 sdata dataset[20];
 for(auto sdate:dataset){
   sdate = (sdata)malloc(sizeof(sdataS));
   sdate->next = -1;
   sdate->prev = -1;
 }
 
 for(auto sdate:dataset){
  free(sdate);
 } 
#endif



  return 0;
}
