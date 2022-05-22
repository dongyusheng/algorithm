#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
    int       m_nKey;
    ListNode* pNext;
};


void PrintListReversingly_Iteratively(ListNode* pHead)
{
    std::stack<ListNode*> nodes;
    ListNode* tempNode = pHead;
    //将所有节点加入栈中
    while (tempNode != nullptr)
    {
        nodes.push(tempNode);
        tempNode = tempNode->pNext;
    }
    //从尾到头打印
    while (!nodes.empty())
    {
        std::cout << nodes.top()->m_nKey << " ";
        nodes.pop();
    }
}
