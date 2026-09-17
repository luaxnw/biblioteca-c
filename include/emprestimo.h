#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

typedef struct Livro Livro;
typedef struct ListaUsuarios ListaUsuarios;
typedef struct ListaLivros ListaLivros;

void emprestaLivro(
    Livro *livro,
    ListaUsuarios *listaUsuarios,
    int ID,
    char emailUsuario[30]
);

void devolveLivro(
    Livro *livro,
    int ID
);

void mostraLivrosEmPosse(
    ListaUsuarios *listaUsuarios,
    ListaLivros *listaLivros,
    char email[30]
);

#endif
