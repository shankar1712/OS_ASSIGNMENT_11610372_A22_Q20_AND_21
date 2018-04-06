#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<conio.h>
int p;
int q;
int i,j;
int n,r;
int instance[10];
int finish[10];
int max[50][50];
int allo[50][50];
int needmatrix[50][50];
int requestmatrix[50][50];
int safe[20];
int avail[20];
int calling()
{
	printf("if you want to continue press 1 otherwise 0  :");
	scanf("%d",&n);
	if(n==1)
	{
		main();
	}
	else
	{
		exit(0);
	}
}
int instances()
{
	for(i=0;i<p;i++)
	{
	printf("enter the no of instances for resource R%d  :",i);
	scanf("%d",&instance[i]);
    }
    for(i=0;i<p;i++)
	{
	printf("no of instances for resource R%d is %d\n",i,instance[i]);
	
    }
}
int maxresource()
{
	for(i=0;i<q;i++)
	{
	 printf("enter the maximum resources need for process p%d ");
	 for(j=0;j<p;j++)
	 {
	 	int sum=0;
		printf("for resource R%d :");
		scanf("%d",&max[i][j]);
		sum=sum+max[i][j];
	    if(max[i][j]<1||max[i][j]>p||sum>p+q)
	    {
	    	printf("you have entered incorrect values\n");
	    	printf("values must be between or equal to 1 and %d \n",p);
			printf("required conditions not satisfed\n");
			calling();
		}
	 }
	 
    }
}
int allocated()
{
	for(i=0;i<q;i++)
	{
	 printf("enter the allocated resources for process p%d ");
	 for(j=0;j<p;j++)
	 {
		printf("for resource R%d :");
		scanf("%d",&allo[i][j]); 
	 }
    }
   
}
int  need()
{
    	printf("\n\nneed matrix :\n    ");
	for(i=0;i<q;i++){
		printf(" R%d",i);
	}
	for(i=0;i<p;i++){
		printf("\nP%d ",i);
		for(j=0;j<q;j++){
			needmatrix[i][j]=max[i][j]-allo[i][j];
			printf("  %d",needmatrix[i][j]);
		}
	}
}
int request()
{
	int j,k;
	for(j=0;j<3;j++)
	{
		printf("\nFor resource %c :",j+65);
		scanf("%d",&requestmatrix[i][j]);
		k=requestmatrix[i][j];
		if(requestmatrix[i][j]>needmatrix[i][j])
		{
			printf("\nProcess has exceeded its maximum claim for instances. Request cannot be granted.");
			return;
		}
		if(requestmatrix[i][j]>avail[j])
		{
			printf("\nResources are not yet available , You have to wait for request grant.");
		}
		else
		{
			avail[j] = avail[j] - requestmatrix[i][j];
			needmatrix[i][j] = needmatrix[i][j] - requestmatrix[i][j];
		}
	}
	int c=safety();
	if(c==0)
	{
		printf("\nProcess P%d is granted the Requested instances ",i);
		return;
	}
	else
	{
		printf("\nProcess P%d cannot be granted the requested instances because of unsafe state,\nProcess has to wait for the safe environment.",i);
		needmatrix[i][j] = needmatrix[i][j] + requestmatrix[i][j];
		avail[j] = avail[j] + requestmatrix[i][j];
	}
}
int safety()
{
	int k=0;
	int ssnum=0;
	int l=0;
	while(1){
		for(i=0;i<q;i++)
		{
			if(finish[i]==0)
			{
				for(j=0;j<p;j++)
				{
					if(avail[j] >= needmatrix[i][j]){
						
					}
					else{
						break;
					}
				}
				if(j==p)
				{	
					for(j=0;j<p;j++)
					{
						avail[j]=avail[j]+allo[i][j];
					}
					finish[i]=1;
					safe[ssnum]=i;
					ssnum++;
					l++;
				}
			}
		}
		
		if(k==r)
		{
			if(l == r)
			{
				printf("\nSystem is in safe state with safe sequence : <");
				for(i=0;i<r;i++)
				{
					printf(" P%d",safe[i]);
				}
				printf(" >");
				calling();
			}
			else
			{
				printf("\nSystem is in unsafe state\n");
				calling();
			}
		}
		k++;
	}
}

int main()
{
	printf("enter no of resources  :");
	scanf("%d",&p);
	printf("enter no of process  :");
	scanf("%d",&q);
	instances();
	maxresource();
	allocated();
	need();
	request();
	safety();
}
