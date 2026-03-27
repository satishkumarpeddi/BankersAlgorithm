#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
int max[100][100],need[100][100],alloc[100][100],avail[100];
int n,r;
void input();
void show();
void calculate();
void main(){
    printf("--Banker's Algorithm--\n");
    input();
    show();
    calculate();
}
void input(){
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter number of resources: ");
    scanf("%d",&r);
    printf("Enter value's for MAX matrix: ");
    for(int i=0;i<n;i++)
        for(int j=0;j<r;j++)
            scanf("%d",&max[i][j]);
    printf("Enter value's for Allocation Matrix: ");
    for(int i=0;i<n;i++)
        for(int j=0;j<r;j++)
            scanf("%d",&alloc[i][j]);
    printf("Enter value's for Available Matrix: ");
    for(int i=0;i<r;i++)
        scanf("%d",&avail[i]);
}
void show(){
    printf("Proccess\tMax\tAllocation\tAvailable\n");
    for(int i=0;i<n;i++){
        printf("P%d ",i);
    printf("\t\t");
        for(int j=0;j<r;j++)
            printf("%d ",max[i][j]);
        printf("\t\t");
        for(int j=0;j<r;j++)
            printf("%d ",alloc[i][j]);
        printf("\t\t");
        if(i==0){
            for(int j=0;j<r;j++)
            printf("%d ",avail[j]);
        }
        printf("\n");
    }
}
void calculate(){
    int finish[100]={0};
    int seq[100];
    int count=0;
    for(int i=0;i<n;i++)    
        for(int j=0;j<r;j++)
            need[i][j] = max[i][j]-alloc[i][j];
    while(count<n){
        int found=0;
        for(int i=0;i<n;i++){
            if(finish[i]==0){
                int canExecute=1;
                for(int j=0;j<r;j++){
                    if(need[i][j]>avail[j]){
                        canExecute=0;
                        break;
                    }
                }
                if(canExecute){
                    for(int k=0;k<r;k++)
                        avail[k]+=alloc[i][k];
                        found=1;
                        finish[i]=1;
                        seq[count++] = i;
                }
            }
        }
        if(!found) break;
    }
    if(count==n){
        printf("System is safe from dead lock's.\n");
        for(int j=0;j<n;j++)
            printf("P%d ",seq[j]);
    }else{
        printf("System is unsafe and dead may exist.\n");
    }
}