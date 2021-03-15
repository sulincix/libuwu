#!/usr/bin/env python3
from ctypes import *

libuwu = CDLL("libuwu.so")

libuwu.get_area.restype=c_char_p
libuwu.get_area.argtypes=[c_char_p,c_char_p]

def get_area(data,name):
    return libuwu.get_area(data.encode("utf-8"),name.encode("utf-8")).decode("utf-8")
    
libuwu.write_area.restype=c_char_p
libuwu.write_area.argtypes=[c_char_p,c_char_p]

def write_area(data,name):
    return libuwu.write_area(data.encode("utf-8"),name.encode("utf-8")).decode("utf-8")

libuwu.readlines.restype=c_char_p
libuwu.readlines.argtypes=[c_char_p]

def readlines(filename):
    return libuwu.readlines(filename.encode("utf-8")).decode("utf-8")

libuwu.get_node.restype=c_char_p
libuwu.get_node.argtypes=[c_char_p,c_char_p]
def get_node(data,path):
    return libuwu.get_node(data.encode("utf-8"),path.encode("utf-8")).decode("utf-8")

libuwu.del_areas.restype=c_char_p
libuwu.del_areas.argtypes=[c_char_p]

def del_areas(data):
    return libuwu.data(filename.encode("utf-8")).decode("utf-8")
    

