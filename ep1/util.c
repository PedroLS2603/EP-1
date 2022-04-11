#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "util.h"

static int idPodcast = 1;

/*Algoritmo de busca da lista de podcasts da lista*/

Podcast * procurarPodcast(Lista lista, Podcast * podcast) {
  int comparacao; 
  for(Celula * aux = lista->inicio; aux != NULL; aux = aux->proximo) {
    comparacao = strcmp(aux->episodio->podcast.nome, podcast->nome);
    if(strcmp(aux->episodio->podcast.nome, podcast->nome) == 0) {
      return podcast;
    }
  }
  return NULL;
}

Celula * criaCelula() {
  Episodio * novoEp = malloc(sizeof(Episodio));
  Celula * nova = malloc(sizeof(Celula));
  Podcast podcast;
  
  printf("\nDigite o número do episódio: ");
  scanf("%d", &novoEp->id);
  getchar();
  
  printf("\nDigite o nome do episódio: ");
  fgets(novoEp->nome, 64, stdin);
  remove_newline_ch(novoEp->nome);

  printf("\nDigite o nome do podcast: ");
  fgets(podcast.nome, 64, stdin);
  remove_newline_ch(podcast.nome);
  
  podcast.id = idPodcast;

  novoEp->podcast = podcast;

  nova->episodio = novoEp;

  return nova;
}



void resetar(Lista lista) { 
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->atual = NULL;
}

void resetarCelula(Celula * celula) {
  celula->anterior = NULL;
  celula->proximo = NULL;
}



void adicionar(Lista lista) {  
  Celula * nova = criaCelula();
  Podcast * resultadoPesquisa = procurarPodcast(lista, &nova->episodio->podcast);
  
  if(resultadoPesquisa != NULL) {
    nova->episodio->podcast = *resultadoPesquisa;
  }
  else {
    idPodcast++;
  }
  
  //Adiciona novo episódio na lista
  if(lista->inicio == NULL) {    
    lista->inicio = nova;
    lista->fim = nova;
    lista->atual = nova;

    nova->anterior = NULL;
    nova->proximo = NULL;


  } else {
    nova->anterior = lista->fim;
    nova->proximo = NULL;
    lista->fim->proximo = nova;
    lista->fim = nova;
  }
  system("clear");
  printf("\nEpisódio adicionado com sucesso! :)\n");
}

void exibirAtual(Lista lista) {

  if(lista->atual != NULL) {
    printf("Estou no episódio %s do podcast %s", lista->atual->episodio->nome, lista->atual->episodio->podcast.nome);
    
  }
  else {
    printf("Não há nenhum podcast na fila!");
  }
}

void exibirProximo(Lista lista) {
  system("clear");
  Celula * aux = lista->atual;
  Episodio * ep;

  if(aux != NULL && aux->proximo != NULL) {
    if(lista->shuffle == 1) {
      if(aux->proximo->proximo != NULL) {
        lista->atual = lista->atual->proximo->proximo;
      }
      else if(aux->proximo == lista->fim) {
        lista->atual = lista->inicio;
      }
      else if(aux == lista->fim) {
        printf("Sua fila zerou! :(");
        return;
      }
      ep = lista->atual->episodio;
  
      printf("Próximo: %d - %s (%s)", ep->id, ep->nome, ep->podcast.nome);
    }
    else {

      lista->atual = lista->atual->proximo;
      ep = lista->atual->episodio;
      printf("Próximo: %d - %s (%s)", ep->id, ep->nome, ep->podcast.nome);
      
    }
  }
  else {
    printf("Sua fila zerou! :(");
  }

}

Lista iniciarLista() {
  Lista lista = malloc(sizeof(Lista));

  lista->atual = NULL;
  lista->inicio = NULL;
  lista->fim = NULL;
  lista->shuffle = 0;
  
  for(int i = 0; i < sizeof(lista->podcasts) / sizeof(Podcast); i++) {
    Podcast pdc;
    pdc.id = -1;
    lista->podcasts[i] = pdc;
  }

  return lista;
}

