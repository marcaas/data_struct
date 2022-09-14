#include <iostream>
using namespace std;

// 顺序表结构体 
struct SqList;

// 插入元素
bool SqList_Insert(SqList &S, int i, int e);

// 删除元素
bool SqList_Delete(SqList &S, int i, int &e);

// 按值查找
int SqList_Search_Location(SqList S, int i);