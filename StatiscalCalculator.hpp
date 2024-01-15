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
        virtual void add(double elem){}

        virtual double getMean() = 0;

        virtual double getStandardDeviation() = 0;

        virtual void getNormalizedHistogram(int maxBinNum){}
    
        virtual ~StatiscalCalculator(){}
};