#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int ports = 0, numPlanes = 0;
    vector<int> planes(10000, 0);
    ifstream file;
    file.open("/home/wylited/Documents/coding/Competitive Programming/ccc/2015/s3.9.in");

    file >> ports >> numPlanes;

    for (int i = 0; i < numPlanes; i++) {
        file >> planes[i];
    }

    int j = 0, cplane = 0, cport = 0, total = 0;
    bool planesLeft = true;
    while(j < numPlanes && planesLeft){
        file >> cplane;
        while (cplane > 0 && planes[cplane] > 0){
            cport = planes[cplane];
            ++planes[cplane];
            cplane = cplane - cport;
        }
        if (cplane <= 0) {
            planesLeft = false;
        } else {
            planes[cplane] = 1;
            ++total;
        }
        ++j;
    }
    return 0;
}