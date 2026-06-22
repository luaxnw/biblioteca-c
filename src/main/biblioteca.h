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

typedef struct LivroUsuario LivroUsuario; 
typedef struct ListaLivrosUsuario ListaLivrosUsuario;

// ===== FUNÇÕES DE CADASTRO =====

void addUser(ListaUsuarios *lista, char *nome, char *email);

void addLivro(ListaLivros *lista, char *titulo, Autor *autor, Data dataPubli);

void addLivroAutor(Autor *autor, Livro *livro);


// ===== FUNÇÕES DE BUSCA =====

void buscarPorId(ListaLivros *lista, int id);

void buscarPorAutor(Autor *autor);

int buscaUsuarioPorEmail(ListaUsuarios *lista, char *email);

void buscaUsuarioPorNome(ListaUsuarios *lista, char *nome);

void mostraLivrosEmPosse(ListaUsuarios *lista, char *email);


// ===== FUNÇÕES CRIAÇÃO =====

ListaUsuarios *criarListaUsuarios(void);

ListaLivros *criarListaLivros(void);

ListaLivrosAutor *criarListaLivrosAutor(void);

Autor *criaAutor(char *nome);

Data criaData(int dia, int mes, int ano);

ListaLivrosUsuario *criaListaLivrosUsuario(void);


// ===== FUNÇÕES ÚTEIS =====

void mostraStatusLivro(Livro *livro);

void mostraListaLivros(ListaLivros *lista);

void mostraListaUsuarios(ListaUsuarios *lista);


// ===== FUNÇÕES MENU =====

void menuCadastro(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios);

void menuConsulta(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios);

void menuAtualizacao(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios);

void menuExclusao(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios);

void menuEmprestimo(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios);

void menuDevolucao(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios);


#endif
