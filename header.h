

struct Gestion
{
    char mat[4];
    char name[20];
    int yearEngage;
    int sBase;
    int lasted;
    int children;
    int sExact;
};

typedef struct Gestion Ges;

// Prototype of creating function
int createEmployer(Ges *g);

// Prototype of printing function
void printEmployer(Ges *g, int taille);

// Prototype of printing employer who have any children
void printFatherEmployer(Ges *g, int taille);

// Prototype of printing old employer
void printOldEmployer(Ges *g, int taille);

// Prototype of searching employer
void searchEmployer(Ges *g, char *mat, int taille);

// Prototype of sort ascending
void sortEmployer(Ges *g, int taille);

// Prototype of exchange two values
void exchange(Ges *a, Ges *b);

// Prototype of scanSingleEmployer
void scanSingleEmployer(Ges *elem);

// Prototype of inserting function
int insertEmployer(Ges *g, Ges elem, int taille);

// Prototype of deleting an employer
int deleteEmployer(Ges *g, char *mat, int taille);

// Prototype of cleaner of buffer
int readString(char *chaine, int taille);
void cleanBuffer();