class Solution {
public:
    int strStr(string haystack, string needle) {
        const int size = needle.length();
        char test[size];
        for(int i=0;i<haystack.length();i++){
            bool flag = true;
            haystack.copy(test,size,i);
            for(int j=0;j<size;j++){
                if(test[j] != needle[j]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                return i;
            }
        }
        return -1;
    }
};