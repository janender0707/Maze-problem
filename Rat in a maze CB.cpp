#include<iostream>
using namespace std;

bool ratinamaze(char maze[10][10],int soln[][10],int i,int j,int m,int n)
{
    //base case
        if(i==m && j==n){
            //print
            soln[m][n]=1;
            for(int i=0;i<=m;i++){
                for(int j=0;j<=n;j++){
                    cout<<soln[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
            return true;
        }

        if(i>m || j>n){
            return false;
        }

        if(maze[i][j]=='X'){
            return false;
        }


        //recursive case
        soln[i][j]=1;

        bool rightsuccess = ratinamaze(maze,soln,i,j+1,m,n);
        bool downsuccess = ratinamaze(maze,soln,i+1,j,m,n);

        //backtracking
        soln[i][j]=0;
        if(rightsuccess||downsuccess){
          return true;
        }
    return false;
}

int main()
{
    char maze[10][10]={{"0X00"},    //Each element is a character string
                        {"00X0"},   //X and 0 represents columns.
                        {"000X"},
                        {"0X00"},};

    int soln[10][10]={0};   //Initialize the array with 0, V.Imp,else system will give random values

    int m=4,n=4;
    bool ans=ratinamaze(maze,soln,0,0,m-1,n-1);
    if(ans==false){
        cout<<"path not found";
    }
    return 0;
}
