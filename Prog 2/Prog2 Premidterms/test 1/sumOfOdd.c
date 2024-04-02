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

    for (int i = 0; i < nValues; i++){
        if (List[i] % 2 != 0){
            sum += List[i];
        }
    }
    printf("The sum of odd is %d.", sum);
}