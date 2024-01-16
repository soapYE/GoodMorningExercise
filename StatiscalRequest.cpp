#include <string>
#include <chrono>
#include "StatiscalRequest.hpp"
#include <map>
#include <iostream> 

using namespace std;

void StatiscalRequest::start(const std::string& uri){
    const auto it = map.find(uri);

    if(it==map.end()){ // if no helper for this uri exists, create a new one and add to the map
        currentHelper = new URIStatiscalHelper;
        map.insert({uri,currentHelper});
    }
    else{ 
        currentHelper = it->second;
    }

    startTime = chrono::high_resolution_clock::now();
}

void StatiscalRequest::finish(){
    auto finishTime = chrono::high_resolution_clock::now();

    //calculate the elapsed time in milisecond unit
    double elapsed_time = std::chrono::duration<double, std::milli>(finishTime-startTime).count();

    currentHelper->add(elapsed_time);
}


double StatiscalRequest::getMean(const std::string& uri){

    const auto it = map.find(uri);

    try{
        if(it==map.end()){ // if no helper for this uri exists, alert user
            throw "no data for this uri, no mean";
        }
    }
    catch(const char* message){
        cout << message << endl;
        return 0;
    }

    URIStatiscalHelper* p = it->second;

    return p->getMean();
}

double StatiscalRequest::getStandardDeviation(const std::string& uri){

    const auto it = map.find(uri);

    try{
        if(it==map.end()){ // if no helper for this uri exists, alert user
            throw "no data for this uri, no standard deviation";
        }
    }
    catch(const char* message){
        cout << message << endl;
        return -1;
    }

    URIStatiscalHelper* p = it->second;

    return p->getStandardDeviation();
}

void StatiscalRequest::getNormalizedHistogram(const std::string& uri){
    const auto it = map.find(uri);

    try{
        if(it==map.end()){ // if no helper for this uri exists, alert user
            throw "no data for this uri, no histogram is printing";
        }
    }
    catch(const char* message){
        cout << message << endl;
        return;
    }

    URIStatiscalHelper* p = it->second;

    return p->getNormalizedHistogram(maxBinNum);
}

int StatiscalRequest::getNumberOfRequest(const std::string& uri){
    const auto it = map.find(uri);

    try{
        if(it==map.end()){ // if no helper for this uri exists, alert user
            throw "no request for this uri";
        }
    }
    catch(const char* message){
        cout << message << endl;
        return 0;
    }

    URIStatiscalHelper* p = it->second;

    return p->getSize();
}


