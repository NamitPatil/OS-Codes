#include<stdio.h>
int msize=100;
int pname[5];
int memory[5];
int executed[5];

int main()
{

    int msize,fsize,pnum,i,rframe[5],count=0;
    printf("Enter The Total Memory Size :");
    scanf("%d",&msize);
    
	int user=msize-(msize*0.40);
	int a=msize*0.40;
	printf("\n\nSpace used for os is :%d",a);
	printf("\n\nRemaining Space for use program is :%d ",user);
	
	printf("\nEnter the no of processes : ");
	scanf("%d",&pnum);
	
	//printf("\nEnter the size of frame : ");
	//scanf("%d",&fsize);
	
//	int tframe=(user/fsize);
	//printf("Total Frames = %d",tframe);
	
	for(i=0;i<pnum;i++)
    {
    	printf("\nEnter the Process name %d : ",i+1);
    	scanf("%d",&pname[i]);
        printf("enter required memory of P%d : ",i+1);
        scanf("%d",&memory[i]);       
    }
    printf("PName\tMemory\n");
    for (i = 0; i < pnum     ; i++) {
       // rframe[i]=memory[i]/fsize;
        printf("P%d\t%d\n",pname[i], memory[i]);
    }
	for (i = 0; i < pnum; i++) {
        if (memory[i] <= user) {
             user -= memory[i];
            executed[i]=i+1;
				count++;
			}
		else{
			break;
		}
		}
            
	
	printf("\nExecuted Process = ");
	for(i=0;i<count;i++)
	{
		printf("P%d ",executed[i]);
	}
	printf("\nRemaining Memory=%d",user);
}
