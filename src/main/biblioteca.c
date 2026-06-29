#include "biblioteca.h"
#include <string.h>

struct Usuario
{
    char nome[SIZE_NOME];
    char email[SIZE_NOME];

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
    char nome[SIZE_NOME];
    ListaLivrosAutor *listaDoAutor;
};

// FUNÇÕES

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
        printf("Email não cadastrado!\nO email que você está tentando cadastrar já consta no sistema.\n");
        return;
    }

    // adiciona no final
    new->prev = listaUsuarios->tail;
    listaUsuarios->tail->next = new;
    listaUsuarios->tail = new;

    printf("Usuário cadastrado\n");
    return;
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

void mostrarLivro(Livro *livro)
{
    if (livro != NULL)
    {
        printf("ID: %d\nTítulo: %s\nAutor: %s\nData de lançamento: %d/%d/%d\n",
               livro->id,
               livro->titulo,
               livro->autor->nome,
               livro->dataPubli.dia,
               livro->dataPubli.mes,
               livro->dataPubli.ano);
        mostraStatusLivro(livro);
        return;
    }
    return;
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

void buscarUsuarioPorEmail(ListaUsuarios *lista, char email[SIZE_NOME])
{
    Usuario *usuario = procuraUsuarioPorEmail(lista, email);

    if (usuario != NULL)
        printf("Nome: %s\nEmail: %s\n", usuario->nome, usuario->email);
}

void buscarUsuarioPorNome(ListaUsuarios *lista, char nome[SIZE_NOME])
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

void mostraLivrosEmPosse(ListaUsuarios *listaUsuarios, ListaLivros *listaLivros, char email[SIZE_NOME])
{
    Usuario *aux_1 = procuraUsuarioPorEmail(listaUsuarios, email);
    Livro *aux_2 = NULL;

    if (aux_1 == NULL)
    {
        printf("Usuário não localizado.\n");
        return;
    }

    for (aux_2 = listaLivros->head; aux_2 != NULL; aux_2 = aux_2->next)
    {
        if (strcmp(aux_2->emailResponsavel, aux_1->email) == 0)
        {
            printf("ID: %d\nTítulo: %s\nAutor: %s\nData de lançamento: %d/%d/%d\n", aux_2->id,
                   aux_2->titulo,
                   aux_2->autor->nome,
                   aux_2->dataPubli.dia,
                   aux_2->dataPubli.mes,
                   aux_2->dataPubli.ano);
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

Livro *buscarPorId(ListaLivros *lista, int id)
{
    Livro *aux = NULL;

    for (aux = lista->head; aux != NULL; aux = aux->next)
    {
        if (aux->id == id)
            return aux;
    }

    printf("Livro não encontrado.\n");

    return NULL;
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

Autor *criaAutor(char nome[SIZE_NOME])
{
    Autor *autor = (Autor *)malloc(sizeof(Autor));

    if (autor == NULL)
        return NULL;

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

// ===== FUNÇÕES ATUALIZAÇÃO =====

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

// ===== FUNÇÕES EXCLUSÃO =====

void removeLivro(ListaLivros *lista, int ID)
{
    Livro *aux = buscarPorId(lista, ID);

    if (aux == NULL)
    {
        printf("Livro não encontraoo.\n");
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

// ===== FUNÇÕES EMPRÉSTIMOS =====

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

    printf("Livro de ID %d devolvido.\n", livro->id);

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
            char titulo[SIZE_TITULO], nomeAutor[SIZE_NOME];
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
            char nomeUsuario[SIZE_NOME], emailUsuario[SIZE_NOME];

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
    char nomeAutor[SIZE_NOME], nomeUsuario[SIZE_NOME], emailUsuario[SIZE_NOME];

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
                mostrarLivro(buscarPorId(listaLivros, ID));
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
            mostraLivrosEmPosse(listaUsuarios, listaLivros, emailUsuario);

            break;

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida\n");
        }

    } while (opcao != 0);
}
void menuAtualizacao(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios)
{
    int opcao = -1, ID = 0;
    char emailUsuario[SIZE_NOME];

    do
    {
        printf("\n===ATUALIZAÇÃO===\n");
        printf("1. Livro\n");
        printf("2. Usuário\n");
        printf("0. Voltar\n");
        printf("Opção: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Informe o ID do livro: ");
            scanf("%d", &ID);
            atualizaLivro(listaLivros, ID);
            break;

        case 2:
            printf("Informe o email do usuário: ");
            getchar();
            fgets(emailUsuario, sizeof(emailUsuario), stdin);
            emailUsuario[strcspn(emailUsuario, "\n")] = '\0';
            atualizaUsuario(listaUsuarios, emailUsuario);
            break;

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida\n");
        }

    } while (opcao != 0);
}

void menuExclusao(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios)
{
    int opcao = -1, ID = 0;
    char emailUsuario[SIZE_NOME];

    do
    {
        printf("\n===EXCLUSÃO===\n");
        printf("1. Livro\n");
        printf("2. Usuário\n");
        printf("0. Voltar\n");
        printf("Opção: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Informe o ID do livro: ");
            scanf("%d", &ID);
            removeLivro(listaLivros, ID);
            break;

        case 2:
            printf("Informe o email do usuário: ");
            getchar();
            fgets(emailUsuario, sizeof(emailUsuario), stdin);
            emailUsuario[strcspn(emailUsuario, "\n")] = '\0';
            removeUsuario(listaUsuarios, emailUsuario);
            break;

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida\n");
        }

    } while (opcao != 0);
}

void menuEmprestimo(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios)
{
    int opcao = -1, ID = 0;
    char emailUsuario[SIZE_NOME];
    Livro *livro = NULL;

    do
    {
        printf("\n===EMPRÉSTIMO===\n");
        printf("1. Livro\n");
        printf("0. Voltar\n");
        printf("Opção: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Informe o ID do livro: ");
            scanf("%d", &ID);
            livro = buscarPorId(listaLivros, ID);

            if (livro == NULL)
            {
                printf("Livro não encontrdo.\n");
                break;
            }

            if (livro->status == 1)
            {
                printf("Livro não está disponível para empréstimo.\n");
                break;
            }

            printf("ID: %d\nTítulo: %s\nAutor: %s\nData de lançamento: %d/%d/%d\n", livro->id,
                   livro->titulo,
                   livro->autor->nome,
                   livro->dataPubli.dia,
                   livro->dataPubli.mes,
                   livro->dataPubli.ano);
            printf("\n");

            printf("Informe o email do usuário: ");
            getchar();
            fgets(emailUsuario, sizeof(emailUsuario), stdin);
            emailUsuario[strcspn(emailUsuario, "\n")] = '\0';
            emprestaLivro(livro, listaUsuarios, ID, emailUsuario);

            break;

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida\n");
        }

    } while (opcao != 0);
}

void menuDevolucao(ListaLivros *listaLivros, ListaUsuarios *listaUsuarios)
{
    int opcao = -1, ID = 0;

    do
    {
        printf("\n===DEVOLUÇÃO===\n");
        printf("1. Livro\n");
        printf("0. Voltar\n");
        printf("Opção: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Informe o ID do livro: ");
            scanf("%d", &ID);
            devolveLivro(listaLivros, ID);
            break;

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida\n");
        }

    } while (opcao != 0);
}
