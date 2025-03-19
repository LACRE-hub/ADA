#include <stdio.h>
#include <stdlib.h>

int suma_arreglo(int n, int skills[]) {
    int acumulador = 0;
    for (int i = 0; i < n; ++i) {
        acumulador += skills[i];
    }
    return acumulador;
}

int main() {
    int n;
    printf("\n¿Cuantos jugadores quieres?");
    scanf("%i", &n);

    int skills[n];

    for (int i = 0; i < n; ++i) {
        printf("Ingresa el elemento %i del arreglo: ", i + 1);
        scanf("%d", &skills[i]);
    }

    int suma = suma_arreglo(n, skills);

    if (suma % 2 != 0) {
        printf("ERROR: La suma total de habilidades es impar, no se puede dividir en equipos iguales.\n");
        return -1;
    }

    int team_skill = suma / (n / 2);

    int chemistry_sum = 0;
    int team_formed = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (skills[i] + skills[j] == team_skill) {
                chemistry_sum += skills[i] * skills[j];
                skills[i] = -1;
                skills[j] = -1;
                team_formed++;
                break;
            }
        }
    }

    if (team_formed == n / 2) {
        printf("La suma de la quimica de todos los equipos es: %d\n", chemistry_sum);
    } else {
        printf("ERROR: No se puede dividir a los jugadores en equipos con habilidades iguales.\n");
        return -1;
    }

    return 0;
}
