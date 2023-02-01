#include <iostream>
#include <string>
using namespace std;

class Student {
public:
	Student(string n, int r, string p) {
		name = n;
		roll_no = r;
		phone_no = p;
	}
	void getInfo() {
		cout << "Name: " << name << endl;
		cout << "Roll Number: " << roll_no << endl;
		cout << "Phone Number: " << phone_no << endl;
	}
private:
	string name;
	int roll_no;
	string phone_no;
};

int main() {
	Student student1("Sam", 1, "6613332888");
	Student student2("John", 2, "6613334137");
	student1.getInfo();
	student2.getInfo();
	return 0;
}
