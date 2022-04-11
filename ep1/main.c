#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(void) {
  int option;
  Lista lista = iniciarLista();


  do {
    
    printf("\nPodquest - Escolha uma opção\n");
    printf(" 1 - Reproduzir atual\n 2 - Reproduzir próximo\n 3 - Adicionar\n 4 - Remover\n 5 - Shuffle\n 6 - Exibir playlist\n 7 - Exibir podcasts\n 0 - Sair\n Opção: ");

    scanf("%d", &option);
    getchar();

    switch(option) {
      case 0:
        printf("\nTchau tchau! :)");
        break;
      case 1:
        exibirAtual(lista);
        break;
      case 2:
        exibirProximo(lista);
        break;
      case 3:
        adicionar(lista);
        break;
      case 4:
        remover(lista);
        break;
      case 5:
        shuffle(lista);
        break;
      case 6:
        exibirPlaylist(lista);
        break;
      case 7:
        exibirPodcasts(lista);
        break;
      default:
        printf("\nOpção inválida! Tente novamente.\n");
        break;
    }
  } while (option != 0);

  free(lista);
  return 0;
}
