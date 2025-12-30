/*
 * @lc app=leetcode.cn id=17 lang=cpp
 * @lcpr version=30204
 *
 * [17] 电话号码的字母组合
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
    string track;
    vector<string> res;
    unordered_map<char,string> map = {{'2',"abc"},{'3',"def"},{'4',"ghi"},
    {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    //index: 当前要处理 digits 中的第几个数字
    void backtrack(string digits,int index){
        if(track.length()==digits.size()){
            res.push_back(track);
            return;
        }
        char digit = digits[index];//每一层的选择列表不同，根据index切换递归到本层的候选列表
        string letters = map[digit];
        for(char c:letters){
            //做选择
            track.push_back(c);
            backtrack(digits,index+1);//组合，控制每次只能往下一个数字的候选列表走
            //撤销选择
            track.pop_back();
        }
        
    }
public:
    vector<string> letterCombinations(string digits) {
        backtrack(digits,0);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "23"\n
// @lcpr case=end

// @lcpr case=start
// "2"\n
// @lcpr case=end

 */

