# Online Judge 11661 - Burguer Time?
## Solução por : rafabarbeta
A estretégia para resolução do problema é percorrer a string representando a estrada e marcar "pontos de referência" conforme os establecimentos ('R', 'Z', 'R') são achados na string

Inicialemente, devemos percorrer a string cegamente até achar o primeiro estabelecimento na estrada
```C++
while (estrada[i] != 'D' && estrada[i] != 'Z' && estrada[i] != 'R') i++; 
        status = estrada[i];
```
Ao encontrar um dos três estabelecimentos, a variável status recebe o caractere encontrado.
Nesse momento, estamos definindo a posição de referência na estrada como sendo o primeiro estabelecimento encontrado. Cabe destacar que se status = 'Z', então o programa escreve 0 na saída e termina a execução para esse caso de teste.
Para as próximas posições, existem quatro possibilidades:

 - O caractere lido é '.', nesse caso apenas incrementa um contador de distância em 1
 - O caractere lido é igual a status. Se isso acontecer, zeramos o contador de distância, pois estamos tomando como referência esse novo ponto na "estrada" e descartando o anterior, uma vez que um estabelecimento mais à frente na estrada sempre será mais perto de outro que um mais à trás (Por exemplo, ...D...D.....R, O segundo D estará sempre mais perto de R do que o primeiro)
 - O caractere lido é um 'Z'. escreve 0 na saída e avança para o próximo caso de teste
 - O caractere lido é diferente de Z e diferente de status, o que significa que encontramos "um par" restaurante-farmácia, portando lemos o contador e comparamos ele com uma variável contendo o mínimo de distância até agora (minDistancia), se o contador for menor, atualizamos o valor de minDistancia. Depois, vamos tomar como ponto de referência esse novo ponto encontrado, atualizando o valor de status para esse novo estabelecimento. É necessário zerar o contador também.

O código que ilustra esse comportamento está representado abaixo:
```C++
        for (int j = i; j < tamEstrada; j++) { // i é o valor do primeiro estabelecimento de referência
            if (estrada[j] == '.') {
                contD++;
                continue;
            }
            else if (estrada[j] == 'Z') {
                minDistancia = 0;
                break;
            }
            else if (estrada[j] == status) {
                contD = 0;
            }
            else {
                if (++contD < minDistancia)
                    minDistancia = contD;
                contD = 0;
                status = estrada[j];
            }
        }
```

Repetindo os passos anteriores para cada caso de teste, obtemos a solução para o problema
