#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char *inputFile = argv[1];
    char *outputFile = argv[2];

    FILE *fin = fopen(inputFile, "r");
    FILE *fout = fopen(outputFile, "w");

    if (fin == NULL || fout == NULL) {
        printf("Error opening input or output file.\n");
        return 1;
    }

    int a, b;
    while (fscanf(fin, "%d %d", &a, &b) == 2) {
        int result = gcd(a, b);
        fprintf(fout, "The GCD of %d and %d is %d\n", a, b, result);
    }

    fclose(fin);
    fclose(fout);

    // Display the contents of the output file
    fout = fopen(outputFile, "r");
    if (fout == NULL) {
        printf("Error reading output file.\n");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), fout)) {
        printf("%s", line);
    }

    fclose(fout);
    return 0;
}
