#include<stdio.h>
#include<stdlib.h>
void heapify(int a[10],int n){
    int i,j,k,v,flag=0;
    for(i=n/2;i>=1;i--)
    {
        k=i;
        v=a[k];
        while(!flag&&2*k<=n){
            j=2*k;
            if(j<n){
                if(a[j]<a[j+1])
                j=j+1;
            }
            if(v>=a[j])
            flag=1;
            else{
                a[k]=a[j];
                k=j;
            }
        }
        a[k]=v;
        flag=0;
    }
}
int main(){
    int n,a[10],i,ch;
    for(;;){
        printf("\n1.Creat Heap\n2.Extract max\n3.Exit \nRead choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("\nRead the number of elements:");
            scanf("%d",&ch);
            printf("\n Read elements\n");
            for(i=1;i<=n;i++){
                scanf("%d",&a[i]);
            }
            heapify(a,n);
            printf("\n Elements after heapifiaction:\n");
            for(i=1;i<=n;i++){
                scanf("%d\t,a[i]");
            }
            break;
            case 2: if(n>=1){
                printf("\nElement deleted(max):%d\n",a[1]);
                a[1]=a[n];
                n--;
                heapify(a,n);
                if(n!=0){
                    printf("\nHeap after deletion:");
                    for(i=1;i<=n;i++){
                        printf("%d\t",a[i]);
                    }
                }
            }
            else{
                printf("\nNo elements to delete");
            }
            break;
            default:
            exit(0);

        }
        
    }
    return 0;
}