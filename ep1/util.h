/*STRUCTS*/

typedef struct CPodcast {
  char nome[64];
  int id;
} CPodcast;

typedef CPodcast Podcast;

typedef struct Episodio {
  Podcast podcast;

  char nome[64];
  int id;
} Episodio;

typedef struct Celula {
  struct Celula * proximo;
  struct Celula * anterior;

  Episodio * episodio;
} Celula;

typedef struct Cabeca {
  Celula * atual;
  Celula * inicio;
  Celula * fim;
  Podcast podcasts[16];
  int shuffle;

} Cabeca;
typedef Cabeca * Lista;

/*CRUD*/

//Adiciona um item no fim da lista
//Todos os ids de podcasts são 1 (não consegui implementar o relatório)
void adicionar(Lista lista);

//Remove um item pelo id que o usuário insere
void remover(Lista lista);

//Exibe o atual
void exibirAtual(Lista lista);

//Ativa o modo de shuffle
void shuffle(Lista lista);

//Exibe o próximo podcast e o configura como atual da lista
void exibirProximo(Lista lista);

//Retorna o indice do podcast num array (não funcional)
Podcast * procurarPodcast(Lista lista, Podcast * podcast);

//Inicia uma lista configurada
Lista iniciarLista();

//Método utilitário para remover caracter \n
void remove_newline_ch(char *line);

//Exibe todos os episódios da lista
void exibirPlaylist(Lista lista);

//Exibe relatório de podcasts (não funcional)
void exibirPodcasts(Lista lista);

//Configura todos os ponteiros da lista como null
void resetar(Lista lista);

//Exibe lista de podcasts da playlist (Não está filtrando os podcasts iguais, por enquanto)
void exibirPodcasts(Lista lista);
