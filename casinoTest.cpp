#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    
    cout<<"|"<<"  Don't worry you will be given the instruction further"<<setw(62-56-2+3)<<"|"<<endl;
    {
    cout<<setw(62-11)<<" "<<setfill('_')<<setw(12)<<" "<<setfill(' ')<<endl;
    cout<<setw(62-11)<<"|"<<"Wrong input"<<"|"<<endl;
    
    cout << " ";
        int i;
        for (i = 0; i < 61-11; i++)
        {
            cout << " ";
        }
        for(i;i<61;i++){
            cout<<"¯";
        }
        cout << endl;
    }}