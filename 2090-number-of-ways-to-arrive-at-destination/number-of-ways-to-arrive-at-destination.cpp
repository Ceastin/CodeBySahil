class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> v(n);

        for(auto it : roads)
        {
            v[it[0]].push_back({it[1],it[2]});
            v[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<
            vector<long long>,
            vector<vector<long long>>,
            greater<vector<long long>>
        > pq;

        pq.push({0,0});

        vector<long long> ans(n,LLONG_MAX);
        vector<long long> time(n);

        const int mod = 1e9+7;

        time[0] = 1;
        ans[0] = 0;

        while(!pq.empty())
        {
            long long dist = pq.top()[0];
            long long node = pq.top()[1];

            pq.pop();

            if(ans[node] < dist)
                continue;

            for(auto it : v[node])
            {
                long long nnode = it.first;
                long long add = dist + it.second;

                if(ans[nnode] > add)
                {
                    pq.push({add,nnode});

                    ans[nnode] = add;

                    time[nnode] = time[node];
                }
                else if(add == ans[nnode])
                {
                    time[nnode] =
                    (time[nnode] + time[node]) % mod;
                }
            }
        }

        return time.back() % mod;
    }
};