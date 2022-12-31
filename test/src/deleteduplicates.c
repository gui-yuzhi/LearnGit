#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Node {
    int val;
    struct Node *next;
} ListNode;

ListNode * CreateListNode(int val)
{
    ListNode *listNode = (ListNode *)malloc(sizeof(ListNode));
    listNode->val = val;
    listNode->next = NULL; 
    return listNode;
}
void PrintListVal(ListNode *listNode)
{
    int i = 0;
    while(listNode) {
        printf("listNode[%d] val is [%d].\n", i++, listNode->val);
        listNode = listNode->next;
    }
}
ListNode * DeleteDuplicates(ListNode *listNode)
{
    if (listNode == NULL) {
        return NULL;
    }
    ListNode *slow = listNode;
    ListNode *fast = listNode;
    while(fast) {
        if (fast->val != slow->val) {
            slow->next = fast;
            slow = slow->next;
        }
        fast = fast->next;
    }
    slow->next = NULL;
    return listNode;
}

int main()
{
    int nums[12] = { 1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4};
    ListNode *listNode = CreateListNode(nums[0]);
    ListNode *tempList = listNode;
    for (int i = 1; i < sizeof(nums) / sizeof(int); i++) {
        tempList->next = CreateListNode(nums[i]);
        tempList = tempList->next;
    }    
    DeleteDuplicates(listNode);
    PrintListVal(listNode);
	return 0;
}