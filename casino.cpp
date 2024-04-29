#include<iostream>
#include<vector>
#include<iomanip>
#include<sstream>
#include<ctime>
#include<cstdlib>
#include<string>
#include <unistd.h>//for sleep function
// #include "number"
using namespace std;
//libraries for keyPressed
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#endif
//this was directly given by chatgpt
// Things not created by me 
// 1.keyPressed

bool keyPressed() {
#ifdef _WIN32
    return _kbhit() != 0;
#else
    struct termios oldt, newt;
    int ch;
    int oldf;
    fd_set readfds;
    struct timeval tv;

    // Get the terminal settings
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    // Disable canonical mode and echoing
    newt.c_lflag &= ~(ICANON | ECHO);
    // Apply the new settings
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    // Set stdin to non-blocking mode
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    // Initialize the file descriptor set
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    // Set the timeout
    tv.tv_sec = 0;
    tv.tv_usec = 0;

    // Check if a character is available for reading
    if (select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv) > 0) {
        ch = getchar();
        // Check if a character was read
        if (ch != EOF) {
            // Clear any additional characters from stdin
            while (getchar() != EOF);
            // Restore terminal settings
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
            // Restore stdin to blocking mode
            fcntl(STDIN_FILENO, F_SETFL, oldf);
            return true;
        }
    }

    // Restore terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    // Restore stdin to blocking mode
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    return false;
#endif
}

using namespace std;

// numbers
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


void TDTNP(int a,int b,const vector<numbers>&n){
    //two digit two number printer
    int once1=a%10;
    int tenth1=(a/10);
    tenth1%=10;
    int once2=b%10;
    int tenth2=(b/10);
    tenth2%=10;

    for(int i=0;i<9;i++){
        ostringstream oss;
        oss<<"|"<<setw(15)<<n[tenth1].num[i]<<setw(12)<<n[once1].num[i]<<"   |"<<setw(15)<<n[tenth2].num[i]<<setw(12)<<n[once2].num[i]<<"   |"<<endl;
        cout<<oss.str();
        oss.clear();
        
    }
}


class casinoUI{
    public:
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
    
    void printTop(int tempCoin,string tempCasinoName="rammu",string tempName="prince")
    {   
        
        cout<<"|"<<setfill(' ')<<setw(40)<<tempCasinoName<<setw(22)<<"|"<<endl;
        printMid();
        cout << "|"<<setfill(' ')<< setw(30) << "Name" << "|" << setw(30) << "Coin" << "|" << endl;
        printMid();
        cout <<"|"<<setfill(' ')<< setw(30) << tempName << "|" << setw(30) << tempCoin << "|" << endl;
        
    }

    
    



    void casinoChoice(int t[]){
        vector<numbers>number=numberInizalizer();
        printMid();
        //TDTNP helps to print two numbers at once
        TDTNP(t[0],t[1],number);
        
        cout<<'|'<<setfill('-')<<setw(31)<<"+"<<setw(31)<<"|"<<endl<<setfill(' ');

        TDTNP(t[2],t[3],number);
        printMid();
        
        
    }

    void casinoBoard(int coin,int r[],string casinoName="Raja Rani chor sipahi",string playerName="Makdhumi"){
        printUp();
        printTop(coin,casinoName,playerName);
        casinoChoice(r);
        cout<<"|"<<setw(45-10)<<"Enter Choice"<<setw(17+10)<<"|"<<endl;
        printEnd();
    }
    
};


class casino{
    protected:
    string casinoName="raju ke samose aur chole";
    static float casinoCoins;
    public:
    static float CC(){
        return casinoCoins;
    }
    string CN(){
        return casinoName;
    }

    casino(){
        //Default
    }
};

class player:public casino{

    public:
    float coins;
    string playerName;
    casinoUI casinoPrinter;
    
    //default constructor
    player(string n,float c):playerName(n),coins(c){}

