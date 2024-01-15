#include <iostream>
#include "URIStatiscalHelper.hpp"
#include <cassert>
using namespace std;


// #1 checking helper add function
void testHelperAdd(){
    cout << "#1 testing helper add function" << endl;
    URIStatiscalHelper helper;
    helper.add(10);
    assert(helper.getSize() == 1);
    cout << "#1 clear" << endl;
    cout << endl;
}

// #2 checking helper add negative values
void testHelperAddNegative(){
    cout << "#2 testing helper add negative" << endl;
    URIStatiscalHelper helper;
    helper.add(-10);
    assert(helper.getSize() == 0);
    cout << "#2 clear" << endl;
    cout << endl;
}


// #3 checking helper get Mean function
void testHelperGetMean(){
    cout << "#3 testing helper get mean function" << endl;
    URIStatiscalHelper helper;
    helper.add(10);
    helper.add(5);
    helper.add(1);
    helper.add(4);
    assert(helper.getMean() == 5);
    cout << "#3 clear" << endl;
    cout << endl;
}

// #4 checking helper get mean when no data
void testHelperGetMeanNoData(){
    cout << "#4 testing helper get mean when no data" << endl;
    URIStatiscalHelper helper;
    assert(helper.getMean() == 0);
    cout << "#4 clear" << endl;
    cout << endl;
}

// #5 testing helper getStandardDeviation
void testHelperGetDeviation(){
    cout << "#5 testing helper getStandardDeviation" << endl;
    URIStatiscalHelper helper;
    helper.add(5);
    helper.add(7);
    helper.add(3);
    helper.add(7);
    double result = helper.getStandardDeviation();
    assert(result>1.65 && result<1.66);
    cout << "#5 clear" << endl;
    cout << endl;
}

// #6 testing helper getStandardDeviation
void testHelperGetDeviationWithNoData(){
    cout << "6 testing helper getStandardDeviation with no data" << endl;
    URIStatiscalHelper helper;
    double result = helper.getStandardDeviation();
    assert(result == 0);
    cout << "#6 clear" << endl;
    cout << endl;
}

// #7 testing helper getNormalizedHistogram
void testHelperGetNormalizedHistogram(){
    cout << "#7 testing helper getNormalizedHistogram" << endl;
    URIStatiscalHelper helper;
    helper.add(10);
    helper.add(5);
    helper.add(1);
    helper.add(4);
    helper.getNormalizedHistogram(10);
    cout << "#7 clear" << endl;
    cout << endl;
}

// #8 testing helper getNormalizedHistogram change maxBinNum
void testHelperGetNormalizedHistogramLimitBin(){
    cout << "#8 testing helper getNormalizedHistogram setting maxBinNum as 1" << endl;
    URIStatiscalHelper helper;
    helper.add(10);
    helper.add(5);
    helper.add(1);
    helper.add(4);
    helper.getNormalizedHistogram(1);
    cout << "#8 clear" << endl;
    cout << endl;
}

// #9 testing helper getNormalizedHistogram with invalid maxBinNum
void testHelperGetNormalizedHistogramInvalidBin(){
    cout << "#9 testing helper getNormalizedHistogram setting invalid maxBinNum" << endl;
    URIStatiscalHelper helper;
    helper.add(10);
    helper.add(5);
    helper.add(1);
    helper.add(4);
    helper.getNormalizedHistogram(-1);
    cout << "#9 clear" << endl;
    cout << endl;
}

// #10 testing helper getNormalizedHistogram with no data
void testHelperGetNormalizedHistogramNoData(){
    cout << "#10 testing helper getNormalizedHistogram with no data" << endl;
    URIStatiscalHelper helper;
    helper.getNormalizedHistogram(10);
    cout << "#10 clear" << endl;
    cout << endl;
}

int main(){
    testHelperAdd();
    testHelperAddNegative();
    testHelperGetDeviation();
    testHelperGetDeviationWithNoData();
    testHelperGetMean();
    testHelperGetMeanNoData();
    testHelperGetNormalizedHistogram();
    testHelperGetNormalizedHistogramLimitBin();
    testHelperGetNormalizedHistogramInvalidBin();
    testHelperGetNormalizedHistogramNoData();
}