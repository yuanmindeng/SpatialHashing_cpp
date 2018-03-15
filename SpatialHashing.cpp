#include "SpatialHashing.h"

SpatialHashing::SpatialHashing(vector<Point3> arg_points, double arg_cell_size)
{
    cell_size = arg_cell_size;
    points = arg_points;
    conversion_factor = 1/cell_size;

    //get 3d grid
    //get x, y, z's min and max
    //double* range = (double *)malloc(sizeof(double)*6);
    double* range = getRange(points);
    double Xmin = range[0];double  Xmax = range[1];
    double Ymin =  range[2];double  Ymax =range[3] ;
    double Zmin = range[4];double  Zmax =range[5] ;

    int length = ceil((Xmax-Xmin)/cell_size);
    int width = ceil((Ymax-Ymin)/cell_size);
    int height = ceil((Zmax-Zmin)/cell_size);


    for(int i=0;i<points.size();i++){
        int index = floor((points[i].x-Xmin)*conversion_factor)+floor((points[i].y-Ymin)*width*conversion_factor)+floor((points[i].z)*height*conversion_factor)+1;
        vector<int> chainlist;
        map<int,vector<int>> ::iterator it;
        it = hashtable.find(index);
        if (it !=hashtable.end()){// if key is exist
            //find the value list and insert new point order
            chainlist = hashtable.at(index);
            chainlist.push_back(i);
        }else{// if key isn't exist
            //build new list and insert
            chainlist.push_back(i);
            hashtable.insert(pair<int,vector<int>>(index,chainlist));
        }
    }


}

vector<int> SpatialHashing::getElement(int num){
    vector<int> elementList;
    map<int,vector<int>>::iterator iter;
    for(iter = hashtable.begin();iter !=hashtable.end();iter++){
        vector<int> chainlist = iter->second;
        for(int j = 0; j<chainlist.size();j++){
            if(j<num) elementList.push_back(chainlist[j]);
        }
    }

    return elementList;
}




double* SpatialHashing::getRange(vector<Point3> arg_points){
    double Xmin = DBL_MAX,Xmax=-DBL_MIN,Ymin=DBL_MAX,Ymax=-DBL_MIN,Zmin = DBL_MAX,Zmax=-DBL_MIN;
    
    for (int i =0; i<arg_points.size();i++){
        if (Xmin>arg_points[i].x){
            Xmin = arg_points[i].x;
        }
        if (Ymin>arg_points[i].y){
            Ymin = arg_points[i].y;
        }
        if (Zmin>arg_points[i].z){
            Zmin = arg_points[i].z;
        }

        if (Xmax<arg_points[i].x){
            Xmax = arg_points[i].x;
        }
        if (Ymax<arg_points[i].y){
            Ymax = arg_points[i].y;
        }
        if (Zmax<arg_points[i].z){
            Zmax = arg_points[i].z;
        }
    }

    
    double* range = (double *)malloc(sizeof(double)*6);
    range[0] = Xmin; range[1] = Xmax;
    range[2] = Ymin; range[3] = Ymax;
    range[4] = Zmin; range[5] = Zmax;
    printf("min-max range\n");
    for (int i=0;i<6;i++){
        printf("%lf ",range[i]);
    }
    printf("\n");

    return range;
}