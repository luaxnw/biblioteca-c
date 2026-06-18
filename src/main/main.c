#include "biblioteca.h"

int main(){


    ListaUsuarios *listaUsers = criarListaUsuarios();
    ListaLivros *listaLiv = criarListaLivros();

    addUser(listaUsers, "Luan", "Luan@gg");
    addUser(listaUsers, "Luiz", "Luiz@gg");
    addUser(listaUsers, "Silva", "Silva@gg");
    addUser(listaUsers, "Pescador", "Pescador@gg");

    printf("%d\n", buscaUsuarioPorEmail(listaUsers, "Luang"));

    
    free(listaUsers);
    free(listaLiv);
}