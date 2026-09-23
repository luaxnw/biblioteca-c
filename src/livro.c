#include "livro.h"
#include "usuario.h"
#include "autor.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


ListaLivros *criarListaLivros(void)
{
    ListaLivros *lista = (ListaLivros *)malloc(sizeof(ListaLivros));

    if (lista == NULL)
        return NULL;

    lista->head = NULL;
    lista->tail = NULL;
    lista->qtdLivros = 1;

    return lista;
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

Livro *buscarPorId(ListaLivros *lista, int id)
{
    Livro *aux = NULL;

    for (aux = lista->head; aux != NULL; aux = aux->next)
    {
        if (aux->id == id)
            return aux;
    }

    printf("\nLivro não encontrado.\n");

    return NULL;
}

void buscarPorAutor(ListaLivros *lista, char nome[SIZE_NOME])
{
    Livro *aux = NULL;
    int indicadorLogico = 0;

    for (aux = lista->head; aux != NULL; aux = aux->next)
    {
        if (strcmp(aux->autor->nome, nome) == 0)
        {

            printf("\nID: %d\nTítulo: %s\nAutor: %s\nData de publicação: %d/%d/%d\nUsuário responsável: %s\n",
                   aux->id,
                   aux->titulo,
                   aux->autor->nome,
                   aux->dataPubli.dia,
                   aux->dataPubli.mes,
                   aux->dataPubli.ano,
                   aux->emailResponsavel);
            mostraStatusLivro(aux);
            indicadorLogico = 1;
        }
    }
    if (indicadorLogico == 0)
        printf("Autor não localizado.\n");

    return;
}

void mostraStatusLivro(Livro *livro)
{

    if (livro->status == 0)
        printf("Disponível\n");
    else
    {
        printf("Indisponível\n");
    }

    return;
}

void atualizaLivro(ListaLivros *lista, int ID)
{
    Livro *aux = buscarPorId(lista, ID);
    char tituloLivro[SIZE_TITULO], nomeAutor[SIZE_NOME];
    int dia = 0, mes = 0, ano = 0;

    if (aux != NULL)
    {
        printf("Informe o novo título ou ENTER para não alterar: ");
        getchar();
        fgets(tituloLivro, sizeof(tituloLivro), stdin);
        tituloLivro[strcspn(tituloLivro, "\n")] = '\0';

        if (!(tituloLivro[0] == '\0'))
        {
            strcpy(aux->titulo, tituloLivro);
            printf("Título do livro de ID %d alterado para %s!\n", aux->id, aux->titulo);
        }

        printf("Informe o novo autor ou ENTER para não alterar: ");
        fgets(nomeAutor, sizeof(nomeAutor), stdin);
        nomeAutor[strcspn(nomeAutor, "\n")] = '\0';

        if (!(nomeAutor[0] == '\0'))
        {
            strcpy(aux->autor->nome, nomeAutor);
            printf("Autor do livro de ID %d alterado para %s!\n", aux->id, aux->autor->nome);
        }

        printf("Informe a nova data de lançamento ou 0 para não alterar: ");
        scanf("%d/%d/%d", &dia, &mes, &ano);

        if (!(dia == 0 || mes == 0 || ano == 0))
        {
            aux->dataPubli = criaData(dia, mes, ano);
            printf("Data de lançamento do livro de ID %d alterada para %d/%d/%d!\n", aux->id,
                   aux->dataPubli.dia,
                   aux->dataPubli.mes,
                   aux->dataPubli.ano);
        }
    }
    return;
}
void atualizaLivro(ListaLivros *lista, int ID)
{
    Livro *aux = buscarPorId(lista, ID);
    char tituloLivro[SIZE_TITULO], nomeAutor[SIZE_NOME];
    int dia = 0, mes = 0, ano = 0;

    if (aux != NULL)
    {
        printf("Informe o novo título ou ENTER para não alterar: ");
        getchar();
        fgets(tituloLivro, sizeof(tituloLivro), stdin);
        tituloLivro[strcspn(tituloLivro, "\n")] = '\0';

        if (!(tituloLivro[0] == '\0'))
        {
            strcpy(aux->titulo, tituloLivro);
            printf("Título do livro de ID %d alterado para %s!\n", aux->id, aux->titulo);
        }

        printf("Informe o novo autor ou ENTER para não alterar: ");
        fgets(nomeAutor, sizeof(nomeAutor), stdin);
        nomeAutor[strcspn(nomeAutor, "\n")] = '\0';

        if (!(nomeAutor[0] == '\0'))
        {
            strcpy(aux->autor->nome, nomeAutor);
            printf("Autor do livro de ID %d alterado para %s!\n", aux->id, aux->autor->nome);
        }

        printf("Informe a nova data de lançamento ou 0 para não alterar: ");
        scanf("%d/%d/%d", &dia, &mes, &ano);

        if (!(dia == 0 || mes == 0 || ano == 0))
        {
            aux->dataPubli = criaData(dia, mes, ano);
            printf("Data de lançamento do livro de ID %d alterada para %d/%d/%d!\n", aux->id,
                   aux->dataPubli.dia,
                   aux->dataPubli.mes,
                   aux->dataPubli.ano);
        }
    }
    return;
}

void removeLivro(ListaLivros *lista, int ID)
{
    Livro *aux = buscarPorId(lista, ID);

    if (aux == NULL)
    {
        printf("\nLivro não encontraoo.\n");
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

    lista->qtdLivros--;

    // remove da lista de livros do autor

    removeLivroAutor(aux->autor, aux);
    printf("Livro de ID %d removido.\n", aux->id);
    free(aux);

    return;
}
