#include "biblioteca.h"

struct data {
    int dia;
    int mes;
    int ano;
};

struct usuario {
    char *nome;
    char *email;
    struct usuario *next;
    struct usuario *prev;
}; 

struct listaUsuarios {
    struct usuario *head;
    struct usuario *tail;
    int qtdUsuarios;
};

struct livro {
    char *titulo;
    char *autor;
    struct data dataPubli;
    int id;
    int status;
    struct usuario usuarioRespo;
};

struct listaLivros {
    struct livro *head;
    struct livro *tail;
    int qtdLivros;
};