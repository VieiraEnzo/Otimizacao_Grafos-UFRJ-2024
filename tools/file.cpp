#include "file.h"

void read_file(std::string name, int &nI, int &nP, int &C, 
                std::vector<item> &items) {
    // Your function implementation here
    // Opening file
    std::ifstream myfile;
    myfile.open(name);

    if (!myfile.is_open()) {
        std::cerr << "Error: Unable to open file " << name << std::endl;
        return;
    }

    myfile >> nI >> nP >> C;
    items.resize(nI);

    for(int i = 0; i < nI; i++) myfile >> items[i].value;
    for(int i = 0; i < nI; i++) myfile >> items[i].wheight;
    
    for(int i = 0; i < nP; i++){
        int a,b; myfile >> a >> b; 
        items[b].forbidden[a] = items[a].forbidden[b] = true;
    }

    for(int i = 0; i < nI; i++) items[i].forbidden[i] = true;

    myfile.close();
}

