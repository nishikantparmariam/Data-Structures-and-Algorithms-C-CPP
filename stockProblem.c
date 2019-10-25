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
    int price[] = { 70, 40, 50, 60, 30, 80, 50, 60, 20, 10, 40 };   
    int lenStocks = sizeof(price)/sizeof(price[0]);
    int hi_stack[lenStocks];
    int span[lenStocks];
    span[0] = 1;
    hi_stack[0] = 0;
    int t = 0; //Already size of stack is 1
    for(int i = 1; i<lenStocks; i++){    
        while(size(hi_stack,t)>0 && price[i]>price[top(hi_stack, &t)]){        
            pop(hi_stack, &t);
        }    
        if(size(hi_stack,t)==0){
        span[i] = i+1;
        } else {
        span[i] = i-top(hi_stack, &t);      
        }    
        push(hi_stack, &t, i);
    }
    print_array(span, lenStocks);
    return 0;
    }