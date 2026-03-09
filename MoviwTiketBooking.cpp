#include <iostream>
#include <string>
using namespace std;

int main()
{
    int choice;
    int movieChoice;
    int seats;
    int totalBill = 0;
    int bookedSeats = 0;
    int bookedSeatsPerMovie[3] = {0, 0, 0};
    int revenuePerMovie[3] = {0, 0, 0};

    string movies[3] = {"Bahubali", "Avengers", "Lion King"};
    string showTime[3] = {"10:00 AM", "2:00 PM", "6:00 PM"};
    int price[3] = {200, 250, 300};

    do
    {
        cout << "\n===== Movie Ticket Booking System =====\n";
        cout << "1. Display Movie List\n";
        cout << "2. Book Ticket\n";
        cout << "3. Show Booked Movies\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\nAvailable Movies:\n";
                cout << "---------------------------------\n";
                cout << "No  Movie Name     Show Time    Price\n";

                for(int i = 0; i < 3; i++)
                {
                    cout << i+1 << "   "
                         << movies[i] << "     "
                         << showTime[i] << "     "
                         << price[i] << endl;
                }
                break;

            case 2:
                cout << "\nSelect Movie Number: ";
                cin >> movieChoice;

                if(movieChoice >= 1 && movieChoice <= 3)
                {
                    cout << "Movie: " << movies[movieChoice-1] << endl;
                    cout << "Show Time: " << showTime[movieChoice-1] << endl;
                    cout << "Ticket Price: " << price[movieChoice-1] << endl;

                    cout << "Enter number of seats: ";
                    cin >> seats;

                    totalBill = seats * price[movieChoice-1];
                    bookedSeats += seats;
                    // update per-movie counters
                    bookedSeatsPerMovie[movieChoice-1] += seats;
                    revenuePerMovie[movieChoice-1] += totalBill;

                    cout << "\nMovie Booked Successfully!\n";
                    cout << "Movie Name: " << movies[movieChoice-1] << endl;
                    cout << "Show Time: " << showTime[movieChoice-1] << endl;
                    cout << "Seats Booked: " << seats << endl;
                    cout << "Total Amount: " << totalBill << endl;
                }
                else
                {
                    cout << "Invalid movie selection!\n";
                }

                break;

            case 3:
                if (bookedSeats > 0) {
                    cout << "\n--- Booking Summary ---\n";
                    int totalRevenue = 0;
                    for (int i = 0; i < 3; ++i) {
                        if (bookedSeatsPerMovie[i] > 0) {
                            cout << "Movie: " << movies[i]
                                 << " | Seats: " << bookedSeatsPerMovie[i]
                                 << " | Amount: " << revenuePerMovie[i] << endl;
                            totalRevenue += revenuePerMovie[i];
                        }
                    }
                    cout << "------------------------\n";
                    cout << "Total Seats Booked so far: " << bookedSeats << endl;
                    cout << "Total Revenue: " << totalRevenue << endl;
                } else {
                    cout << "\nNo movies booked yet!\n";
                }
                break;

            case 4:
                cout << "\nThank you for using Movie Ticket Booking System.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 4);

    return 0;
}
