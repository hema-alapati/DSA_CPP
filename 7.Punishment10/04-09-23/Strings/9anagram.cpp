// https://leetcode.com/problems/valid-anagram/solutions/66519/2-c-solutions-with-explanations/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;      
        int n = s.length();
        unordered_map<char,int>counts;
        for(int i=0;i<n;i++){
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for(auto it:counts){
            if(it.second!=0) return false;
        }
        return true;
    }
};