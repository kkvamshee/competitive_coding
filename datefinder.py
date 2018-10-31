# -*- coding: utf-8 -*-
"""
Created on Thu Aug  9 18:31:53 2018

@author: kkvamshee
"""

import re
from datetime import datetime

month_num = {'jan':1,
			 'feb':2,
			 'mar':3,
			 'apr':4,
			 'may':5,
			 'jun':6,
			 'jul':7,
			 'aug':8,
			 'sep':9,
			 'oct':10,
			 'nov':11,
			 'dec':12}

message = """
Around the turn of millennium, spending on technology was volatile as companies prepared for the year 2000 problem, which, when the clocks changed to the year 2000, actually had minimal impact. On Jan. 10, 2000, America Online announced a merger with Time Warner, the largest to date and a move that was questioned by many analysts. In February 2000, with the Year 2000 problem no longer a worry, Alan Greenspan announced plans to aggressively raise the interest rates which led to significant stock market volatility as analysts disagreed as to whether or not technology companies would be effected by higher borrowing costs.
On 3/10/2000, the NASDAQ Composite stock market index peaked at 5,048.62. Three days later (2000-03-13), news that Japan had once again entered a recession triggered a global sell off that disproportionately aected technology stocks. Another 2 days later on 15-MAR-2000, Yahoo! and eBay ended merger talks and the Nasdaq fell 2.6% but the S&P 500 Index rose 2.4% as investors shifted from strong performing technology stocks to poor performing established stocks.
On 2000-March-20, Barron`s featured a cover titled “Burning up; Warning; Internet companies are running out of cash -- fast”, which predicted the imminent bankruptcy of many internet companies. This led many people to rethink their investments. The same day, Microstrategy announced a revenue restatement due to aggressive accounting practices. Its stock price, which had risen $7 per share to as high as $333 per share in a year, fell $120 per share, or 62%, in a day. The next day(21MAR2000), the Federal Reserve raised interest rates, leading to an inverted yield curve, although stocks rallied temporarily.
"""

test = """
Some  other  examples of valid dates: 2000-sep-3;  MARCH 2, 2017; 2022-MARCH-3; 06/24/2018; JULY 7,2003; 2007-September-20; 1996-February-6; 2008-NOV-22; 24-jul-2030;
Apr. 21, 2014; 1992-NOVEMBER-05; JUN. 08,2005; 26-NOVEMBER-1990; FEBRUARY 20, 2017; 14-August-1991; 1994-Nov-07;19-APRIL-2008; DECEMBER 9,2020; 22MAR2030;
2017-OCT-26;16-AUGUST-2009; 07-Jan-206; 2-JUN-2018;2023-February-08; APRIL 28, 2020;02-Aug-2016; 3-JAN-2024; August 22 2024; 15-Sep-2000;12-DEC-2016;09/01/2009;
2002-02-20; 2013-10-04; 29-SEPTEMBER-2028; 2-Mar-2026; 5-NOV-2010; 06Aug1991; 1990-MARCH-18; 1991-JUNE-14; 27-JUNE-2028; January 9, 1992; Jul 21, 2011; 2013-JUL-20;
DEC. 16,2030; 2001-APR-29; 2005-10-13; Dec. 25, 2013; 06-july-2025; 14NOV2011.
"""


#construction phase
message = ''.join(message.split('\n'))
message = message.lower()

test = ''.join(test.split())
test = test.lower()

month_pattern = r'(jan|feb|mar|apr|jun|jul|aug|sep|oct|nov|dec|january|february|march|april|june|july|august|september|october|november|december)'
p1 = month_pattern+r'\.? (\d{1,2}), (\d\d\d\d)'     #covers Jan. 14, 2015 and January 14, 2015 types.
p2 = r'((\d{1,2})[-/](\d{1,2})[-/](\d\d\d\d)|(\d\d\d\d)[-/](\d\d)[-/](\d\d))'
p3 = r'((\d{1,4})-?'+month_pattern+r'-?(\d{1,4}))'
final_pattern = p1+'|'+p2+'|'+p3
"""
for pat in re.finditer(final_pattern, message):
	print(pat)
"""





#execution phase
result = re.findall(final_pattern, test)
for i in range(len(result)):
	result[i] = list(filter(lambda x: x.isalpha() or x.isnumeric(), result[i]))

for i in range(len(result)):
	arr = result[i].copy()
	for j in range(len(result[i])):
		if result[i][j].isalpha():
			month=month_num[result[i][j][:3]]
			arr.remove(result[i][j])
		elif result[i][j].isnumeric() and len(result[i][j])==4:
			year=int(result[i][j])
			arr.remove(result[i][j])

	if len(arr)==1:
		day=int(arr[0])
	else:
		day=int(arr[1])
		month=int(arr[0])

	print('{0:04d}{1:02d}{2:02d}'.format(year, month, day), result[i])

