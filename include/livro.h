#ifndef LIVRO_H
#define LIVRO_H

#define SIZE_TITULO 50

typedef struct Data
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Livro Livro;
typedef struct ListaLivros ListaLivros;
typedef struct Autor Autor;

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
