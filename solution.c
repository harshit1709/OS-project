#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
struct person
{
int id,wait,burst,turn;
int i,n;
};

void getData(struct person p[30],int n)
{
	int i,x=1;
	p[i].wait = 0;
	p[i].turn = 0; 
    for (i = 0; i < n; i++)
    {
        printf("\n Give data for Person %d \n",x);
        printf("\n Enter Person id : ");
        scanf("%d",&p[i].id);
        printf("\n Give Burst time in minuts :\n");
        scanf("%d",&p[i].burst);
        x++;
    }

}

void sort(struct person p[30],int n)
{
	int i,j;
	struct person t;
	for(i=0;i<(n-1);i++)
	{
		for(j=0;j<(n-i-1);j++)
		{
			if(p[j].burst<p[j+1].burst)
			{
				t = p[j];
				p[j]=p[j+1];
				p[j+1] = t;
			}
			else if (p[j].burst=p[j+1].burst)
			{
				if(p[j].id<p[j+1].id)
				{
					t = p[j];
					p[j]=p[j+1];
					p[j+1] = t;
				}
			}
		}
	}
}

void displayData(struct person p[30],int n)
{
	int i;
	int avgWait = 0 , avgTurn = 0;
    for (i = 0; i < n; i++)
    {
        printf("Waiting time for person %d is : %d\n\n",(i+1),p[i].wait);
        
    }
    for (i = 0; i < n; i++)
    {
        
        printf("Turnaround time for person %d is : %d\n\n",(i+1),p[i].turn);
    }
    for (i = 0; i < n; i++)
    {
    	avgWait += p[i].wait;
    	avgTurn += p[i].turn;
	}
	int y=avgWait/n;
	int z=avgTurn/n;
	printf("Average Waiting time : %d\n",y);
    printf("Average Turnaround time : %d\n",z);
}



void calculate(struct person p[30],int n)
{
	int i,time = 0;
	
	for(i = 0;i<n;i++)
	{
		p[i].wait = time;
		p[i].turn = time+p[i].burst ;
		time += p[i].burst;
	}
	
}
void validate(struct person p[30],int n)
{
	int i;
	for(i = 0;i<n;i++)
	{
		if(p[i].id==p[i+1].id)
		{
			printf("you entered same ID for 2 students\n");
			System.exit(0);
		}
	}
}

void main ()
{
	int n;
	struct person p[30];
	printf("Enter the number of person : ");
	scanf("%d",&n);
	getData(p,n);
	validate(p,n);
	sort(p,n);
	calculate(p,n);
	displayData(p,n);
}
