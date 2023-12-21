// Problem Link -> https://leetcode.com/problems/implement-queue-using-stacks/

Solution

typedef struct {
    int* arr;
    int sz;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->arr = (int*)malloc(sizeof(int)*10);
    obj->sz = 0;
    return obj;
}
void push(MyQueue* obj, int x) {
    if (obj->sz == 0) {
        obj->arr[obj->sz++] = x;
        return;
    }
    int ele = obj->arr[obj->sz-1];
    obj->sz--;
    push(obj, x);
    obj->arr[obj->sz++] = ele;
}

void myQueuePush(MyQueue* obj, int x) {
    push(obj, x);
}

int myQueuePop(MyQueue* obj) {
    int ele = obj->arr[obj->sz-1];
    obj->sz--;
    return ele;
}

int myQueuePeek(MyQueue* obj) {
    int ele = obj->arr[obj->sz-1];
    return ele;
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->sz == 0;
}

void myQueueFree(MyQueue* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/