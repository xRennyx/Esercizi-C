#include <stdio.h>
#include <string.h>

struct Persona
{
    char nome[50];
    char cognome[50];
    int eta;
    float altezza;
};

//Secondo modo per le struct:

/*typedef struct
{
    char nome[50];
    char cognome[50];
    int eta;
    float altezza;
}Persona;*/

/*Main()
{
    Persona p; //con tipo 2: "struct Persona p";
}*/
void stampaDettagliPersona(Persona p)
{
    printf("Nome: %s\n", p.nome);
    pritnf("Cognome: %s\n", p.cognome);
    printf("Eta: %d\n", p.eta);
    printf("Altezza: %.2f\n", p.altezza);
}
void aggiornaeta(Persona *p, int nuovaeta)
{
    (*p).eta=nuovaeta;
}

int main()
{
    Persona p={"A", "B", 22, 1.90};
    stampaDettagliPersona(p);
    aggiornaeta(&p, 41);
    Persona p2[3]={p,p3,p4}; //esempio array di struct
}