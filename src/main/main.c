#include "biblioteca.h"

int main()
{

    ListaLivros *listaLivros = criarListaLivros();
    ListaUsuarios *listaUsuarios = criarListaUsuarios();

    int opcaoPrincipal = -1;

    do
    {

        printf("\n=====BIBLIOTECA DA UFFS=====\n");
        printf("=====1. CADASTRO=====\n");
        printf("=====2. CONSULTA=====\n");
        printf("=====3. ATUALIZAÇÃO DE DADOS=====\n");
        printf("=====4. EXCLUSÃO=====\n");
        printf("=====5. EMPRÉSTIMO=====\n");
        printf("=====6. DEVOLUÇÃO=====\n");
        printf("=====0. SAIR=====\n");
        printf("Escolha uma opção\n");

        scanf("%d", &opcaoPrincipal);

        switch (opcaoPrincipal)
        {
        case 1:
            menuCadastro(listaLivros, listaUsuarios);
            break;

        default:
            printf("Opção inválida\n");
        }

    } while (opcaoPrincipal != 0);

    mostraListaLivros(listaLivros);
    mostraListaUsuarios(listaUsuarios);

    return 0;
}