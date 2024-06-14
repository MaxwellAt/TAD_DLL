#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "DLL.h"

typedef struct {
    char nome[30];
    int idade;
    float nota;
} Student;

void listarStudents(DLList *lista){
    int ind = 0;
    Student *var = (Student*) dllGetFirst(lista);
    if(var != NULL){
        do{
            printf("Student %d: \n",ind + 1);
            printf("Nome: %s ,Idade: %d ,Nota: %.2f \n", var->nome, var->idade, var->nota);
            var = (Student*)dllGetNext(lista);
            ind++;
        }while(var != NULL);
    }else{
        printf("----------Lista vazia--------\n");
    }
}

int cmp(void* a, void* b){
    Student *pa = (Student *) a;
    Student *pb = (Student*) b;
    if(pa != NULL && pb != NULL){
        if(strcmp(pa->nome,pb->nome) == 0 && pa->idade == pb->idade && pa->nota == pb->nota){
            return TRUE;
        }
        return FALSE;
    }
    return -1;
}

int listaClean(DLList* lista){
    if(lista != NULL){
        while(dllRemoveLast(lista) != NULL);
        return TRUE;
    }
    return FALSE;
}

int main(){
    DLList *lista = NULL;

    do{
        printf("1 - Criar lista \n");
        printf("2 - Inserir um estudante \n");
        printf("3 - Remover um estudante \n");
        printf("4 - Consultar um estudante \n");
        printf("5 - Listar os estudantes \n");
        printf("6 - Destruir a lista \n");
        printf("7 - Esvaziar a lista \n");
        printf("0 - Sair \n");
        printf("Deseja realizar qual operacao? \n ");

        int opcao;
        scanf("%d", &opcao);
        switch(opcao){
            case 1:{
                if(lista!= NULL){
                    printf("Lista já criada\n");
                    printf("Primeiro destrua a lista anterior\n");
                    printf("\n");
                    break;
                }
                lista = dllCreate();
                if(lista != NULL){
                    printf("Lista criada com sucesso!\n");
                    printf("\n");
                }else{
                    printf("Não foi possível criar a lista. Tente novamente. \n");
                    printf("\n");
                }
                break;
            }
            case 2:{
                Student *student = (Student *) malloc(sizeof(Student));
                if(lista != NULL && student != NULL){
                    printf("Nome: ");
                    scanf("%s", student->nome);
                    printf("Idade: ");
                    scanf("%d", &student->idade);
                    printf("Nota: ");
                    scanf("%f", &student->nota);
                    if(dllInsertAsLast(lista, student) == TRUE){
                        printf("Estudante inserido com sucesso\n");
                        printf("\n");
                    }else{
                        printf("Erro ao inserir estudante\n");
                        printf("\n");
                    }
                }else{
                    printf("Lista não criada\n");
                    printf("\n");
                }
                break;
            }
            case 3:{
                Student *student = (Student *) malloc(sizeof(Student));
                if(lista != NULL && student != NULL){
                    printf("Nome: ");
                    scanf("%s", student->nome);
                    printf("Idade: ");
                    scanf("%d", &student->idade);
                    printf("Nota: ");
                    scanf("%f", &student->nota);
                    if(dllRemoveSpec(lista, student, cmp) != NULL){
                        printf("Estudante removido com sucesso! \n");
                        printf("\n");
                    }else{
                        printf("Estudante não encontrado\n");
                        printf("\n");
                    }
                }else{
                    printf("Lista não criada\n");
                    printf("\n");
                }
                break;
            }
            case 4:{
                Student *student = (Student*) malloc(sizeof(Student));
                if(lista != NULL && student != NULL){
                    printf("Nome: ");
                    scanf("%s", student->nome);
                    printf("Idade: ");
                    scanf("%d", &student->idade);
                    printf("Nota: ");
                    scanf("%f", &student->nota);

                    Student *chave = (Student*) dllQuerySpec(lista, student, cmp);
                    if(chave != NULL){
                        printf("Estudante encontrado ! \n");
                        printf("Nome: %s, Idade: %d, Nota: %.2f \n", chave->nome, chave->idade, chave->nota);
                        printf("\n");
                    }else{
                        printf("Estudante não encontrado \n");
                        printf("\n");
                    }
                }else{
                    printf("Lista não criada\n");
                    printf("\n");
                }
                break;
            }
            case 5:{
                if(lista != NULL){
                    printf("Aqui estão os estudantes da lista: \n");
                    listarStudents(lista);
                    printf("\n");
                }else{
                    printf("Lista não criada\n");
                    printf("\n");
                }
                break;
            }
            case 6:{
                if(lista != NULL){
                    if(dllDestroy(lista) == TRUE){
                        printf("Lista destruída\n");
                        printf("\n");
                        lista = NULL;
                    }else{
                        printf("Lista não destruída\n");
                        printf("\n");
                    }
                }else{
                    printf("Lista não criada\n");
                    printf("\n");
                }
                break;
            }
            case 7:{
                if(lista != NULL){
                    if(listaClean(lista) == TRUE){
                        printf("Lista esvaziada\n");
                        printf("\n");
                    }else{
                        printf("Lista não esvaziada\n");
                        printf("\n");
                    }
                }else{
                    printf("Lista não criada\n");
                    printf("\n");
                }
                break;
            }
            case 0:{
                printf("Sistema encerrado com sucesso! \n");
                return 0;
            }
            default:{
                printf("Opção inválida \n");
                printf("\n");
                break;
            }
        }
    }while(TRUE);

}