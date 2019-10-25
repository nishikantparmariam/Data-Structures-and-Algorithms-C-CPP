    #include <stdio.h>

    /*Stack implementation*/
    int size(int *arr, int t){    
        return t+1;
    }
    void push(int *arr, int *t, int number){
    if(size(arr,*t)>1000){    
    } else {
        *t+=1;
        arr[*t] = number;    
    }
    }

    int pop(int *arr, int *t){
    int toReturn  = arr[*t];
    *t-=1;  
    return toReturn;
    }

    int top(int *arr, int *t){  
    return arr[*t];
    }

    void print_stack(int *arr, int t){  
    for(int i = 0; i<=t; i++){
        printf("%d ", arr[i]);
    }  
    }
    void print_array(int *arr, int n) {
    for(int i = 0; i<n ; i++){
        printf("%d ", arr[i]);
    }
    }
    /*Stack implementation*/






    int main(void) {

    //1 = {
    //2 = }
    //3 = (
    //4 = )

    int string[] = { 1,2 };
    int lenString = sizeof(string)/sizeof(string[0]);
    int stack[lenString];
    int t = -1;
    int isValid = 1;
    for(int i = 0; i<lenString; i++){
        if(string[i]==1 || string[i]==3){
            push(stack, &t, string[i]);
        } else if(string[i]==2){
            int popped = pop(stack, &t);
            if(popped!=1){
                isValid = 0;
                break;
            } 
        } else {
            int popped = pop(stack, &t);
            if(popped!=3){
                isValid = 0;
                break;
            }
        }
    }

    printf("%d", isValid);

    return 0;
    }