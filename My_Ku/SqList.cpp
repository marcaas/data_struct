#include <iostream>
using namespace std;

// 线性表顺序存储静态分配
#define MAXSIZE 50 // 数组最大容量
struct SqList
{
    int data[MAXSIZE]; // 顺序表的元素
    int length;        // 顺序表长度
} sqls;

// 线性表顺序存储动态分配
#define INITSIZE 100 // 数组初始容量
struct SeqList
{
    int *data;           // 指示动态分配数组的指针
    int MaxSize, length; // 数组最大容量和当前个数
} seqls;
// C的初始动态分配语句为:L.data = (ElemType*)malloc(sizeof(ElemType)*InitSize);
// C++的初始动态分配语句为:L.data = new ElemType[InitSize];

// 顺序表插入操作(在第i个位置插入元素e,其他元素依次后移)
bool SqList_Insert(SqList &S, int i, int e)
{
    // 判断i是否为有效值
    if (i < 1 || i > S.length + 1)
    {
        return false;
    }
    // 判断数组是否已满
    if (S.length >= MAXSIZE)
    {
        return false;
    }
    for (int j = S.length; j >= i; j--)
    {
        S.data[j] = S.data[j - 1];
    }
    S.data[i - 1] = e;
    S.length++;
    return true;
}

// 顺序表删除操作(删除第i个位置的元素并用引用变量e返回该值,其他元素依次前移)
bool SqList_Delete(SqList &S, int i, int &e)
{
    // 判断i是否为有效值
    if (i < 1 || i > S.length)
    {
        return false;
    }
    // 将值传给e
    e = S.data[i - 1];
    for (int j = i - 1; j < S.length - 1; j++)
    {
        S.data[j] = S.data[j + 1];
    }
    S.length--;
    return true;
}

// 在顺序表L中查找第一个元素值等于e的元素,并返回其位序
int SqList_Search_Location(SqList L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i++;
        }
    }
    return 0; // 返回0表示查找失败
}
// 打印数组的所有元素
bool SqList_Prt(SqList L)
{
    if (L.length == 0)
    {
        printf("数组为空.");
        return false;
    }
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    }
    printf("\n");
    return true;
}

// 第二章 习题

// 1.从顺序表中删除具有最小值的元素 ( 假设唯一 ) 并由函数返回被删除元素的值. 空出的位置由最后一个元素填补, 若顺序表为空, 则显示出错误信息并退出运行.
// 删除顺序表L中最小的元素, 并将其值赋给e
bool SqList_T1(SqList &L, int &e)
{
    if (L.length == 0)
    {
        printf("数组为空");
        return false;
    }
    e = L.data[0];
    int loc = 0;
    for (int i = 1; i < L.length; i++)
    {
        if (e > L.data[i])
        {
            loc = i;
        }
    }
    SqList_Delete(L, loc + 1, e);
    printf("删除的元素是 %d", e);
    return true;
}

// 2.设计一个高效算法, 将顺序表L的所有元素逆置, 要求算法的空间复杂度为 O(1).
// 顺序表元素逆置
bool SqList_T2(SqList &L)
{
    int ts;
    for (int i = 0; i < L.length / 2; i++)
    {
        ts = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = ts;
    }
    return true;
}

// 3.对长度为n的顺序表L,编写一个时间复杂度为O(n),空间复杂度为O(1)的算法,该算法删除线性表中所有值为x的数据元素.
// 用k遍历依次数组,在遍历过程中把不等于x的元素个数赋给k,边扫描边统计k,并将不等于x的元素向前移动到第k个位置
bool SqList_T3(SqList &L, int x)
{
    int k = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] != x)
        {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
    return true;
}

// 4.从有序顺序表中删除其值在给定值s与t之间(要求s < t)的所有元素,若s或t不合理或顺序表为空,则显示出错信息并推出运行
bool SqList_T4(SqList &L, int s, int t)
{
    if (s > t)
    {
        printf("出错!!! 区间范围存在错误");
        return false;
    }
    if (L.length == 0)
    {
        printf("出错!!! 数组为空");
        return false;
    }
    int k = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] <= s || L.data[i] >= t)
        {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
    return true;
}

// 5.从顺序表中删除其值在给定值s与t之间(包括s和t,要求s < t)的所有元素,若s或t不合理或顺序表为空,则显示出错信息并推出运行
bool SqList_T5(SqList &L, int s, int t)
{
    if (s > t)
    {
        printf("出错!!! 边界值可能存在错误");
        return false;
    }
    if (L.length == 0)
    {
        printf("出错!!! 数组为空");
        return false;
    }
    int k = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] < s || L.data[i] > t)
        {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
    return true;
}

// 6.从有序顺序表中删除所有其值重复的元素,使表中所有元素的值均不同
bool SqList_T6(SqList &L)
{
    if (L.length == 0)
    {
        printf("表为空");
        return false;
    }

    for (int i = 0; i < L.length; i++)
    {
        for (int j = i + 1; j < L.length; j++)
        {
            if (L.data[j] == L.data[i])
            {
                for (int k = j; k < L.length - 1; k++)
                {
                    L.data[k] = L.data[k + 1];
                }
                L.length--;
            }
        }
    }
    return true;
}

// 7.将两个有序顺序表合并为一个新的有序顺序表,并由函数返回结果顺序表
bool SqList_T7(SqList A, SqList B, SqList &C)
{
    int i = 0;      // 数组A的游标
    int j = 0;      // 数组B的游标
    C.length = 0;   // 清空数组C
    // 用k作为数组C的游标向C中放入元素
    for(int k = 0; k < A.length + B.length; k++)
    {
        // 比较数组A与数组B的第一个元素，把更小的那个放入C的末尾
        if (A.data[i] < B.data[j])
        {
            C.data[k] = A.data[i];
            i++;
        }
        else
        {
            C.data[k] = B.data[j];
            j++;
        }
        C.length++;
    }
    return true;
}

// 8.已知在一维数组A[m + n]中依次存放两个线性表(a1, a2, a3, ... , am)和(b1, b2, b3, ... , bn).试编写一个函数,将数组中两个顺序表的位置互换.
bool SqList_T8(SqList &L, int m, int n)
{
    if (L.length != m + n)
    {
        return false;
    }
    SqList S;
    S.length = 0;
    for (int i = 0; i < n; i++)
    {
        SqList_Insert(S, i + 1, L.data[m + i]);
    }
    for (int i = 0; i < m; i++)
    {
        SqList_Insert(S, n + i + 1, L.data[i]);
    }
    L = S;
    return true;
}

// 9.线性表(a1, a2, a3, ... , an)中元素递增有序且按照顺序存储于计算机内.设计一个算法,完成最少时间在表中查找数值为x的元素,若找到,则将其与后继元素位置相交换,若找不到,则将其插入表中,并使表中元素仍递增有序.
bool SqList_T9(SqList &L, int x)
{
    
}

// 测试
int main()
{
    int del;
    SqList L, LL, L0;
    L.length = 0;
    LL.length = 0;
    for (int i = 1; i <= 10; i++)
    {
        SqList_Insert(L, i, i);
        SqList_Insert(LL, i, 2*i);
    }
    SqList_Merge(L, LL, L0);
    printf("初始数组:\n");
    SqList_Prt(L0);
    // 操作函数
    SqList_T8(L0, 10, 10);
    printf("操作后的数组:\n");
    SqList_Prt(L0);
    return 0;
}
