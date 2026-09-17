#include "autor.h"
#include "livro.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Autor
{
    char nome[SIZE_NOME];
    ListaLivros *listaDoAutor;
};

struct Livro
{
    char titulo[SIZE_TITULO];
    Autor *autor;
    Data dataPubli;
    int id;
    int status;
    char emailResponsavel[SIZE_NOME];

    Livro *next;
    Livro *prev;
};

struct ListaLivros
{
    Livro *head;
    Livro *tail;

    int qtdLivros;
};

Autor *criaAutor(char nome[SIZE_NOME])
{
    Autor *autor = (Autor *)malloc(sizeof(Autor));

    if (autor == NULL)
        return NULL;

    strcpy(autor->nome, nome);
    autor->listaDoAutor = criarListaLivrosAutor();

    return autor;
}

void addLivro(ListaLivros *listaLivros, char titulo[SIZE_TITULO], Autor *autor, Data dataPubli)
{
    Livro *new = (Livro *)malloc(sizeof(Livro));

    if (new == NULL) // erro de alocação
        return;

    strcpy(new->titulo, titulo);
    strcpy(new->emailResponsavel, "");
    new->autor = autor;
    new->dataPubli = dataPubli;
    new->id = listaLivros->qtdLivros;
    new->status = 0;

    new->next = NULL;
    new->prev = NULL;

    addLivroAutor(autor, new);

    // caso lista esteja vazia
    if (listaLivros->head == NULL)
    {
        listaLivros->head = new;
        listaLivros->tail = new;
        listaLivros->qtdLivros++;

        printf("\nLivro cadastrado\n");
        return;
    }

    // adiciona no final
    new->prev = listaLivros->tail;
    listaLivros->tail->next = new;
    listaLivros->tail = new;
    listaLivros->qtdLivros++; // toda chamada adiciona 1 na qtdLivros

    printf("\nLivro cadastrado\n");

    return;
}

void addLivroAutor(Autor *autor, Livro *livro)
{
    Livro *new = (Livro *)malloc(sizeof(Livro));

    if (new == NULL)
        return; // erro de alocação

    new-> = livro;
    new->next = NULL;
    new->prev = NULL;

    // caso a lista do autor esteja vazia
    if (autor->listaDoAutor->head == NULL)
    {
        autor->listaDoAutor->head = new;
        autor->listaDoAutor->tail = new;
        autor->listaDoAutor->qtdLivros++;
        printf("\nLivro cadastrado na lista do autor\n");

        return;
    }

    // adiciona o novo livro no final da lista do autor

    new->prev = autor->listaDoAutor->tail;
    autor->listaDoAutor->tail->next = new;
    autor->listaDoAutor->tail = new;
    autor->listaDoAutor->qtdLivros++;

    printf("\nLivro cadastrado na lista do autor\n");

    return;
}

void removeLivroAutor(Autor *autor, Livro *livro)
{
    LivroAutor *aux = autor->listaDoAutor->head;

    while (aux != NULL)
    {
        if (aux->livro == livro)
        {
            if (aux->prev == NULL)
            {
                autor->listaDoAutor->head = aux->next;

                if (aux->next != NULL)
                    aux->next->prev = NULL;
                else
                    autor->listaDoAutor->tail = NULL;
            }
            else if (aux->next == NULL)
            {
                autor->listaDoAutor->tail = aux->prev;
                aux->prev->next = NULL;
            }
            else
            {
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev;
            }

            autor->listaDoAutor->qtdLivrosAutor--;

            free(aux);
            return;
        }

        aux = aux->next;
    }

    return;
}

