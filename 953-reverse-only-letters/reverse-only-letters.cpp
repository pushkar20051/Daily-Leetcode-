class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            // Move left to a letter
            while (left < right && !isalpha(s[left])) {
                left++;
            }

            // Move right to a letter
            while (left < right && !isalpha(s[right])) {
                right--;
            }

            // Swap letters
            swap(s[left], s[right]);

            left++;
            right--;
        }

        return s;
    }
};