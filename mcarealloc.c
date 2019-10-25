#include <stdlib.h>
#include <stdio.h>
int main(){

    
    /*MALLOC*/
    struct Emp {
        int id;
        char name[50];
        float salary;
    };
    struct Emp* ptr;
    ptr = (struct Emp*) malloc(sizeof(struct Emp));
    if(ptr!=NULL){
        printf("Success");
        scanf("%d %s %f",&ptr->id,ptr->name,&ptr->salary);
        printf("%d",ptr->id);
    }
    
    
        
    
    /*CALLOC*/  
    int n, *myArrptr;
    scanf("%d",&n);
    myArrptr=(int*)calloc(n,sizeof(int));
    if(myArrptr!=NULL){
      printf("Success");
      for(int i; i<n; i++){
        printf("%d", *(myArrptr+i));
      }
    }
    

    /*REALLOC*/
    /*STACK EXAMPLE*/
    int capacity =5, *stack;
    stack = (int*) calloc(capacity,sizeof(int));
    capacity++;
    stack = (int *)realloc(stack, capacity*sizeof(int));
    
    return 0;
}
