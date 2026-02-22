/***************************************
Automated Introspection
Author: [Rafael popma]
Date Completed: [2/11/2026]
Description: [This program will allow the user to enter a simple belief, re-examine the belief, and then output an analysis of the re-examined belief. ]
***************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Setting up the funtion
string *MakePhilosophical(string& belief){
belief += ", right?";

return &belief;
}

//Setting up the variables
int main(){
string userbelief;

//Asking the user for their simple belief
cout << "Enter a simple belief:" <<endl;
getline(cin, userbelief);

cout<<"\n";

//Calling for the MakePhilosophical function
string* result = MakePhilosophical(userbelief);

// Outputing the Re-examined Belief:
cout << "Re-examined Belief:" << endl;
cout << *result <<endl <<endl;

// Checking length requirement
if (result->length() < int(25)){

// Outputing If the length of the returned value is less or more than 25 characters
cout << "Analysis: Pithy and profound!\n";
} else {
cout << "Analysis: Best not to think about it\n";
}

return 0;
}