#include "iostream"
#include "boost/ptr_container/ptr_vector.hpp"
#include "vector"
#include "memory"
using namespace boost;
using namespace std;

int main()
{
 
 typedef ptr_vector<string> stringVector;
 typedef unique_ptr<string> stringVectorPtr;

 stringVector  stringVector_;
 stringVectorPtr stringPtr1(new string("string...1"));
 stringVectorPtr stringPtr2=move(stringPtr1);
 cout<< "*stringPtr2="<< *stringPtr2<<endl;
 stringVector_.push_back(stringPtr2.release());
 //cout<< "after stringPtr1.release(),*stringPtr1="<< *stringPtr1<<endl;
 
 stringVector::iterator it= stringVector_.begin();
 while(it != stringVector_.end())
      {
         cout<<"it= "<< it-stringVector_.begin()<<endl;
         cout<<"*it="<< *it<<endl;
         it++;
      }


 return 0;
}
