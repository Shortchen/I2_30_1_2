#include <stdio.h>
#include <stdlib.h>

#define INPUT_LENGTH 509 //509 character limit in C

int main(int argc, char *argv[]) {
    FILE *fz;

    char zeile[INPUT_LENGTH];

    int line_number = 0;

    //Syntax-Check
    if (argc != 2) {
        fprintf(stdout, "Syntax ERROR: Meinten Sie I2_30_1_2.exe [Dateiname] ?\n", argv[0]);
        return 187;
    }

    //return-wert von fopen() == NULL bei Fehler
    if ( (fz = fopen(argv[1], "r")) == NULL) { //argv[0] .exe;  argv[1] = Datastream
        fprintf(stdout, "Datei %s laesst sich nicht oeffnen", argv[1]);
        return 420;
    }

    //Einlesen in Buffer, print, und reassign
    while (fgets(zeile, INPUT_LENGTH, fz) != NULL) {
        line_number++;
        fprintf(stdout, "%5d %s", line_number, zeile);
    }

    //ordnunggemäß schliessen
    fclose(fz);
    return 0;
}
