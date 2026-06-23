#include "biblioteca.h"
#include <string.h>

struct Usuario
{
    char *nome;
    char *email;
    ListaLivrosUsuario *listaLivros;

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

struct LivroUsuario
{
    Livro *livro;

    LivroUsuario *next;
    LivroUsuario *prev;
};

struct ListaLivrosUsuario
{
    LivroUsuario *head;
    LivroUsuario *tail;

    int qtdLivrosUsuario;
};

// FUNÇÕES

void addUsuario(ListaUsuarios *listaUsuarios, char *nome, char *email)
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

// ===== FUNÇÕES DE BUSCA =====

void buscarPorId(ListaLivros *listaLivros, int id)
{
    Livro *aux = listaLivros->head;

    while (aux != NULL)
    {

        if (aux->id == id)
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
            return;
        }
        aux = aux->next;
    }

    printf("Livro não encontrado\n");

    return;
}

void buscarPorAutor(ListaLivros *lista, char *nome)
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

void buscarUsuarioPorEmail(ListaUsuarios *lista, char *email)
{
    Usuario *aux = lista->head;

    while (aux != NULL)
    {

        if (strcmp(aux->email, email) == 0)
        {
            printf("Nome: %s\nEmail: %s\n", aux->nome, aux->email);
            return;
        }

        aux = aux->next;
    }

    return;
}

void buscarUsuarioPorNome(ListaUsuarios *lista, char *nome)
{
    Usuario *aux = NULL;

    for (aux = lista->head; aux != NULL; aux = aux->next)
    {
        if (strcmp(aux->nome, nome) == 0)
        {
            printf("Nome: %s\nEmail: %s\n", aux->nome, aux->email);
            return;
        }
    }
    printf("Usuário de nome %s não encontrado.\n", nome);
    return;
}

void mostraLivrosEmPosse(ListaUsuarios *lista, char *email)
{
    Usuario *aux_1 = NULL;
    Livro *aux_2 = NULL;

    for (aux_1 = lista->head; aux_1 != NULL; aux_1 = aux_1->next)
    {
        if (strcmp(aux_1->email, email) == 0)
        {
            for (aux_2 = aux_1->listaLivros->head->livro; aux_2 != NULL; aux_2 = aux_2->next)
            {
                printf("ID: %d\nTítulo: %s\nAutor: %s\nData: %d/%d/%d\n",
                       aux_2->id,
                       aux_2->titulo,
                       aux_2->autor->nome,
                       aux_2->dataPubli.dia,
                       aux_2->dataPubli.mes,
                       aux_2->dataPubli.ano);
            }
        }
    }

    return;
}

// ===== FUNÇÕES ÚTEIS =====

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

// ===== FUNÇÕES CRIAÇÃO =====

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

ListaLivrosAutor *criarListaLivrosAutor(void)
{
    ListaLivrosAutor *lista = (ListaLivrosAutor *)malloc(sizeof(ListaLivrosAutor));

    if (lista == NULL)
        return NULL;

    lista->head = NULL;
    lista->tail = NULL;
    lista->qtdLivrosAutor = 0;

    return lista;
}

Autor *criaAutor(char *nome)
{
    Autor *autor = (Autor *)malloc(sizeof(Autor));

    if (autor == NULL)
        return NULL;

    autor->nome = malloc(strlen(nome) + 1);

    strcpy(autor->nome, nome);
    autor->listaDoAutor = criarListaLivrosAutor();

    return autor;
}

Data criaData(int dia, int mes, int ano)
{

    Data data;

    data.dia = dia;
    data.mes = mes;
    data.ano = ano;

    return data;
}

ListaLivrosUsuario *criaListaLivrosUsuario(void)
{
    ListaLivrosUsuario *lista = (ListaLivrosUsuario *)malloc(sizeof(ListaLivrosUsuario));

    if (lista == NULL)
        return NULL;

    lista->head = NULL;
    lista->tail = NULL;
    lista->qtdLivrosUsuario = 0;

    return lista;
}

// ===== FUNÇÕES ATUALIZAÇÃO =====

