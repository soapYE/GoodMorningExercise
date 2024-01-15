#include "URIStatiscalHelper.hpp"
#include <iostream> 
#include <algorithm> 
#include <cmath>

using namespace std;


int URIStatiscalHelper::getSize(){
    return this->size;
}

void URIStatiscalHelper::add(double elem){
    try{
        if(elem <= 0){
            throw "Data should be positive real numbers"; // if data added is not a positive real number, alert user
        }
    }
    catch(const char* message){
        cout << message << endl;
        return;
    }
    this->total += elem;
    dataStorage.push_back(elem);
    this->size++;
}


double URIStatiscalHelper::getMean(){
    try{
        if(this->size==0){
            throw "no data, could not divide by 0"; // if there's no data, alert user
        }
        return this->total/this->size;
    }
    catch(const char* message){
        cout << message << endl;
    }
    return 0;

}


double URIStatiscalHelper::getStandardDeviation(){

    try{
        if(this->size==0){
            throw "no data, could not divide by 0"; // if there's no data, alert user
        }
    }
    catch(const char* message){
        cout << message << endl;
        return 0;
    }

    double mean = this->getMean();
    double temp = 0;
    for(double d : dataStorage){
        temp += pow(d - mean, 2);
    }

    temp/=this->size;

    double result = sqrt(temp);

    return result;
}


void URIStatiscalHelper::getNormalizedHistogram(int maxBinNum){
    try{
        if(this->size==0){
            throw "no data, could not divide by 0"; // if there's no data, alert user
        }
        if(maxBinNum<=0){
            throw "the maximum bin number should be a positive integer"; // if the maxBinNum is not a positive integer, alert user
        }
    }
    catch(const char* message){
        cout << message << endl;
        return;
    }

    sort(dataStorage.begin(), dataStorage.end()); // sort O(NlogN)

    //calculate bin number
    //ensure no empty bin at edge while the real bin number is as close as maximum
    //x range from zero(not included) to data maximum
    double max = dataStorage[this->size-1];
    double min = dataStorage[0];

    int binNumber = (int)floor(max/min);

    binNumber = binNumber>maxBinNum ? maxBinNum : binNumber;

    double binSize = max/binNumber;

    //Find out data frequency in one bin
    double binData[binNumber];

    int rB = this->size-1; // the right border of the target bin


    //Binary search for the index of left border of target bin, so get the number of data in target bin
    //O(logN)
    for(int i=binNumber-1; i>=0; i--){
        double target = i * binSize; // set left border of the target bin as the binary search target
        int l = 0;
        int r = rB;

        while(l<=r){
            int mid = l + (r-l)/2;
            if(dataStorage[mid]<=target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        if(l>rB){
            binData[i] = 0; // no data in this bin
        }
        else{
            binData[i] = (double)(rB - l + 1)/this->size; // number of data in target bin
        }
        rB = l-1; //next target bin's right border = left border of current bin
    }
    
    //print above x axis
    for(int i=10; i>0; i--){
        printf("%2.1f %s ",0.1*i, "|");
        for(int j=0;j<binNumber;j++){
            if(binData[j]>=i*0.1){
                printf("%s ", "  *  ");
            }
            else{
                printf("%s ", "     ");
            }
        }
        cout << endl;
    }

    //print x axis
    printf("%4s","----");

    for(int i=0;i<binNumber;i++){
        printf("%6s", "------");
    }
    
    cout << endl;

    //print under x axis
    printf("%4s", " ");
    
    for(int i=1;i<binNumber;i++){
        printf("%5.2f ", i*binSize);
    }
    
    printf("%5.2f ", max);

    cout << endl;
}