    void win(int a){
        cout<<"Coins:"<<coins<<endl;
        coins+=(2*a);
        cout<<"Coins:"<<coins<<endl;
        string trophy[] = {
        "     ::.::...:::::---.:--     ",
        "   :  :...:  :::::--.::-  :   ",
        " -.-: :...:  :::::--.::- :-.- ",
        "-:  -::...:  :::::--.::-:=  :=",
        "=-   ::...:  :::::-:.---:   -=",
        " :   .::.....:::::-:.:--.   : ",
        " :    ::.....:::::-..:--    : ",
        " -     :.:....::::-..:-:    - ",
        " .:    :..:...::::-.::-    :. ",
        "  -    :..:...::::-::--    -  ",
        "  -.   .:.::..::::-::-:   .-  ",
        "   :    :.::..:::::::-    :   ",
        "   -.   ::::..::::::-:   .-   ",
        "    ::::-::::.::::::--::::    ",
        "     +-   :::..::.::   -=     ",
        "            ::::::            ",
        "              :-              ",
        "             -.-=             ",
        "             :--:             ",
        "              :-              ",
        "              ::              ",
        "              ::              ",
        "              ::              ",
        "              :-              ",
        "              =-              ",
        "             :-==             ",
        "            :=--==            ",
        "          ----------          ",
        "         -:::---:::--         ",
        "        -.::------.--=        ",
        "        -:::-----::--=        ",
        "        -:::-----::--=        ",
        "      =++++++++*********      ",
        "      ==-::::::::::---**      ",
        "      ==-::::::::::---**      ",
        "      +=-::::::::::---**      ",
        "      =+++++++++********      "
    };

    ostringstream oss;
    int i=0;
    int sizeTrophy=sizeof(trophy)/sizeof(trophy[1]);
    casinoPrinter.printUp();
    
    casinoPrinter.printEmptyMid();


    while(i<sizeTrophy-6){
        if(i<16){
            cout<<"|"<<setw(40)<<trophy[i]<<setfill(' ')<<setw(22)<<"|"<<endl;
        }
        else if (i==16){
            cout<<"|"<<setw(40)<<trophy[i]<<setfill(' ')<<setw(15)<<"   You Won "<<setw(62-40-15)<<"|"<<endl;
            
        }

        else if(i==18){
            cout<<"|"<<setw(40)<<trophy[i]<<setfill(' ')<<setw(15)<<"Coins:  "<<setw(5)<<coins<<setw(2)<<"|"<<endl;
        }

        

        else{
            cout<<"|"<<setw(40)<<trophy[i]<<setfill(' ')<<setw(22)<<"|"<<endl;
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

        cout<<"1 ";
        cout.flush();
        sleep(1);
        
        //for Printing ...
        
        for(int i=0;i<3;i++){
            clock_t start=clock();
            cout<<".";
            cout.flush();
            while((clock()-start)/CLOCKS_PER_SEC<.01){
                //do nothing
            }
        }
        cout<<endl;
        
        //console cleared to be
        system("clear");
        play1();

    }
    else {
        system("clear");
        return;
    }


    





    }

    
void lose(int a,int cChoice){
        cout<<"Coins:"<<coins<<endl;

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


    while(i<sizeEmoji){
        if(i<16){
            cout<<"|"<<setw(40)<<sadEmoji[i]<<setfill(' ')<<setw(22)<<"|"<<endl;
        }
        else if (i==16){
            cout<<"|"<<setw(40)<<sadEmoji[i]<<setfill(' ')<<setw(15)<<"   You Lose"<<setw(62-40-15)<<"|"<<endl;
            
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
    cout<<'|'<<setw(20)<<""<<setw(10)<<"Pot was on ` "<< cChoice<<" `"<<setw(62-37)<<"|"<<endl;
    casinoPrinter.printEnd();
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

        cout<<"1 ";
        cout.flush();
        sleep(1);
        
        //for Printing ...
        
        for(int i=0;i<3;i++){
            clock_t start=clock();
            cout<<".";
            cout.flush();
            while((clock()-start)/CLOCKS_PER_SEC<.01){
                //do nothing
            }
        }
        cout<<endl;
        
        //console cleared to be
        system("clear");
        play1();

    }
    else {
        system("clear");
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
        return;
    }
    }
    
    
    void play1(){
        
        //betting
        int bet=0;
        player::bet(bet);

        if(bet==0){
            cout<<"Unexpected Input!\n\tProgram Terminated"<<endl;
            return ;
        }



    

        //Game logic
        
        //changing seed


        srand(time(0));
        
        int choices[4];
        for(int i=0;i<4;i++){
            int temp=1+rand()%100;
            choices[i]=temp;
        }
        //choices made by random function
        casinoPrinter.casinoBoard(coins,choices,casinoName,playerName);
        //choices shown

        srand(time(0));

        

        int cChoice=choices[rand()%4];

        cout<<endl<<endl;

        cout<<"\t\t\t\t";

        int pChoice;
        cin>>pChoice;
        
        // tempcode change after some time

        if(pChoice==cChoice){
            sleep(1);
            win(bet);
        }
        else 
        {
        sleep(1);
        lose(bet,cChoice);
        }

        




    }
        

    void bet(int &a){
        static int trial=2;
        casinoUI printer;
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
        printer.printUp();
        printer.printEmptyMid();
        for(int i=0;i<9;i++){
            ostringstream oss;
            oss<<B[i]<<"        "<<E[i]<<"        "<<T[i];
            cout<<"|"<<setw(50)<<oss.str()<<setw(12)<<"|"<<endl;
        }
        printer.printEmptyMid();
        printer.printMid();
        cout<<"|"<<setw(10)<<" "<<setw(25)<<"Currenlty You Have "<<coins<<" coins"<<setw(20-2)<<"|"<<endl;
        printer.printMid();
        cout<<"|"<<setw(10)<<" "<<setw(25+5)<<"Select Amount To Bet"<<setw(20+2)<<"|"<<endl;
        printer.printEnd();
        cout<<endl;
        cout<<"\t\t\t\t\t    ";
        cin>>a;
        
        
        while ((a > coins || a == 0) && trial!=0){

            printer.printUp();
            cout<<"|"<<setw(10)<<" "<<setw(30)<<"You can't bet for more than "<<coins<<" coins"<<setw(20-2-5)<<"|"<<endl;
            printer.printMid();
            cout<<"|"<<setw(31)<<"Bet again"<<setw(62-1-30)<<"|"<<endl;
            printer.printEnd();

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
        // if(trial<=0) this was the line which was irritating me for the whole time in this program
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


        

        

    }


    



};



void firstPage(){

    casinoUI printer;
    printer.printUp();

    cout<<"|"<<setw(20)<<"Casino "<<setw(10)<<"Game "<<setw(10)<<"|"<<setw(20)<<"By Prince"<<" |"<<endl;

    printer.printMid();
    printer.printEmptyMid();

    cout<<"|"<<setw(30)<<"How"<<setw(3)<<"To"<<setw(5)<<"Play"<<setw(22+2)<<"|"<<endl;

    printer.printEmptyMid();

    printer.printMid();
    cout<<"|"<<setw(3)<<"1."<<" |"<<"  You will now be redirectred to Game Play Bet Menu"<<setw(62-51-3-2)<<"|"<<endl;

    printer.printMid();
    cout<<"|"<<setw(3)<<"2."<<" |"<<"  You are required to choose for the bet."<<setw(62-41-3-2)<<"|"<<endl;

    printer.printMid();
    cout<<"|"<<setw(3)<<"3."<<" |"<<"  After Choosing bet you will see 4 Numbers."<<setw(62-44-3-2)<<"|"<<endl;
    printer.printMid();
    cout<<"|"<<setw(3)<<"4."<<" |"<<"  Choose any one of those."<<setw(62-26-3-2)<<"|"<<endl;
    printer.printMid();
    cout<<"|"<<setw(3)<<"5."<<" |"<<"  If you win bet amount will be doubled and given back."<<setw(62-55-3-2)<<"|"<<endl;
    printer.printMid();
    cout<<"|"<<setw(3)<<"6."<<" |"<<"  If you lose bet amount will not be returned."<<setw(62-46-3-2)<<"|"<<endl;
    printer.printMid();
    cout<<"|"<<setw(3)<<"7."<<" |"<<"  After each round you can Play again."<<setw(62-38-3-2)<<"|"<<endl;
    printer.printEnd();

    printer.printUp();
    
    cout<<"|"<<"  Don't worry you will be given the instruction further"<<setw(62-56-2+3)<<"|"<<endl;
    
    
    
    
    
    printer.printEnd();
    
    // skip button
    {

        std::cout<<endl;
        std::cout<<setw(62-17)<<" "<<setfill('_')<<setw(18)<<" "<<setfill(' ')<<endl;
        std::cout<<setw(62-17)<<"|"<<"Press key to Skip"<<"|"<<endl;
        
        std::cout << " ";
        int i;
        for (i = 0; i < 61-17; i++)
        {
            std::cout << " ";
        }
        for(i;i<61;i++){
            std::cout<<"¯";
        }
        std::cout << endl;
    }

    // . . . 15 sec

    std::cout.flush();
    for(int i=0;i<3;i++){
        clock_t start=clock();
        std::cout<<".";
        std::cout.flush();
        while((clock()-start)/CLOCKS_PER_SEC<5){


        try
        {
            if(keyPressed()){

            throw 10;
        }
            
        }
        catch(...){
            system("clear");

            return ;
            
        }
        }




}}




int main(){
    firstPage();
    player p("Prince",500);
    p.play1();
    return 0;


}

//output for the function number casinoBoard is not coming up to the mark
//try to make the casino ui better
//currently working on single player

//27 march
//now complete the Win and lose function and an winning and losing animation or picutre

//12 April
//today i am goone make the program for betting
//the front page has been made completety and easily

// The Bet function is not working properly ::done

//29th April keypressed is not woing as it should 
// change the places where unnecessary input or output are given

//First page --> bet --> play --> win/lose--*
//                ^                         |
//                |-------------------------*
// this is how currenlty the function flow is
