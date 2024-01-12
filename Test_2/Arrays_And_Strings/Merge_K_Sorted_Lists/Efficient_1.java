// Problem Link -> https://leetcode.com/problems/merge-k-sorted-lists/description/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    private static ListNode mergeSort(ListNode a, ListNode b) {
        if(a == null) return b;
        if(b == null) return a;
        ListNode newListNode = new ListNode(-1);
        ListNode tail = newListNode;
        while(a != null && b != null) {
            if(a.val < b.val) {
                tail.next = a;
                tail = a;
                a = a.next;
            } else {
                tail.next = b;
                tail = b;
                b = b.next;
            }
        }
        if(a != null && b == null) tail.next = a;
        if(b != null && a == null) tail.next = b;
        return newListNode.next;
    }
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length == 0) return null;

        ListNode Head = lists[0];
        for(int i = 1; i < lists.length; i++) {
            Head = mergeSort(Head, lists[i]);
        }
        return Head;
    }
}