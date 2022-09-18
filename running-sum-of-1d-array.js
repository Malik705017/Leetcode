/** Solution 1 */
const runningSum = function (nums) {
  for (let i = 1; i < nums.length; i++) {
    nums[i - 1] += nums[i];
  }
  return nums;
};

/** Solution 2 */
const runningSum2 = function (nums) {
  let ans = [nums[0]];
  nums.forEach((n, index) => index > 0 && ans.push(ans[index - 1] + n));
  return ans;
};
