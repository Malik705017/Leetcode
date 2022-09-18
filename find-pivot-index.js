// https://leetcode.com/problems/find-pivot-index

const pivotIndex = function (nums) {
  let left = 0,
    right = nums.reduce((next, prev) => next + prev) - nums[0];
  for (let i = 0; i < nums.length; i++) {
    if (left === right) return i;
    left += nums[i];
    right -= nums[i + 1];
  }
  return -1;
};

/**
    Time Complexity: O(N), where N is the length of nums.
    Space Complexity: O(1), the space used by leftsum and rightsum.
 */
