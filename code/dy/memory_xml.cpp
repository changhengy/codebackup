
#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#include <libxml/parser.h>  
  

static char* config ="xml_event.c_str()";
bool flag = false;
static int  parseDoc()
 {  
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
  
    if(xmlStrcmp(cur->name, (const xmlChar*)"root")) {  
        printf("end\n");  
        return 0;  
    }  
  
    cur = cur->children;  
    while(cur != NULL) {  
        printf("%s= %s\n",cur->name,   
                (char*)xmlNodeGetContent(cur));  
                //cur->content);  
                char *xml_result=(char*)xmlNodeGetContent(cur);
                if (xml_result==start_VR)
                flag=true;
        cur = cur->next;  
    }  
    xmlFreeDoc(doc);  
    return 0;  
}  
parseDoc(); 

     
  
