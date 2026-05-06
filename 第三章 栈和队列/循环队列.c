// 任务描述
// 假设将循环队列定义为：以域变量 rear 和 length 分别指示循环队列中队尾元素的位置和内含元素的个数。编写相应的入队列和出队列的程序。入队列时判断循环队列是否队满（在出队列的算法中要返回队头元素）。队满时，停止入队，队满时输出 yes ，否则输出 no 。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成循环队列的操作。

// 测试说明
// 输入说明：第一行输入队列大小 N ，第二行开始输入若干入队元素，第三行输入出队元素。

// 输出说明：第一行输出入队后队列情况，队满时输出 yes，否则输出 no。第二行输出出队操作后的循环队列。第三行输出出队后的队头元素。

// 平台会对你编写的代码进行测试：

// 测试输入：
// 5
// 3 4 6 2 7
// 4
// 预期输出：
// yes
// 6 2 7
// 6

#include<stdio.h>
#include<stdlib.h>

typedef struct queue {
    int len;
    int rear;
    int maxlen;
    int q[];
}queue, *Pqueue;

Pqueue initq(int maxlen) {
    Pqueue q = (Pqueue)malloc(sizeof(queue) + maxlen * sizeof(int));
    q -> len = 0;
    q -> rear = -1;
    q -> maxlen = maxlen;
    return q;
}

void push(Pqueue q, int data) {
    if(q -> len == q -> maxlen) return;
    else {
        q -> rear = (q -> rear + 1) % q -> maxlen;
        q -> len++;
        q -> q[q -> rear] = data;
    }
}

int pop(Pqueue q) {
    int front = (q -> rear + 1 - q -> len + q -> maxlen) % q -> maxlen;
    q -> len--;
    return q -> q[front];
}

int top(Pqueue q) {
    int front = (q -> rear + 1 - q -> len + q -> maxlen) % q -> maxlen;
    return q -> q[front];
}

int isempty(Pqueue q) {
    return (q -> len == 0);
}

int isfull(Pqueue q) {
    return (q -> len == q -> maxlen);
}

int main() {
    //初始化
    int max, flag;
    scanf("%d", &max);
    Pqueue q = initq(max);
    //读数
    while(1) {
        int temp;
        scanf("%d", &temp);
        if(!isfull(q)) {
            push(q, temp);
        }
        int ch = getchar();
        if(ch == '\n') break;
    }
    scanf("%d", &flag);
    //判断是否满
    if(isfull(q)) printf("yes\n");
    else printf("no\n");
    //开始pop
    int last;
    do {
        last = pop(q);
    }
    while(last != flag);
    //记录队头和len
    int topele = top(q);
    int curlen = q -> len;
    for(int i = 0; i < curlen - 1; i++) {
        printf("%d ", pop(q));
    }
    printf("%d\n%d", pop(q), topele);
}