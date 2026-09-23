#ifndef MENU_H
#define MENU_H

void menuCadastro(
    ListaLivros *listaLivros,
    ListaUsuarios *listaUsuarios
);

void menuConsulta(
    ListaLivros *listaLivros,
    ListaUsuarios *listaUsuarios
);

void menuAtualizacao(
    ListaLivros *listaLivros,
    ListaUsuarios *listaUsuarios
);

void menuExclusao(
    ListaLivros *listaLivros,
    ListaUsuarios *listaUsuarios
);

void menuEmprestimo(
    ListaLivros *listaLivros,
    ListaUsuarios *listaUsuarios
);

void menuDevolucao(
    ListaLivros *listaLivros,
    ListaUsuarios *listaUsuarios
);

#endif
