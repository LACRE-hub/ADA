#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 5

char mapping[10][5] = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

int main() {
    char digits[MAX_LENGTH];
    char l1[5] = "", l2[5] = "", l3[5] = "", l4[5] = "";
    printf("Ingrese los digitos (2-9): ");
    scanf("%s", digits);
    int len = strlen(digits);
    if (len == 0) {
        printf("[]\n");
        return 0;
    }
        strcpy(l1, mapping[digits[0] - '0']);
    if (len > 1) strcpy(l2, mapping[digits[1] - '0']);
    if (len > 2) strcpy(l3, mapping[digits[2] - '0']);
    if (len > 3) strcpy(l4, mapping[digits[3] - '0']);

    for (int i = 0; i < strlen(l1); i++) {
        for (int j = 0; j < (len > 1 ? strlen(l2) : 1); j++) {
            for (int k = 0; k < (len > 2 ? strlen(l3) : 1); k++) {
                for (int l = 0; l < (len > 3 ? strlen(l4) : 1); l++) {
                    char combinacion[5] = "";
                    combinacion[0] = l1[i];
                    if (len > 1) combinacion[1] = l2[j];
                    if (len > 2) combinacion[2] = l3[k];
                    if (len > 3) combinacion[3] = l4[l];

                    printf("\"%s\" ", combinacion);
                }
            }
        }
    }
     printf("\n");
    return 0;
}
