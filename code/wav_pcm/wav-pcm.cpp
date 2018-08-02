#include<iostream>
#include<fstream>
#include<stdlib.h>
#include <unistd.h>
using namespace std;
string wav_filename;
int getwav()
{
	//string wav_filename;
	cout<<"please input filepath"<<endl;
	cin>>wav_filename;
	return 0;
	
}
int main ()
{	
	size_t result;
	char  *buf;
	//string wav_filename;
	//cout<<"please input filepath"<<endl;
	//cin>>wav_filename;
	//char* wavtemp=const_cast<char*>(wav_filename.c_str());
	getwav();
	FILE *fp1=fopen(wav_filename.c_str(),"rb");
	FILE *fp2=fopen("awake.pcm","wb");
	if(fp1==NULL||fp2==NULL)//判断两个文件指针是否存	
		{
			cout<<"file open filed!!"<<endl;
		cout<<"again"<<endl;
		getwav();
		}
	else
		cout<<"wav文件打开成功，pcm文件创建成功"<<endl;
	fseek(fp1,0,SEEK_END);//把fp1后移到文件的末尾
	long filesize;
	filesize=ftell(fp1);//求文件大小
	cout<<"wav filesize:"<<filesize<<endl;
		
	rewind(fp1);//还原fp1指针位置
	fseek(fp1,44,SEEK_SET);//把fp1后移44字节
	buf=(char *)malloc(sizeof(char)*filesize);//开辟虚拟空间，用作缓存
	result =fread(buf,1,(filesize-44),fp1);
	if(buf==NULL)
	{
			printf ("memory  error");
			return 0;
	}
		if(result!=filesize-44)
		cout<<"reing error!!"<<endl;
		else
			cout<<"写文件结束"<<endl;
		
	fwrite(buf,1,(filesize-44),fp2);
//	memcpy(fp2,fp1,(filesize-44));
//	fgets(buf,filesize,fp1);
//	fputs(buf,fp2);
	long filesize2;
	fseek(fp2,0,SEEK_END);
	filesize2=ftell(fp2);
	cout<<"pcm filesize:"<<filesize2<<endl;
	if(filesize-filesize2==44)
		cout<<"文件切割成功"<<endl;
	else
		cout<<"文件切割失败"<<endl;
	fclose(fp1);
	fclose(fp2);
	free (buf);
	return 0 ;

}

