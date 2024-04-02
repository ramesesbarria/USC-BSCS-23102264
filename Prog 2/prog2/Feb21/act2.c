#include <stdio.h>

struct data{
    int x;
    float y;
};

struct info{
    struct data var[3];
};

struct info getData(){
    struct info temp;

    for (int i = 0; i < 3; i++) {
        printf("Enter x and y for data %d: ", i+1);
        scanf("%d %f", &temp.var[i].x, &temp.var[i].y);
    }

    return temp;
}

void printThis(struct info temp){
    for (int i = 0; i < 3; i++) {
        printf("Data %d: x = %d, y = %.2f\n", i+1, temp.var[i].x, temp.var[i].y);
    }
}

int main(){
    struct info temp = getData();
    printThis(temp);
    
    return 0;
}
