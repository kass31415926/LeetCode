/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int sum = 0;//一个节点的和
        ListNode* p3 = new ListNode(0);
        ListNode* q = p3;
        int k = 0;
        while (p1->next != NULL && p2->next != NULL)
        {
            sum = k + p1->val + p2->val;
            if (sum >= 10)
            {
                k = 1;
                sum = sum % 10;
                q->next = new ListNode(sum);
                q = q->next;
            }
            else
            {
                k = 0;
                q->next = new ListNode(sum);
                q = q->next;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p1->next == NULL && p2->next == NULL)
        {
            sum = k + p1->val + p2->val;
            if (sum >= 10)
            {
                sum = sum % 10;
                q->next = new ListNode(sum);
                q = q->next;
                q->next = new ListNode(1);
                q = q->next;

            }
            else
            {
                q->next = new ListNode(sum);
                q = q->next;
            }
        }
        if (p1->next != NULL)
        {
            sum = k + p1->val + p2->val;
            if (sum >= 10)
            {
                k = 1;
                sum = sum % 10;
                q->next = new ListNode(sum);
                q = q->next;
            }
            else
            {
                k = 0;
                q->next = new ListNode(sum);
                q = q->next;
            }
            q->next = p1->next;
            p1 = p1->next;
            while (p1->next != NULL)
            {
                if (k == 1)
                {
                    p1->val++;
                    if (p1->val >= 10)
                    {
                        k = 1;
                        p1->val = p1->val % 10;
                    }
                    else
                    {
                        k = 0;
                    }
                }
                p1 = p1->next;
            }
            if (k == 1)
            {
                p1->val++;
                if (p1->val >= 10)
                {
                    p1->next = new ListNode(1);
                    p1->val = p1->val % 10;
                    p1 = p1->next;
                }
            }
        }
        if (p2->next != NULL)
        {
            sum = k + p1->val + p2->val;
            if (sum >= 10)
            {
                k = 1;
                sum = sum % 10;
                q->next = new ListNode(sum);
                q = q->next;
            }
            else
            {
                k = 0;
                q->next = new ListNode(sum);
                q = q->next;
            }
            q->next = p2->next;
            p2 = p2->next;
            while (p2->next != NULL)
            {
                if (k == 1)
                {
                    p2->val++;
                    if (p2->val == 10)
                    {
                        k = 1;
                        p2->val = p2->val % 10;
                    }
                    else
                    {
                        k = 0;
                    }
                }
                p2 = p2->next;

            }
            if (k == 1)
            {
                p2->val++;
                if (p2->val >= 10)
                {
                    p2->next = new ListNode(1);
                    p2->val = p2->val % 10;
                    p2 = p2->next;
                }
            }
        }
        return p3->next;

    }
};