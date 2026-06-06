// 任务描述
// 一个四则运算算术表达式以有向无环图的邻接表方式存储，每个操作数原子都由单个字母表示。编写程序输出其逆波兰表达式。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成输出逆波兰表达式。

// 测试说明
// 输入说明: 输入四则运算算术表达式。
// 输出说明: 输出其逆波兰表达式。

// 平台会对你编写的代码进行测试：

// 测试输入：(a+b)*c
// 预期输出：ab+c*

//由于用图做实在复杂而且没有意义 故再写一遍用栈做法

#include<stdio.h>
#include<stdlib.h>

typedef struct stack {
    char s[100];
    int tail;
}stack;

void push(stack* stk, char ch) {
    stk->s[stk->tail] = ch;
    stk->tail++;
}

char pop(stack* stk) {
    stk->tail--;
    return stk->s[stk->tail];
}

int empty(stack* stk) {
    return stk->tail == 0;
}

char top(stack* stk) {
    return stk->s[stk->tail - 1];
}

int priority(char op) {
    switch(op){
        case '+':
        case '-':
            return 0;

        case '*':
        case '/':
            return 1;

        case '(':
            return -1;

        default:
            return -2;
    }
}

char* ToReversePoland(const char* s1) {
    char* s2 = (char*)malloc(100 * sizeof(char));
    char* p2 = s2;
    char* p1 = s1;

    stack sign;
    sign.tail = 0;

    while(*p1 != '\0') {
        //遇到加减乘除左括号
        if(*p1 == '+' || *p1 == '-' || *p1 == '*' || *p1 == '/') {
            //如果栈顶优先级高则出栈入结果数组
            while(!empty(&sign) && priority(top(&sign)) >= priority(*p1)) {
                *p2 = pop(&sign);
                p2++;
            }
            //把读到的符号入栈
            push(&sign, *p1);
        }
        //读到左括号直接入栈
        else if(*p1 == '(') {
            push(&sign, *p1);
        }
        //读到右括号 一直出栈直到把左括号弹出
        else if(*p1 == ')') {
            while(!empty(&sign) && top(&sign) != '(') {
                *p2 = pop(&sign);
                p2++;
            }
            //把左括号出栈
            pop(&sign);
        }
        //读到字符 直接入字符串
        else {
            *p2 = *p1;
            p2++;
        }

        p1++;
    }

    //把剩下的栈内符号一个个弹出
    while(!empty(&sign)) {
        *p2 = pop(&sign);
        p2++;
    }

    *p2 = '\0';
    return s2;
}

int main() {
    char s1[100];
    scanf("%99s", s1);

    char* s2 = ToReversePoland(s1);

    printf("%s", s2);
}