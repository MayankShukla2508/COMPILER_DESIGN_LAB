#include <stdio.h>
#define max 100

int main() {
    char str[max], f = 'A';
    int i;

    FILE *inputFile = fopen("input_1.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *outputFile = fopen("op.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    while (fscanf(inputFile, "%s", str) != EOF) {
        f = 'A'; 

        for (i = 0; str[i] != '\0'; i++) {
            switch (f) {
                case 'A':
                    if (str[i] == '0') f = 'C';
                    else if (str[i] == '1') f = 'B';
                    break;
                case 'B':
                    if (str[i] == '0') f = 'D';
                    else if (str[i] == '1') f = 'A';
                    break;
                case 'D':
                    if (str[i] == '0') f = 'B';
                    else if (str[i] == '1') f = 'C';
                    break;
                case 'C':
                    if (str[i] == '0') f = 'A';
                    else if (str[i] == '1') f = 'D';
                    break;
            }
        }

        if (f == 'A')
            fprintf(outputFile, "String \"%s\" is accepted\n", str);
        else
            fprintf(outputFile, "String \"%s\" is not accepted\n", str);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Results written to ou.txt.\n");

    return 0;
}