// https://blog.csdn.net/qq_41453285/article/details/108170929
/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Dongshao
 * @Date: 2020-07-31 09:09:08
 * @LastEditors: Dongshao
 * @LastEditTime: 2020-08-22 17:52:13
 */

#include <cstdio>
#include <cstdlib>

struct ListNode
{
    int       m_nValue;
    ListNode *m_pNext;
};

/**
 * @description: 使用p1和p2遍历链表判断链表是否存在回环; 如果存在回环, 返回p1和p2第一次相遇的节点; 如果不存在回环, 返回nullptr
 * @param:
        head: 链表头结点
 * @return:
        链表存在回环: p1和p2第一次相遇的节点
        链表不存在回环: nullptr
 * @author: Dongshao
 */
ListNode *MeetingNode(ListNode *head)
{
    if(head == nullptr)
        return nullptr;

    ListNode *p1 = head;
    ListNode *p2 = head;

    // p1每次走1步, p2每次走2步
    while(p1 != nullptr && p2 != nullptr && p2->m_pNext != nullptr)
    {
        p1 = p1->m_pNext;
        p2 = p2->m_pNext;

        // 如果p2的下一个节点不为空, 那么再走一步
        if(p2->m_pNext != nullptr)
            p2 = p2->m_pNext;
        // 否则p2遇到了nullptr, 那么链表就不存在回环, 返回nullptr
        else
            return nullptr;
        
        // 如果p1和p2相遇了, 说明链表存在回环
        if(p1 == p2)
            return p1;
    }

    return nullptr;
}

/**
 * @description: 判断链表是否存在回环, 如果存在回环返回链表的回环地址, 否则返回nullptr
 * @param:
        head: 链表头结点
 * @return:
        链表存在回环: 返回回环入口节点
        链表不存在回环: nullptr
 * @author: Dongshao
 */
ListNode *EntryNodeOfLoop(ListNode *head)
{
    // 调用MeetingNode()函数判断链表是否存在回环
    ListNode *meetingNode = MeetingNode(head);
    if(meetingNode == nullptr)
        return nullptr;
    
    // 如果存在回环, 那么判断环的长度
    ListNode *p1 = meetingNode->m_pNext;
    // 用来保存环的长度
    int n = 1;
    while(p1 != meetingNode)
    {
        n++;
        p1 = p1->m_pNext;
    }

    // 再定义一个p2, 将p1重新指向于头结点然后向后移动n个节点, 然后p1和p2一起向后移动找到回环入口
    p1 = head;
    ListNode *p2 = head;
    for(int i = 0; i < n; ++i)
        p1 = p1->m_pNext;
    while(p1 != p2)
    {
        p1 = p1->m_pNext;
        p2 = p2->m_pNext;
    }

    return p1;
}

// ==================== 链表操作函数 ====================
ListNode* CreateListNode(int value)
{
    ListNode* pNode = new ListNode();
    pNode->m_nValue = value;
    pNode->m_pNext = nullptr;

    return pNode;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
    if(pCurrent == nullptr)
    {
        printf("Error to connect two nodes.\n");
        exit(1);
    }

    pCurrent->m_pNext = pNext;
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

// ==================== Test Code ====================
void Test(char* testName, ListNode* pHead, ListNode* entryNode)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(EntryNodeOfLoop(pHead) == entryNode)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// A list has a node, without a loop
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);

    Test("Test1", pNode1, nullptr);

    DestroyList(pNode1);
}

// A list has a node, with a loop
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ConnectListNodes(pNode1, pNode1);

    Test("Test2", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode3);

    Test("Test3", pNode1, pNode3);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode1);

    Test("Test4", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test5()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode5);

    Test("Test5", pNode1, pNode5);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, without a loop 
void Test6()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test("Test6", pNode1, nullptr);

    DestroyList(pNode1);
}

// Empty list
void Test7()
{
    Test("Test7", nullptr, nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}
