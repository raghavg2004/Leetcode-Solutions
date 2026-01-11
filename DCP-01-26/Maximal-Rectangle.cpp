1class Solution {
2public:
3    int largestRectangleArea(vector<int>& heights) {
4        int n = heights.size();
5        stack<int> st;
6        st.push(-1);
7
8        vector<int> prevSmaller(n), nextSmaller(n);
9
10        for (int i = 0; i < n; i++) {
11            while (st.top() != -1 && heights[st.top()] >= heights[i])
12                st.pop();
13            prevSmaller[i] = st.top();
14            st.push(i);
15        }
16
17        while (!st.empty()) st.pop();
18        st.push(-1);
19
20        for (int i = n - 1; i >= 0; i--) {
21            while (st.top() != -1 && heights[st.top()] >= heights[i])
22                st.pop();
23            nextSmaller[i] = (st.top() == -1) ? n : st.top();
24            st.push(i);
25        }
26
27        int maxArea = 0;
28        for (int i = 0; i < n; i++) {
29            int height = heights[i];
30            int width = nextSmaller[i] - prevSmaller[i] - 1;
31            maxArea = max(maxArea, height * width);
32        }
33
34        return maxArea;
35    }
36
37    int maximalRectangle(vector<vector<char>>& matrix) {
38        int rows = matrix.size();
39        int cols = matrix[0].size();
40
41        vector<int> histogram(cols, 0);
42        int answer = 0;
43
44        for (int i = 0; i < rows; i++) {
45            for (int j = 0; j < cols; j++) {
46                if (matrix[i][j] == '1')
47                    histogram[j]++;
48                else
49                    histogram[j] = 0;
50            }
51            answer = max(answer, largestRectangleArea(histogram));
52        }
53
54        return answer;
55    }
56};