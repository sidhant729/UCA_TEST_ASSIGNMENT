// Problem Link -> https://www.hackerrank.com/contests/17cs1102/challenges/8-c-postfix-expression-evaluation

// Solution
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<stdbool.h>
typedef struct{
    int* arr;
    int sz;
}Stack;
Stack* createStack(int cap){
    Stack* st = (Stack*)malloc(sizeof(Stack));
    st->arr = (int*)malloc(sizeof(int)*cap);
    st->sz = -1;
    return st;
}
void push(Stack* st, int val){
    st->arr[++st->sz] = val;
}
int pop(Stack* st){
    return st->arr[st->sz--];
}
int top(Stack*st){
    return st->arr[st->sz-1];
}
int evalPostfix(char* s){
    Stack* st = createStack(strlen(s));
    int currVal = 0;
    if(s[2] == '?') return s[0]-'0';
    for(int i = 0; i < strlen(s) && s[i] != '?'; i++){
        if(s[i+1] == '?') break;
        char currChar = s[i];
        if(currChar == ' ' && i > 0 && s[i-1] >= '0' && s[i-1] <= '9'){
            push(st, currVal);
            currVal = 0;
        }else if(currChar >= '0' && currChar <= '9'){
            currVal = currVal * 10 + (currChar - '0');
        }else if(currChar ==  '+' || currChar == '*' || currChar == '/' || 
                 currChar == '-'){
            int top1 = pop(st);
            int top2 = pop(st);
            switch(currChar){
                case '+':
                    push(st, top2+top1);
                    break;
                case '-':
                    push(st, top2-top1);
                    break;
                case '*':
                    push(st, top2*top1);
                    break;
                case '/':
                    push(st, top2/top1);
                    break;
            }
        }
    }
    return pop(st);
}
int main() {
    
    int n;
    scanf("%d",&n);
    getchar();
    while(n--){
        char str[100];
        fgets(str, 100,stdin);
        int res = evalPostfix(str);
        printf("%d\n", res);
    }
    return 0;
}
