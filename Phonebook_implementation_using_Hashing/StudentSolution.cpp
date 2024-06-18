#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

class PhoneRecord {
private:
    string name;
    string organisation;
    vector<string> phoneNumbers;

public:
    // Constructor
    PhoneRecord(const string& n, const string& org, const vector<string>& numbers)  
        : name(n), organisation(org), phoneNumbers(numbers) {}

    // Getter methods
    string getName() const {
        return name;
    }

    string getOrganisation() const {
        return organisation;
    }

    vector<string> getPhoneNumbers() const {
        return phoneNumbers;
    }
};

class HashTableRecord {
private:
    int key;
    PhoneRecord* element; // Pointer to PhoneRecord
    HashTableRecord* next;

public:
     
    // Constructor
    HashTableRecord(int k,PhoneRecord* rec)
        : key(k), element(rec), next(nullptr) {}

    // Getter methods
    int getKey() const {
        return key;
    }

 PhoneRecord* getRecord() const {
        return element;
    }

 HashTableRecord* getNext() const {
        return next;
    }

 void setNext(HashTableRecord* nxt) {
        next = nxt;
    }
};
    
class PhoneBook {
private:
    static const int HASH_TABLE_SIZE = 263;
    HashTableRecord* hashTable[HASH_TABLE_SIZE];
            int m=263;


public:
    // Constructor
    PhoneBook() {
        for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
            hashTable[i] = nullptr;
        }
    }

    // Add your own implementation for hashing
    long long computeHash(const string& str)
    {
        
        // Implement a hash function for strings
        long long p = 1000000007;
        long long x = 263;
        long long hashvalue = 0;
        long long x_pow_i = 1;
        int i;
        for(i=0;i<str.size();i++){
            int s = str[i];
            hashvalue = (hashvalue + (s *( (x_pow_i) % p))) ;
            x_pow_i = (x_pow_i * x) ;
        }hashvalue=hashvalue%m;
        return hashvalue;
    
    }

    // Add your own implementation for adding a contact
    void addContact(PhoneRecord* record)  //const was there 
   {
      string l,token;
      l=record->getName();
      vector<string>names;
       std::stringstream ss(l);
       while(getline(ss, token, ' ')){
            names.push_back(token);
        }
      for(int i=0;i<names.size();i++)
      {
        // cout<<names[i];
        long long int key=computeHash(names[i]);
        if(hashTable[key]==nullptr)
        {
         hashTable[key]=new HashTableRecord(key,record);
        //  cout<<key<<"added"<<endl;
        }
        else{
            HashTableRecord* node;
            node=hashTable[key];
            hashTable[key]=new HashTableRecord(key,record);
            hashTable[key]->setNext(node);
            // cout<<key<<"added collision"<<endl;
           }
      }  
   }

    // Add your own implementation for deleting a contact
    bool deleteContact(const string* searchName) {
        // Implement deleting a contact from the phone book
        const std::string& s = *searchName;
        vector<PhoneRecord*> look = fetchContacts(searchName);
        if(look.empty()){
            return false;
        }
        for(int j=0;j<look.size();j++){
        PhoneRecord* remove = look[j];
        // vector<HashTableRecord*> deleted;
        for(int i=0;i<HASH_TABLE_SIZE;i++){
            HashTableRecord* c = hashTable[i];
            HashTableRecord* prev = nullptr;
            while(c!=nullptr){
            if(c->getRecord()->getName() == remove->getName()){
                // deleted.push_back(current);
                if(prev!=nullptr){
                    prev->setNext(c->getNext());
                }
                else {
                    hashTable[i]=c->getNext();
                }
                delete c;
            }
            else{
                prev = c;
            }
            c=c->getNext();
        }
    } }
    return true;
    }

    // Add your own implementation for fetching contacts
    vector<PhoneRecord*> fetchContacts(const string* query)
    {
    
         string l,token;
      l=*query;
      vector<string>search;
       std::stringstream ss(l);
       while(getline(ss, token, ' ')){
            search.push_back(token);
        }
        // for(int i=0;i<search.size();i++)
        // cout<<search[i]<<endl;
        vector<PhoneRecord*>p;
        for(int i=0;i<search.size();i++)
        {
        long long int key=computeHash(search[i]);
        HashTableRecord*iterator; 
        for(iterator=hashTable[key];iterator!=nullptr;iterator=iterator->getNext())
        {
           p.push_back(iterator->getRecord());
        }
      }
         return p;
    }

    // Add your own implementation for counting records pointing to a contact
    int countRecordsPointingTo(const PhoneRecord* record) const;

    // Add your own implementation for reading records from a file
    void readRecordsFromFile(const string& filename)
    {
        
        std::ifstream inputFile(filename);
       if (!inputFile.is_open()) 
       {
        std::cerr << "Failed to open the file." << std::endl;
         // return 0;
        } 
       std::string line,name;
       int i=0,k=0,j=0;
        while (std::getline(inputFile, line))


        { 
          std::stringstream ss(line);
          std::string token;
          std::vector<std::string> tokens;
          

            
           while (std::getline(ss, token, ',')) {
            tokens.push_back(token);
            }

            vector<string>numbers;
            for(int j=1;j<tokens.size()-1;j++)
            {
                numbers.push_back(tokens[j]);
            }
          
          PhoneRecord*o= new PhoneRecord(tokens[0],tokens[tokens.size()-1],numbers);
           
        
             addContact(o);
        

        
        }

    };
};

