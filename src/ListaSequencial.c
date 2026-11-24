#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaSequencial.h"

struct lista{

    int qtd;
    struct aluno dados[MAX];
};
// Guarda quantos elementos existem atualmente (qtd) na lista e o vetor de capacidade máxima MAX


Lista *cria_lista(){

    Lista *li;

    li = (Lista*) malloc(sizeof(struct lista));

    if (li != NULL){
        li->qtd = 0;
    }

    return li;
}
// Criamos a lista de fato, chamamos ela de "li". Aloca memória para a struct lista, verifica se deu certo, zera qtd e retorna o ponteiro li
// Ocorre a verificação se a lista foi criada, se sim, inicializamos a quantidade de itens em 0. (lista vazia)


void libera_lista(Lista *li){

    free(li);

}

int lista_nao_existe(Lista *li){

    return (li == NULL);
}

int lista_cheia(Lista *li){

    if (li == NULL){
        return -1;
    }

    return (li->qtd == MAX);
    // Retorna 1 (verdadeiro) se li->qtd == MAX, ou 0 (falso) caso contrário
}

int lista_vazia(Lista *li){

    if (li == NULL){
        return -1;
    }

    return (li->qtd == 0);
    // Retorna 1 (verdadeiro) se li->qtd == 0, ou 0 (falso) caso contrário (lista contém itens)
}

int lista_tamanho(Lista *li){

    if (li == NULL) {
        return -1;
    }

    return li->qtd;

}

// Retorna 1 se ja existe um aluno com essa matricula na lista, 0 caso contrario
static int matricula_existe(Lista *li, int mat){

    for(int i = 0; i < li->qtd; i++){
        if(li->dados[i].matricula == mat){
            return 1;
        }
    }

    return 0;
}

int lista_insere_final(Lista *li, struct aluno al){

    if (li == NULL){
        return -1;
    }

    if (lista_cheia(li)){
        return 0;
    }

    if (matricula_existe(li, al.matricula)){
        return 2; // matricula duplicada
    }

    li->dados[li->qtd] = al;
    li->qtd++;

    return 1;
}

int lista_insere_inicio(Lista *li, struct aluno al){

    if (li == NULL){
        return -1;
    }

    if (lista_cheia(li)){
        return 0;
    }

    if (matricula_existe(li, al.matricula)){
        return 2; // matricula duplicada
    }

    for(int i = li->qtd - 1; i >= 0; i--){
        li->dados[i + 1] = li->dados[i];
    }

    li->dados[0] = al;
    li->qtd++;

    return 1;
}

int lista_insere_meio(Lista *li, struct aluno al){

    if (li == NULL){
        return -1;
    }

    if (lista_cheia(li)){
        return 0;
    }

    if (matricula_existe(li, al.matricula)){
        return 2; // matricula duplicada
    }

    int k, i = 0;

    while(i < li->qtd && li->dados[i].matricula < al.matricula){

        i++;
    }

    // procura onde inserir a nova matricula ^
    // enquanto i for menor que a quantidade na lista e a matricula atual for menor que a matricula a ser inserida incrementa o i

     for(k = li->qtd - 1; k >= i; k--){

        li->dados[k+1] = li->dados[k];
    }

    // começa do final e decrementa até encontrar a nova vaga

    li->dados[i] = al;
    li->qtd++;

    return 1;

}

int lista_remover_final(Lista *li){

    if (li == NULL){
        return -1;
    }

    if (lista_vazia(li)){
        return 0;
    }

    li->qtd--;
    return 1;
}

int lista_remover_inicio(Lista *li){

    if (li == NULL){
        return -1;
    }

    if (lista_vazia(li)){
        return 0;
    }

    for(int i = 0; i < li->qtd-1; i++){
        li->dados[i] = li->dados[i+1];
    }

    li->qtd--;
    return 1;
}
int lista_remover_meio(Lista *li, int mat){

    if (li == NULL){
        return -1;
    }

    if(lista_vazia(li)){
        return 0;
    }

    int k, i = 0;

    while(i < li->qtd && li->dados[i].matricula != mat){
        i++;
    }

    if (i == li->qtd){ // Não encontrou
        return 2;
    }

    for(k=i; k < li->qtd - 1; k++){
        li->dados[k] = li->dados[k+1];
    }

    li->qtd--;
    return 1;
}
int lista_consulta_posicao(Lista *li, int pos, struct aluno *al){

    if(li == NULL){
        return -1;
    }

    if(lista_vazia(li)){
        return 0;
    }

    if(pos <= 0 || pos > li->qtd){
        return 2;
    }

    *al = li->dados[pos-1];
    return 1;
}
int lista_consulta_matricula(Lista *li, int mat, struct aluno *al){

    if(li == NULL){
        return -1;
    }

    if(lista_vazia(li)){
        return 0;
    }

    int i = 0;
    while(i < li->qtd && li->dados[i].matricula != mat){
        i++;
    }

    if( i == li->qtd){
        return 2;
    }

    *al = li->dados[i];
    return 1;
}
