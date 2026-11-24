#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSequencial.h"
#include "Interface.h"

// Comando para limpar o terminal (Windows usa "cls", Linux/macOS usam "clear")
#ifdef _WIN32
#define LIMPAR_TELA "cls"
#else
#define LIMPAR_TELA "clear"
#endif

// Funcoes de apoio, usadas apenas dentro deste arquivo
void ler_aluno(struct aluno *al);
void exibir_aluno(struct aluno *al);
void pausar_tela();

void exibir_painel(){

    char opcaoLista;
    int opcaoOperadores;

    Lista *li = NULL;
    struct aluno al;

    iniciolista:
        do{
                printf("\n[S] - Sair");
                printf("\n[E] - Verificar se a lista existe");
                printf("\n[C] - Verificar se a lista esta cheia");
                printf("\n[V] - Verificar se a lista esta vazia");
                printf("\n[T] - Verificar tamanho da lista");
                printf("\n[O] - Operacoes");
                printf("\nOpcao: ");
                scanf(" %c", &opcaoLista);

               switch(opcaoLista){
                    case 'S':
                    case 's':{
                        system(LIMPAR_TELA);
                        printf("\nEncerrando o programa!\n");
                        break;
                    }
                    case 'E':
                    case 'e':{

                        system(LIMPAR_TELA);
                        if (lista_nao_existe(li)){
                            system(LIMPAR_TELA);
                            printf("\nErro: lista nao existe / falha ao alocar memoria.\n");
                            goto iniciolista;
                        }

                        printf("\nA lista existe.\n");
                        break;
                    }
                    case 'C':
                    case 'c':{

                         if (lista_nao_existe(li)){
                            system(LIMPAR_TELA);
                            printf("\nErro: lista nao existe / falha ao alocar memoria.\n");
                            goto iniciolista;
                         }

                         system(LIMPAR_TELA);
                         printf("\n ! Esta cheia?");

                         if(lista_cheia(li)){
                            printf("\n ! Esta cheia");
                         }
                         else{
                            printf("\n ! Nao esta cheia");
                         }

                         pausar_tela();
                         system(LIMPAR_TELA);

                         break;
                    }
                    case 'V':
                    case 'v':{

                        if (lista_nao_existe(li)){
                            system(LIMPAR_TELA);
                            printf("\nErro: lista nao existe / falha ao alocar memoria.\n");
                            goto iniciolista;
                         }

                        system(LIMPAR_TELA);
                         printf("\n ! Esta vazia?");

                         if(lista_vazia(li)){
                            printf("\n ! Esta vazia");
                         }
                         else{
                            printf("\n ! Esta cheia");
                         }

                         pausar_tela();
                         system(LIMPAR_TELA);
                         break;
                    }
                    case 'T':
                    case 't':{

                         if (lista_nao_existe(li)){
                            system(LIMPAR_TELA);
                            printf("\nErro: lista nao existe / falha ao alocar memoria.\n");
                            goto iniciolista;
                         }

                         system(LIMPAR_TELA);
                         printf("\nTamanho da lista: %d\n", lista_tamanho(li));
                         break;

                    }
                    case 'O':
                    case 'o':{

                    system(LIMPAR_TELA);
                    inicioperadores:
                        printf("\n[0] - Voltar");
                        printf("\n[1] - Criar lista");
                        printf("\n[2] - Inserir no final da lista");
                        printf("\n[3] - Inserir no inicio da lista");
                        printf("\n[4] - Inserir no meio da lista");
                        printf("\n[5] - Remover do final da lista");
                        printf("\n[6] - Remover do inicio da lista");
                        printf("\n[7] - Remover do meio da lista");
                        printf("\n[8] - Consultar conteudo pela posicao");
                        printf("\n[9] - Consultar conteudo pela matricula");
                        printf("\nOpcao: ");
                        scanf("%d", &opcaoOperadores);

                        switch(opcaoOperadores){
                            case 0:{
                                system(LIMPAR_TELA);
                                goto iniciolista;
                            }
                            case 1:{

                                if (li != NULL) {
                                    libera_lista(li);
                                }

                                li = cria_lista();

                                if (li != NULL){
                                    system(LIMPAR_TELA);
                                    printf("\nLista criada com sucesso!\n");
                                    goto inicioperadores;
                                }
                                break;
                            }
                            case 2:{

                                    if (lista_nao_existe(li)) {
                                        system(LIMPAR_TELA);
                                        printf("\nErro: lista nao existe. Crie a lista primeiro.\n");
                                        goto inicioperadores;
                                    }

                                    system(LIMPAR_TELA);
                                    ler_aluno(&al);
                                    int status = lista_insere_final(li, al);

                                    while(status == 2){
                                        system(LIMPAR_TELA);
                                        printf("\nMatricula ja cadastrada!");
                                        printf("\n ! Insira outra matricula: ");
                                        scanf("%d", &al.matricula);
                                        status = lista_insere_final(li, al);
                                    }

                                    if(status == 1){
                                        system(LIMPAR_TELA);
                                        printf("\nInserido com sucesso!\n");
                                    }
                                    else if(status == 0){
                                        system(LIMPAR_TELA);
                                        printf("\nLista cheia! Nao foi possivel inserir.\n");
                                    }
                                    else{
                                        system(LIMPAR_TELA);
                                        printf("\nERRO: Lista invalida ou nao foi criada.\n");
                                        goto inicioperadores;

                                    }

                                    break;
                                }
                            case 3:{

                                if (lista_nao_existe(li)) {
                                    system(LIMPAR_TELA);
                                    printf("\nErro: lista nao existe. Crie a lista primeiro.\n");
                                    goto inicioperadores;
                                }

                                system(LIMPAR_TELA);
                                ler_aluno(&al);
                                int status = lista_insere_inicio(li, al);

                                while(status == 2){
                                    system(LIMPAR_TELA);
                                    printf("\nMatricula ja cadastrada!");
                                    printf("\n ! Insira outra matricula: ");
                                    scanf("%d", &al.matricula);
                                    status = lista_insere_inicio(li, al);
                                }

                                 if(status == 1){
                                        system(LIMPAR_TELA);
                                        printf("\nInserido com sucesso!\n");
                                    }
                                    else if(status == 0){
                                        system(LIMPAR_TELA);
                                        printf("\nLista cheia! Nao foi possivel inserir.\n");
                                    }
                                    else{
                                        system(LIMPAR_TELA);
                                        printf("\nERRO: Lista invalida ou nao foi criada.\n");
                                        goto inicioperadores;
                                    }

                                break;

                            }
                            case 4:{

                                 if (lista_nao_existe(li)) {
                                    system(LIMPAR_TELA);
                                    printf("\nErro: lista nao existe. Crie a lista primeiro.\n");
                                    goto inicioperadores;
                                }

                                system(LIMPAR_TELA);
                                ler_aluno(&al);
                                int status = lista_insere_meio(li, al);

                                while(status == 2){
                                    system(LIMPAR_TELA);
                                    printf("\nMatricula ja cadastrada!");
                                    printf("\n ! Insira outra matricula: ");
                                    scanf("%d", &al.matricula);
                                    status = lista_insere_meio(li, al);
                                }

                                 if(status == 1){
                                        system(LIMPAR_TELA);
                                        printf("\nInserido com sucesso!\n");
                                    }
                                    else if(status == 0){
                                        system(LIMPAR_TELA);
                                        printf("\nLista cheia! Nao foi possivel inserir.\n");
                                    }
                                    else{
                                        system(LIMPAR_TELA);
                                        printf("\nERRO: Lista invalida ou nao foi criada.\n");
                                        goto inicioperadores;
                                    }


                                break;
                            }
                            case 5:{

                                if (lista_nao_existe(li)) {
                                    system(LIMPAR_TELA);
                                    printf("\nErro: lista nao existe. Crie a lista primeiro.\n");
                                    goto inicioperadores;
                                }

                                system(LIMPAR_TELA);
                                int status = lista_remover_final(li);

                                 if(status == 1){
                                        system(LIMPAR_TELA);
                                        printf("\nRemovido com sucesso!\n");
                                    }
                                    else if(status == 0){
                                        system(LIMPAR_TELA);
                                        printf("\nLista vazia! Nao foi possivel remover\n");
                                    }
                                    else{
                                        system(LIMPAR_TELA);
                                        printf("\nERRO: Lista invalida ou nao foi criada.\n");
                                        goto inicioperadores;
                                    }

                                break;
                            }
                            case 6:{

                                  if (lista_nao_existe(li)) {
                                    system(LIMPAR_TELA);
                                    printf("\nErro: lista nao existe. Crie a lista primeiro.\n");
                                    goto inicioperadores;
                                }

                                system(LIMPAR_TELA);
                                int status = lista_remover_inicio(li);

                                 if(status == 1){
                                        system(LIMPAR_TELA);
                                        printf("\nRemovido com sucesso!\n");
                                    }
                                    else if(status == 0){
                                        system(LIMPAR_TELA);
                                        printf("\nLista vazia! Nao foi possivel remover\n");
                                    }
                                    else{
                                        system(LIMPAR_TELA);
                                        printf("\nERRO: Lista invalida ou nao foi criada.\n");
                                        goto inicioperadores;
                                    }

                                break;

                            }
                            case 7:{

                                int matricula;

                                 if (lista_nao_existe(li)) {
                                    system(LIMPAR_TELA);
                                    printf("\nErro: lista nao existe. Crie a lista primeiro.\n");
                                    goto inicioperadores;
                                }

                                system(LIMPAR_TELA);

                                printf("\n Insira a matricula do aluno: ");
                                scanf("%d", &matricula);

                                int status = lista_remover_meio(li, matricula);

                                 if(status == 1){
                                        system(LIMPAR_TELA);
                                        printf("\nRemovido com sucesso!\n");
                                    }
                                    else if(status == 0){
                                        system(LIMPAR_TELA);
                                        printf("\nLista vazia! Nao foi possivel remover\n");
                                    }
                                    else if (status == 2){
                                        system(LIMPAR_TELA);
                                        printf("\nMatricula nao encontrada\n");
                                    }
                                    else{
                                        system(LIMPAR_TELA);
                                        printf("\nERRO: Lista invalida ou nao foi criada.\n");
                                        goto inicioperadores;
                                    }

                                    break;
                            }
                            case 8:{

                                int posicao;

                                 if (lista_nao_existe(li)) {
                                    system(LIMPAR_TELA);
                                    printf("\nErro: lista nao existe. Crie a lista primeiro.\n");
                                    goto inicioperadores;
                                }

                                system(LIMPAR_TELA);

                                printf("\n Insira a posicao do aluno: ");
                                scanf("%d", &posicao);

                                int status = lista_consulta_posicao(li, posicao, &al);

                                 if(status == 1){
                                        system(LIMPAR_TELA);
                                        printf("\nAluno encontrado com sucesso!\n");
                                        printf("==================== %s ====================", al.nome);
                                        exibir_aluno(&al);
                                        printf("\n==================== %s ====================", al.nome);
                                        pausar_tela();
                                    }
                                    else if(status == 0){
                                        system(LIMPAR_TELA);
                                        printf("\nLista vazia ou Nao foi possivel exibir os dados do aluno\n");
                                    }
                                    else if (status == 2){
                                        system(LIMPAR_TELA);
                                        printf("\nAluno nao encontrado ou a posicao e invalida\n");
                                    }
                                    else{
                                        system(LIMPAR_TELA);
                                        printf("\nERRO: Lista invalida ou nao foi criada.\n");
                                        goto inicioperadores;
                                    }

                                    break;

                            }
                            case 9:{

                                int matricula;

                                 if (lista_nao_existe(li)) {
                                    system(LIMPAR_TELA);
                                    printf("\nErro: lista nao existe. Crie a lista primeiro.\n");
                                    goto inicioperadores;
                                }

                                system(LIMPAR_TELA);

                                printf("\n Insira a matricula do aluno: ");
                                scanf("%d", &matricula);

                                int status = lista_consulta_matricula(li, matricula, &al);

                                 if(status == 1){
                                        system(LIMPAR_TELA);
                                        printf("\nAluno encontrado com sucesso!\n");
                                        printf("==================== %s ====================", al.nome);
                                        exibir_aluno(&al);
                                        printf("\n==================== %s ====================", al.nome);
                                        pausar_tela();
                                    }
                                    else if(status == 0){
                                        system(LIMPAR_TELA);
                                        printf("\nLista vazia ou Nao foi possivel exibir os dados do aluno\n");
                                    }
                                    else if (status == 2){
                                        system(LIMPAR_TELA);
                                        printf("\nAluno nao encontrado ou a posicao e invalida\n");
                                    }
                                    else{
                                        system(LIMPAR_TELA);
                                        printf("\nERRO: Lista invalida ou nao foi criada.\n");
                                        goto inicioperadores;
                                    }

                                    break;

                            }
                            default:{
                                system(LIMPAR_TELA);
                                printf("Comando invalido.\n");
                                goto inicioperadores;
                            }
                        }
                        break;
                    }
                    default:{
                        system(LIMPAR_TELA);
                        printf("Comando invalido.\n");
                    }
               }
            }while(opcaoLista != 'S' && opcaoLista != 's');

        if (li != NULL) {
            libera_lista(li);
            li = NULL;
        }
}

void ler_aluno(struct aluno *al){

    if (al == NULL ){
            return;
        }

    puts("============== CADASTRO ==============");

    getchar();
    printf("\n ! Insira o nome do aluno: ");
    fgets(al->nome, 50, stdin);
    al->nome[strcspn(al->nome, "\n")] = '\0';

    printf("\n ! Insira a matricula do aluno: ");
    scanf("%d", &al->matricula);

    printf("\n ! Insira as 3 notas: ");

    for(int i = 0; i < NOTAS; i++){
        printf("\n[%d] - Nota: ", i+1);
        scanf("%f", &al->notas[i]);
    }

}
void exibir_aluno(struct aluno *al){

    printf("\nNome: %s", al->nome);
    printf("\nMatricula: %d", al->matricula);
    for(int i = 0; i < NOTAS; i++){
        printf("\n[%d] - Nota: %.2f", i+1, al->notas[i]);
    }
}

void pausar_tela() {

    int c;

    while ((c = getchar()) != '\n' && c != EOF);

    printf("\n\nPressione ENTER para continuar...");

    getchar();
    system(LIMPAR_TELA);
}
