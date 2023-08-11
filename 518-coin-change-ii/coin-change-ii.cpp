class Solution {
public:
    int help(int n, int amt, vector<int>& coins,vector<vector<int>>& temp){
        if(amt==0) return 1;
        if(n==0) return 0;
        if(temp[n][amt]!=-1) return temp[n][amt];

    if(coins[n-1]<=amt)
    {
        int opt1=help(n,amt-coins[n-1],coins,temp);
        int opt2=help(n-1,amt,coins,temp);
        return temp[n][amt]=opt1+opt2;
    }
    else
        return temp[n][amt]=help(n-1,amt,coins,temp);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector(amount+1,-1));
        return help(n,amount,coins,dp);
    }
};