void atualizaLivro(ListaLivros *lista, int ID)
{
    Livro *aux = NULL;
    char tituloLivro[30], nomeAutor[30];
    int dia = 0, mes = 0, ano = 0;
    int indicadorLogico = 0;

    for (aux = lista->head; aux != NULL; aux = aux->next)
    {
        if (aux->id == ID)
        {
            indicadorLogico = 1;

            printf("Informe o novo título ou ENTER para não alterar: ");
            fgets(tituloLivro, sizeof(tituloLivro), stdin);
            tituloLivro[strcspn(tituloLivro, "\n")] = '\0';

            if (!(tituloLivro[0] == '\0'))
            {
                strcpy(aux->titulo, tituloLivro);
                printf("Título do livro de ID %d alterado para %s!\n", aux->id, aux->titulo);
            }

            printf("Informe o novo autor ou ENTER para não alterar: ");
            getchar();
            fgets(nomeAutor, sizeof(nomeAutor), stdin);
            nomeAutor[strcspn(nomeAutor, "\n")] = '\0';

            if (!(nomeAutor[0] == '\0'))
            {
                strcpy(aux->autor->nome, nomeAutor);
                printf("Autor do livro de ID %d alterado para %s!\n", aux->id, aux->autor->nome);
            }

            printf("Informe a nova data de lançamento ou 0 para não alterar: ");
            getchar();
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
    if (indicadorLogico == 0)
        printf("Livro não localizado.\n");
    
    return;
}

// ===== FUNÇÕES MENU =====

void menuCadastro(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios)
{
    int opcao = -1;

    do
    {
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

            addUsuario(listaUsuarios, nomeUsuario, emailUsuario);

            break;

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida\n");
        }

    } while (opcao != 0);
}
void menuConsulta(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios)
{
    int opcao = -1, subOpcao = -1, ID = 0;
    char nomeAutor[30], nomeUsuario[30], emailUsuario[30];

    do
    {
        printf("\n===CONSULTA===\n");
        printf("1. Livros\n");
        printf("2. Usuários\n");
        printf("3. Empréstimo\n");
        printf("0. Sair\n");
        printf("Escolha uma opção\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("1. Buscar por ID\n");
            printf("2. Buscar por autor\n");
            scanf("%d", &subOpcao);

            if (subOpcao == 1)
            {
                printf("Informe o ID: ");
                scanf("%d", &ID);
                buscarPorId(listaLivros, ID);
            }
            else if (subOpcao == 2)
            {
                printf("Informe o nome do autor: ");
                getchar();
                fgets(nomeAutor, sizeof(nomeAutor), stdin);
                nomeAutor[strcspn(nomeAutor, "\n")] = '\0';
                buscarPorAutor(listaLivros, nomeAutor);
            }

            break;

        case 2:
            printf("1. Buscar por nome\n");
            printf("2. Buscar por email\n");
            scanf("%d", &subOpcao);

            if (subOpcao == 1)
            {
                printf("Informe o nome: ");
                getchar();
                fgets(nomeUsuario, sizeof(nomeUsuario), stdin);
                nomeUsuario[strcspn(nomeUsuario, "\n")] = '\0';
                buscarUsuarioPorNome(listaUsuarios, nomeUsuario);
            }
            else if (subOpcao == 2)
            {
                printf("Informe o email: ");
                getchar();
                fgets(emailUsuario, sizeof(emailUsuario), stdin);
                emailUsuario[strcspn(emailUsuario, "\n")] = '\0';
                buscarUsuarioPorEmail(listaUsuarios, emailUsuario);
            }

            break;

        case 3:
            printf("Informe o email: ");
            getchar();
            fgets(emailUsuario, sizeof(emailUsuario), stdin);
            emailUsuario[strcspn(emailUsuario, "\n")] = '\0';
            mostraLivrosEmPosse(listaUsuarios, emailUsuario);

            break;

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida\n");
        }

    } while (opcao != 0);
}
void menuAtualizacao(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios);
void menuExclusao(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios);
void menuEmprestimo(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios);
void menuDevolucao(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios);
