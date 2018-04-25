#include <stdio.h>
#include <stdlib.h>

int main()
{
    float matriz[2][3];
    int i,j;
        for(i=0;i<2;i++)
        {
            for(j=0;j<3;j++)
            {
                printf("M[%d][%d]: ",i,j);
                scanf("%f",&matriz[i][j]);
            }
        }
        for(i=0;i<2;i++)
        {
            for(j=0;j<3; j++)
            {
                printf("\t [%d] [%d] %.0f",i,j, matriz[i][j]);
            }
        printf("\n");
        }

    return 0;
}
