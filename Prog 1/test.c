#include <stdio.h>
int main(){

    int n;
    int incrementer = 1;

    printf("Enter an integer: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++){
        printf("%d ", incrementer);
        incrementer += 1;
    }
    
}