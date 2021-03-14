#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;
#define MX 2000005
#define NUM_THREADS 4
typedef struct thread{
	int a;
	int b;
	int result;
} thread_data;

void * myThread(void * arg){
	thread_data * data = (thread_data *) arg;
	int a = data -> a;
	int b = data -> b;
	int result = a + b;
	
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
	
	for(int i=a; i<b; i++){
		if(prime[i]==0) counter++;
	}
	result = counter;
	data -> result = result;
	pthread_exit(NULL);
}

int main(){
	clock_t t;
	t = clock();
	pthread_t tid[NUM_THREADS];
	thread_data data[NUM_THREADS];
	int a = 1e6;
	int b = 2e6;
	int interval = (b-a) / NUM_THREADS;
	int cnt = 0;
	int i;
	for(int i=0; i<NUM_THREADS; i++){
		data[i].a = a + interval * i;
		data[i].b = a + interval * (i+1);
	}
	for(int i=0; i<NUM_THREADS; i++){
		cout<<"Creating Thread "<<i<<"\n";
		pthread_create(& tid[i], NULL, myThread, (void *) & data[i]);
	}
	for(int i=0; i<NUM_THREADS; i++){
		pthread_join(tid[i], NULL);
		cout<<"result: "<<data[i].result<<'\n';
		cnt+= data[i].result;
	}
	cout<<"There are "<<cnt<<" prime number\n";
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	cout<<"Took "<<time_taken<<"seconds to execute\n";
	pthread_exit(NULL);
}
