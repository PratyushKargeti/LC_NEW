class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
 if (matrix.empty() || matrix[0].empty())
            return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            } 
            stack<int> st;
            int area = 0;
            for (int j = 0; j <= cols; j++) {
                while (!st.empty() && (j == cols || heights[j] < heights[st.top()])) {
                    int height = heights[st.top()];
                    st.pop();
                    int width = st.empty() ? j : j - st.top() - 1;
                    area = max(area, width * height);
                }
                st.push(j);
            }
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};

