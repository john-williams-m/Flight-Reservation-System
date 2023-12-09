#include <iostream>
#include <vector>
#include <string>
int passenger_ID = 1;
using namespace std;

struct Passenger
{
    int p_id;
    int seats;
    int amount;
};

class Flight
{
    int flight_no;
    int remainingSeats;
    int currentFare;
    vector<Passenger> bookedTickets;

public:
    Flight(int f_no) : flight_no(f_no), remainingSeats(50), currentFare(5000) {}

    int getFlightNo() { return flight_no; }

    void printBookedTickets()
    {
        for (auto &ticket : bookedTickets)
        {
            cout << "Passenger ID:" << ticket.p_id << ", No. of seats booked:" << ticket.seats << ", Amount:" << ticket.amount << endl;
        }
    }

    void printAvailableTicketsAndFare()
    {
        cout << "Flight Number:" << flight_no;
        cout << ", Available seats:" << remainingSeats << ", Fare:" << currentFare << endl;
    }

    void displayBookedDetails()
    {
        cout << "Passenger Details for Flight Number:" << flight_no << endl;
        for (Passenger &ticket : bookedTickets)
        {
            cout << "Passenger ID:" << ticket.p_id << ", No. of seats booked:" << ticket.seats << ", Amount paid:" << ticket.amount << endl;
        }
    }

    void bookTicket()
    {
        if (remainingSeats <= 0)
        {
            cout << "No seats available" << endl;
            return;
        }
        cout << "Ticket fare:" << currentFare << endl;
        int seats;
        cout << "Enter the No. of seats required:";
        cin >> seats;
        if (seats > remainingSeats)
        {
            cout << "Sufficient number of seats is not available" << endl;
            return;
        }

        int ticketFare = seats * currentFare;
        currentFare += (200 * seats);
        remainingSeats -= seats;
        Passenger p = {passenger_ID++, seats, ticketFare};
        bookedTickets.push_back(p);
        cout << "Ticket Booked successfully!\n No. of seats booked:" << seats << "\nAmount:" << ticketFare << endl;
    }

    void cancelTicket(int p_id)
    {
        bool isCancel(false);
        vector<Passenger>::iterator it = bookedTickets.begin();
        for (; it != bookedTickets.end(); it++)
        {
            if (it->p_id == p_id)
            {
                isCancel = true;
                int noOfSeats = it->seats;
                int refundAmount = it->amount;
                remainingSeats += noOfSeats;
                currentFare -= (noOfSeats * 200);
                bookedTickets.erase(it);
                cout << "Ticket cancelled successfully!" << endl;
                break;
            }
        }
        if (!isCancel)
        {
            cout << "Cancellation failed!" << endl;
        }
    }
};

class ReservationSystem
{
    vector<Flight> flights;

public:
    ReservationSystem(int noOfFlights)
    {
        for (int i = 0; i < noOfFlights; i++)
        {
            flights.push_back(Flight(i + 1));
        }
    }

    void printBookedTickets()
    {
        for (auto &flight : flights)
        {
            flight.displayBookedDetails();
        }
    }

    void printFlightDetails()
    {
        int f_no;
        cout << "Enter the Flight No:";
        cin >> f_no;
        for (auto &flight : flights)
        {
            if (flight.getFlightNo() == f_no)
            {
                flight.printAvailableTicketsAndFare();
                return;
            }
        }
        cout << "Invalid Flight No." << endl;
    }

    void bookTicket()
    {
        int f_no;
        cout << "Enter the Flight No:";
        cin >> f_no;
        for (auto &flight : flights)
        {
            if (flight.getFlightNo() == f_no)
            {
                flight.bookTicket();
                return;
            }
        }
        cout << "Invalid Flight No." << endl;
    }

    void cancelTicket()
    {
        int f_no, p_id;
        cout << "Enter the Flight No:";
        cin >> f_no;
        cout << "Enter passenger ID:";
        cin >> p_id;
        for (auto &flight : flights)
        {
            if (flight.getFlightNo() == f_no)
            {
                flight.cancelTicket(p_id);
                return;
            }
        }
        cout << "Invalid Details." << endl;
    }
};

int main()
{
    ReservationSystem system(2);
    int choice;
    do
    {
        cout << endl;
        cout << "1. Book\n2. Cancel\n3. Available seats and Fare\n4.Print Booked ticket list\n5.Exit\nEnter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system.bookTicket();
            break;
        case 2:
            system.cancelTicket();
            break;
        case 3:
            system.printFlightDetails();
            break;
        case 4:
            system.printBookedTickets();
            break;
        default:
            break;
        }
    } while (choice != 5);
}