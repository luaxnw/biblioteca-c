#include "../include/usuario.h"
#include "../include/menu.h"
#include "../include/livro.h"
#include "../include/autor.h"
#include "../include/emprestimo.h"
#include "../include/data.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Autor *criaAutor(char nome[SIZE_NOME])
{
    Autor *autor = (Autor *)malloc(sizeof(Autor));

    if (autor == NULL)
        return NULL;

    strcpy(autor->nome, nome);
    autor->listaDoAutor = criarListaLivros();

    return autor;
}

void addLivroAutor(Autor *autor, Livro *livro)
{
    // caso a lista do autor esteja vazia
    if (autor->listaDoAutor->head == NULL)
    {
        autor->listaDoAutor->head = livro;
        autor->listaDoAutor->tail = livro;
        autor->listaDoAutor->qtdLivros++;
        printf("\nLivro cadastrado na lista do autor\n");

        return;
    }

    // adiciona o novo livro no final da lista do autor

    livro->prev = autor->listaDoAutor->tail;
    autor->listaDoAutor->tail->next = livro;
    autor->listaDoAutor->tail = livro;
    autor->listaDoAutor->qtdLivros++;

    printf("\nLivro cadastrado na lista do autor\n");

    return;
}

void removeLivroAutor(Autor *autor, int ID)
{
    Livro *aux = buscarPorId(autor->listaDoAutor, ID);

    if (aux == NULL)
    {
        printf("\nLivro não encontrado.\n");
        return;
    }

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

    autor->listaDoAutor->qtdLivros--;

    printf("Autor %s - Livro de ID %d removido\n", autor->nome, ID);

    return;
}
