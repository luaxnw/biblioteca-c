#include "biblioteca.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ESTRUTURAS

typedef struct data data;
typedef struct usuario usuario;
typedef struct listaUsuarios listaUsuarios;
typedef struct livro livro;
typedef struct listaLivros listaLivros;

struct data {
    int dia;
    int mes;
    int ano;
};

struct usuario {
    char *nome;
    char *email;
    usuario *next;
    usuario *prev;
}; 

struct listaUsuarios {
    usuario *head;
    usuario *tail;
    int qtdUsuarios;
};

struct livro {
    char *titulo;
    char *autor;
    data dataPubli;
    int id;
    int status;
    usuario *usuarioRespo;
    livro *next;
    livro *prev;

};

struct listaLivros {
    struct livro *head;
    struct livro *tail;
    int qtdLivros;
};


// FUNÇÕES

void addUser(listaUsuarios *listaUsuarios, char *nome, char *email){

    usuario *new = (usuario*) malloc(sizeof(usuario));
    listaUsuarios->qtdUsuarios++; //toda chamada adiciona 1 na qtdUsers

    strcpy(new->nome, nome);
    strcpy(new->email, email);
    new->next = NULL;
    new->prev = NULL;


    if (new == NULL) //erro de alocação
        return;

    //caso lista esteja vazia
    if (listaUsuarios->head == NULL){
        listaUsuarios->head = new;
        listaUsuarios->tail = new;
        return;
    }

    usuario *aux = listaUsuarios->head;

    // percorre toda a lista verificando se o email fornecido já está
    // no sistema

    while (aux != NULL){

        if (strcmp(aux->email, email) == 0){
            printf("Email não cadastrado!\nO email que você está tentando cadastrar já consta no sistema.\n");
            return;
        }

        aux = aux->next;
    }

    //adiciona no final
    new->prev = listaUsuarios->tail;
    listaUsuarios->tail->next = new;
    listaUsuarios->tail = new; 

}

void addLivro(listaLivros *listaLivros, char *titulo, char *autor, data dataPubli, usuario *usuarioRespo){

    livro *new = (livro*) malloc(sizeof(livro));
    listaLivros->qtdLivros++; //toda chamada adiciona 1 na qtdLivros

    strcpy(new->titulo, titulo);
    strcpy(new->autor, autor);
    new->dataPubli = dataPubli;
    new->id = listaLivros->qtdLivros;
    new->status = 0;
    new->usuarioRespo = usuarioRespo;


    new->next = NULL;
    new->prev = NULL;

    if (new == NULL) //erro de alocação
        return;

    //caso lista esteja vazia
    if (listaLivros->head == NULL){
        listaLivros->head = new;
        listaLivros->tail = new;
        return;
    }

    //adiciona no final
    new->prev = listaLivros->tail;
    listaLivros->tail->next = new;
    listaLivros->tail = new; 
}

// Funções buscar
void buscarPorId(listaLivros *listaLivros, int id){

    livro *aux = listaLivros->head;
    char *status;

    while(aux != NULL){

        if (aux->id == id){
            
            if (aux->status == 0)  
                status = "Dispoível";
            else{
                status = "Indisponível";
            }

            printf("ID: %d\nTítulo: %s\nAutor: %s\nData de publicação: %d/%d/%d\n");
        }

        aux = aux->next;
    }


}

void buscarPorAutor(listaLivros *listaLivros, char *autor);