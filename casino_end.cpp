#include <iostream>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#endif
using namespace std;
bool isKeyPressed() {
#ifdef _WIN32
    return _kbhit() != 0;
#else
    struct termios oldt, newt;
    int ch;
    int oldf;

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

    // Check if a character is available for reading
    ch = getchar();
    // Restore terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    // Restore stdin to blocking mode
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    // Check if a character was read
    if (ch != EOF) {
        // Clear any additional characters from stdin
        while (getchar() != EOF);
        return true;
    }

    return false;
#endif
}

int main() {
    try{
        if(isKeyPressed()){
            throw 10;
        }
        else{
            clock_t start=clock();
        std::cout<<".";
        std::cout.flush();
        while((clock()-start)/CLOCKS_PER_SEC<5){
            //do nothing
        }}

        }
    catch (...){
        cout<<"KEy pressed\n";
    }
    
    
    std::cout << "A key was pressed. Program terminated.\n";
    return 0;
}
