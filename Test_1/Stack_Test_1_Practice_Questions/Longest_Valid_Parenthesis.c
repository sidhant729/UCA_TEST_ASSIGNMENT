// Problem Link -> https://leetcode.com/problems/longest-valid-parentheses/

// Solution

#define max(a, b) (a > b ? a : b)

typedef struct {
    int* arr;
    int sz;
} Stack;

Stack* createStack(int sz) {
    Stack* st = (Stack*)malloc(sizeof(Stack));
    st->arr = (int*)malloc(sizeof(int) * sz);
    st->sz = 0;
    return st;
}

void push(Stack* st, int val) {
    st->arr[st->sz] = val;
    st->sz++;
}

int pop(Stack* st) {
    if (st->sz == 0) {
        return -1;
    }
    st->sz--;
    return st->arr[st->sz];
}

int isEmpty(Stack* st) {
    return st->sz == 0;
}

int longestValidParentheses(char* s) {
    int* dp = (int*)malloc(sizeof(int) * strlen(s));
    memset(dp, 0, sizeof(int) * strlen(s));
    Stack* stack = createStack(strlen(s));
    int res = 0;

    for (int i = 0; i < strlen(s); i++) {
        char ch = s[i];
        if (ch == ')' && isEmpty(stack)) {
            continue;
        }
        if (ch == '(') {
            push(stack, i);
        } else {
            int lastInd = pop(stack);
            dp[i] = i - lastInd + 1;
            if (lastInd > 0) {
                dp[i] += dp[lastInd - 1];
            }
        }
        res = max(res, dp[i]);
    }
    free(dp);
    free(stack->arr);
    free(stack);

    return res;
}