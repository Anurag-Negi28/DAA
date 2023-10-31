//lab-2 Q1. Matrix multiplication of 2 square matrices.
#include<stdio.h>
int main()
{
    printf("Enter size of square matrices\n");
    int size;
    scanf("%d",&size);
    int m1[size][size]; int m2[size][size];
    int result[size][size];

    printf("Enter elements of first matrix\n");
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            scanf("%d",&m1[i][j]);
        }
    }

     printf("Enter elements of second matrix\n");
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            scanf("%d",&m2[i][j]);
        }
    }

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            result[i][j]=0;
           for(int k=0;k<size;k++) 
           {
            result[i][j] += m1[i][k] * m2[k][j];
           }
        }
    }
    printf("Matrix obtained after multiplication is\n");
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
   return 0;

}