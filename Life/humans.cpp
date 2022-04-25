#include <iostream>
#include <string>
using namespace std;

class Humans {      
  public:           
    string Name;        
};

int main() {
  Humans myObj;  

  myObj.Name = "Blob";

  cout << myObj.Name;
  return 0;
}
