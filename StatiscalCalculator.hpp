/**
 * abstract Class for calculating the statiscal result
 * 
 * Stands for interface uses, include 4 functions
 * 
 * add() to add data for future caculations
 * getMean() to get mean value among the data so far, returned in double type
 * getStandardDeviation() to get standard deviation among the data so far, returned in double type
 * getNormalizedHistogram() to print a normalized histogram based on the data we have.
 */

class StatiscalCalculator
{
    public:
        /**
         * Function to add new data, to be implemented in child class
         * 
         * @param [in] elem The double value to be added in data storage
         */
        virtual void add(double elem){}

        /**
         * Function to get the mean value among the data, to be implemented in child class
         */
        virtual double getMean() = 0;

        /**
         * Function to get the standard deviation among the data, to be implemented in child class
         */
        virtual double getStandardDeviation() = 0;

        /**
         * Function draw normalized histogram based on current data, to be implemented in child class
         * 
         * @param [in] maxBinNum The maximum bin number of this histogram
         */
        virtual void getNormalizedHistogram(int maxBinNum){}
    
};