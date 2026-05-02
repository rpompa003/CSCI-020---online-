/***************************************
XML Node Counter
Author: Rafael Pompa
Date Completed: 4/29/2026
Description: this program will parses an XML file 
and displays the number of direct child node elements under the root node to the CLI. 
The program should accept the XML file path as a command line argument.
***************************************/

#include <iostream>
#include "LinkedList.hpp"
#include "pugixml.hpp"
using namespace std;

// creating a class for cats
class cats
{
private:
string c_name;
int c_age;

public:

cats(string name, int age) : c_name(name), c_age(age){}
string getName()
{
return c_name;
}
int getYear()
{
return c_age;
}
};

int main(int argc, char* argv[])
{
// Simple validation for command line arguments
if (argc != 2)
{
cerr<<"Must supply one command line argument to program!\n";
return 1;
}

// Instantiate an xml document
pugi::xml_document doc;

// Load the "inventory.xml" file into the xml document variable
// if a problem occurred while loading, show error and end program
if (!doc.load_file(argv[1]))
{
cerr<<"Problem opening xml file \""<<argv[1]<<"\"\n";
return 1;
}

// Get the root node
pugi::xml_node root = doc.document_element();

// creating a varibale 
int childCount = 0;

//Loop over all <child_node> element children of the root element
for (pugi::xml_node child : root.children()) {
if (child.type() == pugi::node_element) {
childCount++;
}
}

// Output the final result
cout << "Node Count: "<< childCount << endl;

return 0;
}