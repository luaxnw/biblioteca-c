/* Tipos */
#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#define SIZE_TITULO 50
#define SIZE_NOME 30

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

typedef struct nodoBST nodoBST;
typedef struct BST BST;

// ===== FUNÇÕES DE CADASTRO =====

void addUsuario(ListaUsuarios *lista, char nome[SIZE_NOME], char email[SIZE_NOME]);

void addLivro(ListaLivros *lista, char titulo[SIZE_TITULO], Autor *autor, Data dataPubli, BST *arvore);

void addLivroAutor(Autor *autor, Livro *livro);


// ===== FUNÇÕES DE BUSCA =====

void buscarPorId(ListaLivros *lista, int id);

void buscarPorAutor(ListaLivros *lista, char nome[SIZE_NOME]);

void buscarUsuarioPorEmail(ListaUsuarios *lista, char email[SIZE_NOME]);

void buscarUsuarioPorNome(ListaUsuarios *lista, char nome[SIZE_NOME]);

void mostraLivrosEmPosse(ListaUsuarios *lista, char email[SIZE_NOME]);


// ===== FUNÇÕES CRIAÇÃO =====

ListaUsuarios *criarListaUsuarios(void);

ListaLivros *criarListaLivros(void);

ListaLivrosAutor *criarListaLivrosAutor(void);

Autor *criaAutor(char nome[SIZE_NOME]);

Data criaData(int dia, int mes, int ano);

ListaLivrosUsuario *criaListaLivrosUsuario(void);


// ===== FUNÇÕES ÚTEIS =====

void mostraStatusLivro(Livro *livro);

void mostraListaLivros(ListaLivros *lista);

void mostraListaUsuarios(ListaUsuarios *lista);

Usuario *procuraUsuarioPorEmail(ListaUsuarios *lista, char email[SIZE_NOME]);

// ===== FUNÇÕES BST ===== 

BST *criaArvore(void);

nodoBST *criarNodoBST(Livro *livro);

nodoBST *inserirBSTLivro(nodoBST *raiz, nodoBST *new);

Livro *buscarLivroBST(nodoBST *raiz, int id);

Livro *buscarBST(BST *arvore, int id);


// ===== FUNÇÕES ATUALIZAÇÃO =====

void atualizaLivro(ListaLivros *lista, int ID);

void atualizaUsuario(ListaUsuarios *lista, char emailUsuario[SIZE_NOME]);


// ===== FUNÇÕES MENU =====

void menuCadastro(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios, BST *arvore);

void menuConsulta(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios);

void menuAtualizacao(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios);

void menuExclusao(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios);

void menuEmprestimo(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios);

void menuDevolucao(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios);


#endif