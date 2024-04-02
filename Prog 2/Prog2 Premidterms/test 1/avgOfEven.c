#include <stdio.h>
int main(){

    int nValues;

    printf("Enter how many values: ");
    scanf("%d", &nValues);

    int List[nValues];
    int element;

    for (int i = 0; i < nValues; i++){
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &element);
        List[i] = element;
    }
    printf("List {");
    for (int i = 0; i < nValues; i++){
        if (i < nValues - 1){
            printf("%d, ", List[i]);
        } else {
            printf("%d", List[i]);
        }
    }
    printf("}\n");

    int sum = 0;
    int even = 0;

    for (int i = 0; i < nValues; i++){
        if (List[i] % 2 == 0){
            sum += List[i];
            even++;
        }
    }
    printf("The sum of even is %d.\n", sum);

    float average = (float) sum / (float) even;

    printf("The average of even is %.2f.", average);
}