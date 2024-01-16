#include "StatiscalCalculator.hpp"
#include <vector>
using namespace std;


/**
 * Class for calculating the statiscal result on each URI's response time
 * 
 * Implements the StatiscalCalculator interface
 */
class URIStatiscalHelper : public StatiscalCalculator {
    public:

        /**
         * Function to add new data
         * 
         * @param [in] elem The double value to be added in data storage
         */
        void add(double elem); // O(1)

        /**
         * Function to get the mean value among the data
         */
        double getMean(); // O(1) in this implementation


        /**
         * Function to get the standard deviation among the data
         */
        double getStandardDeviation(); // O(n)


        /**
         * Function draw normalized histogram based on current data
         * 
         * @param [in] maxBinNum The maximum bin number of this histogram
         */
        void getNormalizedHistogram(int maxBinNum); // O(nlogn)

        /**
         * Function to get the number of data we have
         */
        int getSize(); // O(1)

    private:
        vector<double> dataStorage; //vector to store data
        
        double total=0; //save Time Complexity for getMean() function

        int size=0; //save Time Complexity for getMean() function
};