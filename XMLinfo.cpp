/***************************************
Round 1 Voting
Author: Rafael Pompa
Date Completed: 4/18/2026
Description: this code will implement the missing/incomplete sections
using HashTable.hpp and LinkedList.hpp
***************************************/

#include <iostream>
#include "LinkedList.hpp"
#include "pugixml.hpp"
using namespace std;

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

// Count direct child elements (excluding text nodes, comments, etc.)
int childCount = 0;
for (pugi::xml_node child : root.children()) {
    if (child.type() == pugi::node_element) {
        childCount++;
    }
}

// Output the result
cout << childCount << endl;


return 0;
}