
#include<iostream>
#include<vector>
#include<iomanip>
#include<sstream>



#include<string>
using namespace std;



int coins=100;
int matchWon=0;
int matchPlayed=9;



void lose(int a){
        coins+=a;
        matchWon++;
        string sadEmoji[] = {
                                     
"          .::::::::.           ",
"       ::::::::::::::          ",
"      ::::::::::::::::         ",
"     .::::::::::::::::::.      ",
"    .::::::::::::::::::::.     ",
"    ::::::::::::::::::::::     ",
"   :::::::##::::::##:::::::    ",
"  :::::::+#*::::::*#+:::::::   ",
"  ::::::###::::::::###::::::   ",
" .::::-##+::::::::::+##-::::.  ",
" ::::###::::::::::::::###::::  ",
" ::::#::::::::::::::::::#::::  ",
" :::::#######::::#######:::::  ",
" :::::##--.*#::::##:--*#:::::  ",
" ::::::---::::::::::---::::::  ",
" ::::::---::::::::::---::::::  ",
" ::::::---::::**::::---::::::  ",
" ::::::---:::####:::---::::::  ",
" .:::::---::+####+::---:::::.  ",
"  :::::---::##**##::---:::::   ",
"  :::::---::#++++#::---:::::   ",
"   ::::---::#++++#::---::::    ",
"    :::---::#*++*#::---:::     ",
"    .::---:::.--.:::---::.     ",
"     .:---::::::::::---:.      ",
"    .:------------------:.     ",
" ----------------------------  ",
"   ------------------------    "
                    
    };

    ostringstream oss;
    int i=0;
    int sizeEmoji=sizeof(sadEmoji)/sizeof(sadeEoji[1]);
    cout<<'|'<<setfill('-')<<setw(62)<<"|"<<endl<<setfill(' ');
    while(i<sizeEmoji){
        if(i<16){
            cout<<"|"<<setw(40)<<sadEmoji[i]<<setfill(' ')<<setw(22)<<"|"<<endl;
        }
        else if (i==16){
            cout<<"|"<<setw(40)<<sadEmoji[i]<<setfill(' ')<<setw(15)<<"   You Won "<<setw(62-40-15)<<"|"<<endl;
            
        }

        else if(i==18){
            cout<<"|"<<setw(40)<<sadEmoji[i]<<setfill(' ')<<setw(15)<<"Coins:  "<<setw(5)<<coins<<setw(2)<<"|"<<endl;
        }

        

        else{
            cout<<"|"<<setw(40)<<sadEmoji[i]<<setfill(' ')<<setw(22)<<"|"<<endl;
        }
        i++;

    }



    }

int main(){
    lose(200);
}




void lose(int a){
        coins-=a;

        string sadEmoji[] = {
                                                
            "          .::::::::.           ",
            "       ::::::::::::::          ",
            "      ::::::::::::::::         ",
            "     .::::::::::::::::::.      ",
            "    .::::::::::::::::::::.     ",
            "    ::::::::::::::::::::::     ",
            "   :::::::##::::::##:::::::    ",
            "  :::::::+#*::::::*#+:::::::   ",
            "  ::::::###::::::::###::::::   ",
            " .::::-##+::::::::::+##-::::.  ",
            " ::::###::::::::::::::###::::  ",
            " ::::#::::::::::::::::::#::::  ",
            " :::::#######::::#######:::::  ",
            " :::::##--.*#::::##:--*#:::::  ",
            " ::::::---::::::::::---::::::  ",
            " ::::::---::::::::::---::::::  ",
            " ::::::---::::**::::---::::::  ",
            " ::::::---:::####:::---::::::  ",
            " .:::::---::+####+::---:::::.  ",
            "  :::::---::##**##::---:::::   ",
            "  :::::---::#++++#::---:::::   ",
            "   ::::---::#++++#::---::::    ",
            "    :::---::#*++*#::---:::     ",
            "    .::---:::.--.:::---::.     ",
            "     .:---::::::::::---:.      ",
            "    .:------------------:.     ",
            " ----------------------------  ",
            "   ------------------------    "
                                
            };

            ostringstream oss;
    int i=0;
    int sizeEmoji=sizeof(sadEmoji)/sizeof(sadEmoji[1]);
    casinoPrinter.printUp();
    
    casinoPrinter.printEmptyMid();


    while(i<sizeEmoji-6){
        if(i<16){
            cout<<"|"<<setw(40)<<sadEmoji[i]<<setfill(' ')<<setw(22)<<"|"<<endl;
        }
        else if (i==16){
            cout<<"|"<<setw(40)<<sadEmoji[i]<<setfill(' ')<<setw(15)<<"   You Won "<<setw(62-40-15)<<"|"<<endl;
            
        }

        else if(i==18){
            cout<<"|"<<setw(40)<<sadEmoji[i]<<setfill(' ')<<setw(15)<<"Coins:  "<<setw(5)<<coins<<setw(2)<<"|"<<endl;
        }

        

        else{
            cout<<"|"<<setw(40)<<sadEmoji[i]<<setfill(' ')<<setw(22)<<"|"<<endl;
        }
        i++;

    }

    casinoPrinter.printEnd();
    


    //input for restart of the match
    casinoPrinter.printUp();
    cout<<'|'<<setw(20)<<""<<setw(10)<<"Want To play More (y/n)"<<setw(20-1)<<"|"<<endl;
    casinoPrinter.printEnd();

    char ch='n';
    cout<<setw(35)<<"";
    cin>>ch;
    if(ch=='y'||ch=='Y'){
        cout<<"Next rount in ";
        //3 2 1
        cout<<"3 ";
        cout.flush();
        sleep(1);

        cout<<"2 ";
        cout.flush();
        sleep(1);

        cout<<"1 ...";
        cout.flush();
        sleep(1);
        

        //for Printing ...
        
        //console cleared to be
        system("clear");
        play1();

    }
    else {
        system("clear");
        return;
    }
    }
    