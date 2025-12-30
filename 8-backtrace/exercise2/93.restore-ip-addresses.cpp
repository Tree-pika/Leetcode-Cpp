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
private:
    vector<string> res;
    string track;
    void backtrack(const string&s,int start,int segNum){
        if(start==s.length()&&segNum==4){
            res.push_back(track);
            return;
        }
        if(segNum>=4) return;
        for(int end=start;end<s.length();end++){
            //判断段是否合法
            string part(s,start,end-start+1);
            if(part.length()>3||(part.length()>1&&part[0]=='0')){
                continue;
            }
            int num = stoi(part);
            if(num<0||num>255){
                continue;
            }
            if(segNum<3){
                part+='.';
            }
            //做选择
            track+=part;
            backtrack(s,end+1,segNum+1);
            //撤销选择
            track.resize(track.size()-part.size());
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        int len = s.length();
        if(len<4||len>12) return res;
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

