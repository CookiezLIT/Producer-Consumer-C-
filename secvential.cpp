#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <dirent.h>
#include <cstring>

using namespace std;
const string RUN_CASE = "trivial";
const bool DEBUG = true;
struct Node{
    int coeficient;
    int exponent;
    Node* next;
};

Node create_linked_list(){
    /*
     * returns the first element from a linked list, with head and tail
     * head and tail have negative coefficient and indexes: -1 for head and -2 for tail
     */


    Node head;
    Node tail;
    head.next = &tail;
    head.coeficient = -1;
    tail.coeficient = -2;
    head.exponent = -1;
    tail.exponent = -2;

    return head;
}

vector<string> read_files_from_dir(string path){
    vector<string> files;
    DIR *dir; struct dirent *diread;

    if ((dir = opendir(path.c_str())) != nullptr) {
        while ((diread = readdir(dir)) != nullptr) {
            files.push_back(diread->d_name);
        }
        closedir (dir);
    } else {
        perror ("opendir");

    }
    // remove the "." and ".." directories
    files.erase(files.begin());
    files.erase(files.begin());

    if (DEBUG) {
        cout << "FILES READ:" << endl;
        for (auto file: files) cout << file << "| ";
        cout << endl;
    }
    return files;
}

int main(){
    Node head = create_linked_list();
    vector<string> files = read_files_from_dir("./data/" + RUN_CASE);

    return 0;
}