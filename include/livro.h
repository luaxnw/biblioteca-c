#ifndef LIVRO_H
#define LIVRO_H

#define SIZE_TITULO 50
#define SIZE_NOME 30

typedef struct Autor Autor;
#include "data.h"


typedef struct Livro
{
    char titulo[SIZE_TITULO];
    Autor *autor;
    Data dataPubli;
    int id;
    int status;
    char emailResponsavel[SIZE_NOME];

    struct Livro *next;
    struct Livro *prev;
} Livro;

typedef struct ListaLivros
{
    Livro *head;
    Livro *tail;

    int qtdLivros;
} ListaLivros;

ListaLivros *criarListaLivros(void);

void addLivro(
    ListaLivros *lista,
    char titulo[SIZE_TITULO],
    Autor *autor,
    Data dataPubli
);

Livro *buscarPorId(
    ListaLivros *lista,
    int id
);

void buscarPorAutor(
    ListaLivros *lista,
    char nome[SIZE_NOME]
);

void mostraStatusLivro(
    Livro *livro
);

void mostrarLivro(
    Livro *livro
);

void atualizaLivro(
    ListaLivros *lista,
    int ID
);

void removeLivro(
    ListaLivros *lista,
    int ID
);


#endif
