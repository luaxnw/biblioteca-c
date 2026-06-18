#include "biblioteca.h"
#include <string.h>

struct Data
{
    int dia;
    int mes;
    int ano;
};

struct Usuario
{
    char *nome;
    char *email;

    Usuario *next;
    Usuario *prev;
};

struct ListaUsuarios
{
    Usuario *head;
    Usuario *tail;

    int qtdUsuarios;
};

struct Livro
{
    char *titulo;
    Autor *autor;
    Data dataPubli;
    int id;
    int status;
    char *emailResponsavel;

    Livro *next;
    Livro *prev;
};

struct ListaLivros
{
    Livro *head;
    Livro *tail;

    int qtdLivros;
};

struct LivroAutor
{
    Livro *livro;

    LivroAutor *next;
    LivroAutor *prev;
};

struct ListaLivrosAutor
{
    LivroAutor *head;
    LivroAutor *tail;

    int qtdLivrosAutor;
};

struct Autor
{
    char *nome;
    ListaLivrosAutor *listaDoAutor;
};

// FUNÇÕES

void addUser(ListaUsuarios *listaUsuarios, char *nome, char *email)
{
    Usuario *new = (Usuario *)malloc(sizeof(Usuario));
    listaUsuarios->qtdUsuarios++; // toda chamada adiciona 1 na qtdUsers

    new->nome = malloc(strlen(nome) + 1);
    new->email = malloc(strlen(email) + 1);
    
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

    Usuario *aux = listaUsuarios->head;

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

void addLivro(ListaLivros *listaLivros, char *titulo, Autor *autor, Data dataPubli, char *emailResponsavel)
{

    Livro *new = (Livro *)malloc(sizeof(Livro));

    if (new == NULL) // erro de alocação
        return;

    new->titulo = malloc(strlen(titulo) + 1);
    new->emailResponsavel = malloc(strlen(emailResponsavel) + 1);


    strcpy(new->titulo, titulo);
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

void addLivroAutor(Autor *autor, Livro *livro)
{
    LivroAutor *new = (LivroAutor *)malloc(sizeof(LivroAutor));

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
void buscarPorId(ListaLivros *listaLivros, int id)
{
    Livro *aux = listaLivros->head;

    while (aux != NULL)
    {

        if (aux->id == id)
        {
            printf("ID: %d\nTítulo: %s\nAutor: %s\nData de publicação: %d/%d/%d\nUsuário responsável: %s\n",
                   aux->id,
                   aux->titulo,
                   aux->autor->nome,
                   aux->dataPubli.dia,
                   aux->dataPubli.mes,
                   aux->dataPubli.ano,
                   aux->emailResponsavel);
            mostraStatusLivro(aux);
            return;
        }
        aux = aux->next;
    }

    printf("Livro não encontrado");

    return;
}

void buscarPorAutor(Autor *autor)
{
    Livro *aux = NULL;

    for (aux = autor->listaDoAutor->head->livro; aux != NULL; aux = aux->next)
    {
        printf("ID: %d\nTítulo: %s\nAutor: %s\nData de publicação: %d/%d/%d\nUsuário responsável: %s\n",
               aux->id,
               aux->titulo,
               aux->autor->nome,
               aux->dataPubli.dia,
               aux->dataPubli.mes,
               aux->dataPubli.ano,
               aux->emailResponsavel);   
               mostraStatusLivro(aux);
    }

    printf("Livro não encontrado");

    return;
}

int buscaUsuarioPorEmail(ListaUsuarios *lista, char *email){

    Usuario *aux = NULL;

    for (aux = lista->head; aux != NULL; aux = aux->next)
    {
        if (strcmp(aux->email, email) == 0)
            return 1;
    }

    printf("Usuário não econtrado.\n");

    return 0;
}

void mostraStatusLivro(Livro *livro)
{

    if (livro->status == 0)
        printf("Dispoível\n");
    else
    {
        printf("Indisponível\n");
    }

    return;
}

// Funções criação das listas

ListaUsuarios *criarListaUsuarios(void)
{
    ListaUsuarios *lista = (ListaUsuarios*) malloc(sizeof(ListaUsuarios));

    lista->head = NULL;
    lista->tail = NULL;
    lista->qtdUsuarios = 0;

    return lista;
}

ListaLivros *criarListaLivros(void)
{
    ListaLivros *lista = (ListaLivros*) malloc(sizeof(ListaLivros));

    lista->head = NULL;
    lista->tail = NULL;
    lista->qtdLivros = 0;

    return lista;
}

ListaLivrosAutor *criarListaLivrosAutor(void)
{
    ListaLivrosAutor *lista = (ListaLivrosAutor*) malloc(sizeof(ListaLivrosAutor));
    
    lista->head = NULL;
    lista->tail = NULL;
    lista->qtdLivrosAutor = 0;

    return lista;
}