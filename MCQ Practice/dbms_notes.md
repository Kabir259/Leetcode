# Intro To Database

Which of the following products was the first to implement true relational algebra in a PC DBMS?
R:base

Which of the following products implemented the CODASYL DBTG model?
IDMS


A DBMS that combines a DBMS and an application generator is ________ .
Microsoft's Access

You have run an SQL statement that asked the DBMS to display data in a table named USER_TABLES. The results include columns of data labeled "TableName," "NumberOfColumns" and "PrimaryKey." You are looking at ________ .metadata

*COBOL stands for Common Business Oriented Language.*

Which of the following is not considered to be a basic element of an enterprise-class database system? 
COBOL programs

# Intro To SQL

The command to remove rows from a table 'CUSTOMER' is:
- [x] DELETE FROM CUSTOMER WHERE ...<br>
UPDATE FROM CUSTOMER ...<br>
REMOVE FROM CUSTOMER ... <br>
DROP FROM CUSTOMER ... <br>

The wildcard in a WHERE clause is useful when?
- [x] An exact match is not possible in a SELECT statement. <br>
An exact match is necessary in a SELECT statement.<br>
An exact match is necessary in a CREATE statement.<br>
An exact match is not possible in a CREATE statement.<br>

```
Wildcard is use to find SUBSTRING.

There are 3 methods for using these,

1) % It substitutes zero or more character.

Eg: select * from details where city LIKE 'ber%';
->It returns citynames start with 'ber'.

2) _ it substitutes only 1 character.

Eg: select * from details where city LIKE '_erlin';
->It returns cityname start with any character followed by 'erlin'.

3) [charlist] Sets range of character.

Eg: select * from details where city LIKE '[a-c]%';
->It returns cityname start with a,b or c .
```

The command to eliminate a table from a database is:
- [x] DROP TABLE CUSTOMER; <br>
REMOVE TABLE CUSTOMER;<br>
DELETE TABLE CUSTOMER;<br>

ON UPDATE CASCADE ensures which of the following?  
- [x] Data Integrity  
Normalization  
Materialized Views  
All of the above.


The HAVING clause does which of the following?  
- [x] Acts like a WHERE clause but is used for groups rather than rows.  
Acts like a WHERE clause but is used for rows rather than columns.  
Acts like a WHERE clause but is used for columns rather than groups.  
Acts EXACTLY like a WHERE clause.  

When three or more AND and OR conditions are combined, it is easier to use the SQL keyword(s):  
- [x] Both IN and NOT IN.  
LIKE only.  
IN only.  
NOT IN only.  

A subquery in an SQL SELECT statement:  
- [x] has a distinct form that cannot be duplicated by a join.  
can only be used with two tables.  
can always be duplicated by a join.  
cannot have its results sorted using ORDER BY.  

```
We use sub query when we're not sure about the condition in the where clause.  
Eg: get list on emp whose salary is greater than min sal using subquery.

select last_name,salary 
from employees
where salary > (select min(salary) from employees)
order by last_name;

Here we have used one column only and sorted the result by order by clause  
On the other hand, for joins it has a replacement called as correlated subqueries that fetches informations from two tables.
```


SQL is:  
- [x] a data sublanguage.  
a programming language.  
an operating system.  
a DBMS.  

# The Relational Model and Normalization

The different classes of relations created by the technique for preventing modification anomalies are called:  
- [x] normal forms.  
referential integrity constraints.  
functional dependencies.  


The primary key is selected from the:  
- [x] candidate keys.  
composite keys.  
determinants.  
foreign keys.  

When the values in one or more attributes being used as a foreign key must exist in another set of one or more attributes in another table, we have created a(n):  
- [x] referential integrity constraint.  
transitive dependency.  
insertion anomaly.  
normal form.  

A functional dependency is a relationship between or among:  
- [x] attributes.  
tables.  
rows.  
relations.  

*A tuple is a row in a table*  
*Table is synonymous with the term <-> relation*  
*If two rows are identical, then it does not have a primary key.*  

A relation in this form is free of all modification anomalies.  
- [x] Domain/key normal form  
First normal form  
Second normal form  
Third normal form  

One solution to the multivalued dependency constraint problem is to:  
- [x] split the relation into two relations, each with a single theme.  
- [ ] add a composite key.  
change the theme.  
create a new theme.  

```BRO I CANT MAKE SO MANY NOTES GO TO INTERVIEWBIT/INTERVIEWPREP/SQL AND DBMS AND SOLVE. CHECK THE NOTES IVE PASTED IN THIS FOLDER```


