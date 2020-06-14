#include <iostream>
#include <unistd.h>
#include <vector>






      using namespace std;

      // object class with bigger size.
      class testclass
      {
      private:
        string bigsizedata;
      public:
        string getdata() { return this->bigsizedata;};
        //! Default constructor
        //testclass() = default;
        testclass(string x="zero"): bigsizedata(x) { cout << "\ndefault constructor";}

        //! Copy constructor
        testclass(const testclass &other) {
          this->bigsizedata = other.bigsizedata;
          cout << "\ncopy constructor";
        }


        //! Move constructor
        testclass(testclass &&other) noexcept {
          this->bigsizedata = move(other.bigsizedata);
          other.bigsizedata = "";
          cout << "\nmove constructor";
        }

        //! Destructor
        virtual ~testclass() noexcept {
          //cout << "\nobject destructor";
    }

        //! Copy assignment operator
        testclass& operator=(const testclass &other) {
          this->bigsizedata = other.bigsizedata;
          return *this;
          cout << "\ncopy assignment operator";;
        }

        //! Move assignment operator
        testclass& operator=(testclass &&other) noexcept {
          this->bigsizedata = move(other.bigsizedata);
          cout << "\nmove assignment operator";;
return *this;
        }
      };


    ostream & operator << (ostream &cout, vector<testclass> &v) {
      for( auto &i: v) cout << " " << i.getdata() ;
      return cout;
  }
      int main(int argc, char *argv[]) {
        vector <testclass> v;
        testclass t;
        v.insert(v.begin(),t);
        v.emplace_back("one"); // here object will be created inplace and pushed to vector.
        v.emplace_back("two"); // here object will be created inplace and pushed to vector.
        v.emplace(v.begin(), "five");
        v.emplace(v.end(), "six");
        v.emplace(v.end(), t);
        v.emplace_back(t); // here object will be created inplace and pushed to vector.
        cout << "\nData: " << v;
        return 0;
      }
