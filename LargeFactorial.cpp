#include<bits/stdc++.h>
#define mx 500

using namespace std;


int multiply(int x, int res[], int res_size){
    int carry = 0;  // Initialize carry

    // One by one multiply n with individual digits of res[]
    for (int i=0; i<res_size; i++){
        int prod = res[i] * x + carry;

        // Store last digit of 'prod' in res[]
        res[i] = prod % 10;

        // Put rest in carry
        carry  = prod/10;
    }

    // Put carry in res and increase result size
    while (carry){
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

string factorial(int n){
    int res[mx];
    res[0]=1;
    int res_size=1;

    for(int x=2; x<=n; x++)
        res_size=multiply(x,res,res_size);

    ///storing factorial in a string;
    string fact="";
    for(int i=res_size-1; i>=0; i--){
        stringstream ss;
        ss<<res[i];
        string s;
        ss>>s;
        fact+=s;
    }
    return fact;
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        cout<<factorial(n)<<endl;
    }
return 0;
}