void remove_newline_ch(char *line)
{
    int new_line = strlen(line) -1;
    if (line[new_line] == '\n')
        line[new_line] = '\0';
}

void exibirPlaylist(Lista lista) {
  system("clear");
  if(lista->inicio != NULL) {
    for(Celula * aux = lista->inicio; aux != NULL; aux=aux->proximo) {
      Episodio * ep = aux->episodio;
      Episodio * epAtual = lista->atual->episodio;

      if(ep->id == epAtual->id && ep->podcast.id == epAtual->podcast.id) {
      printf("%d - %s ([%d] %s) <= Em reprodução\n", ep->id, ep->nome, ep->podcast.id, ep->podcast.nome);
        
      }
      else {
      printf("%d - %s ([%d] %s)\n", ep->id, ep->nome, ep->podcast.id, ep->podcast.nome);
      }
    }
  }
  else {
    printf("Playlist está vazia! :(");
  }
  
}

void remover(Lista lista) {
  system("clear");
  if(lista->inicio != NULL && lista->atual != NULL && lista->fim != NULL) {
    
    int idEpisodio, idPodcast;
    Celula * removido;
    printf("Digite o número do episódio: ");
    scanf("%d", &idEpisodio);
    getchar();
    printf("\nDigite o número (posição) do podcast: ");
    printf("\n");
    scanf("%d", &idPodcast);
    getchar();
    
      //Caso a lista só tenha um elemento
      if(lista->inicio->proximo == NULL) {
        if(lista->inicio->episodio->id == idEpisodio && lista->inicio->episodio->podcast.id) {
          removido = lista->inicio;
          resetar(lista);
          printf("Episódio %d do podcast %s removido!", removido->episodio->id, removido->episodio->podcast.nome);
          return;
        }
      }
      //Caso a lista tenha mais de um elemento
      else {
        for(Celula * aux = lista->inicio; aux != NULL; aux = aux->proximo){
          if(lista->inicio->episodio->id == idEpisodio && lista->inicio->episodio->podcast.id == idPodcast) {
              removido = lista->inicio;
              lista->inicio = lista->inicio->proximo;
            if(lista->atual->episodio->id == idEpisodio && lista->atual->episodio->podcast.id == idPodcast ) {
              lista->atual = lista->atual->proximo;
            }
              printf("Episódio %d do podcast %s removido!", removido->episodio->id, removido->episodio->podcast.nome);
              resetarCelula(removido);
            }
            
          else if(aux->proximo->episodio->id == idEpisodio && aux->proximo->episodio->podcast.id == idPodcast) {
            removido = aux->proximo;
            aux->proximo = aux->proximo->proximo;
            resetarCelula(removido);
            
            if(lista->atual->episodio->id == idEpisodio && lista->atual->episodio->podcast.id == idPodcast ) {
              lista->atual = lista->atual->proximo;
            }
            printf("Episódio %d do podcast %s removido!", removido->episodio->id, removido->episodio->podcast.nome);
            resetarCelula(removido);
            return;
          }
        }
      }
    free(removido);
    }
  else {
    printf("Lista está vazia!");
  }
  
}

void shuffle(Lista lista) {
  system("clear");
  if(lista->shuffle == 0) {
    lista->shuffle = 1;
    
    printf("Shuffle ativado!");    
  }
  else {
    lista->shuffle = 0;

    printf("Shuffle desativado!");
  }
}

void exibirPodcasts(Lista lista) {
  system("clear");
  Podcast podcastAtual;
  if(lista->inicio != NULL) {
    for(Celula * aux = lista->inicio; aux != NULL; aux = aux->proximo) {
      if(aux->episodio->podcast.id == podcastAtual.id) {
        
      }
      else {
        podcastAtual = aux->episodio->podcast;
      }
      printf("%d - %s\n", podcastAtual.id, podcastAtual.nome); 
      
    }
  }
  else {
    printf("Não há nenhum podcast na lista :(");
  }
  
}