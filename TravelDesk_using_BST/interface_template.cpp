#include <iostream>
#include <map>
#include <vector>

class Vehicle {
public:
    Vehicle(std::string vehicle_number, int seating_capacity)
        : vehicle_number(vehicle_number), seating_capacity(seating_capacity) {}

    // Getter for vehicle_number
    std::string getVehicleNumber() const {
        return vehicle_number;
    }

    // Setter for vehicle_number
    void setVehicleNumber(const std::string& new_vehicle_number) {
        vehicle_number = new_vehicle_number;
    }

    // Getter for seating_capacity
    int getSeatingCapacity() const {
        return seating_capacity;
    }

    // Setter for seating_capacity
    void setSeatingCapacity(int new_seating_capacity) {
        seating_capacity = new_seating_capacity;
    }

    // Getter for trips
    const std::vector<Trip*>& getTrips() const {
        return trips;
    }

    // Add a trip to the vehicle
    void addTrip(Trip* trip) {
        trips.push_back(trip);
    }

private:
    std::string vehicle_number;
    int seating_capacity;
    std::vector<Trip*> trips;
};

class Trip {
public:
    Trip(Vehicle* vehicle, std::string pick_up_location, std::string drop_location, int departure_time)
        : vehicle(vehicle), pick_up_location(pick_up_location), drop_location(drop_location), departure_time(departure_time), booked_seats(0) {}

    // Getter for vehicle
    Vehicle* getVehicle() const {
        return vehicle;
    }

    // Getter for pick_up_location
    std::string getPickUpLocation() const {
        return pick_up_location;
    }

    // Setter for pick_up_location
    void setPickUpLocation(const std::string& new_pick_up_location) {
        pick_up_location = new_pick_up_location;
    }

    // Getter for drop_location
    std::string getDropLocation() const {
        return drop_location;
    }

    // Setter for drop_location
    void setDropLocation(const std::string& new_drop_location) {
        drop_location = new_drop_location;
    }

    // Getter for departure_time
    int getDepartureTime() const {
        return departure_time;
    }

    // Setter for departure_time
    void setDepartureTime(int new_departure_time) {
        departure_time = new_departure_time;
    }

    // Getter for booked_seats
    int getBookedSeats() const {
        return booked_seats;
    }

    // Setter for booked_seats
    void setBookedSeats(int new_booked_seats) {
        booked_seats = new_booked_seats;
    }

private:
    Vehicle* vehicle;
    std::string pick_up_location;
    std::string drop_location;
    int departure_time;
    int booked_seats;
};

class Location {
public:
    Location(std::string name, TransportService* serviceptr = nullptr)
        : name(name), serviceptr(serviceptr) {}

    // Getter for name
    std::string getName() const {
        return name;
    }

    // Setter for name
    void setName(const std::string& new_name) {
        name = new_name;
    }

    // Getter for serviceptr
    TransportService* getServicePtr() const {
        return serviceptr;
    }

    // Setter for serviceptr
    void setServicePtr(TransportService* new_serviceptr) {
        serviceptr = new_serviceptr;
    }

private:
    std::string name;
    TransportService* serviceptr;
};

class BSTNode {
public:
    BSTNode(int departuretime = 0, Trip* tripnodeptr = nullptr)
        : leftptr(nullptr), rightptr(nullptr), departuretime(departuretime), tripnodeptr(tripnodeptr) {
    }

    // Getter for leftptr
    BSTNode* getLeftPtr() const {
        return leftptr;
    }

    // Setter for leftptr
    void setLeftPtr(BSTNode* new_leftptr) {
        leftptr = new_leftptr;
    }

    // Getter for rightptr
    BSTNode* getRightPtr() const {
        return rightptr;
    }

    // Setter for rightptr
    void setRightPtr(BSTNode* new_rightptr) {
        rightptr = new_rightptr;
    }

    // Getter for departuretime
    int getDepartureTime() const {
        return departuretime;
    }

    // Setter for departuretime
    void setDepartureTime(int new_departuretime) {
        departuretime = new_departuretime;
    }

    // Getter for tripenodeptr
    Trip* getTripNodePtr() const {
        return tripnodeptr;
    }

    // Setter for tripenodeptr
    void setTripNodePtr(Trip* new_tripnodeptr) {
        tripnodeptr = new_tripnodeptr;
    }

private:
    BSTNode* leftptr;
    BSTNode* rightptr;
    int departuretime;
    Trip* tripnodeptr;
};

class TransportService {
public:
    TransportService(Location* locationptr = nullptr, BSTNode* BSThead = nullptr)
        : locationptr(nullptr), BSThead(nullptr) {}

    // Getter for locationptr
    Location* getLocationPtr() const {
        return locationptr;
    }

    // Setter for locationptr
    void setLocationPtr(Location* new_locationptr) {
        locationptr = new_locationptr;
    }

    // Getter for BSThead
    BSTNode* getBSTHead() const {
        return BSThead;
    }

    // Setter for BSThead
    void setBSTHead(BSTNode* new_BSThead) {
        BSThead = new_BSThead;
    }

private:
    Location* locationptr;
    BSTNode* BSThead;
};

class TravelDesk {
public:
    void add_trip(std::string vehicle_number, int seating_capacity, std::string pick_up_location, std::string drop_location, int departure_time) {
        // Check if the vehicle already exists, if not, create a new one with the seating capacity
        Vehicle* vehicle = nullptr;

        // Create a new trip and add it to the appropriate objects

        // Create or retrieve the Location object and associated pick up location

        // Add the trip to the TransportService's BST
    }

    std::vector<Trip*> show_trips(std::string pick_up_location, int after_time, int before_time) {
        // Retrieve the relevant TransportService first then iterate over the bst to find Function to retrieve trips within a specified time range
        return {};
    }

    Trip* book_trip(std::string pick_up_location, std::string drop_location, std::string vehicle_number, int departure_time) {
        // Find the corresponding trip to book the seat and have proper validation example booked seats should always be less than total seats

        return nullptr;
    }

private:
    std::vector<Vehicle*> vehicles;
    std::vector<Location*> Locations;
};


int main()
{
    
}