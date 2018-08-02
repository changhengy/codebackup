#include<iostream>
#include<pthread.h>
using namespace  std;
#define THREAD_NUM 5
void *say(void * args)
{
cout<<"hello"<<endl;
return 0 ;
}
int main()
{
pthread_t tids[THREAD_NUM];
//pthread_create()//create a new thread
for(int i=0;i<THREAD_NUM;++i)
	{
		int ret=pthread_create(&tids[i],NULL,say,NULL);
		if(ret!=0)
		{
			cout<<"pth_create err:err="<<ret<<endl;
		}

	}
 	pthread_exit(NULL);
}



