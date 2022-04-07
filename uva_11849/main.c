#include <stdio.h>
#include <stdlib.h>

int cd[1000000];

int compara(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{

    int n, m, aux, total;

    while (1)
    {
        total = 0;

        scanf("%d %d", &n, &m);
        if (!n && !m)
            break;

        for (int i = 0; i < n; i++)
            scanf("%d", &cd[i]);

        for (int i = 0; i < m; i++)
        {
            scanf("%d", &aux);
            if (bsearch(&aux, cd, n, sizeof(int), compara))
                total++;
        }

        printf("%d\n", total);
    }

    return 0;
}