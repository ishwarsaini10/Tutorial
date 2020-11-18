// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
    int i = 0;
    const int s = 3894;
    float c ;
    double a[s];
    string line;
    ifstream myfile ("chetna_data.txt");
/*
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            cout << line << '\n';
            i+=1;
        }
        myfile.close();
    }

    else cout << "Unable to open file"; 
    cout  <<  i-1 <<  endl;
*/
    for(int i=0;  i<3894;  i++){
        myfile >> c;
        cout  <<  i << "\t" << c  <<  endl;
    }

    return 0;
}
