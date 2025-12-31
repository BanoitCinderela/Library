#include <bits/stdc++.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if ((a < b + c) && (b < a + c) && (c < a + b))
    {
        printf("SIM\n");
    }
    else
    {
        printf("NAO\n");
    }
    return 0;
}
