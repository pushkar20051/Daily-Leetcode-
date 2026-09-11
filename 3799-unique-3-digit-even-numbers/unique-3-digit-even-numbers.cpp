class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int> set;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i==j || j==k || k==i) continue;
                    if(digits[i] !=0 && digits[k]%2 ==0){
                        int number = digits[i]*100 + digits[j]*10 + digits[k];
                        set.insert(number);
                    }
                }
            }
        }
        return (int)set.size();
    }
};