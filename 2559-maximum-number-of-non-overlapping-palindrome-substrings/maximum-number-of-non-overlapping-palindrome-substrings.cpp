class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        int subString =0;
        int start =0;
        for(int right =k-1; right<n; right++){
            for(int len =k; len <= right-start+1; len++){
                int left = right - len +1;
                if(check(s, left, right)){
                    subString++;
                    start = right +1;
                    break;
                }
            }
        }
        return subString;
    }
private:
    bool check(string s, int left, int right){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};