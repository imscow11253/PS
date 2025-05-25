#include <iostream>

using namespace std;

int a,b,c;
int b_ticket, c_ticket;
int level;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> a >> b >> c;
    cin >> b_ticket >> c_ticket;
    cin >> level;
    
    int minute=0;
    int upgrade=0;
    while(level < 250){
       if(c_ticket > 0){
           for(int i =1;i<=30;i++){
               upgrade += c;
               minute++;
               if(upgrade >= 100){
                   upgrade -= 100;
                   level++;
                   if(level >= 250){
                       cout << minute;
                       exit(0);
                   }
               }
           }
           c_ticket--;
           continue;
       } 
       if(b_ticket > 0){
           for(int i =1;i<=30;i++){
               upgrade += b;
               minute++;
               if(upgrade >= 100){
                   upgrade -= 100;
                   level++;
                   if(level >= 250){
                       cout << minute;
                       exit(0);
                   }
               }
           }
           b_ticket--;
        //   cout << minute << '\n';
           continue;
       } 
       upgrade += a;
       minute++;
       if(upgrade >= 100){
           upgrade -= 100;
           level++;
           if(level >= 250){
               cout << minute;
               exit(0);
           }
       }
    }
    
    return 0;
}