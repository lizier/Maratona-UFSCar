# Online Judge 11683 - Laser Sculpture

Utilizando uma pilha, conseguimos chegar a uma solução de complexidade linear. Começando pelo bloco mais à esquerda, processamos a altura de cada bloco com base na diferença de altura entre ele e o bloco adjacente à esquerda. Há quatro possíveis casos de diferenças, sendo que a altura do novo bloco é colocada na pilha ao final de todos os casos. Então, podemos comparar o novo bloco ao bloco no topo da pilha, que será o bloco à esquerda dele.

Caso 1: O bloco está no início da sequência de blocos
Apenas adicionamos a altura do novo bloco na pilha. Os pedaços que precisam ser cortados acima dele são tratados posteriormente.

Caso 2: Os blocos possuem a mesma altura
Se dois blocos possuem a mesma altura, o laser pode cortar os pedaços acima deles ao mesmo tempo. Então, podemos ignorar a altura de um dos blocos.

Caso 3: O bloco da esquerda é maior
Apenas adicionamos a altura do novo bloco na pilha, como no caso 1.

Caso 4: O bloco da direita é maior
Digamos que x seja a diferença de altura entre o bloco da direita bd e o bloco da esquerda be. Não conhecendo a altura máxima A, sabemos que pelo menos x blocos serão cortados acima de be. Então, podemos adicionar x ao contador da resposta.
Pela própria forma dos casos, as alturas na pilha sempre estão ordenadas de maneira estritamente descrescente. Assim, no momento em que o laser estiver cortando esses pedaços acima de be, ele pode também tirar qualquer pedaço acima de um bloco que esteja entre bd e o bloco à esquerda mais próximo de bd que tenha uma altura maior ou igual à de bd. Além disso, depois quando o laser cortar os pedaços acima de bd, ele também poderá cortar os pedaços restantes acima desses blocos. Dessa maneira, podemos parar de considerar os blocos com altura menor ou igual a de bd na pilha até encontrar um bloco com altura maior que a de bd.

Chegando ao fim da sequência de blocos da esquerda para direita, a pilha ainda terá blocos que não foram tratados (em especial, o último bloco sempre estará na pilha no final). Para tratá-los, podemos considerar que depois de todos os blocos, existe um bloco imaginário de tamanho A. Esse bloco não altera a resposta final, pois não há pedaços para serem cortados acima dele, mas ele permite que nós  reutilizemos o raciocínio do caso 4.