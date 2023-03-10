#include <iostream>
#include <map>
using namespace std;

int main(){
  map<string, int> student = {{"David", 80}, {"James", 90}, {"Jack", 75}};

  map<string, int>::iterator it;  // a pointer variable used for iterating through a map
  for(it = student.begin(); it != student.end(); it++) 
  {
    cout << it->first << "   " << it->second << endl; // first prints key, second prints value
  }

  student["Ahmad"] = 75;  // insert a key value pair using [] operator
  student.insert(make_pair("Sue", 90)); // also inserts key value pair
  student.emplace("Jose", 89); // also inserts

  cout << "David got " << student.at("David") << endl; // retrieving a value

  if(student.count("Molly"))  // checks if a key exists in the map
    cout << "Molly got " << student.at("Molly") << endl;
  else
    cout << "There is no such student." << endl;
  
  return 0;
}
