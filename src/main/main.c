#include "biblioteca.h"

int main()
{
    ListaLivros *listaLivros = criarListaLivros();
    ListaUsuarios *listaUsuarios = criarListaUsuarios();
    BST *arvore = criaArvore();

    Autor *autor_1 = criaAutor("machado");
    Autor *autor_2 = criaAutor("clarice");
    Data data_1 = criaData(20, 03, 1950);
    Data data_2 = criaData(05, 06, 1976);
    Data data_3 = criaData(25, 04, 1980);
    Data data_4 = criaData(05, 03, 2005);
    Data data_5 = criaData(28, 02, 1899);
    Data data_6 = criaData(04, 07, 1970);

    addLivro(listaLivros, "Água", autor_1, data_1, arvore);
    addLivro(listaLivros, "Pedra", autor_1, data_2, arvore);
    addLivro(listaLivros, "Areia", autor_1, data_3, arvore);

    addLivro(listaLivros, "titulo_1", autor_2, data_4, arvore);
    addLivro(listaLivros, "titulo_2", autor_2, data_5, arvore);
    addLivro(listaLivros, "titulo_3", autor_2, data_6, arvore);

    addUsuario(listaUsuarios, "Ana Silva", "ana.silva@gmail.com");
    addUsuario(listaUsuarios, "Bruno Costa", "bruno.costa@hotmail.com");
    addUsuario(listaUsuarios, "Camila Rodrigues", "camila.r@outlook.com");
    addUsuario(listaUsuarios, "Diego Almeida", "diego.almeida@yahoo.com");
    addUsuario(listaUsuarios, "Elena Martins", "elena.martins@gmail.com");
    addUsuario(listaUsuarios, "Felipe Santos", "felipe.santos@outlook.com");
    addUsuario(listaUsuarios, "roger", "roger.com");


    
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
            menuCadastro(listaLivros, listaUsuarios, arvore);
            break;
        case 2:
            menuConsulta(listaLivros, listaUsuarios);
            break;
        case 3:
            menuAtualizacao(listaLivros, listaUsuarios);
            break;
        

        default:
            printf("Opção inválida\n");
        }

    } while (opcaoPrincipal != 0);

    return 0;
}