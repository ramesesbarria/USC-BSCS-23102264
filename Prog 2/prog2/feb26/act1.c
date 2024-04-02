#include <stdio.h>
#include <string.h>

struct temp{
    char fname[20];
    char lname[20];
    char program[20];
    int age;
};

struct info{
    struct temp var[5];
};

struct temp *sortByProgramAsc(struct temp *var);
struct info sortByLastNameAsc(struct temp *var);
void printThisOne(struct temp *var);
void printThisTwo(struct info var);

int main(int argc, char *argv[]){
    struct temp var[5] = {{"Chris", "Maderazo", "BSCOMPE", 51},
                           {"John", "Duterte", "BSIT", 30},
                           {"asdf", "qwer", "BSCS", 19},
                           {"wert", "sdfg", "BSIT", 20},
                           {"sdfg", "hdfgh", "BSCS", 30}};

    struct temp *var2 = sortByProgramAsc(var);
    printThisOne(var2);

    struct info var3 = sortByLastNameAsc(var);
    printThisTwo(var3);

    return 0;
}

struct temp *sortByProgramAsc(struct temp *var){
    int i, j;
    struct temp tempVar;
    for (i = 0; i < 5; i++){
        for (j = i + 1; j < 5; j++){
            if (strcmp(var[i].program, var[j].program) > 0){
                tempVar = var[i];
                var[i] = var[j];
                var[j] = tempVar;
            }
        }
    }
    return var;
}

struct info sortByLastNameAsc(struct temp *var){
    int i, j;
    struct info tempInfo;
    for (i = 0; i < 5; i++){
        tempInfo.var[i] = var[i];
    }
    struct temp tempVar;
    for (i = 0; i < 5; i++){
        for (j = i + 1; j < 5; j++){
            if (strcmp(tempInfo.var[i].lname, tempInfo.var[j].lname) > 0){
                tempVar = tempInfo.var[i];
                tempInfo.var[i] = tempInfo.var[j];
                tempInfo.var[j] = tempVar;
            }
        }
    }
    return tempInfo;
}

void printThisOne(struct temp *var){
    int i;
    for (i = 0; i < 5; i++){
        printf("%s %s %s %d\n", var[i].fname, var[i].lname, var[i].program, var[i].age);
    }
    printf("\n");
}

void printThisTwo(struct info var){
    int i;
    for (i = 0; i < 5; i++){
        printf("%s %s %s %d\n", var.var[i].fname, var.var[i].lname, var.var[i].program, var.var[i].age);
    }
}
