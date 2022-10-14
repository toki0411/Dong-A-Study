#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정
using namespace std;
int map[201][201];
vector<pair<int, int> > graph[100001];
vector<int> v;
int d[100001];
int route[100001];
int n,m;
int a,b,c;
void dijkstra(int start) {
    priority_queue<pair<int, int> > pq;
    // 시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
    pq.push({ 0, start });
    d[start] = 0;
    while (!pq.empty()) { // 큐가 비어있지 않다면
        // 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
        int dist = -pq.top().first; // 현재 노드까지의 비용
        int now = pq.top().second; // 현재 노드
        pq.pop();
        // 현재 노드가 이미 처리된 적이 있는 노드라면 무시
        if (d[now] < dist) continue;
        // 현재 노드와 연결된 다른 인접한 노드들을 확인
        for (int i = 0; i < graph[now].size(); i++) {
            int cost = dist + graph[now][i].second;
            // 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
            if (cost < d[graph[now][i].first]) {
                d[graph[now][i].first] = cost;
                route[graph[now][i].first] = now;//nxt로 가는 최단경로는 직전에 now를 거친다. *
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("path.inp","r",stdin);
    freopen("path.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int k=0;k<m;k++){
            cin>>map[i][k];
            if(map[i][k]==-1)map[i][k]=INF;
        }
    }
    int cnt = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j+1<m){
                a = cnt; b = i*m+(j+1); c = map[i][j+1];
                graph[a].push_back({b,c});
            }
            if(i+1<n){
                a= cnt;b = (i+1)*m+j; c = map[i+1][j];
                graph[a].push_back({b,c});
            }
            cnt++;
        }
    }
    // 최단 거리 테이블을 모두 무한으로 초기화
    fill(d, d + 100001, INF);
    
    // 다익스트라 알고리즘을 수행
    dijkstra(0);
    int goal = (n-1)*m+(m-1);
    // 도달할 수 없는 경우, 무한(INFINITY)이라고 출력
    if (d[goal] == INF) {
        cout << "No path."; return 0;
        
    }
    // 도달할 수 있는 경우 거리를 출력
    else {
        cout << d[goal]+map[0][0] << '\n';
    }
    int idx = goal;
    while (idx != 0) {
        v.push_back(idx);
        idx = route[idx];
    }
    v.push_back(idx);//출발경로도 추가.
    for (int i = v.size()-1; i >= 0; i--) {//도착지>출발지 경로를 저장했으므로
        cout << '('<<v[i]/m<<' '<<v[i]-(v[i]/m)*m<<')'<< "\n";         //거꾸로 출력해 출발> 도착지의 경로를 출력한다.
    }
}
