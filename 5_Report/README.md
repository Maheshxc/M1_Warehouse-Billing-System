
# INTRODUCTION

A warehouse is a commercial place for storing goods. Procedures in a warehouse include inventory management, picking processes, and auditing. Some retailers can acquire the goods in a larger amount immediately from the warehouse. The bill within the program can be recorded by the input of the current month and date. This system utilizes a billing structure to store the records and provides access to the user whenever required. Users shall have several access privileges for the system. It is a user-friendly web-based system that efficiently takes care of the billing activities of the warehouse audit functionality and distribution center management.

# PROBLEM STATEMENT
Design and develop an efficient Warehouse billing system in auditing using C programming.

# PROJECT DESCRIPTION
The project intends to manage the billing process smoothly in large organizations without making any errors. The main feature of this system is, the system can easily calculate the total bill for the goods acquired by the customers, and also it gives some additional features like name, address, mobile number, paid amount, due amount, payment date, etc. of your regular customer. Additionally, if you have a new customer, you can add and edit the account at any time.

#Features of proposed model
1.  It can handle any number of accounts and accounts can be added to the program at any time.
2.  The programming of simple calculations such as calculation of the due amount, balance, etc. have been embed in the code.
3.  The Warehouse Billing System gives you the facility of searching the account in two ways, either by name of the retailer customer or by the number of a retailer.
4.  The due amount to be paid is displayed as a negative balance.
5.  If you have nothing to do with the program, you can direct exit from the main menu.

## EXISTING SYSTEM
The existing system did not have the option to track payments from the warehouse. It was done manually. It was a laborious task. The system did not have the option to print the term reports or payment reports. All the accounts were maintained manually. It was a challenging task to manage the bills as the warehouse has a wide number of retailers to order the goods in a larger amount.

##PROPOSED SYSTEM
This warehouse billing system will help the user to add any number of accounts. There are different types of sections like calculation of the due amount, balance. This system makes billing automated, accurate, and easier. This kind of application is very essential for any organization.

## Data requirements
The data collected for each of the retailers are as follows

•	Name
•	Address
•	Mobile number
•	Paid amount

## Software Requirement
It deals with the Operating system, IDE, Programming language, and Compiler that are used in this system and are mentioned as follows.

Operating System: Windows or Ubuntu
IDE: Code Blocks 
Programming Language: C
Compiler: GCC
##3Functional requirements
The functions that are required for an efficient billing system is as follows:

Calculate bill: It calculates the total price of the purchased products and displays the total amount to pay by the customer.
Add customer: It adds the new customer by taking a name, address, mobile number, paid amount.
Display: It displays all the due amount to be paid. 
Search: It searches the customer whether it is available in the system or not. if not then add a new customer option is there, the facility of searching the account in two ways, either by name of the customer or by the number of the customer.
Exit: 1. If you have nothing to do with the program, you can directly exit from the main menu.

#TEST PLAN
In this project, errors can be injected at any stage during development. There are various techniques for detecting and eliminating errors that originate in that phase. It is particularly true because in the earlier phases and most of the verification techniques are manual because no executable code exists. Ultimately those remaining errors will be reflected in the code. Hence, the code developed during the coding activity is likely to have some requirement errors and design errors, in addition to errors introduced during the coding activity. Behaviour can be observed, testing is the phase where the errors remaining from all the previous phases must be detected. Hence, testing performs a very critical role in assurance and for ensuring the reliability of the software.
##TEST CASE
Different functions are used for performing different billing operations in the       warehouse billing system such as:
•	void input()
•	void writefile()
•	void search()
•	void output()

•	The function void input() is used to add the new customer account i.e. with the help of this functions the parameters such as name, address, phone number, amount paid etc. are asked and entered.

•	The function void writefile() has been utilized to create a file on hard disc of computer for storing the information and data of a customer.
•	The function void search() has been used to look for previously stored accounts either by name or by number of the customer. 
•	The fourth and the last user defined function used in this Warehouse Billing System is void output() which has been defined to show the result as console output.
