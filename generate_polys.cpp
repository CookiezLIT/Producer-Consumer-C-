#include <fstream>
#include <string>
#include <ctime>
#include <iostream>
using namespace std;

ofstream fout;


void generate_poly(string filename, int length, int max_coeficient){
    /*
     * :filename: name of the file that we are writing in
     * :length: power of the biggest exponent
     * writes to :filename: :length: monoms, with the follow form : coeficient power \n
     */

    fout.open(filename);

    srand(time(0));

    for(int i =0; i< length; i++){
        fout << rand() % max_coeficient << " " << i << endl;
        cout << rand() % max_coeficient << " " << i << endl;
    }
    fout.close();
}

int main(){
    generate_poly("./data/trivial/poly2.txt", 10, 10);
    return 0;
}