#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#include <libxml/parser.h>  
#include<iostream>
using namespace std;

  
 static char* config ="<event>"
"<id>"
"10"
"</id>"
"<name>"
"lc"
"</name>"
"<source>"
"..."
"</source>"
"</event> ";
 
 // "<root><intent>start_Vr</intent><node2 >resources</node2><source>kkkkkkk</source></root>"; 
 
  
static int  parseDoc() {  
    xmlDocPtr doc;  
   doc = xmlReadMemory(config, strlen(config), "in_memory.xml", NULL, 0); 
    //xmlKeepBlanksDefault(0);  
  
 
xmlKeepBlanksDefault(0);  
    //doc = xmlParseFile(docname);  
   xmlNodePtr cur;  
    if(doc == NULL) {  
        fprintf(stderr, "doc error!\n");  
        return 0;  
    }  
  
    cur = xmlDocGetRootElement(doc);  
  
    if(cur == NULL) {  
        fprintf(stderr, "root error!\n");  
        xmlFreeDoc(doc);  
        return 0;  
    }  
  
    if(xmlStrcmp(cur->name, (const xmlChar*)"event")) {  
        printf("end\n");  
        return 0;  
    }  
  
    cur = cur->children;  
    while(cur != NULL) {  
        printf("name=%s content=%s\n",cur->name,   
                (char*)xmlNodeGetContent(cur));  
                //cur->content);  strcmp()
                if (xmlStrcmp(cur->name,(const xmlChar*)"id")==0)
                {
					string event_id=(char*)xmlNodeGetContent(cur);
					cout<<"event_id"<<"   =  "<<event_id<<endl;
				}
				else if(xmlStrcmp(cur->name,(const xmlChar*)"name")==0)
				{
					string event_name=(char*)xmlNodeGetContent(cur);
					cout <<"event_name"<<"   =     "<<event_name<<endl;
				}
                else
                    ;
        cur = cur->next;  
    }  
    xmlFreeDoc(doc);  
    return 0;  
}  
  
int main() {  
    //char* docname = "story.xml";  
    parseDoc();  
    return 1;  
}  
/*/*bool parseDoc()
		 {  const char* config ="xml_event.c_str()";
			bool flag = false;
			xmlDocPtr doc;  
		    doc = xmlReadMemory(config, strlen(config), "in_memory.xml", NULL, 0); 
			//xmlKeepBlanksDefault(0);  
			xmlKeepBlanksDefault(0);  
			//doc = xmlParseFile(docname);  
		    xmlNodePtr cur;  
			if(doc == NULL) {  
				fprintf(stderr, "doc error!\n");  
				return 0;  
			}  
		  
			cur = xmlDocGetRootElement(doc);  
		  
			if(cur == NULL) {  
				fprintf(stderr, "event error!\n");  
				xmlFreeDoc(doc);  
				return 0;  
			}  
		  
			if(xmlStrcmp(cur->name, (const xmlChar*)"event")) {  
				printf("end\n");  
				return 0;  
			}  
		  
			cur = cur->children;
			while (cur != NULL) {
				printf("name=%s content=%s\n", cur->name,
					(char*)xmlNodeGetContent(cur));
				//cur->content);  strcmp()
				if (xmlStrcmp(cur->name, (const xmlChar*)"id") == 0)
				{
					string event_id = (char*)xmlNodeGetContent(cur);
					cout << "event_id" << "   =  " << event_id << endl;
					xml_intent = event_id;
				}
				else if (xmlStrcmp(cur->name, (const xmlChar*)"name") == 0)
				{
					string event_name = (char*)xmlNodeGetContent(cur);
					cout << "event_name" << "   =    " << event_name << endl;
				}
				else;
				cur = cur->next;
			}
			xmlFreeDoc(doc);
			return 0;
			if (xml_intent.c_str != NULL)
				return true;

		} */
