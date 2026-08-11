class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int rows = points.size();
        int cols = points[0].size();
        // maxHeap
        priority_queue<pair<float, pair<int, int>>> pq;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols - 1; j++) {
                // make a maxHeap of k closest point
                float distance = sqrt(points[i][j] * points[i][j] +
                                    points[i][j + 1] * points[i][j + 1]);
                int xAxis = points[i][j];
                int yAxis = points[i][j + 1];
                pair<int, int> coordinate = {xAxis, yAxis};
                if (pq.size() < k) {
                    pq.push({distance, coordinate});
                } else {
                    if (pq.top().first > distance) {
                        pq.pop();
                        pq.push({distance, coordinate});
                    }
                }
            }
        }

        vector<vector<int>> ans;

        while (!pq.empty()) {
            vector<int> temp;
            temp.push_back(pq.top().second.first);
            temp.push_back(pq.top().second.second);
            ans.push_back(temp);
            pq.pop();
        }

        return ans;
    }
};