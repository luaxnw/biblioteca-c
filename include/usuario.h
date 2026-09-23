#ifndef USUARIO_H
#define USUARIO_H

#define SIZE_NOME 30

typedef struct Usuario
{
    char nome[SIZE_NOME];
    char email[SIZE_NOME];

    Usuario *next;
    Usuario *prev;

} Usuario;

typedef struct ListaUsuarios
{
    Usuario *head;
    Usuario *tail;

    int qtdUsuarios;
} ListaUsuarios;

ListaUsuarios *criarListaUsuarios(void);

void addUsuario(
    ListaUsuarios *lista,
    char nome[SIZE_NOME],
    char email[SIZE_NOME]
);

void buscarUsuarioPorEmail(
    ListaUsuarios *lista,
    char email[SIZE_NOME]
);

void buscarUsuarioPorNome(
    ListaUsuarios *lista,
    char nome[SIZE_NOME]
);

Usuario *procuraUsuarioPorEmail(
    ListaUsuarios *lista,
    char email[SIZE_NOME]
);

void atualizaUsuario(
    ListaUsuarios *lista,
    char emailUsuario[SIZE_NOME]
);

void removeUsuario(
    ListaUsuarios *lista,
    char emailUsuario[SIZE_NOME]
);

#endif
