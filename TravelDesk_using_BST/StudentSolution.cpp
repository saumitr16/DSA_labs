#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Vehicle;

class Trip {
public:
    Trip(Vehicle* vehicle, std::string pick_up_location, std::string drop_location, int departure_time)
        : vehicle(vehicle), pick_up_location(pick_up_location), drop_location(drop_location), departure_time(departure_time), booked_seats(0) {}

    // Getter functions
    Vehicle* getVehicle() const {
        return vehicle;
    }

    std::string getPickUpLocation() const {
        return pick_up_location;
    }

    std::string getDropLocation() const {
        return drop_location;
    }

    int getDepartureTime() const {
        return departure_time;
    }

    int getBookedSeats() const {
        return booked_seats;
    }

    // Setter functions
    void setVehicle(Vehicle* v) {
        vehicle = v;
    }

    void setPickUpLocation(std::string location) {
        pick_up_location = location;
    }

    void setDropLocation(std::string location) {
        drop_location = location;
    }

    void setDepartureTime(int time) {
        departure_time = time;
    }

    void setBookedSeats(int seats) {
        booked_seats = seats;
    }

private:
    Vehicle* vehicle;
    std::string pick_up_location;
    std::string drop_location;
    int departure_time;
    int booked_seats;
};

class BinaryTreeNode;

class TransportService {
public:
    TransportService(std::string name) : name(name), BSThead(nullptr) {}

    // Getter functions
    std::string getName() const {
        return name;
    }

    BinaryTreeNode* getBSTHead() const {
        return BSThead;
    }

    // Setter functions
    void setName(std::string service_name) {
        name = service_name;
    }

    void setBSTHead(BinaryTreeNode* node) {
        BSThead = node;
    }

    void addTrip(int key, Trip* trip);

   

private:
    std::string name;
    BinaryTreeNode* BSThead;
};

class BinaryTreeNode {
public:
    BinaryTreeNode(int departuretime = 0, Trip* tripenodeptr = nullptr, BinaryTreeNode* parentptr = nullptr)
        : leftptr(nullptr), rightptr(nullptr), parentptr(parentptr), departuretime(departuretime), tripnodeptr(tripenodeptr) {}

    // Getter functions
    BinaryTreeNode* getLeftPtr() const {
        return leftptr;
    }

    BinaryTreeNode* getRightPtr() const {
        return rightptr;
    }

    BinaryTreeNode* getParentPtr() const {
        return parentptr;
    }

    int getDepartureTime() const {
        return departuretime;
    }

    Trip* getTripNodePtr() const {
        return tripnodeptr;
    }

    // Setter functions
    void setLeftPtr(BinaryTreeNode* left) {
        leftptr = left;
    }

    void setRightPtr(BinaryTreeNode* right) {
        rightptr = right;
    }

    void setParentPtr(BinaryTreeNode* parent) {
        parentptr = parent;
    }

    void setDepartureTime(int time) {
        departuretime = time;
    }

    void setTripNodePtr(Trip* trip) {
        tripnodeptr = trip;
    }

private:
    BinaryTreeNode* leftptr;
    BinaryTreeNode* rightptr;
    BinaryTreeNode* parentptr;
    int departuretime;
    Trip* tripnodeptr;
};

class Vehicle {
public:
    Vehicle(std::string vehicle_number, int seating_capacity)
        : vehicle_number(vehicle_number), seating_capacity(seating_capacity) {}

    // Getter functions
    std::string getVehicleNumber() const {
        return vehicle_number;
    }

    int getSeatingCapacity() const {
        return seating_capacity;
    }

    // Setter functions
    void setVehicleNumber(std::string number) {
        vehicle_number = number;
    }

    void setSeatingCapacity(int capacity) {
        seating_capacity = capacity;
    }

    void addTrip(Trip* trip) {
        trips.push_back(trip);
    }
    std::vector<Trip*>getTrips()
    {
        return trips;
    }

private:
    std::string vehicle_number;
    int seating_capacity;
    std::vector<Trip*> trips;
};

class Location {
public:
    Location(std::string name) : name(name) {}

    // Getter functions
    std::string getName() const {
        return name;
    }

    TransportService* getServicePtr(std::string droplocation) const {

        TransportService*t;

        for(int i=0;i<serviceptrs.size();i++){
            if(serviceptrs[i]->getName()==droplocation)
            {
                t=serviceptrs[i];
            }
        }
          return t;

    }

    // Setter functions
    void setName(std::string location_name) {
        name = location_name;
    }

    TransportService* setServicePtr(std::string droplocation) {
        return nullptr;
    }

     TransportService* addServiceptr(TransportService*t)
    {
        serviceptrs.push_back(t);
    }

    void addTrip(Trip* trip) {
        trips.push_back(trip);
    }
     
       std::vector<Trip*>returnTrips()
    {
        return trips;
    }

       std::vector<TransportService*>returnServicePtr()
    {
        return serviceptrs;
    }

private:
    std::string name;
    std::vector<TransportService* >serviceptrs;
    std::vector<Trip*> trips;
};

class BinaryTree {
protected:
    BinaryTreeNode* root;

public:
    BinaryTree() : root(nullptr) {}

    int getHeight() const {
        // Implement this function to return the height of the tree
        return 0; // Placeholder
    }

    int getNumberOfNodes() const {
        // Implement this function to return the number of nodes in the tree
        return 0; // Placeholder
    }
};

class BinarySearchTree : public BinaryTree {
public:
    BinarySearchTree() {}

    BinaryTreeNode* getElementWithMinimumKey() const {
        // Implement this function to return the element with the minimum key
        return nullptr; // Placeholder
    }

