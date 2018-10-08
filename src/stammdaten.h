 struct list_stammdaten{
    char last_name[64];
    char first_name[64];
    int birth;
    int id;
    struct list_stammdaten* prev;
    struct list_stammdaten* next;
};
typedef struct list_stammdaten list_stammdaten;
typedef list_stammdaten* stammdaten;
struct list_S{
  stammdaten first;
  stammdaten last;
};
typedef struct list_S list_S;
typedef list_S* list; //dont use namespace std!!



void listFree(list list);

void listPrintElement(stammdaten list);

stammdaten listInsertElement(list list, char const *_last_name, char const *_first_name, int _id, int _birth);

void listDeleteElement(list list, stammdaten elem);

stammdaten listFindElement(list list, int id);

int listCountElements(list list);

void listPrintList(list list);

int listWriteToDisk(list list, const char *filename);

list listReadFromDisk(const char *filename);


