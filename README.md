**Flight Reservation System Documentation**

### Introduction

This C++ program implements a simple Flight Reservation System. It allows users to book and cancel flight tickets, view available seats and fare, and display the list of booked tickets for a specific flight.

### Code Structure

The program is structured into three classes: `Passenger`, `Flight`, and `ReservationSystem`. The `main` function initializes a `ReservationSystem` with a specified number of flights and provides a menu for users to interact with the system.

#### Passenger Struct

- Represents a passenger with attributes `p_id` (Passenger ID), `seats` (number of seats booked), and `amount` (amount paid).

#### Flight Class

- Manages the details and operations related to a flight.
- Attributes:
  - `flight_no`: Flight number.
  - `remainingSeats`: Number of available seats.
  - `currentFare`: Current fare for a seat.
  - `bookedTickets`: Vector to store booked tickets.
- Methods:
  - `getFlightNo()`: Get the flight number.
  - `printBookedTickets()`: Print details of booked tickets for the flight.
  - `printAvailableTicketsAndFare()`: Print available seats and current fare for the flight.
  - `displayBookedDetails()`: Display details of booked tickets for the flight.
  - `bookTicket()`: Allow booking a ticket for the flight.
  - `cancelTicket()`: Cancel a booked ticket for the flight.

#### ReservationSystem Class

- Manages multiple flights.
- Attributes:
  - `flights`: Vector of Flight objects.
- Methods:
  - `printBookedTickets()`: Print details of booked tickets for all flights.
  - `printFlightDetails()`: Print available seats and fare for a specific flight.
  - `bookTicket()`: Book a ticket for a specific flight.
  - `cancelTicket()`: Cancel a booked ticket for a specific flight.

#### Main Function

- Initializes a `ReservationSystem` with 2 flights.
- Implements a menu-driven loop allowing users to perform various operations:
  - Book a ticket.
  - Cancel a ticket.
  - View available seats and fare for a flight.
  - Print the list of booked tickets.
  - Exit the program.

### Usage

1. Run the program.
2. Choose options from the menu to interact with the Flight Reservation System.

### Note

- The program assumes a fixed initial number of available seats (50) and an initial fare of $5000.
- Fare increases by $200 for each seat booked.

### Conclusion

This Flight Reservation System provides basic functionality for managing flight bookings and cancellations. Users can easily extend the system by adding more features and error handling based on specific requirements.
