# Interviewer

https://in.linkedin.com/in/iamrajivgupta

# TECHNICAL ROUND 1
s = 'ABCDAB'

duplicate characters

dct = {}
for i in range(len(s)):
	if i in dct:
		dct[i] += 1
	else:
		dct[i] = 1
[print(i) for i in dct if i >1]

{'A' = 1}
{'A' = 1, 'B' = 1}
{'A' = 1, 'B' = 1, 'C' = 1 }
{'A' = 1, 'B' = 1, 'C' = 1, 'D' = 1 }
{'A' = 2, 'B' = 1, 'C' = 1, 'D' = 1 }
{'A' = 2, 'B' = 2, 'C' = 1, 'D' = 1 }
======================================================

Input
Logs Table

Id	Num
1	1
2	1
3	1
4	2
5	1
6	2
7	2

Output: 1, beacuse 1 occurs three times consecutively

select * from logstble, count(*) over(partition by num rows )
======================================================
what is shuffling?
In executors?
When is shuffling not invloved?
======================================================

how do you write a mapside join in hive?

select /*+mapside(small_tbl) */ from tbl1 

======================================================
read from hive in spark -> read from a file by defining a schema
sch = Structure(List("col1",toInteger)),
			List("col2",toDatetime))
spark.read.format("json").option("path","usr/tbl/wrk/").schema(sch).load()
======================================================
when do you use a rdd and a dataframe?
how do you read from a rdd?
rdd1 = sc.txtFile("<>")
sc.map()

et 3.1 alphabt 450009 

col 1, col2
ghg | 




