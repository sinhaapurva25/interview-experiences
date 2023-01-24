What are the layers in your project? How is your data pipeline like? I clearly hinted that I do the data loads and no data analysis, there's a separate business team for that. Instinctly avoid questions you don't have practice with off late.

Do you use Spark with Scala or Spark with Python?
At work I use Pyspark, but for learning, I use Scala - I use/know both actually, depending on what I am doing, I just use either.

Why do we use Spark? What was the problem with Hadoop? I said, Spark is a replacement for Map Reduce, not Hadoop. And then went to explain the issues of MR1: 1: Scalibility problem; 2: MR1 could run only MR jobs, not Giraffe or Tez etc. applications.

Write a word count problem. I said I am skiping the session creation and all that, just writing the main thing; the interviewer was fine with it.
s = "this is a very fine morning".split('')
rdd = sc.parallelize(s)
rdd2 = rdd.map(lambda x: (x,1))
'''
t,1
h,1
i
'''
rdd3 = rdd2.reduceByKey(lambda x: x+y)
[i for i in rdd3.collect()]

This was using rdds, how would you do using spark sql? I can't frame it actually. I just wrote this much:
spark.sql("")

How do I get the second highest date of Rahul from the below table?
emp_id emp_name transaction_date
1  Rahul  2022-10-22

2  Sarvesh 2022-09-06

3  Rahul 2022-09-04

4  Rahul 2022-11-05

5  Sarvesh 2022-01-15

6  Ravi 2022-03-09

select * from tblname where emp_name='Rahul' sort by transaction_date limit 10,10;
 
Can you use any other method? I said, we could use DATE, but I am not exactly sure, He said, do you know about rank/row? How would ypu put it?

select * from tblname where emp_name='Rahul' rank -9 transaction_date;

Different file formats available in Spark: txt,csv,avro,parquet,xml,json
parquet is default
xml and avro external jars are needed

diff bw parquet and avro - Hive?

emp_id emp_name transaction_date

1  Rahul  2022-10-22

2  Sarvesh 2022-09-06

How would this file be stored in Avro and Parquet?

In Parquet:

emp_id
	emp_name
		transaction_date

1
	Rahul
		2022-10-22

2
	Sarvesh
		2022-09-06


What is Broadcast join in Hive? I gave an [example](https://github.com/sinhaapurva25/bigd/blob/main/Week10/Materials/SparkCodes/bigdatacampaigndata.py) - You said in context to Spark, how do you think it would be in context to Hive? Why is there no shuffling, as you say?

Do you know about strict mode in hive? No

Have you done any memory optimization in spark? Sadly, no :)
