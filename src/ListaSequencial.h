#ifndef LISTASEQUENCIAL_H_INCLUDED
#define LISTASEQUENCIAL_H_INCLUDED

#define MAX 100
#define NOTAS 3

struct aluno {

    int matricula;
    char nome[50];
    float notas[NOTAS];
};  // Essa struct, declara no header, guarda informação do conteúdo da lista (O que ela guarda)

typedef struct lista Lista;
// Aqui é declarada a lista em sí

Lista *cria_lista();

void libera_lista(Lista *li);
// Essa função libera memória da lista

int lista_nao_existe(Lista *li);
int lista_cheia(Lista *li);
int lista_vazia(Lista *li);
int lista_tamanho(Lista *li);
// Insercoes: 1 = ok, 0 = lista cheia, 2 = matricula duplicada, -1 = lista invalida
int lista_insere_final(Lista *li, struct aluno al);
int lista_insere_inicio(Lista *li, struct aluno al);
int lista_insere_meio(Lista *li, struct aluno al);
int lista_remover_final(Lista *li);
int lista_remover_inicio(Lista *li);
int lista_remover_meio(Lista *li, int mat);
int lista_consulta_posicao(Lista *li, int pos, struct aluno *al);
int lista_consulta_matricula(Lista *li, int matricula, struct aluno *al);


#endif // LISTASEQUENCIAL_H_INCLUDED
