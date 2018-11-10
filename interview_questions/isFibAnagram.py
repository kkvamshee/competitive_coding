#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Nov 10 16:43:27 2018

@author: kkvamshee
"""
"""
 Given a number N tell if its possible to convert it into a fibonacci number by rearranging the digits of N.

        Constraints: 1<=N<=10^15.
"""

import math

def isFibAnagram(n):
    length = math.log(n, 10)//1+1
    
    t1=t2=l=1
    roi=[]
    while l<=length:
        l=math.log(t2,10)//1 + 1
        if l==length:
            roi.append(t2)
        t1, t2 = t2, t1+t2
    print('roi : ', roi)
    roi = [''.join(sorted(str(i))) for i in roi]
    return ''.join(sorted(str(n))) in roi

print(isFibAnagram(int(input())))
