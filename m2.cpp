// C++ program to delete array of 
// objects 
#include <iostream> 
#include <vector>
using namespace std; 

// Class 
class Student { 

public: 
    int n;
	// Constructor 
	Student() 
	{ 
        this->n = -99;
		cout << "Constructor is called!" << endl; 
	} 
    Student(Student const& other) { cout << "copy construction\n"; }
    Student(int n) 
	{ 
        this->n = n;
		cout  << "n Constructor is called!" << endl;; 
	} 

	// Destructor 
	~Student() 
	{ 
		cout << this->n << "Destructor is called!" << endl; 
	} 

	// Function to display message 
	void write() 
	{ 
		cout << "Writing!\n"; 
	} 
}; 

// Driver Code 
int main() 
{ 
    vector<Student> vs;
    for(int i=0; i<2; i++) {
        vs.push_back(Student(i));
    }

	return 0; 
}
