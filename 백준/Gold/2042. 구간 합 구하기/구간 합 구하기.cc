#include <iostream>

using namespace std;

typedef long long ll;

int n,m,k;
ll arr[1000001];
ll tree[4000001];

ll init(int node, int sta, int end){
    if(sta>=end) tree[node] = arr[sta];
    else{
        ll mid = (sta+end)/2;
        tree[node] = init(2*node, sta, mid) + init(2*node+1, mid+1, end);
    }
    return tree[node];
}

ll update(int node, int sta, int end, int index, ll value){
    if(index > end || index < sta) {}
    else if(sta >= end) tree[node] = value;
    else{
        ll mid = (sta+end)/2;
        tree[node] = update(2*node, sta, mid, index, value) + update(2*node+1, mid+1, end, index, value);
    }
    return tree[node];
}

ll query(int node, int sta, int end, int l, int r){
    if(l > end || r < sta) return 0 ;
    if(sta >= l && end <= r) return tree[node];
    else{
        int mid = (sta+end)/2;
        return query(node*2, sta, mid, l, r) + query(node*2+1, mid+1, end, l ,r);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> k;
    for(int i =1;i<=n;i++){
        cin >> arr[i];
    }
    
    init(1,1,n);
    
    // for(int i =0;i<4*n;i++){
    //     cout << tree[i] << " ";
    // }cout << '\n';
    
    ll a,b,c;
    for(int i=0;i<m+k;i++){
        cin >> a >> b >> c;
        if(a ==1){
            update(1,1,n,b,c);
        }
        else if(a == 2){
            cout << query(1,1,n, b,c) << '\n';
        }
    }
    
    return 0;
}