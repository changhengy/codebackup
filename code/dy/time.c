#include<iostream>
#include<ctime>
using namespace std;
int main()
{
	time_t now=time(0);
	cout<< now<<endl;
	char *dt=ctime(&now);
	cout<<"time:"<<dt<<endl;
	return 0;

}
