// https://leetcode.com/problems/is-subsequence/

const isSubsequence = function (s, t) {
  if (s.length === 0) return true;

  let match_num = 0;
  for (let i = 0; i < t.length; i++) {
    if (s[match_num] === t[i]) match_num++;
  }
  return match_num === s.length;
};

/**
    Time Complexity: O(N), where N is the length of t.
    Space Complexity: O(1), the space used by match_num.
 */
