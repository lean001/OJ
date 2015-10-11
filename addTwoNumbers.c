#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode *InitList(void)
{
    struct ListNode *pListHead;
    pListHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    pListHead -> next = NULL;
    return pListHead;
}

struct ListNode *CreateNode(int value)
{
    struct ListNode *pValue = NULL;
    pValue = (struct ListNode *)malloc(sizeof(struct ListNode));
    if(pValue == NULL)
        return NULL;
    pValue -> val = value;
    pValue -> next = NULL;
    return pValue;
}

void DeleteList(struct ListNode *pList)
{
    struct ListNode *pTmp = NULL;
    while(pList)
    {
        pTmp = pList -> next;
        free(pList);
        pList = pTmp;
    }
    pTmp = NULL;
}

void InsertNode(struct ListNode *pListHead, int value)
{
    struct ListNode *pValue = CreateNode(value);
    if (pValue == NULL)
        return;

    if (pListHead -> next == NULL)
        pListHead -> next = pValue;
    else{
        while(pListHead -> next != NULL)
        pListHead = pListHead -> next;
        pListHead -> next = pValue;
    }
}

void printList(struct ListNode* pList)
{
    while(pList)
    {
        printf("%d ", pList -> val);
        pList = pList -> next;
    }
    printf("\n");
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* pValue = NULL;
    struct ListNode* pTmp = l1;
    struct ListNode* pPre = NULL;

    while(l1 && l2)
    {
        if (l1->val + l2->val < 10)
        {
            l1 -> val = l1->val + l2->val;
        }else
        {
            l1 -> val = (l1 -> val + l2 -> val) % 10;
            if ( l1 -> next )
                l1 -> next -> val += 1;
            else{
                pValue = (struct ListNode *)malloc(sizeof(struct ListNode));
                if (!pValue)
                    return NULL;
                else{
                    pValue -> val = 1;
                    pValue -> next = NULL;
                    l1 -> next = pValue;
                }
            }
        }
        pPre = l1;
        l1 = l1 -> next;
        l2 = l2 -> next;
    }
    while ( l1 && l1 -> val >= 10) /*l1 当前节点大于10*/
    {
        l1 -> val = l1 -> val % 10;
        if (l1 -> next != NULL)
            l1 -> next -> val += 1;
        else{
            pValue = (struct ListNode *)malloc(sizeof(struct ListNode));
            if (pValue)
            {
                pValue -> val = 1;
                pValue -> next = NULL;
                l1 -> next = pValue;
            } else
                return NULL;
        }
        l1 = l1 -> next; 
    }
    if (l2)
    {
        pPre -> next = l2;
    }
    return pTmp;
}

int main()
{
    struct ListNode* pHead1 = CreateNode(1);
    struct ListNode* pHead2 = CreateNode(1);
    struct ListNode* pRes = NULL;
    int i;
    for(i = 1; i < 10; i += 2)
    {
        InsertNode(pHead1, i);
    }
    printf("\n");
    for(i = 2; i < 12; i += 2)
    {
        InsertNode(pHead2, i);
    }
    printList(pHead1);
    printList(pHead2);
    pRes = addTwoNumbers(pHead1, pHead2);
    printList(pRes);

    DeleteList(pHead1);
    DeleteList(pHead2);

    return 0;
}
