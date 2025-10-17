/*Scrivere un programma in C che dopo aver dichiarato una struttura denominata Persona con i
seguenti campi: Nome, Cognome, età, codice fiscale, reddito annuo, anno_nascita,residenza(città) ;
determini:
1) La persona con reddito annuo più alto e quella con reddito annuo più basso.Visualizzare
per entrambe: nome, cognome, città e reddito.
2) Ordinare la lista delle persone in base all’anno di nascita** (dal più anziano al più
giovane), e visualizzarla.
3) Consentire all’utente di cercare una persona inserendo il codice fiscale..
4) Visualizzare tutte le persone con reddito superiore o uguale a un valore scelto dall’utente.
5) Calcolare la media dei redditi delle persone registrate nel sistema.
6) Visualizzare tutte le persone nate in un anno specifico, scelto dall’utente;
7) Visualizzare l&#39;elenco delle persone raggruppate per città di residenza, indicando per
ciascuna città: Quante persone vi risiedono, L’età media dei residenti*/
#include <stdio.h>
#include <string.h>
struct Persona {
    char nome[50];
    char cognome[50];
    int eta;
    char codice_fiscale[16];
    float reddito_annuo;
    int anno_nascita;
    char residenza[50];
};

void stampa_persona(struct Persona p) {
    printf("----- Dati della Persona -----\n");
    printf("Nome: %s\n", p.nome);
    printf("Cognome: %s\n", p.cognome);
    printf("Età: %d\n", p.eta);
    printf("Codice Fiscale: %s\n", p.codice_fiscale);
    printf("Reddito Annuo: %.2f\n", p.reddito_annuo);
    printf("Anno di Nascita: %d\n", p.anno_nascita);
    printf("Residenza: %s\n", p.residenza);
}

struct Persona trova_reddito_max(struct Persona persone[], int n)
{
    int i;
    struct Persona *reddito_estremo;
    reddito_estremo=&persone[0];
    for(i=1; i<n; i++)
    {
        if(persone[i].reddito_annuo>reddito_estremo->reddito_annuo)
        {
            reddito_estremo=&persone[i];
        }
    }
    return *reddito_estremo;
}
struct Persona trova_reddito_min(struct Persona persone[], int n)
{
    int i;
    struct Persona *reddito_estremo;
    reddito_estremo=&persone[0];
    for(i=1; i<n; i++)
    {
        if(persone[i].reddito_annuo<reddito_estremo->reddito_annuo)
        {
            reddito_estremo=&persone[i];
        }
    }
    return *reddito_estremo;
}
void ordina_anno(struct Persona p[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (p[j].anno_nascita < p[minIndex].anno_nascita) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            struct Persona temp = p[i];
            p[i] = p[minIndex];
            p[minIndex] = temp;
        }
    }
}
struct Persona ricerca(struct Persona p[], int n, char codice_fiscale[])
{
    for(int i=0; i<n; i++)
    {
        if(strcmp(p[i].codice_fiscale, codice_fiscale) == 0)
        {
            return p[i];
        }
    }
}
void stampa_reddito(struct Persona p[], int n, int reddito)
{
    for(int i=0; i<n; i++)
    {
        if(p[i].reddito_annuo>=reddito)
        {
            stampa_persona(p[i]);
        }
    }
}

int main()
{
    return 0;
}
