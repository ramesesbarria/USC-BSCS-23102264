int main() {
    int num[5]={1,2,3,4,5}, x;
    int *a;
    a = &num;
    
    for(x=0; x<5; x++){
        printf("%i\t", *(a+x));
    }printf("\n");

    for(x=0; x<5; x++){
        printf("%i\t", *(a)); a++;
    }printf("\n");
    
    for(x=0; x<5; x++){
        printf("%i\t", num[x]);
    }

    return 0;
}
