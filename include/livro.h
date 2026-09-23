#ifndef LIVRO_H
#define LIVRO_H

#define SIZE_TITULO 50


typedef struct Data
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Livro
{
    char titulo[SIZE_TITULO];
    Autor *autor;
    Data dataPubli;
    int id;
    int status;
    char emailResponsavel[SIZE_NOME];

    Livro *next;
    Livro *prev;
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
    char nome[30]
);

void mostraStatusLivro(
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

Data criaData(
    int dia,
    int mes,
    int ano
);

#endif
