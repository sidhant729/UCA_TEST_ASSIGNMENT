// Problem Link - > https://leetcode.com/problems/design-circular-queue/

typedef struct {
    int* arr;
    int front;
    int len;
    int totalSz;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->arr = (int*)malloc(sizeof(int)*k);
    obj->front = 0;
    obj->len = 0;
    obj->totalSz = k;
    return obj;
}
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->len == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->len == obj->totalSz;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj)) return false;
    obj->arr[(obj->front + obj->len++)%obj->totalSz] = value;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)) return false;
    obj->front = (obj->front + 1)%obj->totalSz;
    --obj->len;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)) return -1;
    return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)) return -1;
    return obj->arr[(obj->front + obj->len - 1)%obj->totalSz];
}


void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/