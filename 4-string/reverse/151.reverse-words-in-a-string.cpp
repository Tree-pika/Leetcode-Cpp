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
    // string reverseWords(string s) {
    //     int n=s.length();
    //     string res;
    //     for(int i=n-1;i>=0;){
    //         while(i>=0&&s[i]==' ') i--;
    //         if(i<0) break;//前面只剩下空格的情况，比如case2，hello前面只有空格了
    //         // string t;
    //         int right = i;
    //         while(i>=0&&s[i]!=' ')
    //             // t+=s[i--];
    //             i--;
    //         // reverse(t.begin(),t.end());
    //         /*substr(start_pos, length)*/
    //         if(!res.empty()) res+=' ';
    //         res+=s.substr(i+1,right-i);
    //     }
    //     return res;
    // }
    /*method2：inplace solution*/
    string reverseWords(string s) {
        int slow = 0,fast = 0;
        int n = s.length();
        while(fast<n){
            if(s[fast]==' ') 
                fast++;
            else{
                if(slow!=0) s[slow++]=' ';
                while(fast<n&& s[fast]!=' ')//一定要加上fast<n的判断，因为字符串结束标志是'\0'而非' '
                    s[slow++]=s[fast++];
            }
        }
        s.resize(slow);
        reverse(s.begin(),s.end());
        n = s.length();
        int left = 0;
        // for(int i=0;i<n;i++){
        //     if(s[i]==' '||i==n-1){
        //         int right = i==n-1? n:i;
        //         //翻转当前的word:[left,right)
        //         reverse(s.begin()+left,s.begin()+right);
        //         left = i+1;
        //     }
        // }
        for(int i=0;i<=n;i++){
            if(s[i]==' '||i==n){
                reverse(s.begin()+left,s.begin()+i);
                left = i+1;
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

