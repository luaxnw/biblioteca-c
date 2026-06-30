# Sistema de Controle de Biblioteca
Trabalho final da disciplina de estrutura de dados da Universidade Federal da Fronteira Sul. O projeto consiste em um sistema de controle de biblioteca. Permite cadastro, consulta, atualização, exclusão... Foi feito inteiramente na linguagem C.

## Funcionalidades

### Livros

* Cadastro de livros.
* Consulta por ID.
* Consulta por autor.
* Atualização de título, autor e data de publicação.
* Remoção de livros.

### Usuários

* Cadastro de usuários.
* Consulta por nome.
* Consulta por e-mail.
* Atualização de nome e e-mail.
* Remoção de usuários.

### Empréstimos

* Empréstimo de livros para usuários cadastrados.
* Devolução de livros.
* Consulta dos livros atualmente emprestados para um usuário.

## Estruturas utilizadas

O sistema utiliza as seguintes estruturas:

* Lista duplamente encadeada de usuários.
* Lista duplamente encadeada de livros.
* Lista de livros associados a cada autor.
* Estruturas para autores e datas de publicação.

## Organização

As principais operações implementadas são:

* Criação das listas.
* Cadastro de usuários e livros.
* Busca por ID, nome, autor e e-mail.
* Atualização de registros.
* Exclusão de registros.
* Controle de empréstimos e devoluções.
* Menus para navegação das funcionalidades.

## Como executar

Compile o projeto utilizando um compilador C, como o GCC.

Exemplo:

```bash
gcc -Wall biblioteca.c main.c -o main
```

Execute o programa:

```bash
./main
```

## Tecnologias utilizadas

* Linguagem C
* Biblioteca padrão da linguagem (`stdio.h`, `stdlib.h`, `string.h`)

## Observações

* Os dados são armazenados apenas durante a execução do programa.
* Não há persistência em arquivos ou banco de dados.
* Cada livro possui um ID único utilizado para consultas, empréstimos e remoções.
* O sistema impede o cadastro de usuários com e-mails já existentes.

