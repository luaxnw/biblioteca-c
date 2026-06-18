/* Tipos */
#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Data Data;

typedef struct Usuario Usuario;
typedef struct ListaUsuarios ListaUsuarios;

typedef struct Autor Autor;

typedef struct Livro Livro;
typedef struct ListaLivros ListaLivros;

typedef struct LivroAutor LivroAutor;
typedef struct ListaLivrosAutor ListaLivrosAutor;

/* Funções de cadastro */

void addUser(ListaUsuarios *lista, char *nome, char *email);

void addLivro(ListaLivros *lista, char *titulo, Autor *autor, Data dataPubli, char *emailResponsavel);

void addLivroAutor(Autor *autor, Livro *livro);

/* Funções de busca */

void buscarPorId(ListaLivros *lista, int id);

void buscarPorAutor(Autor *autor);

int buscaUsuarioPorEmail(ListaUsuarios *lista, char *email);


// Funções criar listas

ListaUsuarios *criarListaUsuarios(void);
ListaLivros *criarListaLivros(void);
ListaLivrosAutor *criarListaLivrosAutor(void);

// Funções úteis

void mostraStatusLivro(Livro *livro);


#endif
