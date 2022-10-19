#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  int a;
  for (int i = 0; i < 10; i++)
  {
    a = (rand() % 3 + 1) + 1;
    cout << a << endl;
  }
}