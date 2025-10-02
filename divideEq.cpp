#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        
        unordered_map<int,int>fac;

        for(auto num : a){
            if(num != 1){
                for(int i=2;i*i<=num;i++){
                    while(num%i == 0){
                        fac[i]++;
                        num /= i;
                    }
                }
                if(num > 1) fac[num]++;
            }
        }
        bool flag = true;
        for(auto it : fac){
            if(it.second%n != 0){
                flag = false;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
}