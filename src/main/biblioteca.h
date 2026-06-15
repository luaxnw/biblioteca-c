typedef struct tData data;

typedef struct tUsuario usuario;
typedef struct TlistaUsuarios listaUsuarios;

typedef struct tLivro livro;
typedef struct tListaLivros listaLivros;

void addUser(listaUsuarios *listaUsuarios, char *nome, char *email);

void addLivro(listaLivros *listaLivros, char *titulo, char *autor, data dataPubli, int id, int status, usuario *usuarioRespo);