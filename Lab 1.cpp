//Created by: Rafael Pompa
//Date: 9/14
//this program is used to show user inputs

#include <iostream>
using namespace std;

int main() {
  string action = "";
  string verb = "";
  int hours = 0;
  string place = "";
  string action2 = "";
  string action3 = "";
//inputs first choice of action word
cout<<"Please enter a action: ";
  cin>>action;
//inputs of a verb
 cout<<"Please enter a verb that ends with ing: ";
  cin>>verb;
cout<<"Please enter 2 digit for hours : ";
  cin>>hours;
//inputs of a place
cout<<"Please enter a place: ";
  cin>>place;
//inputs two choice of action word
cout<<"Please enter a action: ";
  cin>>action2;
//inputs third choice of action word
cout<<"Please enter a verb that ends with ing: ";
  cin>>action3;

cout<< "Warning! Do not " << action << " my room! I’m currently " << verb << " video games!" << "\n" ;
cout<< "I have just spent " << hours << " hours at school, and I need some " << place << " so that I can " << action2 << " my new video game, "<< action3 << "-craft. " << "\n" ;
//I didn't know if it is allowed to write action1, action2 and so on when the mad lib asks for more than one verb
}