#!/usr/bin/python
# -*- coding: UTF-8 -*- 

import sys 
import os
#脚本说明：
# note: what this script can do 
# input: project name, xml name
#输入： 工程名，后期加入xml名
# output:
#输出：测试list

# project name
str17cyplus_t1t2plus_navi = "17cyplus_t1t2plus_navi"

# manifest xml name
manifestXmlPath = '/home/mengfanbing/Workplace/17Cy/17cyplus_t1t2plus/.repo/manifests/navi.xml'
manifestXmlPath2 = '/home/mengfanbing/Workplace/17Cy/17cyplus_t1t2plus/.repo/manifests/default.xml'
tuple_17cyplus_t1t2plus =(manifestXmlPath,manifestXmlPath2)


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



for i in range(1, len(sys.argv)):

    print "参数", i, sys.argv[i]

xml_file_path = "tuple_"+ os.getcwd()
print
strname = ''
strname = 'tuple_'+sys.argv[1]
print strname
if strname == 'tuple_17cyplus_t1t2plus':
	
	print "good"

print 
print
print xml_file_path

if __name__ == "__main__":
	projectName = sys.argv[1]
	xmlName = sys.argv[2]

	ret = genLocalPath(projectName)
	


