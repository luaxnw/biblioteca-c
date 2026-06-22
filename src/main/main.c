#include "biblioteca.h"

int main()
{
    ListaLivros *listaLivros = criarListaLivros();
    ListaUsuarios *listaUsuarios = criarListaUsuarios();
    Autor *autor_1 = criaAutor("Machado de Assis");
    Autor *autor_2 = criaAutor("Clarice Lispector");
    Data data_1 = criaData(20, 03, 1950);
    Data data_2 = criaData(05, 06, 1976);
    Data data_3 = criaData(25, 04, 1980);
    Data data_4 = criaData(05, 03, 2005);
    Data data_5 = criaData(28, 02, 1899);
    Data data_6 = criaData(04, 07, 1970);

    addLivro(listaLivros, "Água", autor_1, data_1);
    addLivro(listaLivros, "Pedra", autor_1, data_2);
    addLivro(listaLivros, "Areia", autor_1, data_3);

    addUser(listaUsuarios, "Ana Silva", "ana.silva@gmail.com");
    addUser(listaUsuarios, "Bruno Costa", "bruno.costa@hotmail.com");
    addUser(listaUsuarios, "Camila Rodrigues", "camila.r@outlook.com");
    addUser(listaUsuarios, "Diego Almeida", "diego.almeida@yahoo.com");
    addUser(listaUsuarios, "Elena Martins", "elena.martins@gmail.com");
    addUser(listaUsuarios, "Felipe Santos", "felipe.santos@outlook.com");

    buscaUsuarioPorEmail(listaUsuarios, "ana.silva@gmail.com");
    printf("%d ", buscaUsuarioPorEmail(listaUsuarios, "ana.silva@gmail.com"));
    printf("%d ", buscaUsuarioPorEmail(listaUsuarios, "diego.almeida@yahoo.com"));
    printf("%d ", buscaUsuarioPorEmail(listaUsuarios, "cleber.almeida@yahoo.com"));


    buscaUsuarioPorNome(listaUsuarios, "Ana Silva");

    int opcaoPrincipal = -1;
    /*
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
    */

    // mostraListaLivros(listaLivros);
    // mostraListaUsuarios(listaUsuarios);

    return 0;
}