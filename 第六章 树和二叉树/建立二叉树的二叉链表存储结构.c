// 任务描述
// 如果用大写字母标识二叉树结点，则一颗二叉树可以用符合下面语法图的字符序列表示。试编写递归程序，由这种形式的字符序列，建立相应的二叉树的二叉链表存储结构(附图见《严蔚敏：数据结构题集（C语言版）》第45页6.70)。


// 编程要求
// 根据提示，在右侧编辑器补充代码，完成建立二叉树的二叉链表存储结构。

// 测试说明
// 输入说明：
// 输入如图所示的字符序列。
// 输出说明：
// 建立相应二叉树的二成叉链表存储结构，并先序遍历输出。

// 平台会对你编写的代码进行测试：

// 测试输入：A(B(#,D),C(E(#,F),#))
// 预期输出：AB#DCE#F#

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    char c;
    struct Node *l, *r;
}Node;

Node* BuildTree(char** str) {
    //判是否为空树NULL节点
    if(**str == '#') {
        (*str)++;
        return NULL;
    }
    //建立当前节点
    Node* cur = (Node*)malloc(sizeof(Node));
    cur->c = **str;
    (*str)++;
    //查看是否有左右子树
    if(**str == '(') {
        (*str)++;
        cur->l = BuildTree(str);

        (*str)++;
        cur->r = BuildTree(str);

        (*str)++;
    }
    else {
        cur->l = NULL;
        cur->r = NULL;
    }
    return cur;
}

void output(Node* root) {
    if(root != NULL) {
        printf("%c", root->c);
        if(root->l != NULL || root->r != NULL) {
        output(root->l);
        output(root->r);
    }
    }
    else {
        printf("#");
    }   
}

int main() {
    //接收字符串
    char str[100];
    scanf("%s", str);
    char *p = str;

    //建立树
    Node* root = BuildTree(&p);

    //输出
    output(root);
}