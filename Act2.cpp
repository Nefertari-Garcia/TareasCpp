#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

int main() {
int b = 2, c = 3, n = 1, e = 2;
float  d = 2;
double res;
res = b * c / static_cast<float>(pow(d, 3)) + e % n * 3 - 6;
cout << res << endl;
cin.ignore().get();
return 0;
}