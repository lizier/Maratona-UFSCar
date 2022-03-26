# BEE 1068 Balanço de Parênteses I

A estratégia para resolver o problema, é "empilhar" os parênteses que foram abertos mas ainda não foram fechados na estrutura de dados stack. Caso apareça um fecha parênteses, verifica-se se a stack está vazia, nesse caso a quantidade de parentese não está corretada, pois "não há nenhum parênteses para fechar", se não estiver, retira-se uma abre parênteses na stack e continua a execução do programa. No fim, se a stack estiver vazia, a quantidade de parênteses está correta, senão não está.

O problema poderia ser resolvido com um simples contador também