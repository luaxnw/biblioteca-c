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
typedef struct autor autor;
typedef struct listaLivrosAutor listaLivrosAutor;
typedef struct livroAutor livroAutor;

struct data
{
    int dia;
    int mes;
    int ano;
};

struct usuario
{
    char *nome;
    char *email;
    usuario *next;
    usuario *prev;
};

struct listaUsuarios
{
    usuario *head;
    usuario *tail;
    int qtdUsuarios;
};

struct livro
{
    char *titulo;
    struct autor *autor;
    data dataPubli;
    int id;
    int status;
    usuario *usuarioRespo;
    livro *next;
    livro *prev;
};

struct listaLivros
{
    livro *head;
    livro *tail;
    int qtdLivros;
};

struct livroAutor
{
    struct livro *livro;
    livroAutor *next;
    livroAutor *prev;
};

struct listaLivrosAutor
{
    livroAutor *head;
    livroAutor *tail;
    int qtdLivrosAutor;
};

struct autor
{
    char *nome;
    listaLivrosAutor *listaDoAutor;
};

// FUNÇÕES

void addUser(listaUsuarios *listaUsuarios, char *nome, char *email)
{

    usuario *new = (usuario *)malloc(sizeof(usuario));
    listaUsuarios->qtdUsuarios++; // toda chamada adiciona 1 na qtdUsers

    strcpy(new->nome, nome);
    strcpy(new->email, email);
    new->next = NULL;
    new->prev = NULL;

    if (new == NULL) // erro de alocação
        return;

    // caso lista esteja vazia
    if (listaUsuarios->head == NULL)
    {
        listaUsuarios->head = new;
        listaUsuarios->tail = new;

        return;
    }

    usuario *aux = listaUsuarios->head;

    // percorre toda a lista verificando se o email fornecido já está
    // no sistema

    while (aux != NULL)
    {

        if (strcmp(aux->email, email) == 0)
        {
            printf("Email não cadastrado!\nO email que você está tentando cadastrar já consta no sistema.\n");
            return;
        }

        aux = aux->next;
    }

    // adiciona no final
    new->prev = listaUsuarios->tail;
    listaUsuarios->tail->next = new;
    listaUsuarios->tail = new;
}

void addLivro(listaLivros *listaLivros, char *titulo, autor *autor, data dataPubli, usuario *usuarioRespo)
{

    livro *new = (livro *)malloc(sizeof(livro));

    if (new == NULL) // erro de alocação
        return;

    strcpy(new->titulo, titulo);
    new->autor = autor;
    new->dataPubli = dataPubli;
    new->id = listaLivros->qtdLivros;
    new->status = 0;
    new->usuarioRespo = usuarioRespo;

    new->next = NULL;
    new->prev = NULL;

    addLivroAutor(new, autor);

    // caso lista esteja vazia
    if (listaLivros->head == NULL)
    {
        listaLivros->head = new;
        listaLivros->tail = new;
        listaLivros->qtdLivros++; // toda chamada adiciona 1 na qtdLivros

        return;
    }

    // adiciona no final
    new->prev = listaLivros->tail;
    listaLivros->tail->next = new;
    listaLivros->tail = new;
    listaLivros->qtdLivros++; // toda chamada adiciona 1 na qtdLivros

    return;
}

void addLivroAutor(autor *autor, livro *livro)
{
    livroAutor *new = (livroAutor *)malloc(sizeof(livroAutor));

    if (new == NULL)
        return; // erro de alocação

    new->livro = livro;
    new->next = NULL;
    new->prev = NULL;

    // caso a lista do autor esteja vazia
    if (autor->listaDoAutor->head == NULL)
    {
        autor->listaDoAutor->head = new;
        autor->listaDoAutor->tail = new;
        autor->listaDoAutor->qtdLivrosAutor++;
        return;
    }

    // adiciona o novo livro no final da lista do autor

    new->prev = autor->listaDoAutor->tail;
    autor->listaDoAutor->tail->next = new;
    autor->listaDoAutor->tail = new;
    autor->listaDoAutor->qtdLivrosAutor++;

    return;
}

// Funções buscar
void buscarPorId(listaLivros *listaLivros, int id)
{
    livro *aux = listaLivros->head;

    while (aux != NULL)
    {

        if (aux->id == id)
        {
            printf("ID: %d\nTítulo: %s\nAutor: %s\nData de publicação: %d/%d/%d\nUsuário responsável: %s\n",
                   aux->id,
                   aux->titulo,
                   aux->autor,
                   aux->dataPubli.dia,
                   aux->dataPubli.mes,
                   aux->dataPubli.ano,
                   aux->usuarioRespo->email);
            mostraStatusLivro(aux);
            return;
        }
        aux = aux->next;
    }

    printf("Livro não encontrado");

    return;
}

void buscarPorAutor(autor *autor)
{
    livro *aux = NULL;

    for (aux = autor->listaDoAutor->head; aux != NULL; aux = aux->next)
    {
        printf("ID: %d\nTítulo: %s\nAutor: %s\nData de publicação: %d/%d/%d\nUsuário responsável: %s\n",
               aux->id,
               aux->titulo,
               aux->autor,
               aux->dataPubli.dia,
               aux->dataPubli.mes,
               aux->dataPubli.ano,
               aux->usuarioRespo->email);   
               mostraStatusLivro(aux);
    }

    printf("Livro não encontrado");

    return;
}

void mostraStatusLivro(livro *livro)
{

    if (livro->status == 0)
        printf("Dispoível\n");
    else
    {
        printf("Indisponível\n");
    }

    return;
}