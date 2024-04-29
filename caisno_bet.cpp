#include<iostream>
#include<vector>
#include<iomanip>
#include<sstream>
#include <unistd.h>

using namespace std;

void printUp(){
        cout<<" "<<setw(62)<<setfill('_')<<" "<<endl<<setfill(' ');
    }
void printMid(){
    cout<<'|'<<setfill('-')<<setw(62)<<"|"<<endl<<setfill(' ');


}
void printEmptyMid(){
    cout<<'|'<<setfill(' ')<<setw(62)<<"|"<<endl<<setfill(' ');


}
void printEnd(){
    cout << " ";
    for (int i = 0; i < 61; i++)
    {
        cout << "¯";
    }
    cout << endl;
}


int coins=500;
void bet(int &a){
        static int trial=2;
        cout<<"Coins:"<<coins<<endl;
        string B[9]={
                    "* * *  ","*     *","*     *","*     *","* * *  ","*     *","*     *","*     *","* * *  ",
        };

        string E[9]={
                    "* * * *","*      ","*      ","*      ","* * * *","*      ","*      ","*      ","* * * *",
        };
        string T[9]={
                    "* * * * *","    *    ","    *    ","    *    ","    *    ","    *    ","    *    ","    *    ","    *    ",
        };
printUp();
printEmptyMid();
        for(int i=0;i<9;i++){
            ostringstream oss;
            oss<<B[i]<<"        "<<E[i]<<"        "<<T[i];
            cout<<"|"<<setw(50)<<oss.str()<<setw(12)<<"|"<<endl;
        }
printEmptyMid();
printMid();
        cout<<"|"<<setw(10)<<" "<<setw(25)<<"Currenlty You Have "<<coins<<" coins"<<setw(20-2)<<"|"<<endl;
printMid();
        cout<<"|"<<setw(10)<<" "<<setw(25+5)<<"Select Amount To Bet"<<setw(20+2)<<"|"<<endl;
printEnd();
        cout<<endl;
        cout<<"\t\t\t\t\t    ";
        cin>>a;
        
        
        while ((a > coins || a == 0) && trial!=0){

printUp();
            cout<<"|"<<setw(10)<<" "<<setw(30)<<"You can't bet for more than "<<coins<<" coins"<<setw(20-2-5)<<"|"<<endl;
printMid();
            cout<<"|"<<setw(31)<<"Bet again"<<setw(62-1-30)<<"|"<<endl;
printEnd();

            cout<<"This is your Trial No. "<<3-trial<<endl<<"\tNew Page for betting in ";
            cout<<3<<" ";
            cout.flush();
            sleep(1);
            cout<<2<<" ";
            cout.flush();
            sleep(1);
            cout<<1<<" ";
            cout.flush();
            for(int i=0;i<3;i++){
                clock_t start=clock();
                cout<<".";
                cout.flush();
                while((clock()-start)/CLOCKS_PER_SEC<.01){
                    //do nothing
                }
            }

            cout<<endl;
            system("clear");
            trial--;
            bet(a);
            return;


        }
        if (trial<0){
            cout<<"Trial Ended , Exiting Program ";
            cout<<3<<" ";
            cout.flush();
            sleep(1);
            cout<<2<<" ";
            cout.flush();
            sleep(1);
            cout<<1<<" ";
            cout.flush();
            for(int i=0;i<3;i++){
                clock_t start=clock();
                cout<<".";
                cout.flush();
                while((clock()-start)/CLOCKS_PER_SEC<.01){
                    //do nothing
                }
            }

            cout<<endl;
            system("clear");
            return;

        }

        coins-=a;
        trial=2;
        
        system("clear");
        cout<<"value captured"<<endl;

        

        

    }


    




int main(){
    int t;
    while(true){
    bet(t);
    cout<<t;}
}

