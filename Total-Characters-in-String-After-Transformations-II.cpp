class Solution {
public:
    const int MOD = 1e9 + 7;
    using Matrix = vector<vector<long long>>;

    // Multiplies two 26x26 matrices
    Matrix multiply(const Matrix& A, const Matrix& B) {
        Matrix C(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int k = 0; k < 26; ++k) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < 26; ++j) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    // Raises a matrix to the power of t
    Matrix matrixPow(Matrix base, long long t) {
        Matrix result(26, vector<long long>(26, 0));
        // Initialize result as identity matrix
        for (int i = 0; i < 26; ++i) result[i][i] = 1;

        while (t > 0) {
            if (t % 2 == 1) result = multiply(result, base);
            base = multiply(base, base);
            t /= 2;
        }
        return result;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        // Build transition matrix M where M[i][j] = number of times j appears in transformation of i
        Matrix M(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i) {
            int cnt = nums[i];
            for (int j = 1; j <= cnt; ++j) {
                int nextChar = (i + j) % 26;
                M[i][nextChar] = (M[i][nextChar] + 1) % MOD;
            }
        }

        // Raise M to power t
        Matrix Mt = matrixPow(M, t);

        // Base vector: count of each character in the original string
        vector<long long> base(26, 0);
        for (char ch : s) {
            base[ch - 'a']++;
        }

        // Multiply base vector by Mt to get final counts
        vector<long long> final(26, 0);
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                final[j] = (final[j] + Mt[i][j] * base[i]) % MOD;
            }
        }

        // Sum up all final counts
        long long total = 0;
        for (int i = 0; i < 26; ++i) {
            total = (total + final[i]) % MOD;
        }

        return static_cast<int>(total);
    }
};