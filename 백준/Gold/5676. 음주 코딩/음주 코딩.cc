#include <iostream>

using namespace std;

int n,k;
int arr[100001];
int tree[400001];

void init(int node, int sta, int end){
    if(sta == end) tree[node] = arr[sta];
    else{
        int mid = (sta+end)/2;
        init(node*2, sta, mid);
        init(node*2+1, mid+1, end);    
        tree[node] = tree[node*2] * tree[node*2+1];
    }
}

void update(int node, int sta, int end, int index, int value){
    if(index > end || index < sta) {return ;}
    else if(sta == end) tree[node] = value;
    else {
        int mid = (sta+end)/2;
        update(node*2, sta,mid, index,value);
        update(node*2+1, mid+1, end, index,value);
        tree[node] = tree[node*2] * tree[node*2+1];
    }
}

int query(int node, int sta, int end, int l, int r){
    if(sta > r || end < l) return 1;
    if(l <= sta && end <= r) return tree[node];
    int mid = (sta+end)/2;
    return query(node*2, sta,mid,l,r) * query(node*2+1, mid+1, end, l,r);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(cin >> n >> k){
        int temp;
        for(int i =1;i<=n;i++){
            cin >> temp;
            if(temp == 0) arr[i] =0;
            else if(temp > 0) arr[i] = 1;
            else if(temp < 0) arr[i] = -1;
        }
        
        init(1,1,n);
        // for(int i =0;i<4*n;i++)cout << tree[i] << " ";
        // cout << '\n';
        
        char order;
        int a,b;
        while(k--){
            cin >> order >> a >> b;
            if(order == 'C'){
                if(b == 0) update(1,1,n,a,0);
                else if(b>0) update(1,1,n,a,1);
                else update(1,1,n,a,-1);
                // for(int i =0;i<4*n;i++)cout << tree[i] << " ";
                // cout << '\n';
            }
            else if(order == 'P'){
                int result = query(1,1,n,a,b);
                switch (result){
                    case 1:
                        cout << "+";break;
                    case -1:
                        cout << "-"; break;
                    case 0:
                        cout << 0;break;
                }
            }
        }
        cout << '\n';
    }
    
    return 0;
}