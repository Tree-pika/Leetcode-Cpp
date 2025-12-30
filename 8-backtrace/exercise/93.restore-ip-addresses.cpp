/*
 * @lc app=leetcode.cn id=93 lang=cpp
 * @lcpr version=30204
 *
 * [93] 复原 IP 地址
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
/*solution1:模仿lc-131的写法，但是这样不好，因为本题加入了对段数以及每段长度的限制*/
private:
    vector<string> res;
    string track;
    //本轮可以从start开始分割s
    void backtrack(const string&s,int start,int segNum){
        //终止条件：遍历完字符串且正好找到了4段
        if(start==s.length()&&segNum==4){
            res.push_back(track);
            return;
        }
        //剪枝：如果还没处理完字符串，但段数已经超过4了，直接回溯
        if(segNum>=4) return;
        
        //本轮从end处切割s
        for(int end=start;end<s.length();end++){
            string part = s.substr(start,end-start+1);
            //判断分段合法性：检查前导0,同时对单段长度做限制
            if((part.size()>1&&part[0]=='0')||part.size()>3){
                continue;
            }
            int num = stoi(part);
            if(num<0||num>255){
                continue;
            }
            //前三段后面+'.'分割
            if(segNum<3){
                part+='.';
            }
            // 做选择，把 s[start..end] 放入路径列表中
            track+=part;
            // 进入回溯树的下一层，继续切分 s[end+1..]
            backtrack(s,end+1,segNum+1);
            // 撤销选择
            track.resize(track.size()-part.size());
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        track = "";
        // 基础长度剪枝
        if (s.size() < 4 || s.size() > 12) return res;
        backtrack(s,0,0);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "25525511135"\n
// @lcpr case=end

// @lcpr case=start
// "0000"\n
// @lcpr case=end

// @lcpr case=start
// "101023"\n
// @lcpr case=end

 */

