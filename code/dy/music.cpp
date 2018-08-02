#include<iostream>  
#include<string>  
#include<curl/curl.h>  
#include<json/json.h>  
#include<fstream>  
#include<stdio.h>
#include<string.h>
#define filemax 2048  
#define CDN_num 1024  
using namespace std;
char* api_url;
size_t get_data(void*prt, size_t size, size_t nmemb, FILE * stream)
{
	size_t written = fwrite(prt, size, nmemb, stream);
	return written;
}

void get_cmd()
{
	cout << "you can input cmd" << endl;
	cout << "新歌榜    " << endl;
	cout << "热歌榜    " << endl;
	cout << "Hito中文榜   " << endl;
	cout << "KTV热歌榜 " << endl;
	cout << "电台列表   " << endl;
	cout << "获取某个电台下的歌曲列表  " << endl;
	cout << "获取songid的歌曲信息" << endl;
	cout << "歌手列表" << endl;
	cout << "新歌速递" << endl;
	int cmd;
	cin >> cmd;
	switch (cmd)
	{
	case 1:
	{
		api_url = "http://tingapi.ting.baidu.com/v1/restserver/ting?from=qianqian&version=2.1.0&method=baidu.ting.billboard.billList&format=json&type=2&offset=0&size=3";
		break;}
	case 2: {
		api_url = "http://tingapi.ting.baidu.com/v1/restserver/ting?from=qianqian&version=2.1.0&method=baidu.ting.billboard.billList&format=json&type=1&offset=0&size=50";
		break;
	}

	case 3:
	{
		api_url = "http://tingapi.ting.baidu.com/v1/restserver/ting?from=qianqian&version=2.1.0&method=baidu.ting.billboard.billList&format=json&type=6&offset=0&size=50";
		break;
	}
	default:
		break;
	}
}

void jsonjiexi()
{FILE* fp;
//  api_url= strcat(s1,query);

cout << api_url << endl;
CURLcode res;
CURL* curl = curl_easy_init();

char outfile[filemax] = "Temp.json";
fp = fopen(outfile, "wb");
curl_easy_setopt(curl, CURLOPT_URL, api_url);
curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, get_data);
curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
res = curl_easy_perform(curl);
if (res != CURLE_OK)
{
	perror("Curl error");
	return 1;
}
curl_easy_cleanup(curl);
fclose(fp);
std::ifstream ifs;

ifs.open("Temp.json");

Json::Reader reader;
Json::Value root;
if (!reader.parse(ifs, root, false))
{
	return -1;
}

Json::Value add_value = root["song_list"];
for (int i = 0; i < add_value.size(); ++i)
{
	Json::Value temp_value = add_value[i];
	std::string strName = temp_value["title"].asString();
	std::string intName = temp_value["song_id"].asString();
	std::cout << "name: " << strName << "id" << intName << std::endl;

	// use value array[index]
	//Json::Value temp_value = add_value[i];
	//std::string strName = add_value[i]["name"].asString();
	//std::string strMail = add_value[i]["email"].asString();
	//std::cout << "name: " << strName << " email: " << strMail << std::endl;
}
}


void jsonjiexjiei()
{
	FILE* fp;
	//  api_url= strcat(s1,query);

	cout << api_url << endl;
	CURLcode res;
	CURL* curl = curl_easy_init();

	char outfile[filemax] = "temp.json";
	fp = fopen(outfile, "wb");
	curl_easy_setopt(curl, CURLOPT_URL, api_url);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, get_data);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
	res = curl_easy_perform(curl);
	if (res != CURLE_OK)
	{
		perror("Curl error");
		return 1;
	}
	curl_easy_cleanup(curl);
	fclose(fp);
	std::ifstream ifs;

	ifs.open("temp.json");

	Json::Reader reader;
	Json::Value root;
	if (!reader.parse(ifs, root, false))
	{
		return -1;
	}

	Json::Value add_value = root["songurl"];
	for (int i = 0; i < add_value.size(); ++i)
	{
		Json::Value temp_value = add_value[i];
		std::string strName = temp_value["show_link"].asString();
		//std::string intName = temp_value["song_id"].asString();
		std::cout << "name: " << strName << std::endl;

		// use value array[index]"id" << intName << 
		//Json::Value temp_value = add_value[i];
		//std::string strName = add_value[i]["name"].asString();
		//std::string strMail = add_value[i]["email"].asString();
		//std::cout << "name: " << strName << " email: " << strMail << std::endl;
	}
}









int main()
{
	//char* api_url;



	get_cmd();
	jsonjiexi();
	//string song_name();
	string  song_id;
	cin >> song_id;
	string haha = "http://tingapi.ting.baidu.com/v1/restserver/ting?from=qianqian&version=2.1.0&method=baidu.ting.song.getInfos&format=json&ts=1408284347323&e=JoN56kTXnnbEpd9MVczkYJCSx%2FE1mkLx%2BPMIkTcOEu4%3D&nw=2&ucf=1&res=1&songid="
	

		api_url = (haha + song_id).c_str;
	jsonjiexi();


	//char s1[256] = "http://tingapi.ting.baidu.com/v1/restserver/ting?from=qianqian&version=2.1.0&method=baidu.ting.search.catutfalogSug&format=json&query=";

	//cin  query << endl;
	//char *query = "%E5%B0%8F%E8%8B%B9%E6%9E%9C";

	

	/*for (Json::Value::iterator idx = root.begin();idx != root.end();idx++)
	{
	if(!(*idx))
	cout<<"nonono"<<endl;
	//cout<<root[i].size()<<endl;

	for(int j = 0; j < root[i].size(); j++)
	{
	if(!root[i])
	cout<<"111"<<endl;
	if(!root[i][j])
	cout<<"222"<<endl;
	cout << root[i][j]["songname"].asString() << endl;
	j++;
	}


	i++;
	}

	*/

	return 0;
}
