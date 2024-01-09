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

void definesteTari(struct Tara tari[], int *numarTari) {
    *numarTari = 5; // Seteaza numarul de tari

    // Defineste numele tarilor
    strcpy(tari[0].nume, "Tara1");
    strcpy(tari[1].nume, "Tara2");
    strcpy(tari[2].nume, "Tara3");
    strcpy(tari[3].nume, "Tara4");
    strcpy(tari[4].nume, "Tara5");

    // Defineste vecinii pentru fiecare tara
    tari[0].vecini[0] = 1;
    tari[0].vecini[1] = 2;
    tari[0].vecini[2] = 3;
    tari[1].vecini[0] = 0;
    tari[1].vecini[1] = 2;
    tari[2].vecini[0] = 0;
    tari[2].vecini[1] = 1;
    tari[2].vecini[2] = 3;
    tari[2].vecini[3] = 4;
    tari[3].vecini[0] = 0;
    tari[3].vecini[1] = 2;
    tari[3].vecini[2] = 4;
    tari[4].vecini[0] = 2;
    tari[4].vecini[1] = 3;

    // Setează numarul de vecini pentru fiecare tara
    tari[0].numarVecini = 3;
    tari[1].numarVecini = 2;
    tari[2].numarVecini = 4;
    tari[3].numarVecini = 3;
    tari[4].numarVecini = 2;
}

void definesteCulori(char culori[][20], int *numarCulori) {
    *numarCulori = 3; // Setează numarul de culori

    // Defineste numele culorilor
    strcpy(culori[0], "Albastru");
    strcpy(culori[1], "Galben");
    strcpy(culori[2], "Verde");
}

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
            if (esteCuloareDisponibila(tari, i, j, numarTari) && j < tari[i].numarVecini) {
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

    // Defineste tari
    struct Tara tari[MAX_TARI];
    definesteTari(tari, &numarTari);

    // Defineste culori
    char culori[MAX_TARI][20];
    definesteCulori(culori, &numarCulori);

    coloreazaHarta(tari, numarTari, culori, numarCulori);

    printf("\nRezultatul colorarii hartii:\n");
    afiseazaRezultat(tari, numarTari, culori);

    return 0;
}
