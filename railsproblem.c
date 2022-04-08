#include <stdio.h>

// Problem 1062 from beecrowd

// Assume that the train arriving from the direction A
// has N <= 1000 railway carriages numbered in increasing order 1,2, …, N.
#define MAX 1000

// The input should have first the integer N as the number of railway carriages
// and then the permutations of 1, 2, ...N that you want to test.

// The output contains Yes if it is possible to organize the carriages
// in the order required on the corresponding line of the input and No if otherwise.

// Let's use stacks to solve the problem.
typedef struct{

    int vec[MAX];
    int top;

}Pilha;

void push(Pilha *p, int id)
{
    p -> vec[++p->top] = id;
}

void pop(Pilha *p)
{
    p -> top--;
}

int main(){

    int fora, N, i, naoentra, entra, zero;
    Pilha p;

    while(scanf("%i", &N) && N){

        while(1){

            p.top = -1;

            for(i = 0, entra = 1, naoentra = 0, zero = 0; i < N && !naoentra; i++){

                scanf("%i", &fora);

                if(!fora){
                    zero = 1;
                    break;
                }

                while(1){

                    if(fora == entra){
                        entra++;
                        break;
                    }else if(fora > entra){
                        push(&p, entra);
                        entra++;
                    }else{
                        if(p.vec[p.top] == fora)
                            pop(&p);
                        else{
                            naoentra = 1;
                            for(;i<N-1;i++)
                                scanf("%i", &fora);
                        }
                        break;
                    }
                }
            }
            if(!zero)
                if(!naoentra)
                    printf("Yes\n");
                else
                    printf("No\n");
            else
                break;
        }
        printf("\n");
    }
    return 0;
}
