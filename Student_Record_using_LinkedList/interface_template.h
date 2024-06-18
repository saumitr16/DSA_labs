#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;


class StudentRecord{
private:
    string studentName;
    string rollNumber;

public:
    string get_studentName() {
        return studentName;
    }
    void set_studentName(string Name) {
        studentName = Name;
    }
    string get_rollNumber() {
        return rollNumber;
    }
    void set_rollNumber(string rollnum) {
        rollNumber = rollnum;
    }
};

class Node{
	private:
		Node* next=nullptr;
		StudentRecord* element=nullptr;
	public:
	    Node* get_next() {
	        return next; 
	    }
	    StudentRecord* get_element() {
	        return element; 
	    }

	    Node* set_next(Node* value){
	    	next = value;
	    }
	    StudentRecord* set_element(StudentRecord* student){
	    	element = student;
	    }

};

class Entity {
private:
    string name;
    Node* iterator=nullptr;

public:
    string get_name()const {
        return name;
    }
    void set_name(string Name) {
        name = Name;
    }
    Node* get_iterator()const {
        return iterator;
    }
    void set_iterator(Node* iter) {
        iterator = iter;
    }
};
vector<StudentRecord> students;

class LinkedList : public Entity {
    // Implement LinkedList members here
    public:
        void add_student(const StudentRecord& student) 
       
        {
            // StudentRecord* stud= new StudentRecord();
         StudentRecord* studentPtr = new StudentRecord(student);
         Node*node =new Node(); 
        
         if(get_iterator()==nullptr){
           node->set_element(studentPtr);
           node->set_next(nullptr);
           set_iterator(node);
        
         }
         else{
            node->set_element(studentPtr);
            // Node*t=new Node();
            // t=iterator;
           node->set_next(get_iterator());
            set_iterator(node);
         }
            

        }

        void delete_student(string studentName){
            Node*t,*p;
            for(t=get_iterator();t!=nullptr;t=t->get_next())
            {
                if(t->get_element()->get_studentName()==studentName)
                      break;
                    p=t;
            }
            if(t==get_iterator())
            {
                set_iterator(t->get_next());
                 delete t;
            }
            else{
                p->set_next(t->get_next());
                delete t;
            }

            
        }
};
vector<LinkedList> EntityArray; 

    std::string removeSquareBrackets(const std::string& str) {
    std::string result = str;
    result.erase(std::remove(result.begin(), result.end(), '['), result.end());
    result.erase(std::remove(result.begin(), result.end(), ']'), result.end());
    return result;
    }
void read_input_file(string file_path){
    
    std::ifstream inputFile(file_path);

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        // return 0;
    }

    std::string line;
  int i=0,k=0,j=0;
    while (std::getline(inputFile, line)) { 
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        // Remove square brackets from tokens
        for (std::string& value : tokens) {
            value = removeSquareBrackets(value);
        }

        // Output the parsed information
        // std::cout << "Parsed values: ";
        // for (const std::string& value : tokens) {
        //     std::cout << value << " ";}
        
        // std::cout << std::endl;
        StudentRecord ob;
        ob.set_studentName(tokens[0]);
        ob.set_rollNumber(tokens[1]);
        students.push_back(ob);
        // i++;
        
        // for (const std::string& value : tokens)
        for(k=2;k<tokens.size();k++)
        {
        
        for( j=0;j<EntityArray.size();j++)
        {
            if(tokens[k]==EntityArray[j].get_name())
            {
                EntityArray[j].add_student(students[i]);
                break;
            }
        } 
         if(j==EntityArray.size())
         {
             LinkedList obj;
             obj.set_name(tokens[k]);
            // std::cout<<tokens[k]<<" ";
             EntityArray.push_back(obj);
            // EntityArray[j].set_name(tokens[k]);
          EntityArray[j].add_student(students[i]);
            //  std::cout << EntityArray[j].get_name()<<"  ";
         }
        
        
        
        }  
        
      i++; }

    inputFile.close();
   
    // return 0;
}



