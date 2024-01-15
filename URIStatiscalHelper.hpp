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
        void add(double elem); // O(1)

        double getMean(); // O(1) in this implementation

        double getStandardDeviation(); // O(n)

        void getNormalizedHistogram(int maxBinNum); // O(nlogn)

        int getSize(); // O(1)

    private:
        vector<double> dataStorage; //vector to store data
        
        double total=0; //save Time Complexity for getMean() function

        int size=0; //save Time Complexity for getMean() function
};