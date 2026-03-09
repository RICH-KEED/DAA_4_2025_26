#include<iostream>
#include<vector>
using namespace std;


int fib(int n, vector<int>& results)
{
    if(results[n]!=-1) return results[n];
    return results[n]=fib(n-1,results)+fib(n-2,results);
}
int main()
{
    int n;
    cin>>n;

    vector<int> results(n+1,-1);
    results[0]=1;
    results[1]=1;
    cout<<fib(n,results);

}