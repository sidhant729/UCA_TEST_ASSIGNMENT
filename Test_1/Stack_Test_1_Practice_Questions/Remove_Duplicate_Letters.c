// Problem Link -> https://leetcode.com/problems/remove-duplicate-letters/

// Solution

typedef struct{
    int* arr;
    int sz;
}Stack;

Stack* createStack(){
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->arr = (int*)malloc(sizeof(int)*27);
    s->sz = 0;
    return s;
}
void push(Stack* s, int val){
    s->sz++;
    s->arr[s->sz] = val;
}
int top(Stack* s){
    int ele = s->arr[s->sz];
    return ele;
}
int pop(Stack* s){
    int ele = s->arr[s->sz];
    s->sz--;
    return ele;
}
bool isEmpty(Stack* s){
    return s->sz == 0;
}
char* removeDuplicateLetters(char* s) {
    Stack* st = createStack();
    int* arr = (int*)malloc(sizeof(int)*26);
    int* map = (int*)malloc(sizeof(int)*26);
    memset(arr, -1, sizeof(int)*26);
    memset(map, 0, sizeof(int)*26);
    for(int i = 0; i < strlen(s); i++){
        arr[s[i]-'a'] = i;
    }
    for(int i = 0; i < strlen(s); i++){
        if(map[s[i]-'a'] == 1) continue;

        while(!isEmpty(st) && top(st) > (s[i]-'a') && i <  arr[top(st)]){
            int ele = pop(st);
            map[ele] = 0;
        }
        push(st, s[i]-'a');
        map[s[i]-'a'] = 1;
    }
    char* str = (char*)malloc(sizeof(char)*27);
    int index = 0;
    while(!isEmpty(st)){
        str[index++] = top(st) + 'a';
        pop(st);
    }
    str[index] = '\0';
    index = 0;
    char* res = (char*)malloc(sizeof(char)*(strlen(str) + 1));
    for(int i = strlen(str)-1; i >= 0; i--){
        res[index++] = str[i];
    }
    res[index] = '\0';
    return res;
}