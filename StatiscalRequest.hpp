#include <string>
#include <chrono>
#include "URIStatiscalHelper.hpp"
#include "Request.hpp"
#include <map>

using namespace std;
/**
 * Resource request processing class
 *
 * Instantiations of this class do state based processing of resource requests.
 * To use, instantiate an object and call process() on a URI to get the response
 * data.
 * 
 * Augmented functionality with statiscal calculation
 */
class StatiscalRequest : public Request
{
private:

    std::chrono::time_point<std::chrono::high_resolution_clock> startTime; //variable to store the task start time point

    std::map<std::string, URIStatiscalHelper*> map; //map to store the URIStatiscalHelper according to the URI

    URIStatiscalHelper* currentHelper; //variable to store the pointer of the current URIStatiscalHelper

    int maxBinNum = 10; //variable to store the maximum bin number for histogram

protected:
    /**
     * Start processing the request
     * 
     * would save the start time point, and find or initialize the URIStatiscalHelper
     *
     * @param [in] uri The URI of the request endpoint
     */
    void start(const std::string& uri);

    /** 
     * Finish processing the request 
     * 
     * would calculate the time elapsed and save the data to current URIStatiscalHelper
    */
    void finish();

public:
    
    /**
         * Function to get the mean value among the data of uri
         * 
         * 
         * @param [in] uri The URI of the request endpoint
         */
        double getMean(const std::string& uri); // O(1) in this implementation


        /**
         * Function to get the standard deviation among the data of uri
         * 
         * 
         * @param [in] uri The URI of the request endpoint
         */
        double getStandardDeviation(const std::string& uri); // O(n)


        /**
         * Function draw normalized histogram based on current data of uri
         * 
         * bin number is controlled by maxBinNum
         * 
         * 
         * @param [in] uri The URI of the request endpoint
         */
        void getNormalizedHistogram(const std::string& uri); // O(nlogn)


        /**
         * Function get the total number of requests processed in this uri
         * 
         * 
         * @param [in] uri The URI of the request endpoint
         */
        int getNumberOfRequest(const std::string& uri); // O(nlogn)

        StatiscalRequest() = default;

        /**
         * Constructor with parameter
         * 
         * @param [in] m The maximum bin number of the histogram
         */
        StatiscalRequest(int m) : maxBinNum(m) {}
};