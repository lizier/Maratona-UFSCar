# UVA 12247, Jollo

A estratégia adotada para resolver o problema é nada mais que tentar todas as combinações de partidas.
A partir da combinação das primeiras duas primeiras rodadas, é possível determinar, se existir, uma carta, na qual o príncipe sempre irá vencer:
-Cartas da irmã(A,B,C)
-Cartas do príncipe(X,Y,Z)

Se X>A && Y>B, Z = 1;
Se X<A && Y<B, Z = -1;
Se X>A && Y<B, Z = C + 1;
Se X<A && Y>B, Z = C + 1;

Portanto, basta considerar todas as combinações possíveis.
Pode-se dividir este processo em 3 funções:

## void jogosPossiveis(unsigned irma[], unsigned principe[], unsigned partidas[][2])

    Lista o resultado de todas os embates de cartas possíveis em uma matriz(1->carta do Principe vence, 0->carta do Principe perde).

## int relacoes(unsigned a, unsigned b, int i, int j, unsigned irma[])

    Recebe uma combinação de cartas e calcula C com base nas combinações de cartas. Por exemplo, se X>A && Y>B, Z = 1.

## int cCalc(unsigned partidas[][2], unsigned irma[])

    Recebe todas as combinações de partidas e retorna uma combinação possível para a função "relacoes", isto é, sem cartas repetidas.

Após isto, basta ter um cuidado para que Z não seja igual a nenhuma outra carta.
