# Online Judge 100 - 3n + 1 
## Solução por : Anathan Telles Pereira
A estretégia para resolução do problema é basicamente a força bruta para encontrar maior ciclo dentre os números da entrada.

A maior lógica da solução se encontra neste loop, onde é possível ver que é testado todos os números do intervalo i à j em busca do ciclo com maior tamanho.
```C++
while(i<=j){ // loop por todo o intervalo dado
            int n=i;
            cicloAtual = 1;

            while (n!=1)// calcula o tamanho do ciclo relativo ao atual n
            {
                if(n%2 == 1) n=3*n+1;
                else n = n/2;

                cicloAtual++;
            }

            if(cicloAtual > maiorCiclo)
                maiorCiclo = cicloAtual; // caso ciclo atual for o maior, atualiza o maiorCiclo
            
            i++;
        }
```

