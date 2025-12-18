#include <bits/stdc++.h>
using namespace std;

class Theater
{
private:
    string theaterName;

public:
    Theater(string name)
    {
        this->theaterName = name;
    }

    string getName()
    {
        return this->theaterName;
    }
};

class Movies
{
private:
    unordered_map<Theater *, unordered_set<string>> theaterToMovies; // Theater To Movies
public:
    Movies(Theater *t1, const vector<string> moviesList)
    {
        this->theaterToMovies[t1].insert(moviesList.begin(), moviesList.end());
    }

    void addMovie(Theater *t1, string movie)
    {
        this->theaterToMovies[t1].insert(movie);
    }

    vector<string> getMoviesList(Theater *t1)
    {
        vector<string> ans;
        for (auto &movie : this->theaterToMovies[t1])
        {
            ans.push_back(movie);
        }
        return ans;
    }
};

class Shows
{
private:
    unordered_map<string, unordered_set<string>> theaterToShows;

public:
    Shows(Theater *t1, const vector<string> shows)
    {
        this->theaterToShows[t1->getName()].insert(shows.begin(), shows.end());
    }

    void addShow(Theater *t1, const string show)
    {
        this->theaterToShows[t1->getName()].insert(show);
    }

    vector<string> getShowsList(Theater *t1)
    {
        auto &show = this->theaterToShows[t1->getName()];
        return vector<string>(show.begin(), show.end());
    }
};

class User
{
private:
    string userName, userLocation;
    int id;
    static int globalUserId;

public:
    User(const string userName, const string userLocation)
    {
        this->userName = userName;
        this->userLocation = userLocation;
        this->id = ++globalUserId;
    }

    string getUserName()
    {
        return userName;
    }
    string getUserLocation()
    {
        return userLocation;
    }
    int userId()
    {
        return id;
    }
};
int User::globalUserId = 0; // Pre Intialize

class Seat
{
private:
    string theaterName;
    string movieName;
    string showName;

public:
    Seat(string theaterName, string movieName, string showName)
    {
        this->theaterName = theaterName;
        this->movieName = movieName;
        this->showName = showName;
    }

    Seat()
    {
    }

    string getSeatByMovie(string theaterName, string movieName)
    {
        return "41";
    }

    string getSeatByShow(string theaterName, string showName)
    {
        return "91";
    }

    void bookSeat(string theaterName, string seatNumber, User *user)
    {
        cout << "Seat Number " << seatNumber << " is Booked For " << user->getUserName() << " " << "For Theater " << theaterName << endl;
    }
};

enum BookingStatus
{
    Hold,
    Booked,
    Cancelled
};
enum PaymentStatus
{
    Success,
    Failed
};

class Booking
{
private:
    string bookingId;
    Seat seat;
    User *user;
    BookingStatus status;

public:
    Booking(Seat seat, User *user)
        : seat(seat), user(user), status(Hold) {}

    void confirm()
    {
        status = Booked;
    }

    void cancel()
    {
        status = Cancelled;
    }
};

class Payment {
private:
    string transactionId;
    double amount;
    PaymentStatus status;

public:
    bool makePayment() {
        status = Success; // assume success
        return true;
    }
};

int main()
{
    //Theater Create
    Theater t1("PVR");
    
    //Add movies
    Movies movies(&t1 , {"Inception", "Interstellar"});

    // Add SHows
    Shows shows(&t1 , {"10:00 AM", "6:00 PM"});

    //Creater User
    User user("Aaju" , "HLD");

    Seat seat;
    string seatNumber = seat.getSeatByMovie("PVR" , "Inception");

    cout << "Seat selected: " << seatNumber << endl;
    cout << "Booking seat on HOLD..." << endl;

    // Payment Processing
    cout << "Processing payment..." << endl;
    bool paymentSuccess = true; 

    if (paymentSuccess) {
        seat.bookSeat("PVR", seatNumber, &user);
        cout << "Booking CONFIRMED" << endl;
    } else {
        cout << "Payment Failed. Booking Cancelled." << endl;
    }

    return 0;
}