#include<iostream>
#include<iomanip>
#include<sstream>
#include<vector>
using namespace std;
class numbers{
    public:
    int n;
    string num[9];
    numbers(){}
    void numCopy(string a[9]){
        for(int i=0;i<9;i++){
            num[i]=a[i];
        }
    }
};

vector<numbers> numberInizalizer(){
    vector<numbers> number;

    //this is the style/numberCharacter/whatever you want to call this you can call
    string zero[9]={" * * * ","*     *","*     *","*     *","*     *","*     *","*     *","*     *"," * * * ",};
    string one[9]={"      *","      *","      *","      *","       ","      *","      *","      *","      *",};
    string two[9]={" * * * ","      *","      *","      *"," * * * ","*      ","*      ","*      "," * * * ",};
    string three[9]={" * * * ","      *","      *","      *"," * * * ","      *","      *","      *"," * * * ",};
    string four[9]={"       ","*     *","*     *","*     *"," * * * ","      *","      *","      *","       ",};
    string five[9]={" ****","*      ","*      ","*      "," * * * ","      *","      *","      *"," * * * ",};
    string six[9]={" * * * ","*      ","*      ","*      "," * * * ","*     *","*     *","*     *"," * * * ",};
    string seven[9]={" * * * ","      *","      *","      *","    * *","      *","      *","      *","       ",};
    string eight[9]={" * * * ","*     *","*     *","*     *"," * * * ","*     *","*     *","*     *"," * * * ",};
    string nine[9]={" * * * ","*     *","*     *","*     *"," * * * ","      *","      *","      *"," * * * ",};

    numbers tempNum;
    //this temp num helps in inizilazing the values to the numbers
    //this takes the value first and then push back that number character into number vector


    tempNum.numCopy(zero);
    number.push_back(tempNum);
    number[0].n=0;

    tempNum.numCopy(one);
    number.push_back(tempNum);
    number[1].n=1;

    tempNum.numCopy(two);
    number.push_back(tempNum);
    number[2].n=2;

    tempNum.numCopy(three);
    number.push_back(tempNum);
    number[3].n=3;

    tempNum.numCopy(four);
    number.push_back(tempNum);
    number[4].n=4;

    tempNum.numCopy(five);
    number.push_back(tempNum);
    number[5].n=5;

    tempNum.numCopy(six);
    number.push_back(tempNum);
    number[6].n=6;

    tempNum.numCopy(seven);
    number.push_back(tempNum);
    number[7].n=7;

    tempNum.numCopy(eight);
    number.push_back(tempNum);
    number[8].n=8;

    tempNum.numCopy(nine);
    number.push_back(tempNum);
    number[9].n=9;

    return number;

}

void TDNP(int a,const vector<numbers> & n){
    int once=a%10;
    int tenth=(a/10);
    tenth%=10;
    //if num is 72 then 72%10=2 once and 72/10=7%10=7 tenth
    //once and tenth are the indices for the vecotor
    for(int i=0;i<9;i++){
        cout<<n[tenth].num[i]<<"\t "<<n[once].num[i]<<endl;
    }
}
void TDTNP(int a,int b,const vector<numbers>&n){
    int once1=a%10;
    int tenth1=(a/10);
    tenth1%=10;
    int once2=b%10;
    int tenth2=(b/10);
    tenth2%=10;
    cout<<'|'<<setfill('-')<<setw(62)<<"|"<<endl<<setfill(' ');
    for(int i=0;i<9;i++){
        ostringstream oss;
        oss<<"|"<<setw(15)<<n[tenth1].num[i]<<setw(12)<<n[once1].num[i]<<"   |"<<setw(15)<<n[tenth2].num[i]<<setw(12)<<n[once2].num[i]<<"   |"<<endl;
        cout<<oss.str();
        oss.clear();
        
    }
    cout<<'|'<<setfill('-')<<setw(31)<<"+"<<setw(31)<<"|"<<endl<<setfill(' ');
}
int main(){
    cout.clear();
    vector<numbers> pq;
    pq=numberInizalizer();
    
    TDTNP(72,50,pq);
    return 0;

   
}