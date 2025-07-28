#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int num, char *binary, int index)
{
    if (index < 0)
        return;
    binary[index] = (num % 2) + '0';
    decimalToBinary(num / 2, binary, index - 1);
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <n> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    char *inputFile = argv[2];
    char *outputFile = argv[3];

    FILE *fin = fopen(inputFile, "r");
    FILE *fout = fopen(outputFile, "w");

    if (fin == NULL || fout == NULL)
    {
        printf("Error opening input or output file.\n");
        return 1;
    }

    int num, count = 0;
    while (count < n && fscanf(fin, "%d", &num) == 1)
    {
        char binary[17];
        binary[16] = '\0';

        for (int i = 0; i < 16; i++)
            binary[i] = '0';

        decimalToBinary(num, binary, 15);

        fprintf(fout, "The binary equivalent of %d is %s\n", num, binary);
        count++;
    }

    fclose(fin);
    fclose(fout);

    fout = fopen(outputFile, "r");
    if (fout == NULL)
    {
        printf("Error reading output file.\n");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), fout))
    {
        printf("%s", line);
    }

    fclose(fout);
    return 0;
}
