#include <iostream>
#include<sstream>
#include<iomanip>
using namespace std;
class numbers{
    public:
    string zero[9]={
                " * * * ",
                "*     *",
                "*     *",
                "*     *",
                "*     *",
                "*     *",
                "*     *",
                "*     *",
                " * * * ",
    };
    string one[9]={
                "      *",
                "      *",
                "      *",
                "      *",
                "       ",
                "      *",
                "      *",
                "      *",
                "      *",
    };
    string two[9]={
                " * * * ",
                "      *",
                "      *",
                "      *",
                " * * * ",
                "*      ",
                "*      ",
                "*      ",
                " * * * ",
    };
    string three[9]={
                " * * * ",
                "      *",
                "      *",
                "      *",
                " * * * ",
                "      *",
                "      *",
                "      *",
                " * * * ",
    };
    string four[9]={
                "       ",
                "*     *",
                "*     *",
                "*     *",
                " * * * ",
                "      *",
                "      *",
                "      *",
                "       ",
    };
    string five[9]={
                " ****",
                "*      ",
                "*      ",
                "*      ",
                " * * * ",
                "      *",
                "      *",
                "      *",
                " * * * ",
    };
    string six[9]={
               
                " * * * ",
                "*      ",
                "*      ",
                "*      ",
                " * * * ",
                "*     *",
                "*     *",
                "*     *",
                " * * * ",
    };
    string seven[9]={
                " * * * ",
                "      *",
                "      *",
                "      *",
                "    * *",
                "      *",
                "      *",
                "      *",
                "       ",
    };
    string eight[9]={
                " * * * ",
                "*     *",
                "*     *",
                "*     *",
                " * * * ",
                "*     *",
                "*     *",
                "*     *",
                " * * * ",
    };
    string nine[9]={
                " * * * ",
                "*     *",
                "*     *",
                "*     *",
                " * * * ",
                "      *",
                "      *",
                "      *",
                " * * * ",
    };
    numbers(){
        //default
    }
};

// extern numbers number;
string a="|              *     *          *     *|                    *           *     *|";

int main(){
    numbers n;
    cout << "|"<<setfill(' ')<< setw(30) << "Name" << "|" << setw(30+1) << "Coin" << "|" << endl;
    for(int i=0;i<9;i++){
        cout<<"|";
        ostringstream oss,oss1;
        oss<<n.nine[i]<<"\t"<<n.four[i]<<" ";
        cout<<setw(30)<<oss.str()<<"|";
        oss1<<n.one[i]<<"\t"<<n.eight[i];
        cout<<setw(30)<<oss1.str()<<"|";
        cout<<endl;

    }
}


string newEight[9]={
                "  * *  ",
                "*     *",
                "*     *",
                "*     *",
                "  * *  ",
                "*     *",
                "*     *",
                "*     *",
                "  * *  ",
}
