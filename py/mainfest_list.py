#!/usr/bin/python
# -*- coding: UTF-8 -*- 

import sys 
import os
from xml.dom.minidom import parse
import xml.dom.minidom

#脚本说明：
# note: what this script can do 
# input: project name, xml name
#输入： 工程名，后期加入xml名
# output:
#输出：测试list

# project name
str17cyplus_t1t2plus_navi = "17cyplus_t1t2plus_navi"

# manifest xml name
manifestXmlPath = '/home/chy/WorkPlace/17Cy/.repo/manifests/navi.xml'
manifestXmlPath2 = '/home/chy/WorkPlace/17Cy/.repo/manifests/default.xml'
tuple_17cyplus_t1t2plus   =(manifestXmlPath,manifestXmlPath2)
#tuple_17cyplus_t1t2plus  =  (manifestXmlPath,)

manifestMap = {}
manifestMap[str17cyplus_t1t2plus_navi] = tuple_17cyplus_t1t2plus


print tuple_17cyplus_t1t2plus
print tuple_17cyplus_t1t2plus[0]
print tuple_17cyplus_t1t2plus[1]


print "脚本名：", sys.argv[0]



def genLocalPath(projectName):
    if not manifestMap.has_key(projectName):
        print ("wrong projectName!")
        exit(1)

    manifestList = manifestMap[projectName]
    remoteNameAndNativePathMap = {}
    
    for i in range(1, len(sys.argv)):
        print "参数", i, sys.argv[i]

    for xmlFile in manifestList:
        DOMTree = xml.dom.minidom.parse(xmlFile)
        collection = DOMTree.documentElement
        i = 0
          
        defaults = collection.getElementsByTagName("default")
        for  default in defaults:
            default_strremote = ''
            if default.hasAttribute("remote"):
                default_strremote = default.getAttribute("remote")

        projects = collection.getElementsByTagName("project")
        for project in projects:
            strName = ''
            strPath = ''
            strremote = ''
            if project.hasAttribute("name"):
                strName = project.getAttribute("name")
                #print ("name: %s" % (strName))
            else:
                print ("project do not have name attribute!")
                exit(0)

            if project.hasAttribute("path"):
                strPath = project.getAttribute("path")
                #print ("path: %s" % (strPath))
            
            if project.hasAttribute("remote"):
                strremote = project.getAttribute("remote")
            else:
                strremote = default_strremote
            
            if strPath == "" and strName != "":
                print "name : [%s] do not have native path"
                strPath = strName

            remoteNameAndNativePathMap[strName] = [strPath,strremote]
          
    b = len(remoteNameAndNativePathMap)
    print b
    remoteNameAndNativePathMap.items()
    #return remoteNameAndNativePathMap.keys()
    return remoteNameAndNativePathMap

    


if __name__ == "__main__":
	projectName = sys.argv[1]
	#xmlName = sys.argv[2]
    #ret = {}
	ret = genLocalPath(projectName)
	print ret
     

