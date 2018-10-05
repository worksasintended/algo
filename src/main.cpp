#include<iostream>

#if TASK1_1
#include"stammdaten.h"
#endif
int main(int argc, char** argv){

#if TASK1_1
  //c style solution called in c++
  std::cout << "TASK 1_1" << std::endl << "-------------------------------------" << std::endl;

  //init first element of list, same as adding to nullptr
  stammdaten initUser = listInsertElement(nullptr, "Marschall", "Marc", 1, 19001114);
  std::cout << "This is the first element of the list:" << std::endl ;
  listPrintElement(initUser);

  //append element 
  stammdaten user2 = listInsertElement(initUser, "Marschall", "Pia", 2, 19940108);
  listInsertElement(user2, "Marschall", "Jul", 3, 20151224);
  std::cout << std::endl << "These are all elements after adding additional users" << std::endl;
  listPrintList(user2); 

  //print number of elements
  std::cout << std::endl << "Current number of elements in the list: " << listCountElements(user2) << std::endl;

  //search for element containing id
  std::cout << std::endl << "Searching for user with id 0002: " << std::endl;
  listPrintElement(listFindElement(initUser, 2));

  //delete elemente
  listDeleteElement(initUser);
  std::cout << std::endl << "These are all elements after removing first list element" << std::endl;
  listPrintList(user2);
  
  //write on disk
  const char* filename = "list_stammdaten.dat";
  if(!listWriteToDisk(user2, filename)){
    std::cout << std::endl << "List has been written to " << filename << std::endl; 
  }

  //readFromDisk
  stammdaten newList = listReadFromDisk("list_stammdaten.dat");
  std::cout << std::endl << "List read from 'list_stammdaten.dat' at disk: " << std::endl;
  listPrintList(newList); 

  //free lists
  std::cout << std::endl << "Free the lists!" << std::endl;
  listFree(user2);
  listFree(newList);
#endif

  return 0;
}
