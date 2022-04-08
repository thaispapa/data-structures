#include <stdio.h>
#include <stdlib.h>

// Problem 1069 from beecrowd

// John is working in a diamond mine, trying to extract the highest number of diamond "<>".
// He must exclude all sand particles found "." in this process and after a diamond can be extracted,
// new diamonds can be formed. If he has as an input
// <... << .. >> ....> .... >>> three diamonds are formed.

// The input contains the number of character strings that are going to be tested followed by
// the strings.

// The output contains the number of diamonds that we can extract from a given string.

// Let's use stacks to solve the problem.
struct elemento{

    char dado;

    struct elemento *proximo;
};

struct pilha{

    struct elemento *topo;

    struct elemento *base;
};

void push(char c, struct pilha *pilha)
{
    struct elemento * novo_topo = (struct elemento *)malloc(sizeof(struct elemento));

    novo_topo -> dado = c;

    novo_topo -> proximo = pilha -> topo;

    pilha -> topo = novo_topo;

    if(pilha -> base == NULL){

        pilha -> base = novo_topo;
    }
}

void pop(struct pilha *pilha)
{
    struct elemento *removido = pilha -> topo;

    pilha -> topo = pilha -> topo -> proximo;

    free(removido);

    if(pilha -> topo == NULL) {

        pilha -> base = NULL;
    }
}

// Function to count the number of diamonds in a given string.
int diamantes(char cadeia[])
{
    int i = 0, qtd = 0;

    struct pilha *pilha = (struct pilha*)malloc(sizeof(struct pilha));

    pilha -> topo = NULL;
    pilha -> base = NULL;

    // Here we are just going to push '<' to a stack and when we
    // find '>' to complete the diamond, we pop from the stack and add 1
    // to the quantity of diamonds qtd.
    while(cadeia[i] != '\0')
    {
        if(cadeia[i] == '<') {

            push('<', pilha);

        } else if(cadeia[i] == '>') {

            if(pilha -> topo != NULL) {
                pop(pilha);
                qtd++;
            }
        }

        i++;
    }

    return qtd;
}

int main()
{
    int N;
    char cadeia[1001];

    printf("How many cases are going to be tested?\n");
    scanf("%i", &N);

    while(N--)
    {
        setbuf(stdin, NULL);
        scanf("%s", cadeia);
        printf("You've found %i diamonds\n", diamantes(cadeia));
    }

    return 0;
}

