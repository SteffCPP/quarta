#include <stdio.h>
#define MAX 10
int coda[MAX];
int inizio = -1;
int fine = -1;

int vuota() {
    return (inizio == -1);
}

int piena() {
    return ((fine + 1) % MAX == inizio);
}

void enqueue(int valore) {
    if (piena()) {
        printf("Coda piena! Inserimento non possibile.\n");
        return;
    }
    if (vuota()) {
        inizio = 0;
        fine = 0;
    } else {
        fine = (fine + 1) % MAX;
    }
    coda[fine] = valore;
}

void dequeue() {
    if (vuota()) {
        printf("Coda vuota! Non c'e' niente da estrarre.\n");
        return;
    }
    printf("Estratto: %d\n", coda[inizio]);
    if (inizio == fine) {
        inizio = -1;
        fine = -1;
    } else {
        inizio = (inizio + 1) % MAX;
    }
}

void stampa() {
    if (vuota()) {
        printf("Coda vuota!\n");
    return;
    }
    printf("Coda: ");
    int i = inizio;
    while (1) {
        printf("%d ", coda[i]);
        if (i == fine)
        break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int scelta, valore;
    do {
        printf("\n--- CODA CIRCOLARE ---\n");
        printf("1. Inserisci\n");
        printf("2. Estrai\n");
        printf("3. Stampa\n");
        printf("0. Esci\n");
        scanf("%d", &scelta);
        switch (scelta) {
            case 1:
                printf("Inserisci numero: ");
                scanf("%d", &valore);
                enqueue(valore);
            break;
            case 2:
                dequeue();
            break;
            case 3:
                stampa();
            break;
        }
    } while (scelta != 0);
    return 0;
}
