//Rafael Penido Soares
#include <stdio.h>

int ehMaior(unsigned carta1, unsigned carta2)
{
    return carta1 > carta2;
}

void jogosPossiveis(unsigned irma[], unsigned principe[], unsigned partidas[][2])
{

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            partidas[i][j] = ehMaior(principe[j], irma[i]);
}

int relacoes(unsigned a, unsigned b, int i, int j, unsigned irma[])
{
    if (a && b)
        return 1;

    if (!a && !b)
        return -1;

    for (int k = 0; k < 3; k++)
        if (k != i && k != j)
            return irma[k] + 1;
}

int cCalc(unsigned partidas[][2], unsigned irma[])
{

    int aux, c = 0;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (i != j)
            {
                aux = relacoes(partidas[i][0], partidas[j][1], i, j, irma);
                if (aux == -1)
                    return aux;
                if (aux > c)
                    c = aux;
            }

    return c;
}

int main()
{

    unsigned cartasIrma[3],
        cartasPrincipe[2],
        partidas[3][2];

    while (1)
    {
        for (int i = 0; i < 3; i++)
            scanf("%d", &cartasIrma[i]);

        for (int i = 0; i < 2; i++)
            scanf("%d", &cartasPrincipe[i]);

        if (!cartasIrma[0] && !cartasIrma[1] && !cartasIrma[2] && !cartasPrincipe[0] && !cartasPrincipe[1])
            break;

        jogosPossiveis(cartasIrma, cartasPrincipe, partidas);

        int resultado = cCalc(partidas, cartasIrma);

        while (resultado == cartasIrma[0] || resultado == cartasIrma[1] || resultado == cartasIrma[2] || resultado == cartasPrincipe[0] || resultado == cartasPrincipe[1])
            resultado++;

        if (resultado > 52)
            resultado = -1;

        printf("%d\n", resultado);
    }

    return 0;
}