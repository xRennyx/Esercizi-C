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
        printf("\nQuale operazione vuoi fare?\n1-Visualizza\n2-Visualizza invertito\n3-Somma e Media\n4-Numeri Pari\n5-Numeri Dispari\n6-Ricerca Numero\n7-Elimina Numero\n8-Scambio\n9-Ordinamento\n10-Esci");
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
            case 5:
            {
                printf("\nNumeri Dispari: ");
                for(int i=0; i<dim; i++)
                {
                    if(array[i]%2!=0)
                    {
                        printf("%d ", array[i]);
                    }
                }
                break;
            }
            case 6:
            {
                int num;
                int j=0;
                printf("Inserire un numero da cercare: ");
                scanf("%d", &num);
                for(int i=0; i<dim; i++)
                {
                    if(num==array[i])
                    {
                        j++;
                    }
                }
                if(j>=1)
                {
                    printf("Numero presente\n");
                }
                else
                {
                    printf("Numero non presente\n");
                }
                break;
            }
            case 7:
            {
                int num;
                int j=0;
                printf("Inserisci il numero da rimuovere: \n");
                scanf("%d", &num);
                for (int i=0; i<dim; i++)
                {
                    if (array[i]!=num)
                    {
                        array[j]=array[i];
                        j++;
                    }
                }
                dim = j; 
                 printf("Array aggiornato:\n");
                for (int i=0; i<dim; i++)
                {
                    printf("%d ", array[i]);
                }
                break;
            }
            case 8:
            {
                for (int i=0; i<dim- 1; i+=2)
                {
                    int temp=array[i];
                    array[i]=array[i+ 1];
                    array[i+ 1]=temp;
                }
                printf("Vettore alternato:\n");
                for (int i=0; i<dim; i++)
                {
                    printf("%d ", array[i]);
                }
                break;
            }
            case 9:
            {
                for (int i=0; i<dim- 1; i++)
                {
                    int min=i;
                    for (int j=i+ 1; j<dim; j++)
                    {
                        if (array[j]<array[min])
                        {
                            min=j;
                        }
                    }
                    int temp=array[i];
                    array[i]=array[min];
                    array[min]=temp;
                }
                printf("Vettore ordinato: ");
                for (int i=0; i<dim; i++)
                {
                    printf("%d ", array[i]);
                }
                break;
            }
        }
    }while(scelta!=10);

    return 0;
}
