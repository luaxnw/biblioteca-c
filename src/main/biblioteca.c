#include "biblioteca.h"
#include <stdlib.h>
#include <stdint.h>
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

    //adiciona no final
    new->prev = listaUsuarios->tail;
    listaUsuarios->tail->next = new;
    listaUsuarios->tail = new; 

}

void addLivro(listaLivros *listaLivros, char *titulo, char *autor, data dataPubli, int id, int status, usuario *usuarioRespo){

    livro *new = (livro*) malloc(sizeof(livro));
    strcpy(new->titulo, titulo);
    strcpy(new->autor, autor);
    new->dataPubli = dataPubli;
    new->id = id;
    new->status = status;
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
