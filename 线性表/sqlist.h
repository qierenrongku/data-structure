#ifndef _SQLIST_H_
#define _SQLIST_H_

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 2   //线性表存储空间的初始分配量
#define LISTINCREMENT 10   // 空间分配增量
#define OVERFLOW -1
#define NOTEXIT 0  
typedef int Status;
typedef int ElemType;

typedef struct 
{
    ElemType *elem;
    int length;
    int listsize;
}SqList;
// 构造一个空的线性表
Status InitList_Sq(SqList &L);
// 销毁线性表
void DestoryList_Sq(SqList &L);
// 置空线性表
void ClearList_Sq(SqList &L);
// 判断是否为空
Status ListEmpty_Sq(SqList L);
// 获取线性表的长度
int ListLength_Sq(SqList L);
// 用e返回L中的第i个值
void GetElem_Sq(SqList L, int i, ElemType &e);
// 返回第一个与e满足关系compare()的数据元素的位序
int LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType, ElemType));
// pre_e 返回cur_e的前驱
Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType &pre_e);
// next_e 返回cur_e的后继
Status NextElem_Sq(SqList L, ElemType cur_e, ElemType &next_e);
// 第i个位置插入元素e
void ListInsert(SqList &L, int i, ElemType e);
// 山粗第i个位置 并用e返回他的值
void ListDelete_Sq(SqList &L, int i, ElemType &e);
// 依次对各个元素调用visit()函数
Status ListTraverse_Sq(SqList L, Status (*visit)(ElemType));
Status compare_equal_Sq(ElemType e1, ElemType e2);
Status visit_display_Sq(ElemType e);

//算法2.1
void unionList_Sq(SqList &La, SqList Lb);
//算法2.2
void MergeList_Sq(SqList La, SqList Lb, SqList &Lc);

#endif