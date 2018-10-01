#include<string>
struct list_stammdaten{
    std::string last_name;
    std::string first_name;
    int birth;
    int id;
    struct stammdaten *prev=NULL;
    struct stammdaten *next=NULL;
    ~list_stammdaten(){ }
};


//void printElement();
//void insertElement();
//void deleteElement();
//int findElement();
//int countElements();
//void printList();
//void writeToDisk();
//struct stammdaten readFromDisk();


