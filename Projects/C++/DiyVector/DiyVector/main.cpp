//
//  main.cpp
//  DiyVector
//
//  Created by Sarah Bateman on 9/12/23.
//

#include <iostream>
#include "DiyFunctions.hpp"
#include <cassert>
#include <numeric>
#include <algorithm>

bool isEven(int i){
    return(i%2 == 0);
}

int main(int argc, const char * argv[]) {
    
    //-------------------------TESTS!--------------------------
    
    myVector<int> practiceVec;
    myVector<int> secondVec;
    
    //makeVec tests
    assert(practiceVec.getCapacity() == 10 && "makeVector test 1 failed\n");
    
    assert(practiceVec.getSize() == 0 && "makeVector test 2 failed\n");
    
    //copy constructor tests
    myVector<int> thirdVec(secondVec);
    assert(thirdVec == secondVec && "copy constructor test 1 failed\n");
    
    //pushBack tests
    practiceVec.pushBack(4);
    practiceVec.pushBack(34);
    practiceVec.pushBack(21);
    assert(practiceVec.getSize() == 3 && "pushBack test 1 failed\n");
    assert(practiceVec.getCapacity() == 10 && "pushBack test 2 failed\n");
    
    //setValue tests
    practiceVec.setValue(2, 6);
    assert(practiceVec.getSize() == 3 && "setValue test failed\n");
    
    //getValue tests
    assert (practiceVec.getValue(2) == 6 && "getValue test 1 failed\n");
    assert(practiceVec.getValue(1) == 34 && "getValue test 2 failed\n");
    
    //popBack tests
    practiceVec.popBack();
    assert(practiceVec.getSize() == 2 && "popBack test 1 failed\n");
    assert(practiceVec.getCapacity() == 10 && "popBack test 2 failed\n");
    
    //Operator tests------------------------------------------------------------
    
    // operator= and operator[] tests
    practiceVec[0] = 901;
    assert(practiceVec[0] == 901 && "operator[] test failed\n");
    secondVec = practiceVec;
    assert(secondVec.getSize() == 2 && "operator= test 1 failed\n");
    assert(secondVec[0] == practiceVec[0] && practiceVec[1] == secondVec[1] && "operator= test 2 failed\n");
    
    
    //operator==
    assert(practiceVec == secondVec && "operator== test 1 failed\n");
    
    //operator!=
    practiceVec.pushBack(5);
    practiceVec.pushBack(18);
    assert(practiceVec != secondVec && "operator!= test 1 failed\n");
    
    //operator<
    secondVec.pushBack(1);
    secondVec.pushBack(20);
    assert(secondVec < practiceVec && "operator< test 1 failed\n");
    
    //operator>
    assert(practiceVec > secondVec && "operator> test 1 failed\n");
    
    //operator <= and >=
    assert(secondVec <= practiceVec && "operator<= test 1 failed\n");
    assert(practiceVec >= secondVec && "operator>= test 1 failed\n");
    secondVec = practiceVec;
    assert(secondVec == practiceVec);
    assert(secondVec <= practiceVec && "operator<= test 1 failed\n");
    assert(practiceVec >= secondVec && "operator>= test 1 failed\n");
    
    //other class type test-------------------------------------------------------------
    //chars
    myVector<char> charVec;
    charVec.pushBack('S');
    charVec.pushBack('A');
    charVec.pushBack('R');
    charVec.pushBack('A');
    charVec.pushBack('H');
    
    assert(charVec.getCapacity() == 10 && "charVec test 1 failed\n");
    assert(charVec.getSize() == 5 && "charVec test 2 failed\n");
    assert(charVec[2] == 'R' && "charVec test 3 failed\n");
    
    //testing = copies correctly
    myVector<char> secondCharVec;
    secondCharVec = charVec;
    
    assert(secondCharVec == charVec && "charVec test 4 failed\n");
    
    //testing + adds two vectors correctly - should repeat "SARAH"
    //twice
    myVector<char> thirdCharVec;
    thirdCharVec = charVec + secondCharVec;
    assert(thirdCharVec.getSize() == 10 && "charVec test 5 failed\n");
    assert(thirdCharVec[5] == 'S' && "charVec test 6 failed\n");
    assert(thirdCharVec[9] == 'H' && "charVec test 7 failed\n");
    
    //strings
    myVector<std::string> StringVec;
    StringVec.pushBack("All");
    StringVec.pushBack("tests");
    StringVec.pushBack("passed!");
    StringVec.pushBack("NOT!!!!");
    
    //testing >
    assert(StringVec[2] > StringVec[3] && "stringVec test 1 failed\n");
    
    StringVec.popBack();
    
    assert(StringVec.getSize() == 3 && "stringVec test 1 failed\n");
    
    //testing printVec - will print "All tests passed!"
    StringVec.printVec();
    
    
    //STL Tests ----------------------------------------------------------
    
    //sort
    std::sort(practiceVec.begin(), practiceVec.end());
    
    //print with a for/each loop
    for(int i: practiceVec){
        std::cout << i << std::endl;
    }
    
    //find min element
    int *min = std::min_element(practiceVec.begin(), practiceVec.end());
    std::cout << "Min: " << *min << std::endl;
    
    //find the sum
    int sum = std::accumulate(practiceVec.begin(), practiceVec.end(), 0);
    std::cout << "Sum: " << sum << std::endl;
    
    //count even numbers
    //I also have an isEven function I could reference instead of using a lambda func
    int count = std::count_if(practiceVec.begin(), practiceVec.end(), [](int i)
    {
    return(i%2 == 0);
    });
    std::cout << "Count: " << count << std::endl;
    
    //remove all even numbers by moving all even numbers to the back of the
    //vector, then popping back as many times as even numbers
    std::remove_if(practiceVec.begin(), practiceVec.end(), [](int i)
    {
    return(i%2 == 0);
    });
    
    practiceVec.popBack();
    practiceVec.popBack();
    
    practiceVec.printVec();
    
    
    return 0;
}





