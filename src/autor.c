#include "autor.h"
#include "livro.h"

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
    removeLivro(autor->listaDoAutor, ID);
    printf("Autor %s - Livro de ID %d removido\n", autor->nome, ID);

    return;
}

