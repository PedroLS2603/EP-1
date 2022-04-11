# EP-1

O código possui 7 funcionalidades

1 - Reproduzir atual  
    Reproduz o episódio atual configurado na estrutura da lista. Caso a lista esteja vazia imprime "Não há nenhum podcast na fila!"  
2 - Reproduzir próximo  
    Reproduz o episódio no ponteiro "proximo" da célula atual e atualiza o ponteiro "atual" para o mesmo.  
    Altera a ordem de reprodução, caso a flag "shuffle" esteja ativa. 
    Caso a lista esteja vazia imprime: "Sua fila zerou! :("  
3 - Adicionar podcast  
    Adiciona podcast no fim da lista  
4 - Remover  
    Remove podcast com o id do episódio e o id do podcast (listado na funcionalidade 6)  
5 - Shuffle  
    Muda a flag "shuffle" da estrutura da lista.  
6 - Exibir playlist  
    Exibe todos os podcasts adicionados na lista no formato => 'idEpisodio' - 'nomeEpisódio' (['idPodcast'] 'nomePodcast')  
7 - Exibir podcasts (TODO)  
    Exibe todos os podcasts da lista, filtrando os repetidos.  
  
Para a realização do exercício foi definida a estrutura de uma lista com cabeça duplamente ligada.