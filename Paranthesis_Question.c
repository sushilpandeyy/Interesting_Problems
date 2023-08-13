#include <stdio.h>
#include <string.h>
int maxi(char ar[100]){
int stack[strlen(ar)];
    int top=-1;
    int symlen=0;
    int maxsem=0;
    if(strlen(ar)%2==1){
        printf("Not Symmetric");
        return 0;
    }
    else if(ar[0]=='}'||ar[0]==']'||ar[0]==')'){
        printf("Not Symmetric");
        return 0;
    }
    for(int i=0; i<strlen(ar); i++){
        if(ar[i]=='['||ar[i]=='{'||ar[i]=='('){
            top++;                 //PUSH
            stack[top]=ar[i];
            symlen++;
        }
        else if( (ar[i]==']' && stack[top]=='[')||(ar[i]=='}'&&stack[top]=='{')||(ar[i]==')' && stack[top]=='(')){
            top--;
            symlen++;
        }
        if(top==-1){
            if(maxsem<=symlen){
                maxsem=symlen;
            }
            symlen=0;
        }
    }
    return maxsem;
}
int main(){
    char ar[100];
    printf("Enter Sequence: ");
    scanf("%s",ar); 
    int a=maxi(ar);
    if(a!=0)
    printf("%d",a);
}