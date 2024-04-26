#include<stdio.h>
int dline[5];
int profit[5];
int seq[5];
int jname[5];

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform Bubble Sort
void bubbleSort(int profits[], int deadlines[],int jname[] ,int n) {
	int i,j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (profits[j] < profits[j + 1]) {
                swap(&profits[j], &profits[j + 1]);
                swap(&deadlines[j], &deadlines[j + 1]);
                swap(&jname[j],&jname[j+1]);
            }
        }
    }
}

int main() {
	int j=1,i=0;
    int dmax,count=0,r=0,dead;
    int pr=0;
    int slot[5]={-1};
    printf("Enter The maximum deadline : ");
    scanf("%d",&dead);
    for(i=0;i<5;i++)
    {
    	printf("Enter the job name %d : ",i+1);
    	scanf("%d",&jname[i]);
        printf("enter profit of %d : ",i+1);
        scanf("%d",&profit[i]);
        printf("enter the deadline of %d : ",i+1);
        scanf("%d",&dline[i]);

    }
    //int profits[] = {60, 100, 120}; // Example profit array
    //int deadlines[] = {2, 1, 3};     // Example deadline array
    int n = sizeof(profit) / sizeof(profit[0]);

    // Sorting both arrays based on profit
    bubbleSort(profit, dline,jname, n);

    // Printing the sorted arrays
    printf("\nSorted Profits and Deadlines based on Profit:\n");
    printf("Name\tProfit\tDeadline\n");
    for (i = 0; i < n; i++) {
        printf("J%d\t%d\t%d\n",jname[i], profit[i], dline[i]);
    }
    for(i=0;i<n;i++)
    {
    	if(dline[i]<=dead)
    	{
    		pr+=profit[i];
    		dead-=dline[i];
    		
    		seq[i]=jname[i];
    		count++;            
		}
	}
	printf("\nMax profit = %d",pr);
	printf("\nSequence is : ");
	for(i=0;i<count;i++)
	{
		printf("J%d  ",seq[i]);
	}
	
     
    /*for(i=0;i<n;i++)
    {
        if(dline[i]>dmax)
        {
            dmax=dline[i];
        }
    }
    for(i=1;i<=dmax;i++)
    {
        slot[i]=-1;
    }
    for(i=0;i<5;i++)
    {
        for(r=dline[i];r>=1;r--){
            if(slot[r]==-1)
            {
                slot[r]=i;
                pr+=profit[i];
                count++;
                break;
            }
        }
        if(count ==dmax)
        {
            break;
        }
    }
    printf("\n\nTotal profit is : %d",pr);
    printf("\nMaximum deadline is : %d",dmax);*/
    return 0;
}


