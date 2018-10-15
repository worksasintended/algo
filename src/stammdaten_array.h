 struct sdataS{
    char last_name[64];
    char first_name[64];
    int birth;
    int id;
    int prev;
    int next;
};
typedef struct sdataS sdataS;
typedef sdataS* sdata;

/*
void listFree(list list);

void listPrintElement(stammdaten list);

stammdaten listInsertElement(list list, char const *_last_name, char const *_first_name, int _id, int _birth);

void listDeleteElement(list list, stammdaten elem);

stammdaten listFindElement(list list, int id);

int listCountElements(list list);

void listPrintList(list list);

int listWriteToDisk(list list, const char *filename);

list listReadFromDisk(const char *filename);

*/
