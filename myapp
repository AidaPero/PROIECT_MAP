#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TARI 100

struct Tara {
    char nume[30];
    int culoare;
    int vecini[MAX_TARI];
    int numarVecini;
};

int esteCuloareDisponibila(struct Tara tari[], int taraIndex, int culoare, int numarTari) {
    for (int i = 0; i < tari[taraIndex].numarVecini; i++) {
        int vecinIndex = tari[taraIndex].vecini[i];
        if (tari[vecinIndex].culoare == culoare) {
            return 0; // Culoarea este deja folosita de un vecin
        }
    }
    return 1; // Culoarea este disponibila
}

void coloreazaHarta(struct Tara tari[], int numarTari, char culori[][20], int numarCulori) {
    for (int i = 0; i < numarTari; i++) {
        for (int j = 0; j < numarCulori; j++) {
            if (esteCuloareDisponibila(tari, i, j, numarTari)) {
                tari[i].culoare = j;
                break;
            }
        }
    }
}

void afiseazaRezultat(struct Tara tari[], int numarTari, char culori[][20]) {
    for (int i = 0; i < numarTari; i++) {
        printf("%s este colorata cu %s\n", tari[i].nume, culori[tari[i].culoare]);
    }
}

int main() {
    int numarTari, numarCulori;

    printf("Introduceti numarul de tari: ");
    scanf("%d", &numarTari);

    if (numarTari <= 0 || numarTari > MAX_TARI) {
        printf("Numar invalid de tari!\n");
        return 1;
    }

    struct Tara tari[MAX_TARI];
    char culori[MAX_TARI][20];

    for (int i = 0; i < numarTari; i++) {
        printf("Introduceti numele tarii %d: ", i + 1);
        scanf(" %[^\n]", tari[i].nume);
        tari[i].numarVecini = 0;
    }

    for (int i = 0; i < numarTari; i++) {
        int numarVecini;
        printf("Introduceti numarul de vecini pentru tara %s: ", tari[i].nume);
        scanf("%d", &numarVecini);

        printf("Introduceti vecinii pentru tara %s (indicii separati prin spatiu (1-n)): ", tari[i].nume);
        for (int j = 0; j < numarVecini; j++) {
            scanf("%d", &tari[i].vecini[j]);
            tari[i].vecini[j]--; // Indicele in program incepe de la 0
            tari[i].numarVecini++;
        }
    }

    printf("Introduceti numarul de culori disponibile: ");
    scanf("%d", &numarCulori);

    if (numarCulori <= 0) {
        printf("Numar invalid de culori!\n");
        return 1;
    }

    for (int i = 0; i < numarCulori; i++) {
        printf("Introduceti numele culorii %d: ", i + 1);
        scanf("%s", culori[i]);
    }

    coloreazaHarta(tari, numarTari, culori, numarCulori);

    printf("\nRezultatul colorarii hartii:\n");
    afiseazaRezultat(tari, numarTari, culori);

    return 0;
}
