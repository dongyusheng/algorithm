// https://blog.csdn.net/qq_41453285/article/details/108275367
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *head = new ListNode(-1);
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        ListNode *temp = head;

        int nextNum = 0;

        int num1, num2, sum;

        // 只要两个链表有一个不为空就遍历
        while(temp1 != nullptr || temp2 != nullptr)
        {
            num1 = (temp1 != nullptr) ? temp1->val : 0;
            num2 = (temp2 != nullptr) ? temp2->val : 0;

            // 得到总和
            sum = num1 + num2 + nextNum;
            // 判断是否超出10
            nextNum = sum / 10;

            // 创建新节点并拼接在temp后面
            temp->next = new ListNode(sum % 10);
            temp = temp->next;

            // 链表向后移动
            temp1 = (temp1 != nullptr) ? temp1->next : temp1;
            temp2 = (temp2 != nullptr) ? temp2->next : temp2;
        }

        // 如果结尾还超出了10, 那么新添加一个节点
        if(nextNum > 0)
        {
            temp->next = new ListNode(nextNum);
        }  

        return head->next;
    }
};
