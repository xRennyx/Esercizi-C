#include <stdio.h>

int main()
{
    int dim;
    int somma=0;
    float media;
    int scelta;
    
    do
    {
        printf("Inserisci dimensione del vettore: ");
        scanf("%d", &dim);
    }while(dim<0);
    
    int array[dim];
    
    for(int i=0; i<dim; i++)
    {
        printf("Inserisci il %d° numero: ", i+1);
        scanf("%d", &array[i]);
    }
    
    do
    {
        printf("\nQuale operazione vuoi fare?\n1-Visualizza\n2-Visualizza invertito\n3-Somma e Media\n4-Numeri Pari");
        scanf("%d", &scelta);
        switch(scelta)
        {
            case 1: 
            {
                printf("\nArray: ");
                for(int i=0; i<dim; i++)
                {
                    printf("%d ", array[i]);
                }
                break;
            }
            case 2:
            {
                printf("\nArray Invertito: ");
                for(int i=dim-1; i>=0; i--)
                {
                    printf("%d ", array[i]);
                }
                break;
            }
            case 3:
            {
                for(int i=0; i<dim; i++)
                {
                    somma=somma+array[i];
                }
                media=(float)somma/dim;
                printf("\nSomma= %d\n", somma);
                printf("Media= %.2f", media);
                break;
            }
            case 4:
            {
                printf("\nNumeri Pari: ");
                for(int i=0; i<dim; i++)
                {
                    if(array[i]%2==0)
                    {
                        printf("%d ", array[i]);
                    }
                }
                break;
            }
            
        }
        
        
    }while(scelta!=5);

    return 0;
}
