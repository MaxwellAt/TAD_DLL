#ifndef DLL_H
#define DLL_H
#define TRUE 1
#define FALSE 0

typedef struct dllNode {
    struct dllNode *prev;
    void* data;
    struct dllNode *next;
} DLLNode;

typedef struct sLList {
    DLLNode* first;
    DLLNode* cur;
} DLList;

DLList *dllCreate ();
int dllDestroy (DLList *l);
void *dllRemoveLast(DLList *l);
void *dllQuerySpec(DLList *l, void *key, int (*cmp)(void *, void *));
int dllInsertAsFirst ( DLList *l, void *data);
void *dllGetFirst(DLList *l);
void *dllGetNext(DLList *l);
int dllInsertAsLast(DLList *l, void *data);
int dllInsertAfterSpec( DLList *l, void *key, void *data, int (*cmp)(void *, void *));
void * dllRemoveSpec( DLList *l, void *key, int (*cmp)(void *, void *));



#endif //DLL_H
