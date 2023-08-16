#include <stdio.h>
int main()
{
    int a;
    printf("Enter number of elements \n");
    scanf("%d",&a);
    int arr[a];
    for(int i=0; i<a; i++){
        scanf("%d",&arr[i]);
    }
    int time;
    printf("Enter number of times: \n");
    scanf("%d",&time);
    while(time--){
    int temp=arr[0];
    for(int i=0; i<a; i++){
        arr[i]=arr[i+1];
    }
    arr[a-1]=temp;
    printf("After %d Turn\n",time);
    for(int j=0; j<a; j++){
        printf("%d ",arr[j]);
    }
    printf("\n");}
    return 0;
}