/***************************************
Tip Calculator
Author: [Rafael popma]
Date Completed: [1/28/2026]
Description: [this program is used to calculate the tip amount based on the service you recived]
***************************************/
#include <iostream>
#include <iomanip>
using namespace std;
//seting up the variables
int main()
{
int service =0;
double total =0;
double tip =0;
double charged =0;

//asking how much you were charged befor the tip
cout <<"Welcome to the tip calculator tool!\n\n";
cout <<"How much were you charged? (in dollars)\n";
cin >> charged;
cout<<"\n";

//funtion to see what type of service you picked
cout <<"How was the service?\n";
cout <<"1. Very Good (20%)\n";
cout <<"2. Good (15%)\n";
cout <<"3. Poor (10%)\n";
cout <<"4. Very Poor (5%)\n";
cin >> service;
cout<<"\n";

//function to see how what percentage of tip you would pay
if (service==1){
tip= charged *0.20;
} else if (service==2){
tip= charged *0.15;
} else if (service==3){
tip= charged *0.10;
} else if (service==4){
tip= charged *0.05;

//function to see if you choose a number not givin
} else {
cout<< "Not a valid service rating number\n";
return 0;
}

//calculating how much you payed total
total = tip + charged;
//displaying the final results

cout << fixed << setprecision(2);
cout << "Tip Amount: $" << tip <<endl; 
cout << "Total: $" << total <<endl;
return 0;
}