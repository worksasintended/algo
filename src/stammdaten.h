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





void listFree(stammdaten list);

void listPrintElement(stammdaten list);

stammdaten listInsertElement(stammdaten list, char const *_last_name, char const *_first_name, int _id, int _birth);

void listDeleteElement(stammdaten);

stammdaten listFirstElement(stammdaten list);

stammdaten listFindElement(stammdaten list, int id);

int listCountElements(stammdaten list);

void listPrintList(stammdaten list);

int listWriteToDisk(stammdaten list, const char *filename);

stammdaten listReadFromDisk(const char *filename);


