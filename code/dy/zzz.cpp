#include<iostream> 
#include<fstream>  
#include<string>  
#include<curl/curl.h>  
#include<jsoncpp/json/json.h>  

#include<stdio.h>
#include<string.h>
using namespace std;



int ParseJsonFromFile(const char* filename)
{
  // 解析json用Json::Reader
  Json::Reader reader;
  // Json::Value是一种很重要的类型，可以代表任意类型。如int, string, object, array...
  Json::Value root; 
	Json::Value::iterator iter; 
	//用来获取节点名
	Json::Value::Members members;       

 std::ifstream is;
is.open (filename, std::ios::binary );  


  if (reader.parse(is, root))
  {

	Json::Value val_parsed_text = root["merged_res"]["semantic_form"]["parsed_text"];
	Json::Value val_raw_text = root["merged_res"]["semantic_form"]["raw_text"];
	string parsed_text=val_parsed_text.asString();
	string raw_text=val_raw_text.asString();
    	

    int file_size = root["merged_res"]["semantic_form"]["results"].size();
 
    for(int i = 0; i < file_size; ++i)
    {
      Json::Value val_image = root["merged_res"]["semantic_form"]["results"];
      int image_size = val_image.size();
      for(int j = 0; j < image_size; ++j)
      {
        std::string type = val_image[j]["domain"].asString();
        std::string url = val_image[j]["intent"].asString();
	std::string date=val_image[j]["object"]["date"].asString();
//------------------
	cout <<"domain"<<"    "<<type<<endl;
	cout <<"intent"<<"    "<<url<<endl;
	cout <<"date"<<"     "<<date<<endl;
	cout <<"parsed_text"<<"    "<<parsed_text<<endl;
	cout <<"raw_text"<<"    "<<raw_text<<endl;
//------------------
      }
    }
  }
 //is.close();
  return 0;
}
int main ()
{

	 ParseJsonFromFile("test.json");
}

