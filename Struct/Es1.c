#include <stdio.h>
#include <string.h>

struct Auto {
    char modelloAuto[50];
    char marca[50];
    int cilindrata;
    int prezzo;
    int anno_immatricolazione;
    char targa[20];
};

void inserisciAuto(struct Auto *a) {
    printf("Inserisci modello auto: ");
    scanf("%s", a->modelloAuto);

    printf("Inserisci marca auto: ");
    scanf("%s", a->marca);

    printf("Inserisci cilindrata: ");
    scanf("%d", &a->cilindrata);

    printf("Inserisci prezzo: ");
    scanf("%d", &a->prezzo);

    printf("Inserisci anno immatricolazione: ");
    scanf("%d", &a->anno_immatricolazione);

    printf("Inserisci targa: ");
    scanf("%s", a->targa);
}

void stampaAuto(struct Auto a) {
    printf("\n--- Dettagli Auto ---\n");
    printf("Modello: %s\n", a.modelloAuto);
    printf("Marca: %s\n", a.marca);
    printf("Cilindrata: %d\n", a.cilindrata);
    printf("Prezzo: %d\n", a.prezzo);
    printf("Anno immatricolazione: %d\n", a.anno_immatricolazione);
    printf("Targa: %s\n", a.targa);
}

int main() {
    int dim;

    do {
        printf("Quante auto vuoi inserire? ");
        scanf("%d", &dim);
    } while (dim <= 0);

    struct Auto a[dim];

    for (int i = 0; i < dim; i++) {
        printf("\nInserimento Auto #%d\n", i + 1);
        inserisciAuto(&a[i]);
    }

    int indiceMax = 0, indiceMin = 0;
    for (int i = 1; i < dim; i++) {
        if (a[i].prezzo > a[indiceMax].prezzo) {
            indiceMax = i;
        }
        if (a[i].prezzo < a[indiceMin].prezzo) {
            indiceMin = i;
        }
    }

    printf("\nPrezzo più alto:\n");
    stampaAuto(a[indiceMax]);

    printf("\nPrezzo più basso:\n");
    stampaAuto(a[indiceMin]);

    for (int i = 0; i < dim - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < dim; j++) {
            if (a[j].anno_immatricolazione < a[minIndex].anno_immatricolazione) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            struct Auto temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }

    printf("\nAuto ordinate per anno di immatricolazione:\n");
    for (int i = 0; i < dim; i++) {
        stampaAuto(a[i]);
    }

    int prezzoScelto;
    printf("\nInserisci un prezzo per visualizzare le auto con prezzo maggiore o uguale: ");
    scanf("%d", &prezzoScelto);

    int trovato = 0;
    for (int i = 0; i < dim; i++) {
        if (a[i].prezzo >= prezzoScelto) {
            stampaAuto(a[i]);
            trovato = 1;
        }
    }
    if (!trovato) {
        printf("Nessuna auto trovata con prezzo maggiore o uguale a %d.\n", prezzoScelto);
    }

    char targaRicerca[50];
    printf("\nInserisci la targa dell'auto da cercare: ");
    scanf("%s", targaRicerca);

    trovato = 0;
    for (int i = 0; i < dim; i++) {
        if (strcmp(a[i].targa, targaRicerca) == 0) {
            printf("\nAuto trovata:\n");
            stampaAuto(a[i]);
            trovato = 1;
            break;
        }
    }
    if (!trovato) {
        printf("Nessuna auto trovata con la targa %s.\n", targaRicerca);
    }
    int sommaPrezzi = 0;
for (int i = 0; i < dim; i++) {
    sommaPrezzi += a[i].prezzo;
}
float mediaPrezzo = (float)sommaPrezzi / dim;
printf("\nMedia dei prezzi delle auto: %.2f\n", mediaPrezzo);

int annoScelto;
printf("\nInserisci l'anno di immatricolazione da cercare: ");
scanf("%d", &annoScelto);

trovato = 0;
for (int i = 0; i < dim; i++) {
    if (a[i].anno_immatricolazione == annoScelto) {
        stampaAuto(a[i]);
        trovato = 1;
    }
}
if (!trovato) {
    printf("Nessuna auto trovata con anno di immatricolazione %d.\n", annoScelto);
}
    return 0;
}