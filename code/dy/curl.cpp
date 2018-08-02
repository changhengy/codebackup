//
//g++ demo.c   -std=c++11 -lcurl -ljson
//
#include<iostream>  
#include<string>  
#include<curl/curl.h>  
#include<jsoncpp/json/json.h>  
#include<fstream>  
#include<stdio.h>
#include<string.h>
#define filemax 2048  
#define CDN_num 1024  
using namespace std;
char* api_url;
char* download_url;

size_t get_data(void*prt, size_t size, size_t nmemb, FILE * stream)
{
 size_t written = fwrite(prt, size, nmemb, stream);
 return written;
}

int download()
{
 FILE* fp;
 cout << download_url << endl;
 CURLcode res;
 CURL* curl = curl_easy_init();

 char outfile[filemax] = "Temp.mp3";
 fp = fopen(outfile, "wb");
 curl_easy_setopt(curl, CURLOPT_URL, download_url);
 curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, get_data);
 curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
 res = curl_easy_perform(curl);
 if (res != CURLE_OK)
 {
  perror("Curl error");
  return 0;
 }
 curl_easy_cleanup(curl);
 fclose(fp);
}


void get_name()
{
 
}

int json_parsing1()
{
 cout<<"请输入歌曲或者歌手名"<<endl;
 FILE* fp;
 string  songname;
 cin >> songname;
 string url_temp = "http://tingapi.ting.baidu.com/v1/restserver/ting?from=android&version=5.6.5.0&method=baidu.ting.search.catalogSug&format=json&query=";
 string song_url = url_temp + songname;
 cout<<song_url<<endl;
 //string song_url;
 api_url = const_cast<char*>(song_url.c_str());
 cout << api_url << endl;
 CURLcode res;
 CURL* curl = curl_easy_init();
cout<<api_url<<endl;
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


int json_parsing2()
{
 string  song_id;
 cout <<"请输入歌曲id："<<endl;
 cin >> song_id;
 string song_id_url_temp = "http://tingapi.ting.baidu.com/v1/restserver/ting?format=jsonl&calback=&from=webapp_music&method=baidu.ting.song.play&songid=";
 string song_id_url = song_id_url_temp + song_id;
 api_url = const_cast<char*>(song_id_url.c_str());
 FILE* fp;
 cout << api_url << endl;
 CURLcode res;
 CURL* curl = curl_easy_init();
 cout << api_url <<"00000000000000000"<< endl;
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
 cout<<"文件内的json应该是对的，等会查一下"<<endl;
 
 std::ifstream ifs;

 ifs.open("temp.json");

 Json::Reader reader;
 Json::Value root;
//ifstream is;

//is.open (filename, std::ios::binary);
 
 if(reader.parse(ifs,root))
{

Json::Value val_songinfo = root["bitrate"];
int songinfo_size = val_songinfo.size();
string download_url;
for(int i = 0;i< songinfo_size;++i)
{
download_url = val_songinfo["show_link"].asString();

}

cout<<"download_url: "<<download_url<<endl;
}
download();
}

int main()
{
 get_name();
 json_parsing1();

 json_parsing2();
 return 0;
}
