#include <iostream>

using namespace std;

// deep copy vs shallow copy
// copy constructors



// private
class Stack {
private: // this is redundant, classes are private unless declared public
  int top;
  int size;
  int *stack;

public:
// default constructor
  Stack() {
    top = -1;
    size = 10;
    stack = new int[size];
  }
        // overloaded constructor

  Stack(int size):top(-1),size(size),stack(new int [size]){}
  // destructor
  ~Stack(){
    delete []stack;
  }
};

int main(int argc, char **argv) {
  cout << "Stack example ...!" << endl;
  Stack stack1;
  Stack stack2(100000000);
}