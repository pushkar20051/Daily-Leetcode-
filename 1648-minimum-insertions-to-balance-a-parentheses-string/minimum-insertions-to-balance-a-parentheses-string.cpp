class Solution {
public:
    int minInsertions(string s) {  
        int closingRequired = 0;
        int insertions = 0;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (ch == '(') {
                if (closingRequired % 2 != 0) {
                    insertions++;
                    closingRequired--;
                }

                closingRequired += 2;
            } else {
                closingRequired--;

                if (closingRequired < 0) {
                    insertions++;
                    closingRequired = 1;
                }
            }
        }

        return insertions + closingRequired;
    }
};