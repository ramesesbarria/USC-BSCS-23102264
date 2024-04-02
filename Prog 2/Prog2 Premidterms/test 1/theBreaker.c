#include <stdio.h>
int main(){

    int nValues;

    printf("Enter the size of the array: ");
    scanf("%d", &nValues);

    int List[nValues];
    int element;

    for (int i = 0; i < nValues; i++){
        printf("Enter element: ");
        scanf("%d", &element);
        List[i] = element;
    }

    int missing = 0;
    int found = 0;

    if (nValues == 1){
        missing = List[0] - 1;
    } else {
        while (found == 0){
            for (int i = 0; i < nValues; i++){
                if (List[i + 1] - List[i] == 2){
                    missing = List[i] + 1;
                    found++;
                }
            }
        }
    }
    printf("The missing number is: %d", missing);

}