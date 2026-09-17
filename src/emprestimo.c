#include "emprestimo.h"
#include "livro.h"
#include "usuario.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void emprestaLivro(Livro *livro, ListaUsuarios *listaUsuarios, int ID, char emailUsuario[SIZE_NOME])
{
    Usuario *aux_2 = procuraUsuarioPorEmail(listaUsuarios, emailUsuario);

    if (aux_2 == NULL)
    {
        printf("Usuário não localizado.\n");
        return;
    }

    strcpy(livro->emailResponsavel, emailUsuario);
    livro->status = 1;

    printf("Livro de ID %d emprestado para %s\n", livro->id, aux_2->email);

    return;
}

void devolveLivro(Livro *livro, int ID)
{
    Livro *aux = buscarPorId(livro, ID);

    if (aux == NULL)
    {
        printf("Livro não localizado.\n");
        return;
    }

    if (aux->status == 0)
    {
        printf("Livro não está emprestado.\n");
        return;
    }

    strcpy(aux->emailResponsavel, "");
    aux->status = 0;

    printf("Livro de ID %d devolvido.\n", ID);

    return;
}

void mostraLivrosEmPosse(ListaUsuarios *listaUsuarios, ListaLivros *listaLivros, char email[SIZE_NOME])
{
    Usuario *aux_1 = procuraUsuarioPorEmail(listaUsuarios, email);
    Livro *aux_2 = NULL;

    if (aux_1 == NULL)
    {
        printf("\nUsuário não localizado.\n");
        return;
    }

    for (aux_2 = listaLivros->head; aux_2 != NULL; aux_2 = aux_2->next)
    {
        if (strcmp(aux_2->emailResponsavel, aux_1->email) == 0)
        {
            printf("\nID: %d\nTítulo: %s\nAutor: %s\nData de lançamento: %d/%d/%d\n", aux_2->id,
                   aux_2->titulo,
                   aux_2->autor->nome,
                   aux_2->dataPubli.dia,
                   aux_2->dataPubli.mes,
                   aux_2->dataPubli.ano);
        }
    }

    return;
}

