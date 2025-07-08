#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
vector<pair<pair<int,int>, pair<int,int>>> lines;

int ccw(pair<int,int> point_1, pair<int,int> point_2, pair<int,int> point_3){
	
	long long result = (point_1.first * point_2.second) + (point_2.first * point_3.second) + (point_3.first * point_1.second);
	result -= (point_1.second * point_2.first) + (point_2.second * point_3.first) + (point_3.second * point_1.first);
	
	return (result <=0 ) ? (result == 0) ? 0 : -1 : 1;
}

bool check_cross(int index1, int index2){
    pair<int,int> points[4] = {lines[index1].first, lines[index1].second, lines[index2].first, lines[index2].second};
    
	int a = ccw(points[0], points[1], points[2]);
	int b = ccw(points[0], points[1], points[3]);
	int c = ccw(points[2], points[3], points[0]);
	int d = ccw(points[2], points[3], points[1]);
	
// 	if(index1 == 2 && index2 == 5) cout << a << " " << b << " " << c << " " << d << '\n';
	
	if(a*b <= 0 && c*d <= 0){
		if(a ==0 && b ==0 && c ==0 && d==0){
			// 두 선분이 평행하더라도 겹치는지 확인해야 한다.
			if(points[0].first == points[2].first){
			    if(points[0].second > points[1].second) swap(points[0], points[1]);    
			    if(points[2].second > points[3].second) swap(points[2], points[3]);
			    return (points[0].second <= points[3].second && points[2].second <= points[1].second);
			}
			if(points[0].first > points[1].first) swap(points[0], points[1]);
			if(points[2].first > points[3].first) swap(points[2], points[3]);
			return (points[0].first <= points[3].first && points[2].first <= points[1].first);
		}
		return 1;
	}
	return 0;
}

int _rank[3000] = {0,};
int parent[3000];

int find(int node){
    if(parent[node] == node) return node;
    
    parent[node] = find(parent[node]);
    return parent[node];
}

void _union(int node1, int node2){
    int parent1 = find(node1);
    int parent2 = find(node2);
    
    if(_rank[parent1] < _rank[parent2]) swap(parent1, parent2);
    
    parent[parent2] = parent1;
    _rank[parent1] += _rank[parent2];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    int p1,p2,p3,p4;
    for(int i =0;i<n;i++){
        cin >> p1 >> p2 >> p3 >> p4;
        lines.push_back({{p1,p2},{p3,p4}});
    }
    
    for(int i =0;i<n;i++) {parent[i] = i; _rank[i] = 1;}
    
    for(int i =0;i<n;i++){
        for(int j = i+1; j<n;j++){
            if(find(i) == find(j)) continue;
            bool temp = check_cross(i,j);
            // cout << "[" << i << ", " << j << "]\n";
            // cout << temp << '\n';
            if(temp){
                _union(i,j);
                // for(int k =0;k<n;k++) cout << _rank[k] << " "; cout << '\n';
            }
        }
    }
    
    for(int i = 0; i < n; i++) find(i);
    
    int num=0;
    int max_line =0;
    for(int i =0;i<n;i++){
        if(parent[i] == i) {num++; max_line = max(max_line, _rank[i]);}
    }
    
    cout << num << '\n' << max_line << '\n';
    
    return 0;
}