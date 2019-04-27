/**
	HelloWho.cpp by idebtor@gmail.com
	It prints "Hello World!" on the console or
	"Hello" with a given name.

	To build the program which generates hellowho.exe:
	> g++ HelloWho.cpp -o hello

	To run the program without a command line argument:
	> ./hello
	> Enter a name:

	To run the program with a command line argument:
	> ./hello Dr. John Kim
	> Hello Dr. John Kim!

	02/10/19: Created
*/

/*
On my honour, I pledge that I have neither received nor provided improper assistance
in the completion of this assignment.
signed : 신지영 Section:03 Student Number:21800409
*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    // Use setvbuf() to prevent the output from buffered on console.
    // setvbuf(stdout, NULL, _IONBF, 0);
  if(argc==1){
    string name;
    while(1){
      cout << "Enter a name: ";
      //if fail
      if(!getline(cin,name) || name.length()==0){
        cout << "Hello World!\n";
        break;
      }
      //if not fail
      else{
        cout <<"Hello "+name+"!\n";
      }
    }
  }
  else{
    cout << "Hello";
  	for (int i = 1; i < argc; i++)
  		cout <<" "<<argv[i] ;
    cout << "!\n";
  }
    // Use system("pause") to prevent the terminal from disappearing
    // as soon as the program terminates such as Visual Studio sometimes.
    // system("pause");
    return EXIT_SUCCESS;
}
