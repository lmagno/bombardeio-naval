# bombardeio-naval
Projeto para a matéria MAC0211 - Laboratório de Programação 1

**bibliotecas:**

*libbarco*

biblioteca necessaria para o posicionamento inicial do barco no mapa e para o movimento do barco a cada rodada

1. posiciona_barco - função pede uma coluna para ser a coluna inicial do barco, se não for um ponto válido ele pede novamente.
2. rema_barco - função que movimenta o barco, quando possível, e retorna TRUE se o barco se movimentou ou FALSE se não.

*libembarcações*

biblioteca que controla as embarcações e o processo de disparar os tiros

1. afunda_destroyer - função que muda na mapa a nave destroyer de atingida com um tiro para totalmente afundada
2. afunda_porta_aviao - função que muda na mapa a nave porta avião de atingida com um tiro para totalmente afundada
3. afunda_hidro_aviao - função que muda na mapa a nave hidro avião de atingida com um tiro para totalmente afundada
4. afunda_cruzador - função que muda na mapa a nave cruzador de atingida com um tiro para totalmente afundada
5. sorteia - função que sorteia um numero de 0 a k, sendo k fornecido 
6. coordenadas_tiro - função que sorteia o ponto a ser atinigido por um tiro usando a função sorteia para x de 0 a numero de colunas e y de 0 ao numero de linhas
7. identifica_alvo_atingido - Imprime as coordenadas de um tiro e a mensagem correspondente ao efeito desse tiro; Retorna o tipo de embarcação atingido 
8. dispara_tiros - Dispara 3 tiros, imprime as mensagens correspondentes aos efeitos dos tiros e atualiza a matriz


*libmapa*

biblioteca que define o mapa (como struct) e contêm todas suas funções referentes.

1. leia_mapa_arquivo - recebe um porteiro para arquivo e tenta pegar os dados no formato de mapa, e retorna um ponteiro pro mapa lido em caso de sucesso
2. leia_mapa_prompt -  pede que o usuário entre com o nome de um arquivo até que este seja aberto com sucesso. Faz a leitura e retorna o ponteiro para o arquivo.
3. escreve_mapa_tela - recebe um mapa e imprime na tela as casas que o jogador pode ver
4. escreve_mapa_arquivo - recebe o nome do arquivo de mapa e um struct mapa, retorna positivo se conseguir concatenar a impressão no arquivo e negativo se não conseguir
5. libera_mapa - desaloca a struct mapa
6. matriz - retorna a matriz **char que representa o mapa na struct
7. linhas - retorna o numero de linhas na struct mapa
8. colunas - retorna o numero de colunas na struct mapa


*libutils*

biblioteca com funções uteis para as outras bibliotecas

1. aloca_matriz - aloca matriz char com o numero de linhas e colunas fornecido no argumento
2. libera_matriz - desaloca matriz char com o numero de linhas fornecido no argumento
3. escreve_matriz_tela - escreve uma matriz inteira na tela
4. descarta_resto_linha - Recebe o ponteiro para um arquivo e avança seu buffer até uma quebra de linha.
5. prox_elem - Recebe o ponteiro para um arquivo e avança seu buffer até o primeiro caracter que não seja whitespace, retornando ele em seguida.
6. anexa_arquivo - Recebe o nome de um arquivo e uma string e a concatena ao final desse arquivo.



