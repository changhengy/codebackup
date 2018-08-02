#include <iostream>
#include <cstdint>
#include "pugixml.hpp"
#include "pugiconfig.hpp"
#include <cstring>
#include <jsoncpp/json/json.h>  
#include <iostream>
#include <string>
#include<fstream>
#include<sstream>
using namespace std;

typedef Json::Reader JsonReader;
typedef Json::Value  JsonValue;


pugi::xml_node child_node_dd;
pugi::xml_node child_node;
pugi::xml_node object_node;
pugi::xml_node result_node;

int  print_json(JsonValue data)
{
JsonValue::Members mem = data.getMemberNames();
for (auto iter = mem.begin(); iter != mem.end(); iter++)
{
    //cout << *iter<< "\t: ";
    if (data[*iter].type() == Json::objectValue)
    {   
        print_json(data[*iter]);
    }   
    else if (data[*iter].type() == Json::arrayValue)
    {
        cout <<"数组"<<endl;
        auto cnt = data[*iter].size();
        cout<<cnt<<endl;
        for (auto i = 0; i !=cnt; i++)
        {
            
            cout<<*iter<<endl;
            string ll=data[*iter][i].asString();
            cout<<ll<<endl;
            object_node=child_node_dd.append_child((*iter).c_str());
            object_node.text().set(ll.c_str());  
            //print_json(data[*iter][i]);       
        }
    }
    else if (data[*iter].type() == Json::stringValue)
    {
        //cout<<*iter<<endl;
        string vava=data[*iter].asString() ;
        object_node=child_node_dd.append_child((*iter).c_str());
        object_node.text().set(vava.c_str());
        //cout<<vava<<endl;
    }
    else if (data[*iter].type() == Json::realValue)
    {
        cout << data[*iter].asDouble() << endl;
    }
    else if (data[*iter].type() == Json::uintValue)
    {
        cout << data[*iter].asUInt() << endl;
    }
    else
    {
        cout << data[*iter].asInt() << endl;
    }
}
return 0;
}

int json2xml( const string &filename)
{
    std::ostringstream oss;
    pugi::xml_document doc;
    //pugi::xml_node pre = doc;
    pugi::xml_node node = doc.append_child("event");
    node.append_attribute("name") = "asrResult";
    ifstream is;
    is.open (filename, std::ios::binary );  

    JsonReader reader;
    JsonValue temp;
    if(reader.parse(is, temp))       
    {
        
        Json::Value val_parsed_text = temp["merged_res"]["semantic_form"]["parsed_text"];
        Json::Value val_raw_text = temp["merged_res"]["semantic_form"]["raw_text"];
        string parsed_text=val_parsed_text.asString();
        string raw_text=val_raw_text.asString();
        //add parsed_text_node
        pugi::xml_node child_node = node.append_child("parsed_text");
        child_node.text().set(parsed_text.c_str());
        //add raw_text_node
        child_node = node.append_child("raw_text");
        child_node.text().set(raw_text.c_str());
        //add results_node
        pugi::xml_node result =node.append_child("results");

        int file_size = temp["merged_res"]["semantic_form"]["results"].size();
        //cout<<"result size "<<file_size<<endl;

        if(file_size!=0)
        {
            Json::Value val_image = temp["merged_res"]["semantic_form"]["results"];
            int image_size = val_image.size();
            for(int j = 0; j < image_size; ++j)
            {   
                pugi::xml_node result_node =result.append_child("result");
                std::string type = val_image[j]["domain"].asString();

                child_node = result_node.append_child("domain");
                child_node.text().set(type.c_str());

                std::string url = val_image[j]["intent"].asString();
                child_node = result_node.append_child("intent");

                child_node.text().set(url.c_str());
                double score=val_image[j]["score"].asDouble();
                child_node = result_node.append_child("score");
                
                child_node.text().set(score);
                
                JsonValue ob=val_image[j]["object"];
                
                child_node_dd = result_node.append_child("object");
                print_json(ob);
            }

            doc.print(oss);
            std::string docString = oss.str();
            cout <<    docString   << "          "<<endl;
            return 0;
        }
    }

}


int  main ()
{
    
    json2xml("test.json");
    return 0;
}




