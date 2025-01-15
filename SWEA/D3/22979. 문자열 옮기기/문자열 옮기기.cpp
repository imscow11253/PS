#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv){
    int test_case;
	int T;
    
    cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        string str;
        cin >> str; 
        int length = str.length();
        
        int oper_num;
        cin >> oper_num;
        
        int oper; long long result =0; 
        for(int i =0;i<oper_num;i++){
            cin >> oper;
            if(oper ==0) continue;
            int real_oper_num = oper%length;
            result = (real_oper_num + result) % length; 
        }

        if(result > 0){
            string prefix = str.substr(0,result);
            string suffix = str.substr(result);
            str = suffix + prefix;
        }
        else if(result < 0){
            result *= -1;
            string prefix = str.substr(0, length-result);
            string suffix = str.substr(length-result);
            str = suffix + prefix;
        }
        cout << str << '\n';
	}
	return 0;
}