#include <bits/stdc++.h>

using namespace std;

int max(int a, int b){
    if(a < b){
        return b;
    }
    return a;
}

int coin_row(vector<int>& coins, stack<int>& parents){ 
    vector<int> results(coins.size());
    results[0] = 0;
    results[1] = coins[1];

    for(int i = 2; i < coins.size(); i++){
        results[i] = max(coins[i] + results[i - 2], results[i - 1]);
       // cout<<results[i]<<endl;
    }
    
    int cnt = coins.size() -1;
    while(cnt >= 0){
        if(results[cnt] != results[cnt - 1]){
            //cout<<results[cnt]<< "ta"<<endl;
            parents.push(coins[cnt]);
            cnt = cnt - 2;
        }
        else{
            //cout<<results[cnt]<< "tb"<<endl;
            cnt = cnt - 1;
        }
    }
    return results[coins.size() - 1];
}

int main(){
    int cases;
    cin>>cases;
    for(int i = 0; i < cases; i++){
        int numCoins;
        cin>>numCoins;

        vector<int> coins(numCoins + 1);
        coins[0] = 0;
        for(int j = 1; j < numCoins + 1; j++){
            int value;
            cin>> value;
            coins[j] = value;
        }
        stack<int> parents;
        cout<<"Caso "<< i + 1<<": ";
        coin_row(coins,parents);
        int aux = parents.size();
        if(coins.size() > 1){

        for(int i = 0; i < aux; i++){
            if(i < aux -1){
            cout<< parents.top()<< "+";
            parents.pop();    
            }
            else{
                cout<< parents.top()<< "=";
                parents.pop();
            }
        }
        
            cout<<coin_row(coins, parents)<< endl;    
        }

        else if(coins.size() > 0){
            cout<< coins[0]<<"="<<coins[0];
        }
        else{
            cout<< 0<<"="<<0<<endl;
        }
    }
}