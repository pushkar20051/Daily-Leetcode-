class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int degree =0;
        for(int i=0;i<n;i++){
            char ch = s[i];
            int idx = 123 - (int)ch;
            degree += idx * (i+1);
        }
        return degree;
    }
};