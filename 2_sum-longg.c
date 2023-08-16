#include <stdio.h>
#include <stdlib.h>
struct node
{   int data;
    struct node * next;
};
struct sum{
    int data;
    struct sum* next;
};
struct node1{
    int data;
    struct node1* next;
};
struct sum * reverse(struct sum * home)
{
   struct sum *prevnode,*currentnode, *nextnode;
   prevnode=NULL;
   currentnode=nextnode=home;
   while(nextnode->next!=NULL)
   {
    nextnode=nextnode->next;
    currentnode->next=prevnode;
    prevnode=currentnode;
    currentnode=nextnode;    
   }
   nextnode->next=prevnode;
   home=nextnode;
   
    return home;

}
int main(){
    long long int n;
    long long int n1;
    printf("Enter the number1: ");
    scanf("%lld",&n);
    printf("Enter the number2: ");
    scanf("%lld",&n1);
    int count=0;
    int count1=0;
    struct node* head;
    struct node1* head1;
    struct node1* temp1;
    struct node* temp;
    while(n){
        struct node* newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=n%10;
        newnode->next=NULL;
        if(count==0)
        {
        head=newnode;
        temp=head;
        }
        else{
        temp->next=newnode;
        temp=newnode;
        }
        n=n/10;
        count++;
    }
    while(n1){
        struct node1* newnode=(struct node1 *)malloc(sizeof(struct node1));
        newnode->data=n1%10;
        newnode->next=NULL;
        if(count1==0)
        {
        head1=newnode;
        temp1=head1;
        }
        else{                      
        temp1->next=newnode;
        temp1=newnode;
        }
        n1=n1/10;
        count1++;
    }
    int cot=1;
    struct sum* heads;
    struct sum* temps;
    int borrow=0;
    while(head!=NULL || head1!=NULL){
        int sum=head->data+head1->data;
        sum=sum+borrow;  
        if(sum>9){
            borrow=1;
        }
        else{
            borrow=0;
        }
        sum=sum%10;
      struct sum* newnode=(struct sum*)malloc(sizeof(struct sum));
      newnode->data=sum;
        if(cot){
            heads=newnode;
            newnode->next=NULL;
            temps=heads;
            cot--;
        }
        else{
            temps->next=newnode;
            newnode->next=NULL;
            temps=newnode;
        }
        head=head->next;
        head1=head1->next;
    }
    if(borrow)
    printf("%d",borrow);
    heads=reverse(heads);
    while(heads!=NULL){
        printf("%d",heads->data);
        heads=heads->next;
    }

}
