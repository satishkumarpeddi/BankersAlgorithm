#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
int max[100][100],finish[100]={0},need[100][100],alloc[100][100],avail[100];
int p,r;
void input();
void show();
void preventDeadLock();
int safeCheck();
void calculate();
void main(){
    printf("--DeadLock Prevention--\n");
    input();
    show();
    calculate();
    if(safeCheck()){
        printf("There exit a dead lock.\n");
        preventDeadLock();
    }else{
        printf("No Dead Lock Exists.\n");
    }
}
void input(){
    printf("Enter number of processes: ");
    scanf("%d",&p);
    printf("Enter number of resources: ");
    scanf("%d",&r);
    printf("Enter value's for MAX matrix: ");
    for(int i=0;i<p;i++)
        for(int j=0;j<r;j++)
            scanf("%d",&max[i][j]);
    printf("Enter value's for Allocation Matrix: ");
    for(int i=0;i<p;i++)
        for(int j=0;j<r;j++)
            scanf("%d",&alloc[i][j]);
    printf("Enter value's for Available Matrix: ");
    for(int i=0;i<r;i++)
        scanf("%d",&avail[i]);
}
void show(){
    printf("Proccess\tMax\tAllocation\tAvailable\n");
    for(int i=0;i<p;i++){
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
    for(int i=0;i<p;i++)
        for(int j=0;j<r;j++)    
            need[i][j] = max[i][j] - alloc[i][j];
}
int safeCheck(){ 
        int found=0;
        for(int i=0;i<p;i++){
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
            }
            if(found) return 1;
        }
        return 0;
}
void preventDeadLock(){
    printf("Applying Prevention(No Preemption + No Hold & Wait)\n");
    for(int i=0;i<p;i++){
       if(!finish[i]){
         printf("P%d cannot be exectued -> Applying Preemption.\n",i);
        for(int j=0;j<r;j++){
            avail[j]+=alloc[i][j];
            alloc[i][j]=0;
        }
        int canAllocate=1;
        for(int j=0;j<r;j++){
            if(need[i][j]>avail[j]){
                canAllocate=0;
                break;
            }
        }
        if(canAllocate){
            for(int j=0;j<r;j++){
                printf("\n Allocating the resource for P%d",i);
                avail[j]-=need[i][j];
                alloc[i][j]+=need[i][j];
                need[i][j];
            }
            printf("\n Resource are allocated to the P%d",i);
            for(int j=0;j<r;j++){
                avail[j]+=alloc[i][j];
                alloc[i][j]=0;
            }
            finish[i]=1;
            }else{
                printf("\n Still Allocation is not properly setted.\n");
            }
       }
    }
    printf("\n\nFinal Available Resources: ");
    for (int j = 0; j < r; j++)
        printf("%d ", avail[j]);

    printf("\n\nDeadlock prevented by:\n");
    printf("Eliminating Hold and Wait\n");
    printf("Applying Preemption\n");
}