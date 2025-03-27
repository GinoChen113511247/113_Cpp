#define M_PI = 3.14159
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

char quadrant(double a, double b)
{
  if (a==0 && b==0)
    return '0';
  else if (a>0 && b>0)
    return '1';
  else if (a<0 && b>0)
    return '2';
  else if (a<0 && b<0)
    return '3';
  else if (a>0 && b<0)
    return '4'; 
  else if (a==0)
    return 'y';
  else if (b==0)
    return 'x';
}

double area(double c)
{
   return M_PI*c*c;
}

struct point {double x;double y;};
struct circle {point p1;double radius;};

int main(void)
{
    point p1;
    circle c1;
    cin >> p1.x >> p1.y >> c1.radius;
    cout << "The center is at " << quadrant(p1.x, p1.y) << ", and the area is ";
    cout << fixed << setprecision(5) << area(c1.radius) << ".";
    return 0;
}

