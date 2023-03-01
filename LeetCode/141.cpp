#include<iostream>
#include<vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //快慢指针法
        //一个快指针一次走两步，一个慢指针一次走一步
        //如果有环，这两个指针最终都会进入环
        //然后在环内快指针逐渐追上慢指针，重合即有环
        //如果没环快指针最后为NULL
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast!=NULL&&slow!=NULL)
        {
            ListNode *tmp=fast->next;
            if(tmp!=NULL&&tmp->next!=NULL) fast=tmp->next;
            else return false;
            tmp=slow->next;
            if(tmp!=NULL) slow=tmp;
            else return false;
            if(slow==fast) return true;            
        }
        return false;
    }
};
//看到环想用拓扑排序，但是度数未知，深搜或广搜求度数在排序等等
//空间和时间都有消耗
//实际上链表中每个节点都只有一个next，并不复杂
//可以有更简单的算法，因为next的唯一导致进入环就出不来了
//当然快慢指针在某些情况也会很慢