// Problem Link -> https://leetcode.com/problems/valid-parentheses/description/

// Solution
struct Stack { 
    int top; 
    unsigned capacity; 
    int* array; 
}; 
  
struct Stack* createStack(unsigned capacity) 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 
  

int isFull(struct Stack* stack) 
{ 
    return stack->top == stack->capacity - 1; 
} 

int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1; 
} 
  

void push(struct Stack* stack, int item) 
{ 
    if (isFull(stack)) 
        return; 
    stack->array[++stack->top] = item; 
} 

int pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return -1; 
    return stack->array[stack->top--]; 
} 
  
int peek(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return -1; 
    return stack->array[stack->top]; 
} 
bool isMatching(char a, char b){
    if( (a == '[' && b==']') || (a == '(' && b == ')') || (a == '{' && b == '}')) return true;
    return false;
}
bool isValid(char* s) {
    struct Stack* st = createStack(strlen(s));

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            push(st, s[i]);
        } else {
            if (isEmpty(st) || !isMatching(peek(st), s[i])) {
                free(st->array);
                free(st);
                return false;
            } else {
                pop(st);
            }
        }
    }

    bool result = isEmpty(st);

    free(st->array);
    free(st);

    return result;
}

