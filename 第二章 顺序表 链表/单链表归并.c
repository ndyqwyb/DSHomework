// 任务描述
// 假设两个按元素值非递减有序排列的线性表 A 和 B ，均以单链表作为存储结构，试编写程序，将 A 表和 B 表归并成一个按元素值非递增有序排列的线性表 C ，并要求利用原表（即 A 表和 B 表的）结点空间存放表 C 。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成单链表的归并操作。

// 测试说明
// 输入说明：
// 第一行输入两个正整数m,n (m,n<=100),用空格分开，分别表示线性表 A 和 B 中元素个数，其后两行分别输入单链表 A 和 B 。

// 输出说明：
// 输出单链表 C 。

// 平台会对你编写的代码进行测试：
// 测试输入：
// 5 5
// 1 3 7 12 16
// 2 6 7 13 20
// 预期输出：
// 20 16 13 12 7 7 6 3 2 1

#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int num;
    struct Node* next;
}Node, *PNode, *PLinklist;

void merge() {
    //输入数据
    int sizeA, sizeB;
    scanf("%d %d", &sizeA, &sizeB);
    int sizeC = sizeA + sizeB;
    PLinklist PA = (PLinklist)malloc(sizeof(Node));
    PLinklist PB = (PLinklist)malloc(sizeof(Node));
    PA->next = NULL;
    PB->next = NULL;
    PNode tailA = PA;
    PNode tailB = PB;
    for(int i = 0; i < sizeA; i++) {
        int temp;
        scanf("%d", &temp);
        PNode newnode = (PNode)malloc(sizeof(Node));
        newnode->num = temp;
        newnode->next = NULL;
        tailA->next = newnode;
        tailA = tailA->next;
    }
    for(int i = 0; i < sizeB; i++) {
        int temp;
        scanf("%d", &temp);
        PNode newnode = (PNode)malloc(sizeof(Node));
        newnode->num = temp;
        newnode->next = NULL;
        tailB->next = newnode;
        tailB = tailB->next;
    }
    //测试输出
    // tailA = PA->next;
    // for(int i = 0; i < sizeA; i++) {
    //     int temp = tailA->num;
    //     tailA = tailA->next;
    //     printf("%d ", temp);
    // }
    //创建PC并合并
    PLinklist PC = (PLinklist)malloc(sizeof(Node));
    PC->next = NULL;
    PNode head = PC;
    tailA = PA->next;
    tailB = PB->next;
    while(sizeA > 0 || sizeB > 0) {
        if(sizeB == 0 || (sizeA > 0 && tailA->num <= tailB->num)) {
            PNode temp = tailA;
            tailA = tailA->next;
            temp->next = head->next;
            head->next = temp;
            sizeA--;
        }
        else {
            PNode temp = tailB;
            tailB = tailB->next;
            temp->next = head->next;
            head->next = temp;
            sizeB--;
        }
    }
    //输出
    head = head->next;
    for(int i = 0; i < sizeC - 1; i++) {
        int temp = head->num;
        head = head->next;
        printf("%d ", temp);
    }
    printf("%d", head->num);
}

int main() {
    merge();
}