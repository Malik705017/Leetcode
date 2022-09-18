// https://leetcode.com/problems/middle-of-the-linked-list

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */

const middleNode = function (head) {
  if (!head) return head;
  let length = 1,
    copyHead = head;

  // compute list length
  while (head.next) {
    length++;
    head = head.next;
  }

  let curPtr;
  for (let i = 0; i <= length / 2; i++) {
    curPtr = copyHead;
    copyHead = copyHead.next;
  }

  return curPtr;
};
