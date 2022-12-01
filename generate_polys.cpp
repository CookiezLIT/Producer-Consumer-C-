#include <fstream>
#include <string>
#include <random>
#include <ctime>
#include <iostream>
using namespace std;

ofstream fout;


void generate_poly(string filename, int length){
    /*
     * :filename: name of the file that we are writing in
     * :length: power of the biggest exponent
     * writes to :filename: :length: monoms, with the follow form : coeficient power \n
     */

    fout.open(filename);

    srand(time(0));

    for(int i =0; i< length; i++){
        fout << rand() % 1000 << " " << i << endl;
        cout << rand() % 1000 << " " << i << endl;
    }
    fout.close();
}

int main(){
    generate_poly("./data/poly1000_2.txt", 50);
    return 0;
}