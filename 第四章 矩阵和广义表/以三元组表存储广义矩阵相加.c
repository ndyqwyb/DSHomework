// 任务描述
// 假设稀疏矩阵 A 和 B 均以三元组表作为存储结构。试编写矩阵相加的程序，另设三元组表 C 存放结果矩阵。矩阵大小为 m 行 n 列 (0)。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成以三元组表为存储结构实现矩阵相加。

// 测试说明
// 输入说明：
// 第一行输入t1，t2 (0) ,t1 和 t2 分别是矩阵A和B中非零元素的个数；
// 后面 t1+t2 行分别输入 A 和 B 中的元素，用三元组表示。

// 输出说明：
// 输出三元组表 C。

// 平台会对你编写的代码进行测试：

// 测试输入：

// 3 3
// 1 2 3
// 3 2 1
// 3 4 2
// 1 1 4
// 3 2 5
// 3 4 1
// 预期输出：

// 1 1 4
// 1 2 3
// 3 2 6
// 3 4 3

#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int row, col, data;
}elem;

typedef struct {
    int sum;
    elem arr[50];
}matrix;

matrix initmatrix(int s) {
    matrix m;
    m.sum = s;
    for(int i = 0; i < s; i++) {
        elem temp;
        scanf("%d %d %d", &temp.row, &temp.col, &temp.data);
        m.arr[i] = temp;
    }
    return m;
}

matrix add(matrix m1, matrix m2) {
    matrix m3;
    //创建m1m2m3矩阵的迭代下标
    int i = 0, j = 0, k = 0;
    //开始遍历
    while(i < m1.sum && j < m2.sum) {
        if(m1.arr[i].row < m2.arr[j].row) {
            m3.arr[k] = m1.arr[i];
            i++, k++;
        }
        else if(m1.arr[i].row > m2.arr[j].row) {
            m3.arr[k] = m2.arr[j];
            j++, k++;
        }
        else {
            if(m1.arr[i].col < m2.arr[j].col) {
                m3.arr[k] = m1.arr[i];
                i++, k++;
            }
            else if(m1.arr[i].col > m2.arr[j].col) {
                m3.arr[k] = m2.arr[j];
                j++, k++;
            }
            else {
                int s = m1.arr[i].data + m2.arr[j].data;
                if (s) {
                    m3.arr[k] = m1.arr[i];
                    m3.arr[k].data = s;
                    k++;
                }
                i++, j++;
            }
        }
    }
    //如果有剩余 按顺序加在后面
    while(i < m1.sum) {
        m3.arr[k] = m1.arr[i];
        i++, k++;
    }
    while(j < m2.sum) {
        m3.arr[k] = m2.arr[j];
        j++, k++;
    }
    m3.sum = k;
    return m3;
}

void output(matrix m) {
    for(int i = 0; i < m.sum; i++) {
        printf("%d %d %d\n", m.arr[i].row, m.arr[i].col, m.arr[i].data);
    }
}

int main() {
    int s1, s2;
    scanf("%d %d", &s1, &s2);
    matrix m1 = initmatrix(s1);
    matrix m2 = initmatrix(s2);
    matrix m3 = add(m1, m2);
    output(m3);
}