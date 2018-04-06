#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
	float spf;				//time to service a page fault
	float rpm;		   		//time to modify a replaced page
	float mat;				//memory access time
	float mp;					//percentage of time taken to modify a replaced page
	float mapfr;            //maximum acceptable page-fault rate
    float ea;                 //effective access time
	printf("Enter the time takes to service a page fault in milliseconds\n");
	scanf("%f",&spf);
	printf("Enter the time takes to modify a replaced page in milliseconds \n");
	scanf("%f",&rpm);
	printf("Enter the memory access time in nano seconds \n");
	scanf("%f",&mat);
	printf("Enter percentage of time taken to modify a replaced page\n");
	scanf("%f",&mp);
	printf("Enter maximum access time in milliseconds\n");
	scanf("%f",&ea);
	mapfr=((rpm/1000)-(mat/1000))/(-(mat/1000)+(0.3*spf)+((mp/100)*rpm));
	printf("%f",mapfr);
}
