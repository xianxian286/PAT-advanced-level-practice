//已AC
#include<iostream>
#include<vector>
using namespace std;
int main(){
//dp[i]表示从起始点到Ci的最短距离
//team[i]表示能集结的最大队伍数量
//用邻接表存每座城市的邻居城市
//边界条件，起点C1的距离为0，dp[C1] = 0
    vector<pair<int, int>> roads[1001];
    int rescue[1001], dp[1001], ways[1001];
    int N, M, C1, C2;
    cin >> N >> M >> C1 >> C2;

    for(int i = 0; i < N; i++) cin >> rescue[i];

    for(int i = 0; i < M; i++){
        int c1, c2, L;
        cin >> c1 >> c2 >> L;
        roads[c1].push_back({c2, L});
        roads[c2].push_back({c1, L});
    }

    int teams[1001];
    for(int i = 0; i < N; i++){
        dp[i] = 1e9;
        teams[i] = 0;
        ways[i] = 0;
    }
    dp[C1] = 0;
    teams[C1] = rescue[C1];
    ways[C1] = 1;

    bool visited[1001] = {false};
    
    for(int i = 0; i < N; i++){
        int city = -1;

        for(int j = 0; j < N; j++){
            if(!visited[j] && (city == -1 || dp[j] < dp[city])){
                city = j;
            }
        }

        if(city == -1 || dp[city] == 1e9) break;

        visited[city] = true;

        for(int j = 0; j < roads[city].size(); j++){
            int nextCity = roads[city][j].first;
            int distance = roads[city][j].second;
            if(dp[city] + distance < dp[nextCity]){
                dp[nextCity] = dp[city] + distance;
                ways[nextCity] = ways[city];
                teams[nextCity] = teams[city] + rescue[nextCity];
            }else if(dp[city] + distance == dp[nextCity]){
                ways[nextCity] += ways[city];

                int candidateTeams = teams[city] + rescue[nextCity];
                if (candidateTeams > teams[nextCity]) {
                    teams[nextCity] = candidateTeams;
                }
            }
        }
    }

    cout << ways[C2] << " " << teams[C2];
}