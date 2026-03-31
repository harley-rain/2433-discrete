#include <iostream> 
using namespace std; 
//*****************************
//*           CLASS           *
//*****************************
// Storing an activities data
class Schedule
{
    private: 
      int start; 
      int end; 
      int length;
      // constructors 
    public: 
      Schedule(); 
      Schedule(int, int, int); 

      // getters & setters
      int getStart();
      int getEnd();
      int getLength();

      void setLength(int);
      void setEnd(int);
      void setStart(int);
  
}

// our input data format 
// The first line of input will contain the number of activities to process, N, where 1 <= N <=20.
// The next N lines will contain each activities’ information start_time and length.
