// https://leetcode.com/problems/isomorphic-strings/

/** Solution 1 */
const isIsomorphic = function (s, t) {
  let charMap = {}; // s[i] map to t[i]
  let charUsed = {}; // if t[i] is used

  for (let i = 0; i < s.length; i++) {
    // if s[i] hasn't mapped before
    if (charMap[s[i]] === undefined) {
      charMap[s[i]] = t[i];
      // if t[i] has been mapped by other char
      if (charUsed[t[i]] === true) return false;
    }
    // if s[i] has mapped but value wrong
    else if (charMap[s[i]] !== t[i]) return false;

    // mark t[i] been mapped
    charUsed[t[i]] = true;
  }

  return true;
};

/** Solution 2 */
const isIsomorphic2 = function (s, t) {
  // Create two maps for s & t strings...
  const map1 = {};
  const map2 = {};
  // Traverse all elements through the loop...
  for (let idx = 0; idx < s.length; idx++) {
    // Compare the maps, if not equal, return false...
    if (map1[s[idx]] !== map2[t[idx]]) return false;
    // Insert each character if string s and t into seperate map...
    map1[s[idx]] = idx + 1;
    map2[t[idx]] = idx + 1;
  }
  return true; // Otherwise return true...
};
