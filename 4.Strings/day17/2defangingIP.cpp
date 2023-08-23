// https://leetcode.com/submissions/detail/1029329882/

class Solution
{
public:
    string defangIPaddr(string address)
    {
        string defangedIP = "";
        for (auto i : address)
        {
            if (i == '.')
            {
                defangedIP += "[.]";
            }
            else
                defangedIP += i;
        }
        // for(int i=0;i<address.size();i++){
        //     if(address[i]=='.') defanged+='[';
        //     defanged+=address[i];
        //     if(address[i]=='.') defanged+=']';
        // }
        return defangedIP;
    }
};