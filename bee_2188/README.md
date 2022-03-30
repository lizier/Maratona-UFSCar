# BEE 2188, Macaco-prego 

A estratégia adotada para resolver o problema é determinar a intersecção entre as duas primeiras regiões quadradas dadas na entrada,
e com o resultado, fazer a intersecção entre a terceira e assim por diante.
Duas situações podem ocorrer:
- Nenhuma intersecção foi encontrada entre duas regiões a qualquer momento, então a saída será "nenhuma"
- Depois de dtodas as intersecções , existe uma região. Então essa será escrita na saída.

As coordenadas dos pontos são guardados em um std::pair, sendo que o campo first contem o valor de x e o second o valor de y 

## função de intersecção

Primeiro verifica-se se há alguma intersecção entre os dois quadrilateros:
```C
    if  ( ! ((U.first <= B.first && U.second >= B.second) &&
             (V.first >= A.first && V.second <= A.second))
        )
                    return 0; 
```
Ou seja, para ter uma intersecção, obrigatoriamente o ponto superior esquerdo está "acima e à esquerda" do ponto inferior direito da segunda região, e o ponto inferior direito está "abaixo e à direita" do ponto superior esquerdo do segundo quadrilátero.

```C
    if ( A.first <= U.first && U.first <= B.first )
        AI.first = U.first;
    else
        AI.first = A.first;
    // escolha de Y do novo ponto A
    if ( B.second <= U.second && U.second <= A.second )
        AI.second = U.second;
    else
        AI.second = A.second;
    // Ponto B
    // escolha de X do novo ponto B
    if ( A.first <= V.first && V.first <= B.first )
        BI.first = V.first;
    else
        BI.first = B.first;
    // escolha de Y do novo ponto B
    if ( B.second <= V.second && V.second <= A.second )
        BI.second = V.second;
    else
        BI.second = B.second;
```
Nesse trecho, escolhe-se os pontos de intersecção AI e BI, que são uma combinação dos valores de x e y das regiões analisadas. Os novos pontos serão sempre "os menores possíveis".

Retora-se o valor 1 para indicar que a intersecção ocorreu. Repete-se esse passo até ler o valor 0 na entrada