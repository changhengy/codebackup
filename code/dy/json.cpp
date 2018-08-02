#include<iostream>  
#include<string>  
#include<curl/curl.h>  
#include<jsoncpp/json/json.h>  
#include<fstream>  
#define filemax 2048  
#define CDN_num 1024  
using namespace std;  
size_t get_data(void*prt,size_t size, size_t nmemb, FILE * stream)  
{  
        size_t written = fwrite(prt,size,nmemb,stream);  
            return written;  
}  
  
  
struct CDN_Info  
{  
    string name;  
    string IP;  
    string APP;  
    string StreamName;  
    int Link_num;  
};  
  
int main()  
{  
	cout<<"请输入歌曲或者歌手名"<<endl;
    CDN_Info CDN_Mess[CDN_num];  
    int i=0;  
    FILE* fp;  
	const char* api_url="http://tingapi.ting.baidu.com/v1/restserver/ting?from=qianqian&version=2.1.0&method=baidu.ting.search.catalogSug&format=json&query=thriller";  
    CURLcode res;  
    CURL* curl=curl_easy_init();  
    char outfile[filemax]="Temp.json";  
    fp = fopen(outfile,"wb");  
    curl_easy_setopt(curl,CURLOPT_URL,api_url);  
    curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,get_data);  
    curl_easy_setopt(curl,CURLOPT_WRITEDATA,fp);  
    res=curl_easy_perform(curl);  
    if (res!=CURLE_OK)  
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

 Json::Value add_value = root["song"];
 for (int i = 0; i < add_value.size(); ++i)
 {
  Json::Value temp_value = add_value[i];
  std::string strName = temp_value["songname"].asString();
  std::string intName = temp_value["songid"].asString();
  std::string iggName = temp_value["artistname"].asString();
  std::cout << "name: " << strName << "id" << intName << "artistname" << iggName << std::endl;
 }
} 
