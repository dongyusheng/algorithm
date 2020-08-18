#include <cstdio>

using namespace std;

struct ListNode {
    int m_nValue;
    ListNode *m_pNext;
};

/**
 * @description: 从pListHead链表中删除pToBeDeleted节点
 * @param:
         pListHead: 链表
         pToBeDeleted: 指定要删除的节点
 * @return {type} 
 * @author: Dongshao
 */
// 因为链表的头结点也可能被删除, 所以参数1传入链表头结点的地址进来
void DeleteNode(ListNode **pListHead, ListNode *pToBeDeleted)
{
    if(pListHead == nullptr || pToBeDeleted == nullptr)
        return;

    // 如果该节点属于"中间节点", 那么直接使用O(1)的解法删除
    if(pToBeDeleted->m_pNext != nullptr)
    {
        // 得到删除节点的下一个节点
        ListNode *pNext = pToBeDeleted->m_pNext;
        // 将下一个节点的值赋值给要删除的节点
        pToBeDeleted->m_nValue = pNext->m_nValue;
        // 让pToBeDeleted->m_pNext指向于pNext->m_pNext, 实际上删除pNext
        pToBeDeleted->m_pNext = pNext->m_pNext;
        delete pNext;
        pNext = nullptr;
    }
    // 如果链表中只有一个节点, 直接删除即可
    else if(*pListHead == pToBeDeleted)
    {
        delete *pListHead;
        *pListHead = pToBeDeleted =nullptr;
    }
    // 如果删除的是尾节点, 仍然需要遍历链表来删除
    else
    {
        ListNode *pNode = *pListHead;
        // 遍历找到尾节点的前一个节点
        while(pNode->m_pNext != pToBeDeleted)
            pNode = pNode->m_pNext;
        
        pNode->m_pNext = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}


ListNode* CreateListNode(int value)
{
    ListNode* pNode = new ListNode();
    pNode->m_nValue = value;
    pNode->m_pNext = nullptr;

    return pNode;
}

void DestroyList(ListNode* pHead)
{
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        pHead = pHead->m_pNext;
        delete pNode;
        pNode = pHead;
    }
}

void PrintList(ListNode* pHead)
{
    printf("PrintList starts.\n");
    
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        printf("%d\t", pNode->m_nValue);
        pNode = pNode->m_pNext;
    }

    printf("\nPrintList ends.\n");
}

void PrintListNode(ListNode* pNode)
{ 
    if(pNode == nullptr)
    {
        printf("The node is nullptr\n");
    }
    else
    {
        printf("The key in node is %d.\n", pNode->m_nValue);
    }
}

void Test(ListNode* pListHead, ListNode* pNode)
{
    printf("The original list is: \n");
    PrintList(pListHead);

    printf("The node to be deleted is: \n");
    PrintListNode(pNode);

    DeleteNode(&pListHead, pNode);
    
    printf("The result list is: \n");
    PrintList(pListHead);
}

// 链表中有多个结点，删除中间的结点
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    pNode1->m_pNext = pNode2;
    pNode2->m_pNext = pNode3;
    pNode3->m_pNext = pNode4;
    pNode4->m_pNext = pNode5;

    Test(pNode1, pNode3);

    DestroyList(pNode1);
}

// 链表中有多个结点，删除尾结点
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    pNode1->m_pNext = pNode2;
    pNode2->m_pNext = pNode3;
    pNode3->m_pNext = pNode4;
    pNode4->m_pNext = pNode5;

    Test(pNode1, pNode5);

    DestroyList(pNode1);
}

// 链表中有多个结点，删除头结点
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    pNode1->m_pNext = pNode2;
    pNode2->m_pNext = pNode3;
    pNode3->m_pNext = pNode4;
    pNode4->m_pNext = pNode5;

    Test(pNode1, pNode1);

    DestroyList(pNode1);
}

// 链表中只有一个结点，删除头结点
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);

    Test(pNode1, pNode1);
}

// 链表为空
void Test5()
{
    Test(nullptr, nullptr);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    return 0;
}    
