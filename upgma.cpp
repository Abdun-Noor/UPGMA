#include<iostream>
#include <string>
#include <sstream>

using namespace std;

const int clusternumber = 4;
double inf = 99999.99;

double dis_matrix[clusternumber][clusternumber] = {{0,3,4,3},{3,0,4,5},{4,4,0,2},{3,5,2,0}}; //distance matrix
//double dis_matrix[clusternumber][clusternumber];

class pos{
public:
   int x;
   int y;

pos(int a, int b){
    x = a;
    y = b;
}

};

pos find_min(){
    double min = inf;
    int pos_x = -1 , pos_y = -1;

    for(int i=0;i<clusternumber;i++)
    {
        for(int j=0; j<clusternumber ;j++){
            if(dis_matrix[i][j]<min && dis_matrix[i][j]!= 0){
                min = dis_matrix[i][j];
                pos_x = i;
                pos_y = j;
            }
        }
    }
    return pos(pos_x, pos_y);
}

int main(){

cout<<"input number of elements :"<<endl;
//cin>>clusternumber;                                //Number of elements
int remaining_cluster = clusternumber;
double value ;
string labels[clusternumber] = {"i","j","k","l"};   //labels are added here

for(int i=0;i<clusternumber;i++)
{
    for(int j=0; j<clusternumber ;j++){
        cout<<" "<<dis_matrix[i][j];
    }
    cout<<" "<<endl;
}

pos p(0,0) ;

cout<<"staring :"<<endl;
while(remaining_cluster!=1){
    p = find_min();

    for(int i=0;i<clusternumber;i++)
    {
        dis_matrix[p.x][i] = (dis_matrix[p.x][i] + dis_matrix[p.y][i])/2;
    }

    value = dis_matrix[p.x][p.x];

    for(int i=0;i<clusternumber;i++)
    {
        dis_matrix[i][p.x] = (dis_matrix[i][p.x] + dis_matrix[i][p.y])/2;
    }

    for(int i =0 ;i<clusternumber;i++)
    {
        dis_matrix[p.y][i] = inf;
        dis_matrix[i][p.y] = inf;
    }
    dis_matrix[p.x][p.x] = 0;

    string t;
    stringstream ss;
    ss << value;
    ss >> t;

    string tem = "( " + labels[p.x] +"," +labels[p.y]+ ": "+ t+" )";
    labels[p.x] = tem;
    remaining_cluster-=1;
 //   cout<<remaining_cluster<<endl;
}

cout<<"Output : "<<labels[p.x]<<endl;

/*
cout<<"Testing :"<<value <<endl;
for(int i=0;i<clusternumber;i++)
{
    for(int j=0; j<clusternumber ;j++){
        cout<<"\t"<<dis_matrix[i][j];
    }
    cout<<" "<<endl;
}
*/
}
