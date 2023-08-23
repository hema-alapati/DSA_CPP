
// https://leetcode.com/problems/jewels-and-stones/solutions/1842275/c-short-comment-explanation-easy-to-understand/

class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        // int count=0;
        // for(int i=0;i<stones.size();i++){
        //     if(jewels.find(stones[i])!=string::npos) count++;
        // }
        // return count;

        int ans = 0;
        map<char, int> count;

        // counting all stones
        for (int i = 0; i < stones.size(); i++)
            count[stones[i]]++;

        // sum all valid jewels stone
        for (int i = 0; i < jewels.size(); i++)
            ans += count[jewels[i]];

        return ans;
    }
};