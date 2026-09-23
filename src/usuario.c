#include "usuario.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>



ListaUsuarios *criarListaUsuarios(void)
{
    ListaUsuarios *lista = (ListaUsuarios *)malloc(sizeof(ListaUsuarios));

    if (lista == NULL)
        return NULL;

    lista->head = NULL;
    lista->tail = NULL;
    lista->qtdUsuarios = 0;

    return lista;
}

void addUsuario(ListaUsuarios *listaUsuarios, char nome[SIZE_NOME], char email[SIZE_NOME])
{
    Usuario *new = (Usuario *)malloc(sizeof(Usuario));
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
        printf("Usuário cadastrado\n");

        return;
    }

    // percorre toda a lista verificando se o email fornecido já está
    // no sistema

    Usuario *aux = procuraUsuarioPorEmail(listaUsuarios, email);

    if (aux != NULL)
    {
        printf("\nEmail não cadastrado!\nO email que você está tentando cadastrar já consta no sistema.\n");
        return;
    }

    // adiciona no final
    new->prev = listaUsuarios->tail;
    listaUsuarios->tail->next = new;
    listaUsuarios->tail = new;

    printf("\nUsuário cadastrado\n");
    return;
}

void buscarUsuarioPorEmail(ListaUsuarios *lista, char email[SIZE_NOME])
{
    Usuario *usuario = procuraUsuarioPorEmail(lista, email);

    if (usuario != NULL)
        printf("\nNome: %s\nEmail: %s\n", usuario->nome, usuario->email);
    else{
        printf("\nUsuário de email %s não encontrado.\n", email);
    }
}

void buscarUsuarioPorNome(ListaUsuarios *lista, char nome[SIZE_NOME])
{
    Usuario *aux = NULL;

    for (aux = lista->head; aux != NULL; aux = aux->next)
    {
        if (strcmp(aux->nome, nome) == 0)
        {
            printf("\nNome: %s\nEmail: %s\n", aux->nome, aux->email);
            return;
        }
    }
    printf("\nUsuário de nome %s não encontrado.\n", nome);
    return;
}

Usuario *procuraUsuarioPorEmail(ListaUsuarios *lista, char email[SIZE_NOME])
{
    Usuario *aux = lista->head;

    while (aux != NULL)
    {
        if (strcmp(aux->email, email) == 0)
            return aux;

        aux = aux->next;
    }
    return NULL;
}

void atualizaUsuario(ListaUsuarios *lista, char emailUsuario[SIZE_NOME])
{
    char nome[SIZE_NOME], email[SIZE_NOME];

    Usuario *aux = procuraUsuarioPorEmail(lista, emailUsuario);

    if (aux != NULL)
    {
        printf("Informe o novo nome do usuário ou ENTER para não alterar: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';

        if (nome[0] != '\0')
        {
            strcpy(aux->nome, nome);
            printf("Nome do usuário alterado para %s!\n", aux->nome);
        }

        printf("Informe o novo email do usuário ou ENTER para não alterar: ");
        fgets(email, sizeof(email), stdin);
        email[strcspn(email, "\n")] = '\0';

        if (email[0] != '\0')
        {
            strcpy(aux->email, email);
            printf("Email do usuário alterado para %s!\n", aux->email);
        }
    }
    else
    {
        printf("Usuário não localizado.\n");
    }
}

void removeUsuario(ListaUsuarios *lista, char emailUsuario[SIZE_NOME])
{
    Usuario *aux = procuraUsuarioPorEmail(lista, emailUsuario);

    if (aux == NULL)
    {
        printf("Usuário não encontrado.\n");
        return;
    }

    if (aux->prev == NULL)
    {
        lista->head = aux->next;

        if (aux->next != NULL)
            aux->next->prev = NULL;
        else
            lista->tail = NULL;
    }
    else if (aux->next == NULL)
    {
        lista->tail = aux->prev;
        aux->prev->next = NULL;
    }
    else
    {
        aux->prev->next = aux->next;
        aux->next->prev = aux->prev;
    }

    lista->qtdUsuarios--;

    printf("Usuário de %s removido.\n", aux->email);
    free(aux);

    return;
}

