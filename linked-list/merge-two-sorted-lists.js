// https://leetcode.com/problems/merge-two-sorted-lists

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
const mergeTwoLists = function (list1, list2) {
  if (!list1 && !list2) return null;
  if (!list1) return list2;
  if (!list2) return list1;

  let mergedList;

  if (list1.val < list2.val) {
    mergedList = new ListNode(list1.val);
    list1 = list1.next;
  } else {
    mergedList = new ListNode(list2.val);
    list2 = list2.next;
  }

  let head = mergedList;

  while (list1 || list2) {
    if (list1 && list2) {
      if (list1.val < list2.val) {
        mergedList.next = new ListNode(list1.val);
        mergedList = mergedList.next;
        list1 = list1.next;
      } else {
        mergedList.next = new ListNode(list2.val);
        mergedList = mergedList.next;
        list2 = list2.next;
      }
    } else if (list1) {
      mergedList.next = new ListNode(list1.val);
      mergedList = mergedList.next;
      list1 = list1.next;
    } else {
      mergedList.next = new ListNode(list2.val);
      mergedList = mergedList.next;
      list2 = list2.next;
    }
  }

  return head;
};
