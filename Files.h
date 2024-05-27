#ifndef FILES_H
#define FILES_H

#include <stdio.h>
#include"constants.h"
#include <stdlib.h>
#include "./Variables.h"



void writeFile(double gameTime) {
    errno_t err;

    err = fopen_s(&fp, "./game_stats.txt", "a");
    if (err != 0)
    {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }
    else
    {
        fprintf(fp, "%f\n", gameTime);
        printf("File 'game_stats.txt' updated successfully.\n");
        fclose(fp);
    }
}

double readFile() {
    errno_t err;
    double minTime = 100000;
    double currentTime;

    err = fopen_s(&fp, "./game_stats.txt", "r");
    if (err != 0)
    {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }
    else
    {
        while (fgets(read, 100, fp) != NULL) {
            currentTime = strtod(read, NULL);
            if (currentTime < minTime) {
                minTime = currentTime;
            }
        }
        fclose(fp);

        if (minTime == 100000) {
            minTime = 0.0;
        }

        double time = strtod(read, NULL);
        return time;
    }
};
#endif
