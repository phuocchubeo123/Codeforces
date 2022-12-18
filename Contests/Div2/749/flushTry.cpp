// Below is C++ program
#include <iostream>
#include <thread>
#include <chrono>
 
using namespace std;
 
int main()
{
  for (int i = 1; i <= 5; ++i)
  {
      cout << i << " ";
      _sleep(1000);
  }
  cout << endl;
  return 0;
}