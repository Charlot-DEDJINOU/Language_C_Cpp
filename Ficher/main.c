#include <stdio.h>

int main() {

    FILE *fichier = fopen("fichier.txt", "a");

    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier\n");
        return 1;
    }

    fprintf(fichier, "Nouvelle ligne de texte\n");
    fprintf(fichier, "Nouvelle ligne de texte\n");
    fprintf(fichier, "Nouvelle ligne de texte\n");
    fclose(fichier);

    return 0;
}
