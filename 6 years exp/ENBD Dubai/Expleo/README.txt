Explain the memory management in Spark.
Do you know what is Databricks?
What is a RDD and Dataframes?
What is DAG?
What is lazy evaluation?
What is Spark Session?
Have you worked on Cloud in Prod? No - I have done POCs and 
What if you submit a Spark Job and it is slow? How will you debug it?

The Scenario: "Anti-Money Laundering (AML) Flagging"
"We have two massive tables.
Transactions: (10 billion rows) contains account_id, amount, timestamp.
Blacklisted_Accounts: (1 million rows) contains account_id and risk_level.
Task: We need to find all transactions over $10,000 from blacklisted accounts that occurred in the last 24 hours, and calculate the total 'Risk Exposure' per account. How would you implement this efficiently? Can you write the code in pyspark?

join -> account_id 
records -> amount > 10k

timestamp -> filter -> 24 hours

group by account_id

sum(amount)


// broad cast join is enabled in spark conf
select accoun_id, sum(amount) as txn_amt from Transactions 
inner join  Transactions.account_id === Blacklisted_Accounts.account_id
where Transactions.amount > 10000 and timestamp UDF to fileyr for last 24 hrs
group by account_id;

10000000/128 -> 


