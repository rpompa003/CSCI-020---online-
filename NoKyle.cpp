/***********************************************************
Program Name: Stargaze Simulator
Program Author: Kyle NoCompile
Date Completed: 9/4/18
Program Description:
This program allows the user to simulate stargazing 
by allowing them to choose a location to point a 
"telescope" into the "sky" and see different planets.
Just as in reality, not all locations reveal a planet, 
so the user must explore through trial and error.
Planetary data source: 
https://nssdc.gsfc.nasa.gov/planetary/factsheet/

Modified Date: 3/4/2026
Modified Description:
I went through Kyle code and added comments to show him know what chagnges
i made and where he made the errors
***********************************************************/

// I changed #implement to #include
#include <iostream> // you had a misspelling, It was streamio not iostream
#include <array>

// I changed including namespace std to using namespace std
using namespace std; // I also addeda simicolon


// Definition of Planet custom data type
class Planet // I replaced the parenthes() with braces {}
{

// Member variables (shouldn't be modified from outside of object)
string name_; // I changed  int to string as your trying to output a name
float distanceFromSun_; // fixed missspelling of distanceFromSum_ to distanceFromSun_
int diameter_; // in kilometers
float averageTemperature_; // in celsius
int moonCount_;

public: // I added a so that the constructor and getters are public

// Planet constructor with initializer list to initialize member variables
Planet(string name, float distFromSun, int diameter, float averageTemp, int moons) // I changed the Brackets[] to parenthes ()
// I added commas that were missing
: name_(name), distanceFromSun_(distFromSun), diameter_(diameter),
  averageTemperature_(averageTemp), moonCount_(moons)
{}

// Name getter member function
string getName() // get doesn't need a parameter
{
return name_;
}

// Distance from sun getter member function
float getDistanceFromSun()
{
// removed the = as it is not needed
return distanceFromSun_; //added a simicolon
}

// Diameter getter member function
int getDiameter()
{
return diameter_;
}

// Average temperature getter member function
float getAverageTemperature() // I changed bool to float
{
return averageTemperature_;
}

// Moon count getter member function
int getMoonCount()
{
return moonCount_; // changed parentheses to braces
}
};


// Definition of Telescope custom data type
class Telescope // changed misspilleing of classy to class
{ // fixed the brackets and made them braces

// Member variable used to point to a Planet object
Planet* targetPlanet_; // changed from Planet to Planet* to make it a pointer pointers

public: // needed so main can use constructor and functions

// Telescope constructor with initializer list that initializes the target planet to nullptr
Telescope() : targetPlanet_(nullptr) {} // I removed void from constructor

// Target planet setter member function
void setTargetPlanet(Planet* newTarget) // removed semicolon
{
targetPlanet_ = newTarget; // changed == to = as were not trying to equal to
}

// Member function to print target planet details to Stdout
void targetPlanetToStdout() // changed return type from float to void
{
// Only print planet details if telescope is actually pointing to a Planet object
if (targetPlanet_ != nullptr)
{

cout << "Planet Name: " << (*targetPlanet_).getName() << endl;
cout << "Distance From Sun: " << (*targetPlanet_).getDistanceFromSun() << " * 10^6 kilometers\n"; // Changed >> to <<
cout << "Diameter: " << (*targetPlanet_).getDiameter() << " kilometers\n";
cout << "Average Temperature: " << (*targetPlanet_).getAverageTemperature() << " degrees (C)\n";
cout << "Number Of Moons: " << (*targetPlanet_).getMoonCount() << endl;
cout << endl;
}
else // got rid of the if
{
cout << "No planet found!\n"; // added quotes so it would output
cout <<endl;
}
}
};


int main()
{
// Instantiate array of pointer to Planet objects and
// use brace-initialization to initialize array.

// All Planet objects use dynamic memory (i.e., heap memory)

// Adding several nullptr values in the array to signify
// distance between planets in solar system.

array<Planet*, 40> planets =
{
new Planet("Mercury", 57.9, 4879, 167, 0),
nullptr,
new Planet("Venus", 108.2, 12104, 464, 0), // added new to venus
new Planet("Mars", 227.9, 6792, -65, 2),
nullptr,
nullptr,
new Planet("Jupiter", 778.6, 142984, -110, 79), // Got rid of delete and changed it to new
nullptr,
nullptr,
nullptr,
nullptr,
nullptr,
new Planet("Saturn", 1433.5, 120536, -140, 82),
nullptr,
nullptr,
nullptr,
nullptr,
nullptr,
nullptr,
nullptr,
nullptr,
new Planet("Uranus", 2872.5, 51118, -195, 27), // fixed newer to new
nullptr,
nullptr,
nullptr,
nullptr,
nullptr,
nullptr,
nullptr,
nullptr,
nullptr,
nullptr,
nullptr,
nullptr,
nullptr,
new Planet("Neptune", 4495.1, 49528, -200, 14),
nullptr,
nullptr,
nullptr,
new Planet("Pluto", 5906.4, 2370, -225, 5)
};


// Instantiate Telescope object that will be used to 
// target (i.e., look at) Planet objects
Telescope telescope; // added a missing semicolon

cout << "Welcome to Stargaze Simulator!"<<endl; // Changed >> to <<

// Use simple single character variable to indicate
// if the user wants to keep running the program
char keepGazing = 'y'; // added quotes

while (keepGazing == 'y') // changed = to ==
{

// Prompt user for telescope location number to use and collect user input
int location;
cout << endl;
cout << "Choose a location to point the telescope. Select a location number between 1-40.\n";
cin >> location; // Changed << to >>

// Validate that the user entered a valid location number (i.e., between 1-40 inclusive)
if (location < 1 || location > 40) // changed && to ||
{
cout << "You must select a location number between 1-40\n";
cout << endl;
}
else
{
// Set the telescope's target planet to the corresponding Planet object in the array.
// Since array's use zero-based indexes, be sure to translate user input to actual array index
telescope.setTargetPlanet(planets.at(location - 1));


// Display the target information to the CLI
telescope.targetPlanetToStdout(); // added ()
}

// Prompt user to keep going and collect user input

cout << "Would you like to keep stargazing? (y = yes, n = no)\n";
cin >> keepGazing;
}


// Delete dynamic memory before closing program...
for (int i = 0; i < planets.size(); ++i) // changed start index from 1 to 0
{
// Check to see if pointer at array index actually points to a Planet object
if (planets.at(i) != nullptr)
{
delete planets.at(i); // changed del to delete
planets.at(i) = nullptr; // don't leave dangling pointer
}
}

return 0; // added missing semicolon
}