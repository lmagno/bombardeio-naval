# TO-DO

Em ordem de importância
- [ ] Colocar as condições de término do jogo (chegar ao final da linha e ficar três jogadas seguidas num beco, sejá lá o que isso signifique)
- [ ] Fazer um menu pro jogo
- [x] Tratar os erros de forma mais decente, usando structs ou enum
- [ ] Fazer a documentação (pra usuário e pra desenvolvedor)
- [ ] Deixar o jogo bonitinho pelo menos
- [ ] Mudar o Makefile para usar bibliotecas dinâmicas
- [ ] Mais testes!
- [ ] Usar uma struct para representar pontos (x, y)

# Status e tratamento de erros
Agora temos a biblioteca `status`  , que introduz uma struct Status para representar o valor de retorno de uma função qualquer.
Ela é composta de um valor (`int`) e uma mensagem (`string`). Como de costume,
0 indica que a função terminou com sucesso e qualquer outro valor, um erro.

Para facilitar seu uso, há algumas funções:
* `sucesso`: retorna um `Status*` com valor 0 e sem mensagem.
* `erro`: retorna um `Status*` com o valor (que deve ser diferente de zero) e a mensagem desejados.
* `trata_status`: recebe um `Status*`, libera seu espaço na memória e retorna somente seu valor. Caso este seja diferente de zero, também imprime a mensagem associada para a `STDERR`.

Idealmente todas as funções de mais alto nível (bibliotecas `mapa`, `barco` e `embarcacoes`) deveriam retornar um Status*, mas a maioria ainda está sem tratamento de erro e não está claro também onde exatamente erros poderiam surgir nelas. De qualquer forma, é bom sempre manter em mente uma situação extrema que pode ocorrer e a indicar com o respectivo erro.

Alguns detalhes:
* Atualmente não distinção entre os números que representam erro (qualquer inteiro diferente de zero), o que não segue muito os padrões de C, mas parece que as mensagens associadas tornam essa distinção desnecessária (a não ser que encontremos uma situação em que queiramos comportamentos diferentes dependendo do tipo de erro que ocorreu).
* O código todo está definido em função de ponteiros de Status (`Status*`), sendo necessária a liberação do espaço em memória alocado dinamicamente para ele, mas o Fernando aponto que não é necessário e parece ser bem verdade. Entretanto, usar a struct diretamente apresenta dois problemas:
  * Incompatibilidade estética com o padrão C e com a forma como já lidamos com a struct `Mapa` (ficaria `Status.valor` ao invés de `Status->valor`).
  * Seria necessário exportar a forma interna da struct através do seu header, para que seja possível declarar variáveis desse tipo em outros locais (atualmente isso não é possível, porque ninguém fora a própria biblioteca sabe a estrutura interna da struct, ou seja, sua organização na memória. Então só é possível declarar ponteiros para ela, o que não requer informação alguma.). O problema aqui é que isso expõe a estrutura interna da struct, o que é no mínimo deselegante, e permite que os valores de seus campos sejam alterados.

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
8. dispara_tiros - Dispara 3 tiros, imprime na tela e no arquivo as mensagens correspondentes aos efeitos dos tiros e atualiza a matriz


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

*O jogo*

além das bibliotecas citadas acima, temos o programa principal (main.c) e o arquivo de makefile que são necessários para a compilação e execução do programa.
Nós fizemos a bilioteca de mapa separada com o intuito de quem utiliza-la não precisar saber como ela é implementada.A biblioteca de embarcações e a de tiros foram feita
assim como o enunciado do Exercício Programa indica.

para rodar o jogo, faça o make e depois execute no terminal o main.

partirmos do principio que o jogador não vá alterar as funções do jogo e sempre proverá um mapa novo , que concorde com as regras do enunciado, para o programa a cada nova execução.



**responsáveis**
Lucas Magno - 7994983
Fernando Freire Scattone - 8125021
Gustavo Covas - 7995052
