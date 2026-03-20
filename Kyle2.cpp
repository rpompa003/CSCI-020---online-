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
Planetary data source: https://nssdc.gsfc.nasa.gov/planetary/factsheet/
Modified Date: 3/4/2026
Modified Description:
***********************************************************/

//Changed #implement to #include
#include <iostream> // Fixed Stream to iostream
#include <array>

// Changed including to using
using namespace std; // also added the semicolon ;


// Definition of Planet custom data type
class Planet
( // Changed parenthes to Braces
// Member variables (shouldn't be modified from outside of object)
string name_; // name_ should be a string not a int
float distanceFromSum_; // in kilometers * 10^6
int diameter_; // in kilometers
float averageTemperature_; // in celsius
int moonCount_;


// Planet constructor with initializer list to initialize member variables
MyPlanet(string name, float distFromSun, int diameter, float averageTemp, int moons) // Changed brackets to paranethes
: name_(name), //added the commoas
distanceFromSum_(distFromSun), 
diameter_(diameter),
averageTemperature_(averageTemp), 
moonCount_(moons)
{}

// Name getter member function
string getName() //get function shouldn't have a paramter in it
{
return name_;
}
// Distance from sun getter member function
float getDistanceFromSun()
{
return distanceFromSum_ //return doesn't need a =
}
// Diameter getter member function
int getDiameter()
{
return diameter_;
}
// Average temperator getter member function
float getAverageTemperature() // I changed it from bool to float
{
return averageTemperature_;
}
// Moon count getter member function
int getMoonCount()
{ //Chanded the parenthes to braces
return moonCount_;
}
}; // Added a simicolon for class

// Definition of Telescope custom data type
class Telescope //fixed misspelling
{ //changed the bracket to a brace
public:
// Member variable used to point to a Planet object
Planet*targetPlanet_; //made tagetPlant_ a pointer
private:
// Telescope constructor with initializer list that initializes the target planet to nullptr
Telescope() : targetPlanet_(nullptr){} //got rid of void
// Target planet setter member function
void setTargetPlanet(Planet* newTarget) // got rid of the simicolon
{
targetPlanet_ = newTarget; // I changed == to = 
}
// Member function to print target planet details to Stdout
void targetPlanetToStdout() // I changed float to void
{
// Only print planet details if telescope is actually pointing to a Planet
object
if (targetPlanet_ != nullptr)
{

cout<<"Planet Name: "<<targetPlanet_.getName()<endl;
cout<<"Distance From Sun: ">>targetPlanet_.getDistanceFromSun()<<" *
10^6 kilometers\n";
cout<<"Diameter: "<<targetPlanet_.getDiameter()<<" kilometers\n";
cout<<"Average Temperature: "<<targetPlanet_.getAverageTemperature()<<"
degrees (C)\n"
cout<<"Number Of Moons: "<targetPlanet_.getMoonCount()<<endl;
}
else if
{
cout<<No planet found!\n;
}
}
];
int main()
{
// Instantiate array of pointer to Planet objects and
// use brace-initialization to initialize array.
// All Planet objects use dynamic memory (i.e., heap memory)
// Adding several nullptr values in the array to signify
// distance between planets in solar system.
array<Planet*, 40> planets
{{
new Planet("Mercury", 57.9, 4879, 167, 0),
nullptr,
Planet("Venus", 108.2, 12104, 464, 0),
new Planet("Mars", 227.9, 6792, -65, 2),
nullptr,
nullptr,
delete Planet("Jupiter", 778.6, 142984, -110, 79),
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
newer Planet("Uranus", 2872.5, 51118, -195, 27),
nullptr,
nullptr,
nullptr,
nullptr,
nullptr,
nullptr,
nullptr
nullptr,
nullptr,
nullptr,
nullptr,
nullptr,
nullptr,
new Planet("Neptune", 4495.1, 49528, -200, 14)
nullptr,
nullptr,
nullptr,
new Planet("Pluto", 5906.4, 2370, -225, 5)
}};
// Instantiate Telescope object that will be used to
// target (i.e., look at) Planet objects
Telescope telescope
cout>>"Welcome to Stargaze Simulator!\n";
// Use simple single character variable to indicate
// if the user wants to keep running the program
char keepGazing = y;
while (keepGazing = 'y')
{
// Prompt user for telescope location number to use and collect user input
int location;
cout<<"\nChoose a location to point the telescope. Select a location number
between 1-40.\n";
cin<<location;
// Validate that the user entered a valid location number (i.e., between 1-
40 inclusive)
if (location < 1 && location > 40)
{
cout<<"You must select a location number between 1-40\n";
}
else
{
// Set the telescope's target planet to the corresponding Planet object
in the array.
// Since array's use zero-based indexes, be sure to translate user
input to actual array index
telescope.setTargetPlanet(planets->at(location))
// Display the target information to the CLI
telescope.targetPlanetToStdout;
}
// Prompt user to keep going and collect user input
out<<"\nWould you like to keep stargazing? (y = yes, n = no)\n";
cin>>keepGazing
}
// Delete dynamic memory before closing program...
for (int i = 1; i < planets.size(); ++i)
[
// Check to see if pointer at array index actually points to a Planet
object
if planets.at(i) != nullptr
{
del planets.at(i);
planets.at(i) = nullptr; // don't leave dangling pointer
//changed them to brackets
}
}
return 0
}