class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    string toBaseK(long long num, int k) {
        string res;
        while (num) {
            res += (num % k) + '0';
            num /= k;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    long long kMirror(int k, int n) {
        long long sum = 0;
        int count = 0;

        for (int length = 1; count < n; length++) {
            // Generate palindromes of given length
            for (int half = pow(10, (length - 1) / 2); half < pow(10, (length + 1) / 2) && count < n; ++half) {
                string halfStr = to_string(half);
                string fullStr = halfStr;
                int start = (length % 2 == 0) ? halfStr.size() - 1 : halfStr.size() - 2;
                for (int i = start; i >= 0; --i)
                    fullStr += halfStr[i];
                long long num = stoll(fullStr);
                string baseK = toBaseK(num, k);
                if (isPalindrome(baseK)) {
                    sum += num;
                    count++;
                }
            }
        }

        return sum;
    }
};
