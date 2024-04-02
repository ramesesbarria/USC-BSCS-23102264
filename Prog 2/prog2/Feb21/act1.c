#include <stdio.h>
#include <stdlib.h>

struct data {
    int x;
    float y;
};

struct data *getData() {
    
    struct data *ptr = (struct data *)malloc(3 * sizeof(struct data));
    
    int i;
    
    for(i = 0; i < 3; i++) {
        printf("Enter integer [%d]: ", i + 1);
        scanf("%d", &ptr[i].x);
    }
    
    for(i = 0; i < 3; i++) {
        printf("Enter float [%d]: ", i + 1);
        scanf("%f", &ptr[i].y);
    }
    
    
    return ptr;   
}

void printThis(struct data *temp) {
    
    int i;
    
    printf("Results: ");
    
    for(i = 0; i < 3; i++) {
        printf("\nInteger [%d]: %d", i + 1, temp[i].x);
    }
    
    for(i = 0; i < 3; i++) {
        printf("\nFloat [%d]: %.2f", i + 1, temp[i].y);
    }

}

int main() {
    
    struct data *var = getData();
    
    printThis(var);
    
    free(var); // Optional
    
    return 0;
}