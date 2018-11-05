# -*- coding: utf-8 -*-
"""
Created on Sun Nov  4 18:18:42 2018

@author: kkvamshee
"""
"""
A string which consists if numeric characters, "#" and paranthesis is given.
Each numeric character represents an alphabet. example: "a" for 1, "b" for 2, "c" for 3....
To avoid the case of overlapping, characters >= "j" are decoded as 10# or r"\d\d#" format.
Also to decrease the length of encoded string, if a continuous substing has all same characters, frequency of chaarcters
is added in brackets. example: substring "aaaaa" is decoded as 1(5) and "kkkkk" as 11#(5).

Given an already encoded string, we have to find frequencies of each character in the original string.
"""


import re

s = input()
s = s.replace('(', '!')
s = s.replace('(', '@')
result = [0 for i in range(26)]
matches = re.findall(r'(\d\d)#!(\d+)@|(\d\d)#|(\d)!(\d+)@|(\d)',s)
for match in matches:
    match = list(filter(lambda x: x!='',match))
    if len(match)==1:
        result(match[0]-1)+=1
    elif len(match)==2:
        result(match[0]-1)+=match[1]
return result