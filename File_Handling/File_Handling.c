#include <stdio.h>

typedef struct {
    char FName[16], MI, LName[16];
}nameType;

typedef struct {
    nameType name;
    int age;
    char course[16];
}studRec;

int main() {
    FILE *fp;
    studRec student[] = {{{"Lawrence", 'A', "Tulod"}, 19, "BSCS"}, {{"Jonaz Juan", 'C', "Sayson"}, 22, "BSCS"}};
    fp = fopen("file.txt", "wb+");
    studRec receive[2];
    if (fp != NULL) {
        // char message[100];
        // fgets(message, 100, fp); 
        // printf("%s", message);
        int x;
        fwrite(student, sizeof(studRec), 2, fp);
        rewind(fp);
        fread(receive, sizeof(studRec), 2, fp);
        // for (x = 0; x < 2; x++) {
        // fprintf(fp, "%s %c. %s %d %s\n", student[x].name.FName,
        //                                  student[x].name.MI,
        //                                  student[x].name.LName,
        //                                  student[x].age,
        //                                  student[x].course);
        // }
        for (x = 0; x < 2; x++) {
        printf("%s %c. %s %d %s\n",      receive[x].name.FName,
                                         receive[x].name.MI,
                                         receive[x].name.LName,
                                         receive[x].age,
                                         receive[x].course);
        }
    }
    fclose(fp);
}