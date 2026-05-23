// 任务描述
// 编写程序，输出以二叉树表示的算术表达式，若该表达式中含有括号，则在输出时应添上。

// 编程要求
// 根据提示，在右侧编辑器补充代码，输出以二叉树表示的算术表达式。

// 测试说明
// 输入说明：
// 按先序输入一行字符，其中#表示取消建立子树结点，即所有叶子节点均为#。
// 输出说明：
// 输出该二叉树所表示的算术表达式（若表达式中含有括号，则在输出时应添上）。

// 平台会对你编写的代码进行测试：

// 测试输入：*+a(###b#)##c##
// 预期输出：(a+b)*c

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    char c;
    struct Node *l, *r;
}Node;

Node* BuildTree(char** str) {
    if(**str == '#') {
        (*str)++;
        return NULL;
    }

    Node* cur = (Node*)malloc(sizeof(Node));
    cur->c = (**str);
    (*str)++;

    cur->l = BuildTree(str);
    cur->r = BuildTree(str);

    return cur;
}

void output(Node* root) {
    if(root != NULL) {
        output(root->l);
        printf("%c", root->c);
        output(root->r);
    }
}

int main() {
    //接收输入
    char str[100];
    scanf("%s", str);
    char* p = str;
    //建立树并输出
    Node* root = BuildTree(&p);
    output(root);
}