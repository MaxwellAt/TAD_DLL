#include "DLL.h"
#include <stdlib.h>

DLList *dllCreate (){
    DLList *l;
    l = (DLList *) malloc ( sizeof (DLList ));
    if(l != NULL){
        l->first = NULL;
        l->cur = NULL;
        return l;
    }else{
        return NULL;
    }
}

int dllDestroy (DLList *l){
    if(l != NULL && l->first == NULL){
        free(l);
        return TRUE;
    }else{
        return FALSE;
    }
}
void *dllRemoveLast(DLList *l){
    if(l != NULL){
        if(l->first == NULL){
            return NULL;
        }else if(l->first->next == NULL){
            void *data = l->first->data;
            free(l->first);
            l->first = NULL;
            return data;
        }else{
            DLLNode *curNode = l->first;
            while(curNode->next->next != NULL){
                curNode = curNode->next;
            }
            void *data = curNode->next->data;
            free(curNode->next);
            curNode->next = NULL;
            if(curNode->prev != NULL){
                curNode->prev->next = NULL;
            }
            return data;
        }
    }
    return NULL;
}
void *dllQuerySpec(DLList *l, void *key, int (*cmp)(void *, void *)){
    if(l != NULL){
        DLLNode *curNode = l->first;
        while(curNode != NULL){
            if(cmp(curNode->data, key) == TRUE){
                return curNode->data;
            }
            curNode = curNode->next;
        }
    }
    return NULL;
}
int dllInsertAsFirst (DLList *l, void *data){
    if(l != NULL){
        DLLNode *newNode = (DLLNode*)malloc(sizeof(DLLNode));
        if(newNode != NULL){
            newNode->data = data;
            newNode->next = l->first;
            newNode->prev = NULL;
            if(l->first != NULL){
                l->first->prev = newNode;
            }
            l->first = newNode;
            return TRUE;
        }
    }
    return FALSE;
}

void *dllGetFirst(DLList *l){
    if(l != NULL){
        l->cur = l->first;
        if(l->cur != NULL){
            return l->cur->data;
        }
    }
    return NULL;
}

void *dllGetNext(DLList *l){
    if(l != NULL){
        if(l->cur != NULL){
            l->cur = l->cur->next;
            if(l->cur != NULL){
                return l->cur->data;
            }
        }
    }
    return NULL;
}

int dllInsertAsLast(DLList *l, void *data){
    if(l != NULL){
        DLLNode *newNode = (DLLNode*)malloc(sizeof(DLLNode));
        if(newNode != NULL){
            newNode->data = data;
            newNode->next = NULL;
            if(l->first == NULL){
                newNode->prev = NULL;
                l->first = newNode;
            }else{
                DLLNode *lastNode = l->first;
                while(lastNode->next != NULL){
                    lastNode = lastNode->next;
                }
                newNode->prev = lastNode;
                lastNode->next = newNode;
            }
            return TRUE;
        }
    }
    return FALSE;
}

int dllInsertAfterSpec( DLList *l, void *key, void *data, int (*cmp)(void *, void *)){
    if(l != NULL){
        if(l->first == NULL){
            return -1;
        }
        DLLNode *curNode = l->first;
        while(curNode != NULL){
            if(cmp(curNode->data, key) == TRUE){
                DLLNode *newNode = (DLLNode*)malloc(sizeof(DLLNode));
                if(newNode != NULL){
                    newNode->data = data;
                    newNode->next = curNode->next;
                    newNode->prev = curNode;
                    if(curNode->next != NULL){
                        curNode->next->prev = newNode;
                    }
                    curNode->next = newNode;
                    return TRUE;
                }
                return FALSE;
            }
            curNode = curNode->next;
        }
    }
    return FALSE;
}

void * dllRemoveSpec( DLList *l, void *key, int (*cmp)(void *, void *)){
    if(l != NULL){
        if(l->first == NULL){
            return NULL;
        }
        DLLNode *curNode = l->first;
        while(curNode != NULL){
            if(cmp(curNode->data, key) == TRUE){
                DLLNode *prevNode = curNode->prev;
                DLLNode *nextNode = curNode->next;

                if (prevNode != NULL) {
                    prevNode->next = nextNode;
                } else {
                    l->first = nextNode;
                }

                if (nextNode != NULL) {
                    nextNode->prev = prevNode;
                }

                void *data = curNode->data;
                free(curNode);
                return data;
            }
            curNode = curNode->next;
        }
    }
    return NULL;
}

