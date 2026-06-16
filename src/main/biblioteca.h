typedef struct tData data;
typedef struct tUsuario usuario;
typedef struct tListaUsuarios listaUsuarios;

typedef struct tLivro livro;
typedef struct TlistaLivros listaLivros;

typedef struct tAutor autor;
typedef struct tLivroAutor livroAutor;
typedef struct tListaLivrosAutor listaLivrosAutor;

// FUNÇÕES

// Funções adicionar

void addUser(listaUsuarios *listaUsuarios, char *nome, char *email);

void addLivro(listaLivros *listaLivros, char *titulo, autor *autor, data dataPubli, usuario *usuarioRespo);

void addLivroAutor(autor *autor, livro *livro);

// Funções buscar

void buscarPorId(listaLivros *listaLivros, int id);

void buscarPorAutor(autor *autor);
