#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    long long a, b;
    cin >> a >> b;

    string sum = to_string(a + b);
    int sign = (sum[0] == '-') ? 1 : 0;
    string result;

    for(int i = sum.size() - 1; i >= sign; i--){
        if(i < sum.size()-1 && (sum.size()-i) % 3 == 1){
            result += ',';
        }
        result += sum[i];
    }

    if(sign == 1) result += '-';

    for(int i = result.size() - 1; i >= 0; i--){
        cout << result[i];
    }
}