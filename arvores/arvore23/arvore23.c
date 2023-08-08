#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura para armazenar os dados da arvore
typedef struct {
    int Info1, Info2;
    Arv23 esq, centro, dir;
    int nInfos
} Arv23;

Arv23 * insereArv23(Arv23 **Raiz, int Info, Arv23*Pai, int *sobe){
    Arv23 MaiorNo;
    MaiorNo = NULL;
    if(*Raiz == NULL){
        *Raiz = criaNo(Info, NULL, NULL, NULL);
    } else{
        if(ehfolha(*Raiz)){
            if((*Raiz)->nInfos == 1)
                adicionaNO(Raiz, Info, NULL);
            else{
                MaiorNo = quebraNo(Raiz, Info, sobe, NULL);
            if(Pai == NULL){
                *Raiz = criaNO(sobe, *Raiz, MaiorNo, NULL);
                MaiorNo = NULL;
            }
        } elseif(Info < (*Raiz)->Info1)
            MaiorNo = insereArv23(&((*Raiz)->esq), Info, *Raiz, sobe);
            elseif((((*Raiz)->nInfos) == 1) || (((*Raiz)->nInfos) == 2) && Info < (*Raiz)->Info2)
                MaiorNo = insereArv23 (&((*Raiz)->centro), Info, *Raiz, sobe);
                else
                    MaiorNo = insereArv23(&((*Raiz)->dir), Info, *Raiz, sobe);   
        if (MaiorNo != NULL){
            if((*Raiz)->nInfos == 1){
                adicionaNO(Raiz, *sobe, MaiorNo);
                MaiorNo = NULL;
            }
        }else{
            int SobeNovo;
            MaiorNo = quebraNo(Raiz, sobe, &SobeNovo, MaiorNo);
            if(Pai == NULL){
                *Raiz = criaNo(SobeNovo, *Raiz, MaiorNo, NULL);
                MaiorNo = NULL;
            }
        }
    }
    return MaiorNo;
}

Arv23 criaNo(int Info, Arv23 esquerda, Arv23 direita, Arv23 centro){

}