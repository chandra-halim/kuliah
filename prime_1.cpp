#include <bits/stdc++.h>
using namespace std;
#define MX 2000005

int main(){
	int prime[MX];
	memset(prime, 0, sizeof(prime));
	prime[0]=1;
	prime[1]=1;
	for(int i=2; i<=5000; i++){
		if(prime[i]==0){
			cout<<i<<'\n';
			for(int j=i*i; j<=MX; j+=i){
				prime[j] = 1;
			}
		}
	}	
	int counter = 0;
	int i;
	int a = 1000000;
	int b = 2000000;
	for(int i=a; i<b; i++){
		if(prime[i]==0) counter++;
	}
	cout<<"There are "<<counter<<" prime number\n";
}
