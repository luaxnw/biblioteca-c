#include "livro.h"
#include "usuario.h"
#include "autor.h"
#include "emprestimo.h"
#include "menu.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

            printf("\nTítulo do livro: ");
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
        printf("Opção: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("1. Buscar por ID\n");
            printf("2. Buscar por autor\n");
            printf("Opção: ");

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
            printf("Opção: ");

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
                printf("\nLivro não encontrdo.\n");
                break;
            }

            if (livro->status == 1)
            {
                printf("Livro não está disponível para empréstimo.\n");
                break;
            }

            printf("\nID: %d\nTítulo: %s\nAutor: %s\nData de lançamento: %d/%d/%d\n", livro->id,
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

