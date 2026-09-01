class Solution {
public:
    int addDigits(int num) {
        int sum = addDigit(num, 0);
        while (sum >= 10) {
            sum = addDigit(sum, 0);
        }
        return sum;
    }
    int addDigit(int num, int sum) {
        while (num > 0) {
            int first = num % 10;
            sum += first;
            num /= 10;
        }
        return sum;
    }
};