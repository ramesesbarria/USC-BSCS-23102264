#include <stdio.h>
#include <stdlib.h>
#define STRING_MAX 50
#define LIST_MAX 10
typedef struct{
	int month;
	int year;
}currentDate;
typedef struct{
	int hireMonth;
	int hireYear;
}hiringDetails;

typedef struct{
	char fName[STRING_MAX];
}empDetails;

typedef struct{
	hiringDetails dateOfHire;
	empDetails employeeInfo;
}employee;

typedef struct{
	employee employeeList[LIST_MAX];
	int count;
}employeeRecords;

employee* getLoyalList(employeeRecords record,int *loyalListCount,currentDate currDate);

void display(employeeInfo *loyalList,int loyalListCount);
int main(){
	employeeRecords record;
	int employeeCount;
	int loyalListCount=0;
	record.count=0;
	employee *loyalList;
	currentDate date={07,2023};
	
	int i=0;
	printf("Input Number of Employees:" );
    scanf("%d",&employeeCount);
    
    printf("\nInput Details for Employees: \n");
    for(i=0;i<employeeCount;i++){
    	printf("\n\n===Employee %d===\n",i+1);
    	/*CODE FOR INPUTS*/
	}
	
	loyalList=getLoyalList(record,&loyalListCount,date);
	
	display(/*COMPLETE THE FUNCTION CALL*/);
	
}

employee* getLoyalList(employeeRecords record,int *loyalListCount,currentDate currDate){
    /*CODE TO CREATE THE LOYAL LIST*/
}

void display(employeeInfo *loyalList,int loyalListCount){
    /*CODE TO DISPLAY*/
}