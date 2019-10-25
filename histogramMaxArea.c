    #include <stdio.h>

    /*Stack implementation*/
    long long int size(long long int  *arr, long long int t){    
        return t+1;
    }
    void push(long long int  *arr, long long int *t, long long int number){
    if(size(arr,*t)>1000){    
    } else {
        *t+=1;
        arr[*t] = number;    
    }
    }

    long long int pop(long long int  *arr, long long int *t){
    long long int toReturn  = arr[*t];
    *t-=1;  
    return toReturn;
    }

    long long int top(long long int  *arr, long long int *t){  
    return arr[*t];
    }

    void print_stack(long long int  *arr, long long int t){  
    for(long long int  i = 0; i<=t; i++){
        printf("%d ", arr[i]);
    }  
    }
    void print_array(long long int  *arr, long long int n) {
    for(long long int  i = 0; i<n ; i++){
        printf("%d ", arr[i]);
    }
    }
    /*Stack implementation*/

    int main(void) {
        long long int N;
        scanf("%lld", &N);
        long long int houses[N];
        long long int houses_reverse[N];
        long long int span[N];
        long long int span_reverse[N];
        long long int hi_stack[N];
        long long int hi_stack_reverse[N];
        long long int ans = -1;
        long long int number;
        for(long long int  i = 0; i<N; i++){            
            scanf("%lld", &number);
            houses[i] = number;
            houses_reverse[N-i-1] = number;
        }


        //Front Span        
        span[0] = 1;
        long long int t;
        hi_stack[0] = 0;
        t = 0; //Already size of stack is 1
        for(long long int  i = 1; i<N; i++){    
            while(size(hi_stack,t)>0 && houses[i]<=houses[top(hi_stack, &t)]){  
                pop(hi_stack, &t);
            }    
            if(size(hi_stack,t)==0){
            span[i] = i+1;
            } else {
            span[i] = i-top(hi_stack, &t);      
            }    
            push(hi_stack, &t, i);
        }




        //Back Span        
        span_reverse[0] = 1;        
        hi_stack_reverse[0] = 0;
        t = 0; //Already size of stack is 1
        for(long long int  i = 1; i<N; i++){    
            while(size(hi_stack_reverse,t)>0 && houses_reverse[i]<=houses_reverse[top(hi_stack_reverse, &t)]){  
                pop(hi_stack_reverse, &t);
            }    
            if(size(hi_stack_reverse,t)==0){
            span_reverse[i] = i+1;
            } else {
            span_reverse[i] = i-top(hi_stack_reverse, &t);      
            }    
            push(hi_stack_reverse, &t, i);
        }


        //Reversing the Back Span
        long long int tempStack[N];
        long long int tt = -1;
        for(long long int  i = 0; i<N; i++){
            push(tempStack, &tt, span_reverse[i]);
        }
        for(long long int  i = 0; i<N; i++){        
            span_reverse[i] = pop(tempStack, &tt);
        }

        
        long long int value_now;
        for(long long int  i = 0; i<N; i++){            
            value_now = (span[i]+span_reverse[i]-1)*houses[i];            
            if(value_now>ans){
                ans = value_now;
            }
        }

        printf("%lld\n", ans);

        return 0;
    }
