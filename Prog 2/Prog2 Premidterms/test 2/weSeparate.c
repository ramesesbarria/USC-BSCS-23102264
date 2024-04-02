#include <stdio.h>
#define MAX 100

void main() {
    int list[MAX];
    int n;

    printf("Enter how many values: ");
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", list+i);
    }

    printf("Original {");
    for(int i = 0; i < n; ++i) {
        printf("%d", *(list + i));
        if(i < n-1) {
            printf(", ");
        }
    }
    printf("}\n");

    int size = 0;
    int new[MAX];
    
        if (*(list) % 2 == 0){
            for (int j = 0; j < n; j++){
                if (*(list + j) % 2 == 0){
                    new[size + 1] = *(list + j);
                    size++;
                }
            }
        } else {
            for (int j = 0; j < n; j++){
                if (*(list + j) % 2 != 0){
                    new[size + 1] = *(list + j);
                    size++;
                }
            }
        }


    new[0] = size;
    
    printf("New {");
    for (int i = 1; i < new[0] + 1; i++){
        if (i == new[0]){
            printf("%d", new[i]);
        } else {
            printf("%d, ", new[i]);
        }
    }
    printf("}\n");


}