/**************************************
 * Name: First Come First Serve Tickets
 * Author: Tanner Babcock
 * Created: September 24, 2022
 * Course: CIS 152 - Data Structures
 * Version: 1.0
 * OS: Void GNU/Linux
 * IDE: Emacs
 * Copyright : This is my own original work based
 * on specifications issued by our instructor.
 * Academic Honesty: I attest that this is my original
 * work. I have not used unauthorized source code,
 * either modified or unmodified. I have not given
 * other fellow student(s) access to my program.
**************************************/
#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

int lineSize;
extern int lineSize;
int totalTickets;
extern int totalTickets;

void simulate(int tickets, bool print = false) {
    int customer = 1, quant = 1;
    totalTickets = tickets;
    srand(time(NULL));

    cout << lineSize << " people in line" << endl;
    for (int quant = 1; (totalTickets > 0) && (lineSize > 0); lineSize--) {
        quant = (rand() % 4) + 1;
        if (print)
            cout << quant << " tickets sold to customer " << customer << endl;
        totalTickets -= quant;
        customer++;
    }

    if (totalTickets <= 0)
        cout << "Simulation over - out of tickets" << endl;
    else if (lineSize <= 0)
        cout << "Simulation over - out of customers" << endl;
    cout << "Sold " << tickets << " tickets to " << customer << " customers" << endl;
    cout << lineSize << " customers left in queue" << endl;
}

int main(void) {
    srand(time(NULL));
    lineSize = rand() % 1000;
    cout << "Starting simulation with " << lineSize << " customers and 10 tickets" << endl << endl;
    simulate(10, true);
    cout << endl;

    lineSize = rand() % 1000;
    cout << "Starting simulation with " << lineSize << " customers and 100 tickets" << endl << endl;
    simulate(100);
    cout << endl;

    lineSize = rand() % 1000;
    cout << "Starting simulation with " << lineSize << " customers and 1000 tickets" << endl << endl;
    simulate(1000);
    cout << endl;
    return 0;
}

