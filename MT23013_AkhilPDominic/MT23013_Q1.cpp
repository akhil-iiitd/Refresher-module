#include<iostream>
using namespace std;

//counter value to store the total steps taken
int count_val=0;


//function for tower of hanoi with 4 pegs
void towerofhanoi4(int n,int k,int source_peg,int inter_peg1,int inter_peg2,int destination_peg)
{

    //checking if we have reached with last disk on the peg
    //if yes, we would move that to the destination peg 
    if(n==1)
    {
        cout<<"T"<<source_peg<<" -> T"<<destination_peg<<endl;
        //step counter increasing
        count_val++;
    }

    //else 
    else if(n>1)
    {

        //recursive call to the towerofhanoi4 function
        //We would be moving the n-k disks from the source peg to one of the intermediate pegs
        towerofhanoi4(n-k,k,source_peg,inter_peg2,destination_peg,inter_peg1);
        
        //moving second last element in source peg to the other intermediate
        cout<<"T"<<source_peg<<" -> T"<<inter_peg2<<endl;

        //moving the last element in source to the destination peg
        cout<<"T"<<source_peg<<" -> T"<<destination_peg<<endl;

        //finally moving the second last disk in the intermediate peg T2 to the destination
        cout<<"T"<<inter_peg2<<" -> T"<<destination_peg<<endl;

        //step counter increasing
        count_val+=3;

        //recursive call to move the n-k disks in the intermediate peg T1 to the destination peg
        towerofhanoi4(n-k,k,inter_peg1,inter_peg2,source_peg,destination_peg);
    }
}

int main()
{
    //accepting input values from user
    int n,k=2;
    cout<<">> Enter the number of disks :";
    cin>>n;
    cout<<"The sequence of steps are :-"<<endl;
    //function call with the required parameters
    towerofhanoi4(n,k,1,2,3,4);
    cout<<count_val;
    return 0;
}