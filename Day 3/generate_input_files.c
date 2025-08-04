#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateAscending(const char *filename, int count) {
    FILE *fp = fopen(filename, "w");
    for (int i = 1; i <= count; i++) {
        fprintf(fp, "%d ", i * 10);
    }
    fclose(fp);
    printf("%s generated with %d ascending elements.\n", filename, count);
}

void generateDescending(const char *filename, int count) {
    FILE *fp = fopen(filename, "w");
    for (int i = count; i >= 1; i--) {
        fprintf(fp, "%d ", i * 10);
    }
    fclose(fp);
    printf("%s generated with %d descending elements.\n", filename, count);
}

void generateRandom(const char *filename, int count) {
    FILE *fp = fopen(filename, "w");
    srand(time(0));
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d ", rand() % 10000);
    }
    fclose(fp);
    printf("%s generated with %d random elements.\n", filename, count);
}

int main() {
    int count = 500;  // Number of elements in each file

    generateAscending("inAsce.dat", count);
    generateDescending("inDesc.dat", count);
    generateRandom("inRand.dat", count);

    return 0;
}