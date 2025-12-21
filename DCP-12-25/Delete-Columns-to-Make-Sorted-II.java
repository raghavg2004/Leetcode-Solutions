1class Solution {
2    public int minDeletionSize(String[] A) {
3        int N = A.length;
4        int W = A[0].length();
5        int ans = 0;
6
7        // cur : all rows we have written
8        // For example, with A = ["abc","def","ghi"] we might have
9        // cur = ["ab", "de", "gh"].
10        String[] cur = new String[N];
11        for (int j = 0; j < W; ++j) {
12            // cur2 : What we potentially can write, including the
13            //        newest column col = [A[i][j] for i]
14            // Eg. if cur = ["ab","de","gh"] and col = ("c","f","i"),
15            // then cur2 = ["abc","def","ghi"].
16            String[] cur2 = Arrays.copyOf(cur, N);
17            for (int i = 0; i < N; ++i)
18                cur2[i] += A[i].charAt(j);
19
20            if (isSorted(cur2))
21                cur = cur2;
22            else
23                ans++;
24        }
25
26        return ans;
27    }
28
29    public boolean isSorted(String[] A) {
30        for (int i = 0; i < A.length - 1; ++i)
31            if (A[i].compareTo(A[i+1]) > 0)
32                return false;
33
34        return true;
35    }
36}