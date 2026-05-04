#include <iostream>
using namespace std;

 class Company
{
private:
	string founder = "Boss";
	string address = "Nakhonrachasima";
	friend class Employee;
public:
	static int count;
};
class Employee
{
private :
	string name  = "No Name";
	int salary = 0;
public :
	Employee()
	{
		cout << "Create Empty Object" << endl;
	}
	Employee(string n, int s)
	{
		name = n;
		salary = s;
	}
	void showdata()
	{
		cout <<"Name   : " << name << endl;
		cout <<"Salary : " << salary << endl;
		cout << "---------------" << endl;
	}
	void setname(string n)
	{
		name = n;
	}
	void setsalary(int s)
	{
		salary = s;
	}
	string getname()
	{
		return name;
	}
	int getsalary()
	{
		return salary;
	}
	virtual void about() = 0;
	void showcompany()
	{
		Company c;
		cout <<"CEO : " << c.founder << endl;
		cout <<"Address : " << c.address << endl;
	}

};
class IT : public Employee
{
public:
	IT()
	{
		cout << "Create IT Object" << endl;
	}
	IT(string n,int s) : Employee(n,s) 
	{
		Company::count++;
	}
	void showdata()
	{
		cout << "IT Department" << endl;
		cout << "Name   : " << getname() << endl;
		cout << "Salary : " << getsalary() << endl;
		cout << "---------------" << endl;
	}
	void about()
	{
		cout << "Development Product" << endl;
	}
};
class Sale : public Employee
{
public:
	Sale()
	{
		cout << "Creat Sale Object" << endl;
	}
	Sale(string n, int s) : Employee(n, s)
	{
		Company::count++;
	}
	void showdata()
	{
		cout << "Sale Department" << endl;
		cout << "Name   : " << getname() << endl;
		cout << "Salary : " << getsalary() << endl;
		cout << "---------------" << endl;
	}
	void about()
	{
		cout << "Sale Product" << endl;
	}
};
int Company::count = 0;
int main()   
{
	IT emp1("Party", 50000);
	IT emp2("Jojo", 25000);
	Sale emp3("Dio", 40000);
	Sale emp4("Nam", 45000);
	cout <<"Employee Total = " <<Company::count << endl;
	
}
