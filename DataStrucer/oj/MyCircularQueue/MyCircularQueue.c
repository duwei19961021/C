//
// Created by duwei on 2021/1/6.
//

/*
 * 设计循环队列
 * 链接: https://leetcode-cn.com/problems/design-circular-queue/
 * */

typedef struct {
    int *_a;
    int _front; // 头,出方向
    int _rear; // 尾,进方向
    int _size; // size
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* queue = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if(!queue)
    {
        return NULL;
    }
    queue->_a = (int*)malloc(sizeof(int)*(k+1)); // 这里使用数组模拟循环队列，总有一个位置无法使用到(在判断队列满时，rear+1=front)，为了解决这个问题，在创建数组时就额外创建一个位置。
    queue->_size = k+1;
    queue->_front = queue->_rear = 0;
    return queue;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    assert(obj);
    return (obj->_rear+1)%obj->_size == obj->_front; // 创建3长度的队列，但是实际上创建的是4长度，有一个长度不用，所以空的时候front和rear不是重合的，而是相差了一个元素
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    assert(obj);
    return obj->_rear == obj->_front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    assert(obj);
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }
    obj->_rear %= obj->_size; // 取模，当rear的值大于size时，能回到第队头
    obj->_a[obj->_rear] = value;
    obj->_rear++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    assert(obj);
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }
    obj->_front%=obj->_size;
    obj->_front++;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    assert(obj);
    if(myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->_a[obj->_front];// 返回front的指向元素
}

int myCircularQueueRear(MyCircularQueue* obj) {
    assert(obj);
    if(myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->_a[(obj->_rear)-1]; // 每次入队后rear会往后移动一次，所以队尾是rear的前一个位置的元素
}



void myCircularQueueFree(MyCircularQueue* obj) {
    assert(obj);
    free(obj->_a);
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