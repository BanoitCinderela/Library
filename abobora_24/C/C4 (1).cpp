#include <bits/stdc++.h>

void troca(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
int main()
{
    int N;
    scanf("%d", &N);
    int doces[N];
    int ordem[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &doces[i]);
        ordem[i]=i;
    }


    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (doces[i] < doces[j])
            {
                troca(&doces[j], &doces[i]);
                troca(&ordem[i], &ordem[j]);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d",ordem[i]+1);
        if (i != (N - 1))
            printf(" ");
        else printf("\n");
    }

    return 0;
}