#include <vector>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <map>

using namespace std;
struct Point3{
    double x,y,z;
};

class SpatialHashing 
{
public:
  SpatialHashing(vector<Point3> arg_points, double cell_size);
  ~SpatialHashing(void);
  int query1();
  int query2();
  double* getRange(vector<Point3> arg_points);
  vector<int> getElement(int num);

private:
  vector<Point3> points;
  double cell_size=0.001;
  double conversion_factor = 1000;
  map<int,vector<int>> hashtable;
  //Hashtable
  //conversion vector

};
