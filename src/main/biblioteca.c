#include "biblioteca.h"
#include <string.h>

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
        printf("Usuário cadastrado\n");

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

    printf("Usuário cadastrado\n");
    return;
}

void addLivro(ListaLivros *listaLivros, char *titulo, Autor *autor, Data dataPubli)
{

    Livro *new = (Livro *)malloc(sizeof(Livro));

    if (new == NULL) // erro de alocação
        return;

    new->titulo = malloc(strlen(titulo) + 1);

    strcpy(new->titulo, titulo);
    new->emailResponsavel = '\0';
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
        printf("Livro cadastrado\n");

        return;
    }

    // adiciona no final
    new->prev = listaLivros->tail;
    listaLivros->tail->next = new;
    listaLivros->tail = new;
    listaLivros->qtdLivros++; // toda chamada adiciona 1 na qtdLivros

    printf("Livro cadastrado\n");
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
        printf("Livro cadastrado na lista do autor\n");

        return;
    }

    // adiciona o novo livro no final da lista do autor

    new->prev = autor->listaDoAutor->tail;
    autor->listaDoAutor->tail->next = new;
    autor->listaDoAutor->tail = new;
    autor->listaDoAutor->qtdLivrosAutor++;

    printf("Livro cadastrado na lista do autor\n");

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
    LivroAutor *aux = NULL;

    for (aux = autor->listaDoAutor->head; aux != NULL; aux = aux->next)
    {
        printf("ID: %d\nTítulo: %s\nAutor: %s\nData de publicação: %d/%d/%d\nUsuário responsável: %s\n",
               aux->livro->id,
               aux->livro->titulo,
               aux->livro->autor->nome,
               aux->livro->dataPubli.dia,
               aux->livro->dataPubli.mes,
               aux->livro->dataPubli.ano,
               aux->livro->emailResponsavel);   
               mostraStatusLivro(aux->livro);
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
    return 0;
}

// Funções úteis

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

void mostraListaLivros(ListaLivros *lista)
{
    Livro *aux = NULL;

    for (aux = lista->head; aux != NULL; aux = aux->next)
    {
        printf("%s, %s, %d", aux->autor->nome, aux->titulo, aux->id);
    }
    printf("\nFIM\n");
    return;
}

void mostraListaUsuarios(ListaUsuarios *lista)
{
    Usuario *aux = NULL;

    for (aux = lista->head; aux != NULL; aux = aux->next)
    {
        printf("%s, %s", aux->nome, aux->email);
    }
    printf("\nFIM\n");
    return;
  
}


// Funções criação das listas

ListaUsuarios *criarListaUsuarios(void)
{
    ListaUsuarios *lista = (ListaUsuarios*) malloc(sizeof(ListaUsuarios));

    if (lista == NULL)
        return NULL;

    lista->head = NULL;
    lista->tail = NULL;
    lista->qtdUsuarios = 0;

    return lista;
}

ListaLivros *criarListaLivros(void)
{
    ListaLivros *lista = (ListaLivros*) malloc(sizeof(ListaLivros));

    if (lista == NULL)
        return NULL;

    lista->head = NULL;
    lista->tail = NULL;
    lista->qtdLivros = 0;

    return lista;
}

ListaLivrosAutor *criarListaLivrosAutor(void)
{
    ListaLivrosAutor *lista = (ListaLivrosAutor*) malloc(sizeof(ListaLivrosAutor));

    if (lista == NULL)
        return NULL;
    
    lista->head = NULL;
    lista->tail = NULL;
    lista->qtdLivrosAutor = 0;

    return lista;
}

Autor *criaAutor(char *nome)
{
    Autor *autor = (Autor*) malloc(sizeof(Autor));

    if (autor == NULL)
        return NULL;

    autor->nome = malloc(strlen(nome) + 1);

    strcpy(autor->nome, nome);
    autor->listaDoAutor = criarListaLivrosAutor();

    return autor;
}

Data criaData(int dia, int mes, int ano){

    Data data;
    
    data.dia = dia;
    data.mes = mes;
    data.ano = ano;

    return data;
}

// Funções menu

void menuCadastro(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios)
{
    int opcao;

    do {
        printf("\n===CADASTRO===\n");
        printf("1. Livro\n");
        printf("2. Usuário\n");
        printf("0. Voltar\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            char titulo[30], nomeAutor[30];
            int dia, mes, ano;
            
            printf("Título do livro: ");
            getchar();
            fgets(titulo, sizeof(titulo), stdin);
            titulo[strcspn(titulo, "\n")] = '\0';

            printf("Nome do autor: ");
            fgets(nomeAutor, sizeof(nomeAutor), stdin);
            nomeAutor[strcspn(nomeAutor, "\n")] = '\0';
            Autor *autor = criaAutor(nomeAutor);

            printf("Data de lançamento do livro: ");
            scanf("%d/%d/%d", &dia, &mes, &ano);
            Data dataLancamento = criaData(dia, mes, ano);

            addLivro(listaLivros, titulo, autor, dataLancamento);

            break;

        case 2:
            char nomeUsuario[30], emailUsuario[30];

            printf("Nome do usuário: ");
            getchar();
            fgets(nomeUsuario, sizeof(nomeUsuario), stdin);
            nomeUsuario[strcspn(nomeUsuario, "\n")] = '\0';

            printf("Email do usuário: ");
            fgets(emailUsuario, sizeof(emailUsuario), stdin);
            emailUsuario[strcspn(emailUsuario, "\n")] = '\0';

            addUser(listaUsuarios, nomeUsuario, emailUsuario);

            break;
        
        default:
            printf("Opção inválida\n");
        }


    } while (opcao != 0);

}
void menuConsulta(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios);
void menuAtualizacao(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios);
void menuExclusao(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios);
void menuEmprestimo(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios);
void menuDevolucao(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios);
