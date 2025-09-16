#include <stdio.h>
#include <string.h>

#define DIM 1024

int main()
{
    int j=0;
    int k=0;
    char string[DIM];
    char stringPARI[DIM];
    char stringDISPARI[DIM];
    char c;
    printf("Inserisci una stringa: ");
    scanf("%s", string);
    for(int i=0; i<strlen(string); i++)
    {
        if(string[i]>='a' && string[i]<='z')
        {
            j++;
        }
    }
    if(j==strlen(string))
    {
        printf("Contiene solo lettere\n");
    }
    else
    {
        printf("Non contine solo lettere\n");
    }
    printf("Inserisci una lettera da cercare: ");
    scanf(" %c", &c);
    for(int i=0; i<strlen(string); i++)
    {
        if(string[i]==c)
        {
            k++;
        }
    }
    printf("la lettera %c compare %d volte\n", c,k);
    
    for(int i=0, a=0, b=0; i<strlen(string); i++)
    {
        if(i%2==0)
        {
            stringPARI[a]=string[i];
            a++;
        }
        else
        {
            stringDISPARI[b]=string[i];
            b++;
        }
    }
    printf("Lettere pos pari: %s\n", stringPARI);
    printf("Lettere pos dispari: %s\n", stringDISPARI);
    
    char string2[DIM];
    printf("Inserisci una stringa: ");
    scanf("%s", string2);
    
    if(strlen(string)>strlen(string2))
    {
        printf("La prima stringa è maggiore\n");
    }
    else if(strlen(string)<strlen(string2))
    {
        printf("La seconda stringa è maggiore\n");
    }
    else
    {
        printf("le stringhe sono uguali\n");
    }
    return 0;
}
