// https://practice.geeksforgeeks.org/problems/binary-number-to-decimal-number3525/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
// stoi= to convert string to integer

// doesn't work string input->
int binary_to_decimal(string str)
{
    int n = stoi(str);
    int decVal = 0;
    int base = 1;
    while (n)
    {
        int unitDigit = n % 10;
        decVal += unitDigit * base;
        base = base * 2;
        n = n / 10;
    }
    return decVal;
}

//input given as string
int binary_to_decimal(string str) {
        // Code here.
        string num=str;
        int decVal=0;
        int base=1;
        int len=num.length();
        for(int i=len-1;i>=0;i--){
            if(num[i]=='1'){
                decVal+=base;
            }
            base*=2;
        }
        return decVal;
    }