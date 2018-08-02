#include<iostream>
#include<cstdlib>
#include<pthread.h>
using namespace  std;
#define THREAD_NUM 5
void *sayhello(void * args)
{
int tid=*((int*)args);
cout<<"hello thread id:"<<tid<<endl;
pthread_exit(NULL);
}
int main()
{
pthread_t threads[THREAD_NUM];
//pthread_create()//create a new thread
int indexes[THREAD_NUM];
int rc;
int i;
for(i=0;i<THREAD_NUM;++i)
	{
		cout <<"main ()create thread"<<i<<endl;
		indexes[i]=i;
		rc=pthread_create(&threads[i],NULL,sayhello,(void*)&(indexes[i]));
		if(rc)
		{
			cout<<"pth_create err:err="<<rc<<endl;
			exit(-1);
		}


	}
 	pthread_exit(NULL);
}