    BinaryTreeNode* getElementWithMaximumKey() const {
        // Implement this function to return the element with the maximum key
        return nullptr; // Placeholder
    }

    BinaryTreeNode* searchNodeWithKey(int key) const {
        // Implement this function to search for a node with the given key or the next larger key
        return nullptr; // Placeholder
    }

    BinaryTreeNode* getSuccessorNode(BinaryTreeNode* node) const {
        // Implement this function to return the successor node of the given node
        return nullptr; // Placeholder
    }

    BinaryTreeNode* getSuccessorNodeByKey(int key) const {
        // Implement this function to return the successor node by key
        return nullptr; // Placeholder
    }

    BinaryTreeNode* getPredecessorNode(BinaryTreeNode* node) const {
        // Implement this function to return the predecessor node of the given node
        return nullptr; // Placeholder
    }

    BinaryTreeNode* getPredecessorNodeByKey(int key) const {
        // Implement this function to return the predecessor node by key
        return nullptr; // Placeholder
    }
};




class TravelDesk {
public:

 BinaryTreeNode* insertnode(BinaryTreeNode* b, BinaryTreeNode* bs, Trip* t, TransportService* ts)
{
    int time = bs->getDepartureTime();
    if (b == nullptr)
    {
        bs->setTripNodePtr(t);
        ts->setBSTHead(bs);
        
        BinaryTreeNode* tree = ts->getBSTHead();
        
        return tree;
    }
    else
    {
        if (time >= b->getDepartureTime())
        {
            b->setRightPtr(insertnode(b->getRightPtr(), bs, t, ts));
        }
        else
        {
            b->setLeftPtr(insertnode(b->getLeftPtr(), bs, t, ts));
        }

        return b; // Return the updated root node after insertion
    }
}












void addTrip(std::string vehicle_number, int seating_capacity, std::string pick_up_location, std::string drop_location, int departure_time)
{
    // Implement this function to add a trip
    Vehicle* vehicle = nullptr;
    Trip* t;
    int ct;
    
    for (ct = 0; ct < vehicles.size(); ct++)
    {
        if (vehicles[ct]->getVehicleNumber() == vehicle_number)
        {
            // cout << "checkpoint 1" << endl;
            t = new Trip(vehicles[ct], pick_up_location, drop_location, departure_time);
            vehicles[ct]->addTrip(t);
            break;
        }
    }

    if (ct == vehicles.size())
    {
        vehicle = new Vehicle(vehicle_number, seating_capacity);
        // cout << "checkpoint 1" << vehicle_number << endl;
        t = new Trip(vehicle, pick_up_location, drop_location, departure_time);
        vehicle->addTrip(t);
        vehicles.push_back(vehicle);
    }

    for (ct = 0; ct < locations.size(); ct++)
    {
        if (locations[ct]->getName() == pick_up_location)
        {
            locations[ct]->addTrip(t);
            break;
        }
    }

    if (locations.size() == ct)
    {
        Location* loc = new Location(pick_up_location);
        loc->addTrip(t);
        locations.push_back(loc);
    }

    TransportService* ts = nullptr;
    BinaryTreeNode* bs = new BinaryTreeNode;
    bs->setDepartureTime(departure_time);

    for (ct = 0; ct < locations.size(); ct++)
    {
        if (locations[ct]->getName() == drop_location)
        {
            ts = locations[ct]->getServicePtr(drop_location);
            break;
        }
    }

    if (ct == locations.size())
    {
        ts = new TransportService(drop_location);
        locations[ct]->setServicePtr(drop_location);
    }

    ts->setBSTHead(insertnode(ts->getBSTHead(), bs, t, ts));
    // std::cout << "Trip added" << std::endl;
}




std::vector<Trip*> showTrips(std::string pick_up_location, int after_time, int before_time) {
        // Implement this function to retrieve trips within a specified time range
      int ct; vector<Trip*>sh;
      for(ct=0;ct<locations.size();ct++)
      {
        if(locations[ct]->getName()==pick_up_location)
        break;
      }
        Location* lo;
        lo=locations[ct];
        
        
        for(ct=0;ct<lo->returnTrips().size();ct++)
        {
              if(lo->returnTrips()[ct]->getDepartureTime()>=after_time && lo->returnTrips()[ct]->getDepartureTime()<before_time)
                 
                 sh.push_back(lo->returnTrips()[ct]);
        }



        return sh; // Placeholder
    }



 Trip* bookTrip(std::string pick_up_location, std::string drop_location, std::string vehicle_number, int departure_time) {
        // Implement this function to book a trip
   int ct; Vehicle*ve; Trip* tsp;
        for( ct=0;ct<vehicles.size();ct++)
        {
            if(vehicles[ct]->getVehicleNumber()==vehicle_number)
            ve=vehicles[ct];
        }
        for(ct=0;ct<ve->getTrips().size();ct++)
        {
            if(ve->getTrips()[ct]->getPickUpLocation()==pick_up_location&&ve->getTrips()[ct]->getDropLocation()==drop_location)
            tsp=ve->getTrips()[ct];
        }
          tsp->setBookedSeats(tsp->getBookedSeats()+1);


        return tsp; // Placeholder
    }
Location* getLocation(std::string loca){
         
        string l=loca; Location*loac;
        for(int ct=0;ct<locations.size();ct++)
        {  
            //  cout<<"tt"<<locations.size()<<endl;
            if(locations[ct]->getName()==l){
                loac=locations[ct];
            }
        }
                // cout<<loac->getName()<<endl;
        return loac;
    }

private:
    std::vector<Vehicle*> vehicles;
    std::vector<Location*> locations;
};


