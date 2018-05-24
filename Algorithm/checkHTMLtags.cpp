#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct StackNode
{
    char data;
    struct Stacknode *next;
} stackNode;

typedef struct Stack
{
    struct StackNode *top;
} stack;

stack *stackInit()
{
    stack *s = (stack*) malloc(sizeof(stack));
    if(s == NULL)
        return NULL;
    s->top = NULL;
    return s;
}

void stackPush(stack *s, char data)
{
    stackNode *newnode = (stackNode*) malloc(sizeof(stackNode));
    if(newnode == NULL)
        return NULL;
    newnode->data = data;
    newnode->next = s->top;
    s->top = newnode;
}

int stackEmty(stack *s)
{
    return s->top == NULL;
}

char stackPop(stack *s)
{
    if(stackEmty(s))
        return NULL;
    char data = s->top->data;
    stackNode *node = s->top;
    s->top = s->top->next;
    free(node);
    return data;
}

int kiemtra(stack *s, char *a)
{
    int i, k;
    for(i=0;i<strlen(a);i++)
    {
        if(a[i] == '<' && a[i+1] != '/')
            while(a[++i] != '>')
                stackPush(s,a[i]);
        if(a[i] == '<' && a[i+1] == '/')
            if(stackEmty(s))
            {
                printf("Incorrect");
                return 0;
            }
            else
            {
                while(a[++i + 1] != '>')
                    k = i+1; // vd: k la vi tri cua y trong </body>
                while(a[k] != '/')
                    if(a[k--] == stackPop(s))
                        continue;
                    else
                    {
                        printf("Incorrect");
                        return 0;
                    }
            }
    }
    if(stackEmty(s))
        printf("Correct");
    else
        printf("Incorrect");
    return 0;
}

int main()
{
    stack *s = stackInit();
    char a[] = "<html><title>HTML Tutorial</title><body><h1>This is a heading</h1><p>This is a paragraph.</p></body></html>";
    kiemtra(s,a);

    printf("\n-----------------------------\n");
    return 0;
}
