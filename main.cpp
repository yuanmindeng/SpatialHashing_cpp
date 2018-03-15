#include "SpatialHashing.h"

int main()
{
    // This is the array to store the input
    double x,y,z;
    int n = 81;

    double* data = (double *)malloc(sizeof(double)*3*n);
    vector<Point3> points;
    //read data from txt
    FILE * fp = fopen("../test_data.txt", "r");
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%lf %lf %lf", &data[3*i], &data[3*i+1], &data[3*i+2]);
        Point3 point;
        point.x = data[3*i];
        point.y = data[3*i+1];
        point.z = data[3*i+2];
        points.push_back(point);
        //printf("print: %e %e %e \n", point.x,point.y,point.z);
    }
    fclose(fp);
    SpatialHashing* sh =new SpatialHashing(points,0.1);
    vector<int> index = sh->getElement(1);
    
    for(int i=0;i<index.size();i++){
        printf("%d \n",index[i]);
    }
    printf("size of list %d",index.size());
   printf("end\n");
   //get all the first index of points
   return(0);
}