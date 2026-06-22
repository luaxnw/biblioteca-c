/* Tipos */
#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Data
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Usuario Usuario;
typedef struct ListaUsuarios ListaUsuarios;

typedef struct Autor Autor;

typedef struct Livro Livro;
typedef struct ListaLivros ListaLivros;

typedef struct LivroAutor LivroAutor;
typedef struct ListaLivrosAutor ListaLivrosAutor;

/* Funções de cadastro */

void addUser(ListaUsuarios *lista, char *nome, char *email);

void addLivro(ListaLivros *lista, char *titulo, Autor *autor, Data dataPubli);

void addLivroAutor(Autor *autor, Livro *livro);

/* Funções de busca */

void buscarPorId(ListaLivros *lista, int id);

void buscarPorAutor(Autor *autor);

int buscaUsuarioPorEmail(ListaUsuarios *lista, char *email);


// Funções criação

ListaUsuarios *criarListaUsuarios(void);
ListaLivros *criarListaLivros(void);
ListaLivrosAutor *criarListaLivrosAutor(void);
Autor *criaAutor(char *nome);
Data criaData(int dia, int mes, int ano);



// Funções úteis

void mostraStatusLivro(Livro *livro);
void mostraListaLivros(ListaLivros *lista);
void mostraListaUsuarios(ListaUsuarios *lista);


// Funções menu

void menuCadastro(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios);
void menuConsulta(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios);
void menuAtualizacao(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios);
void menuExclusao(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios);
void menuEmprestimo(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios);
void menuDevolucao(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios);


#endif
