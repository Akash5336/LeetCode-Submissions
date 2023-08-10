class Solution {
public:
    bool isPalindrome(int x) {
        int num=x;
        long int res=0;
        int d=0;
        while(num>0){
            d = num%10;
            res = res*10 + d;
            num /= 10;
        }
        return (res == x);
    }
};