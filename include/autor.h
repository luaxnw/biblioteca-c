#ifndef AUTOR_H
#define AUTOR_H

#define SIZE_NOME 30

typedef struct Autor Autor;
typedef struct Livro Livro;

Autor *criaAutor(char nome[SIZE_NOME]);

void addLivroAutor(Autor *autor, Livro *livro);
void removeLivroAutor(Autor *autor, Livro *livro);

#endif
