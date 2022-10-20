class Solution {
    string answer;

    void convert(int digit, vector<string> symbols) {
        if (digit < 4) {
            string ones;
            for (int j = 0; j < digit; j++) ones += symbols[0];
            answer = ones + answer;
        } 
        else if (digit == 4) answer = symbols[1] + answer;
        else if (digit == 5) answer = symbols[2] + answer;
        else if (digit < 9) {
            string ones;
            for (int j = 0; j < digit - 5; j++) ones += symbols[0];
            answer = symbols[2] + ones + answer;
        }
        else answer = symbols[3] + answer;
    }
public:
    string intToRoman(int num) {
        vector<int> digits;
        while (num != 0) {
            int digit = num % 10;
            digits.push_back(digit);
            num /= 10;
        }

        int n = digits.size();
        for (int i = 0; i < n; i++) {
            if (digits[i] == 0) continue;

            if (i == 0) {
                convert(digits[i], {"I", "IV", "V", "IX"});
            } else if (i == 1) {
                convert(digits[i], {"X", "XL", "L", "XC"});
            } else if (i == 2) {
                convert(digits[i], {"C", "CD", "D", "CM"});
            } else if (i == 3) {
                convert(digits[i], {"M", "", "", ""});
            }
        }
        return answer;
    }
};