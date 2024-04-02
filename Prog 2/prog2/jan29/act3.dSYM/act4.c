#include <stdio.h>
void printThis(int *num,int y)
{
	int x;
	printf("%i\n", sizeof(num));
	printf("%x\n", &num[0]);
	for(x=0; x<y; x++)
    {
        printf("%i\t", *num++);
    }printf("\n");
}
int main() {
    int num[5]={1,2,3,4,5},  x, *a;
    a = &num;
    for(x=0; x<sizeof(num)/sizeof(int); x++)
    {
        scanf("%i",&num[x]);
    }printf("\n");
    
    for(x=0; x<sizeof(num)/sizeof(int); x++)
    {
        printf("%i\t", num[x]);
    }printf("\n");
	printf("%x\n", &num[0]);
	printThis(num, sizeof(num)/sizeof(int));
    return 0;
}
