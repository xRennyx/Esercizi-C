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
#include <string.h>
#include <stdio.h>

struct Persona{
    char nome[50];
    char cognome[50];
    int eta;
    char codice_fiscale[50];
    float reddito_annuo;
    int anno_nascita;
    char residenza[50];
};

void stampaPersona(struct Persona p)
{
    printf("Nome: %s\n", p.nome);
    printf("Cognome: %s\n", p.cognome);
    printf("Età: %d\n", p.eta);
    printf("Codice fiscale: %s\n", p.codice_fiscale);
    printf("Reddito annuo: %.2f\n", p.reddito_annuo);
    printf("Anno nascita: %d\n", p.anno_nascita);
    printf("Residente: %s\n", p.residenza);
}

void inserisciPersone(struct Persona *p)
{
    printf("Inserisci nome: ");
    scanf("%s", p->nome);
    printf("Inserisci cognome: ");
    scanf("%s", p->cognome);
    printf("Inserisci eta: ");
    scanf("%d", &p->eta);
    printf("Inserisci codice fiscale: ");
    scanf("%s", p->codice_fiscale);
    printf("Inserisci reddito annuo: ");
    scanf("%f", &p->reddito_annuo);
    printf("Inserisci anno nascita: ");
    scanf("%d", &p->anno_nascita);
    printf("Inserisci residenza: ");
    scanf("%s", p->residenza);
}

struct Persona redditoMassimo(struct Persona p[], int n)
{
    int i;
    struct Persona *redditoMassimo;
    redditoMassimo=&p[0];
    for(i=1; i<n; i++)
    {
        if(redditoMassimo->reddito_annuo<p[i].reddito_annuo)
        {
            redditoMassimo=&p[i];
        }
    }
    return *redditoMassimo;
}

struct Persona redditoMinimo(struct Persona p[], int n)
{
    int i;
    struct Persona *redditoMinimo;
    redditoMinimo=&p[0];
    for(i=1; i<n; i++)
    {
        if(redditoMinimo->reddito_annuo>p[i].reddito_annuo)
        {
            redditoMinimo=&p[i];
        }
    }
    return *redditoMinimo;
}

void ordinaAnnoNascita(struct Persona p[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(p[i].anno_nascita>p[j].anno_nascita)
            {
                struct Persona temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
        
    }
}

struct Persona findWCodiceFiscale(struct Persona p[], int n, char codice_fiscale[])
{
    for(int i=0; i<n; i++)
    {
        if(strcmp(p[i].codice_fiscale, codice_fiscale)==0)
        {
            return p[i];
        }
    }
}

void visualizzaReddito(struct Persona p[], int n, float reddito)
{
    for(int i=0; i<n; i++)
    {
        if(p[i].reddito_annuo>reddito)
        {
            stampaPersona(p[i]);
        }
    }
}
float calcola_media_redditi(struct Persona p[], int n) {
    float somma = 0;
    for (int i = 0; i < n; i++) {
        somma += p[i].reddito_annuo;
    }
    return somma / n;
}

void stampa_persone_anno(struct Persona p[], int n, int anno) {
    for (int i = 0; i < n; i++) {
        if (p[i].anno_nascita == anno) {
            stampaPersona(p[i]);
        }
    }
}

int main()
{
    int n;
    printf("Inserisci numero di persone: ");
    scanf("%d", &n);
    struct Persona persone[n];
    for (int i = 0; i < n; i++) {
    printf("\n--- Inserisci dati persona %d ---\n", i + 1);
    inserisciPersone(&persone[i]);
}
    int scelta;
    do {
        printf("\n--- MENU ---\n");
        printf("1) Persona con reddito max e min\n");
        printf("2) Ordina per anno di nascita\n");
        printf("3) Cerca per codice fiscale\n");
        printf("4) Persone con reddito >= valore scelto\n");
        printf("5) Media dei redditi\n");
        printf("6) Persone nate in un anno specifico\n");
        printf("0) Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1: {
                struct Persona max = redditoMassimo(persone, n);
                struct Persona min = redditoMinimo(persone, n);
                printf("\n--- Reddito massimo ---\n");
                stampaPersona(max);
                printf("\n--- Reddito minimo ---\n");
                stampaPersona(min);
                break;
            }
            case 2: {
                ordinaAnnoNascita(persone, n);
                printf("\n--- Ordinato per anno di nascita ---\n");
                for (int i = 0; i < n; i++) stampaPersona(persone[i]);
                break;
            }
            case 3: 
            {
                char cf[17];
                printf("Inserisci codice fiscale da cercare: ");
                scanf("%16s", cf); // legge fino a 16 caratteri, sicuro
                struct Persona ricercata;
                ricercata = findWCodiceFiscale(persone, n, cf);
                stampaPersona(ricercata);
                break;
            }
            case 4: {
                float val;
                printf("Inserisci reddito minimo: ");
                scanf("%f", &val);
                visualizzaReddito(persone, n, val);
                break;
            }
            case 5: {
                float media = calcola_media_redditi(persone, n);
                printf("Media dei redditi: %.2f\n", media);
                break;
            }
            case 6: {
                int anno;
                printf("Inserisci anno di nascita: ");
                scanf("%d", &anno);
                stampa_persone_anno(persone, n, anno);
                break;
            }
            case 0:
                printf("Uscita dal programma.\n");
                break;
            default:
                printf("Scelta non valida.\n");
        }
    } while (scelta != 0);

    return 0;
}
