#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#define SIZE_NOME 30

typedef struct ListaUsuarios ListaUsuarios;
typedef struct ListaLivros ListaLivros;
typedef struct Livro Livro;
typedef struct Data Data;


void emprestaLivro(
    Livro *livro,
    ListaUsuarios *listaUsuarios,
    int ID,
    char emailUsuario[SIZE_NOME]
);

void devolveLivro(
    ListaLivros *lista,
    int ID
);

void mostraLivrosEmPosse(
    ListaUsuarios *listaUsuarios,
    ListaLivros *listaLivros,
    char email[SIZE_NOME]
);

#endif
