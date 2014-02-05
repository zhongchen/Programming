#include "RangeAdaptor.h"
#include <boost/range/adaptor.hpp>
#include <boost/range/algorithm.hpp>
#include <iostream>
#include <vector>


void RangeAdaptorTest()
{
    std::vector<int> vec = {3,4,5};
    boost::copy( vec | boost::adaptors::reversed,
                 std::ostream_iterator<int>(std::cout));
}




















