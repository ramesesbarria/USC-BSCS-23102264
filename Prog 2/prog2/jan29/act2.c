int main() {
    int a,b,*c;
    a=10;
    c= &b;
    *c=20;
    printf("The content of a is %i\n",a);
    printf("The content of b is %i\n",b);
    printf("The content of c is %i\n",c);
    
    printf("The value in the address that is c holding is %i\n\n",*c);
    
    printf("The address of a is %i\n",&a);
    printf("The address of b is %i\n",&b);
    printf("The address of c is %i\n",&c);

    return 0;
}