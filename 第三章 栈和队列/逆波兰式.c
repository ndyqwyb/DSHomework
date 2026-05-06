// 任务描述
// 假设表达式由单字母变量和双目四则运算算符构成。试编写程序，将一个通常书写形式且书写正确的表达式转换为逆波兰式。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成输出逆波兰式。

// 测试说明
// 输入说明：输入由单字母变量和双目四则运算算符构成的表达式。

// 输出说明：输出其逆波兰式。

// 平台会对你编写的代码进行测试：

// 测试输入：(a+b)*c
// 预期输出：ab+c*

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack {
    char s[100];
    int tail;
}Stack, *PStack;

char top(PStack stk) {
    return stk->s[stk->tail];
}

void push(PStack stk, char c) {
    stk->tail = stk->tail + 1;
    stk->s[stk->tail] = c;
}

void pop(PStack stk) {
    stk->tail = stk->tail - 1;
}

int empty(PStack stk) {
    return (stk->tail == -1);
}

int pri(char c) {
    switch(c) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default: return 0;
    }
}

int isSymbol(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')');
}

int main() {
    //创建符号栈
    PStack stk = (PStack)malloc(sizeof(Stack));
    stk->tail = -1;

    //加一个保护位'#'方便后续
    push(stk, '#');
    
    //while循环读数
    int ch;
    while(( ch = getchar() ) != '\n' && ch != EOF) {
        char c = (char)ch;

        //遇到变量直接输出
        if(!isSymbol(c)) {
            printf("%c", c);
        }
        //遇到左括号直接入栈
        else if(c == '(') {
            push(stk, c);
        }
        //遇到右括号一直读到左括号
        else if(c == ')') {
            //一直弹出并输出栈顶
            while(top(stk) != '(') {
                printf("%c", top(stk));
                pop(stk);
            }
            //遇到左括号直接弹出
            pop(stk);
        }
        //遇到常规符号比较优先级
        else {
            //若栈顶算符优先级大于等于读取算符 则循环出栈输出
            while(pri(top(stk)) >= pri(c)) {
                printf("%c", top(stk));
                pop(stk);
            }
            //直到小于 使读取算符入栈
            push(stk, c);
        }
    }
    //处理剩下的算符
    while(top(stk) != '#') {
        printf("%c", top(stk));
        pop(stk);
    }
}