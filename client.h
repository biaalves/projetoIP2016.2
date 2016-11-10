#include "default.h"

int network_socket;
struct sockaddr_in server_address;

void connectToServer(const char *server_IP);

int sendMovToServer(mov_msg message);

int readTxtFromServer(char* message);

int getch();

int sendInfoToServer(clientInfo info);

int readUpdFromServer(upd_msg* message);
int getch() {
    struct termios oldt, newt;
    int ch;
    struct pollfd mypoll = { STDIN_FILENO, POLLIN|POLLPRI };
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    if ( poll(&mypoll, 1, 100)){
	    ch = getchar();
	    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	}
	else{
	    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
		return -1;
	}
    return ch;
}
