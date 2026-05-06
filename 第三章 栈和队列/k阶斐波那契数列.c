// 任务描述
// 试利用循环队列编写 k 阶斐波那契数列中前 n+1 项 （f(0),f(1),…,f(n)）的程序，要求满足： f(n)<=max 而 f(n+1)>max，其中 max 为某个约定的常数。（注意：本题所用循环队列的容量仅为 k ，则在程序执行结束时，留在循环队列中的元素应是所求 k 阶斐波那契序列中的最后 k 项 f(n−k+1),…,f(n))。 
// k阶斐波那契数列

// 编程要求
// 根据提示，在右侧编辑器补充代码，实现 k 阶斐波那契数列。

// 测试说明
// 输入说明：输入常数max（0），阶数k（1），用空格隔开。

// 输出说明：输出 k 阶斐波那契数列中的最后 k 项 f(n-k+1),…,f(n)。

// 平台会对你编写的代码进行测试：

// 测试输入：14 2
// 预期输出：8 13

#include<stdio.h>
#include<stdlib.h>

typedef struct queue {
    int maxlen;
    int rear;
    int q[];
}queue, *Pqueue;

int sum(Pqueue q) {
    int s = 0;
    for(int i = 0; i < q -> maxlen; i++) {
        s += q -> q[i];
    }
    return s;
}

void push(Pqueue q, int data) {
    int site = (q -> rear + 1) % q -> maxlen;
    q -> q[site] = data;
    q -> rear = site;
}

Pqueue initq(int max) {
    Pqueue q = (Pqueue)malloc(sizeof(queue) + max * sizeof(int));
    q -> maxlen = max;
    q -> rear = -1;
    return q;
}

Pqueue initfib(Pqueue q) {
    for(int i = 0; i < q -> maxlen - 1; i++) {
        q -> q[i] = 0;
    }
    q -> q[q -> maxlen - 1] = 1;
    q -> rear = q -> maxlen - 1;
    return q;
}

void output(Pqueue q) {
    for(int i = 1; i <= q -> maxlen; i++) {
        int site = (q -> rear + i) % q -> maxlen;
        printf("%d", q -> q[site]);
        if(i != q -> maxlen) printf(" ");
    }
}

int main() {
    //初始化k阶斐波那契队列
    int max, k;
    scanf("%d %d", &max, &k);
    Pqueue q = initq(k);
    q = initfib(q);
    //迭代
    while(1) {
        int next = sum(q);
        if(next > max) break;
        push(q, next);
    }
    //输出
    output(q);
}