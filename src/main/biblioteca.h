/* Tipos */

typedef struct Data Data;

typedef struct Usuario Usuario;
typedef struct ListaUsuarios ListaUsuarios;

typedef struct Autor Autor;

typedef struct Livro Livro;
typedef struct ListaLivros ListaLivros;

typedef struct LivroAutor LivroAutor;
typedef struct ListaLivrosAutor ListaLivrosAutor;


/* Funções de cadastro */

void addUser(
    ListaUsuarios *lista,
    char *nome,
    char *email
);

void addLivro(
    ListaLivros *lista,
    char *titulo,
    Autor *autor,
    Data dataPubli,
    Usuario *usuarioRespo
);

void addLivroAutor(
    Autor *autor,
    Livro *livro
);


/* Funções de busca */

void buscarPorId(
    ListaLivros *lista,
    int id
);

void buscarPorAutor(
    Autor *autor
);
