#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"

// 函数实现

Status InitList_Sq(SqList &L){
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(SqList));
    if(!L.elem){
        return OVERFLOW;
    }
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

void DestoryList_Sq(SqList &L){
    free(L.elem);
    L.elem = NULL;
    return;
}

void ClearList_Sq(SqList &L){
    L.length = 0;
}

int ListLength_Sq(SqList L){
    return L.length;
}

void GetElem_Sq(SqList L, int i, ElemType &e){
    e = *(L.elem + i - 1);
}

Status compare_equal_Sq(ElemType e1, ElemType e2){
    return e1 == e2 ? TRUE : FALSE;
}

int LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType, ElemType)){
    ElemType *p = L.elem;
    for(int i = 1; i<=L.length; i++){
        if(compare(e,*(p+i-1))){
            return i;
        }
    }
    return 0;
}

Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType &pre_e){
    int pos = LocateElem_Sq(L, cur_e, compare_equal_Sq);
    if(!pos || pos == 1){
        return NOTEXIT;
    }else{
        pre_e = *(L.elem+pos-2);
        return OK;
    }
}

Status NextrElem_Sq(SqList L, ElemType cur_e, ElemType &next_e){
    int pos = LocateElem_Sq(L, cur_e, compare_equal_Sq);
    if (!pos || pos == L.length){
        return NOTEXIT;
    }else{
        next_e = *(L.elem+pos);
        return OK;
    }
}

void ListInsert(SqList &L, int i, ElemType e){
    ElemType *p=NULL;
    if(L.length+1 > L.listsize){
        p = (ElemType*)realloc(L.elem, (L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!p){
            exit(OVERFLOW);
        }
        L.elem = p;
        L.listsize += LISTINCREMENT;
    }
    for(int j = L.length;j>=i;j--){
        *(L.elem+j) = *(L.elem+j-1);
    }
    *(L.elem+i-1) = e;
    L.length++;

}


void ListDelete_Sq(SqList &L, int i, ElemType &e){
    e = *(L.elem+i-1);
    for(int j = i;j<L.length;j++){
        *(L.elem+j-1) = *(L.elem+j);
    }
    L.length--;  
}

Status ListTraverse_Sq(SqList L, Status (*visit)(ElemType)){
    for (int i = 0; i < L.length; i++)
    {
        if(!visit(*(L.elem+i))){
            return FALSE;
        }
    }
    return TRUE;
    
}

Status visit_display_Sq(ElemType e){
    printf("%d",e);
    return TRUE;
}

void unionList_Sq(SqList &La, SqList &Lb){
    int la_length = ListLength_Sq(La);
    int lb_length = ListLength_Sq(Lb);
    ElemType e;
    
    for(int i = 0;i<=lb_length;i++){
        GetElem_Sq(Lb,i,e);
        if(!LocateElem_Sq(La,e,compare_equal_Sq)){
            ElemType *p=NULL;
            if(La.length+1 > La.listsize){
                p = (ElemType*)realloc(La.elem, (La.listsize+LISTINCREMENT)*sizeof(ElemType));
                if(!p){
                    exit(OVERFLOW);
                }
                La.elem = p;
                La.listsize += LISTINCREMENT;
            }
            ListInsert(La,++la_length,e);
        }
    }
}

void MergeList_Sq(SqList &La, SqList &Lb, SqList &Lc){
    InitList_Sq(Lc);
    int la_length = ListLength_Sq(La);
    int lb_length = ListLength_Sq(Lb);
    int lc_length = ListLength_Sq(Lc);
    int i =1, j = 1,k = 0; 
    ElemType ai,bj;
    while(i<la_length and j < lb_length){
        GetElem_Sq(La,i,ai);
        GetElem_Sq(Lb,j,bj);
        ElemType *p=NULL;
        if(Lc.length+1 > Lc.listsize){
            p = (ElemType*)realloc(Lc.elem, (Lc.listsize+LISTINCREMENT)*sizeof(ElemType));
            if(!p){
                exit(OVERFLOW);
            }
            Lc.elem = p;
            Lc.listsize += LISTINCREMENT;
        }
        if(ai<=bj){
            ListInsert(Lc,++k,ai);
            i++;
        }else{
            ListInsert(Lc,++k,bj);
            j++;
        }
    }
    while(i<la_length){
            ElemType *p=NULL;
            if(Lc.length+1 > Lc.listsize){
                p = (ElemType*)realloc(Lc.elem, (Lc.listsize+LISTINCREMENT)*sizeof(ElemType));
                if(!p){
                    exit(OVERFLOW);
                }
                Lc.elem = p;
                Lc.listsize += LISTINCREMENT;
            }
            GetElem_Sq(La,i,ai);
            ListInsert(Lc,++k,ai);
            i++;
    }
    while(i<la_length){
            ElemType *p=NULL;
            if(Lc.length+1 > Lc.listsize){
                p = (ElemType*)realloc(Lc.elem, (Lc.listsize+LISTINCREMENT)*sizeof(ElemType));
                if(!p){
                    exit(OVERFLOW);
                }
                Lc.elem = p;
                Lc.listsize += LISTINCREMENT;
            }
            GetElem_Sq(Lb,i,bj);
            ListInsert(Lc,++k,bj);
            j++;
    }
}










