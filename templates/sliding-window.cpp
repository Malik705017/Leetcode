#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * parent 為搜尋範圍， child 為目標字串
 */
void slidingWindow (string parent, string child)
{
    /**
     * need 用來紀錄目標字串包含的字元與對應的個數
     * window 用來記錄 sliding window 內資料
     */
    unordered_map<char, int> need, window;
    for (char c:child) need[c]++;

    int left = 0, right = 0;  /* two pointers for window's two bound */
    /**
     * 變數 valid 用來紀錄目標字串內各字元是否已經找齊，
     * 如果 valid == need.size()，
     * 代表 window 內已經收集完資料
     */
    int valid = 0;
    while(right < parent.size()) {
        // input 是要放入 window 的字元
        char input = parent[right];
        // 移動右邊窗口將 window 增大
        right++;
        // 進行 window 內資料更新
        // ...

        // 這邊要放入 window needs shrink 的條件，因避免跳 error 這邊用 true，實際在寫的時候不會是 true 
        if (true) {
            // out 是要移出 window 的字元
            char out = parent[left];
            // 移動左邊窗口將 window 縮小
            left++;
            // 進行 window 內資料更新
            // ...
        }
    }
}