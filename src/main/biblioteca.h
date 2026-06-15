typedef struct tData data;

typedef struct tUsuario usuario;
typedef struct TlistaUsuarios listaUsuarios;

typedef struct tLivro livro;
typedef struct tListaLivros listaLivros;

// FUNÇÕES

// Funções adicionar

void addUser(listaUsuarios *listaUsuarios, char *nome, char *email);

void addLivro(listaLivros *listaLivros, char *titulo, char *autor, data dataPubli, usuario *usuarioRespo);

// Funções buscar
void buscarPorId(listaLivros *listaLivros, int id);

void buscarPorAutor(listaLivros *listaLivros, char *autor);