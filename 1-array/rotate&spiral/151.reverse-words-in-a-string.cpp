/*
 * @lc app=leetcode.cn id=151 lang=cpp
 * @lcpr version=30204
 *
 * [151] 反转字符串中的单词
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    void reverse(string& s,int start,int end){
        int left=start,right = end;
        while(left<right){
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }
    string reverseWords(string s) {
        int slow=0,fast=0;
        // while(fast<s.length()){
        //     if(s[fast]!=' '){
        //         s[slow++] = s[fast];
        //     }else if(fast>0&&s[fast-1]!=' '&&s[fast]==' '){
        //         s[slow++] = s[fast];
        //     }
        //     fast++;
        // }
        // if(s[slow-1]==' ') slow-=1;//若原始有尾随空格，则清理后还有一个
        while(fast<s.length()){
            if(s[fast]!=' '){
                if(slow!=0){
                    s[slow++]=' ';
                }
                while(fast<s.length()&&s[fast]!=' '){
                    s[slow++] = s[fast++];
                }
            }
            fast++;
        }
        s.resize(slow);
        reverse(s,0,slow-1);
        int start=0;
        for(int i=0;i<=s.length();i++){
            //前面的单词末尾是' '，最后一个不同，是边界
            if(s[i]==' '||i==s.length()){
                reverse(s,start,i-1);
                start = i+1;
            }
        }
        return s;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "the sky is blue"\n
// @lcpr case=end

// @lcpr case=start
// "  hello world  "\n
// @lcpr case=end

// @lcpr case=start
// "a good   example"\n
// @lcpr case=end

 */

