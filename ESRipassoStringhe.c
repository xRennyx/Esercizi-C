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
    int vocali1=0;
    int consonanti1=0;
    int vocali2=0;
    int consonanti2=0;
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
    
    int contadoppie=0;
    for(int i=0; i<strlen(string); i++)
    {
        for(int j=i+1; j<strlen(string); j++)
        {
            if(string[i]==string[j])
            {
                contadoppie++;
            }
        }
    }
    if(contadoppie>0)
    {
        printf("Sono presenti doppie\n");
    }
    else
    {
        printf("Non sono presenti doppie\n");
    }
    
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
    
    char stringAMBE[DIM]; 
    for(int i=0, a=0;i<strlen(string); i++)
    {
        for(int j=0; j<strlen(string2); j++)
        {
            if(string[i]==string2[j])
            {
                stringAMBE[a]=string[i];
                a++;
            }
        }
    }
    printf("lettere uguali: %s\n", stringAMBE);
    
    for(int i=0; i<strlen(string); i++)
    {
        if(string[i]=='a' || string[i]=='e' || string[i]=='i' || string[i]=='o' || string[i]=='u')
        {
            vocali1++;
        }
        else if(string[i]!='a' && string[i]!='e' && string[i]!='i' && string[i]!='o' && string[i]!='u')
        {
            consonanti1++;
        }
    }
    for(int i=0; i<strlen(string2); i++)
    {
        if(string2[i]=='a' || string2[i]=='e' || string2[i]=='i' || string2[i]=='o' || string2[i]=='u')
        {
            vocali2++;
        }
        else if(string2[i]!='a' && string2[i]!='e' && string2[i]!='i' && string2[i]!='o' && string2[i]!='u')
        {
            consonanti2++;
        }
    }
    if(vocali1>vocali2)
    {
        printf("La prima stringa ha più vocali");
    }
    else if(vocali1<vocali2)
    {
        printf("La seconda stringa ha èiù vocali");
    }
    else
    {
        printf("Hanno le stesse vocali");
    }
    if(consonanti1>consonanti2)
    {
        printf("La prima stringa ha più consonanti");
    }
    else if(consonanti1<consonanti2)
    {
        printf("La seconda stringa ha più consonanti");
    }
    else
    {
        printf("Hanno le stesse consonanti");
    }
    
    
    return 0;
}
