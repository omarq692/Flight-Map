///redid the code without comments and spaces to avoid clutter and make it more readable for myself
#include <iostream>
#include <string>
#include <unordered_map>
#include "OurStack.cpp"
using namespace std;

static std::string NO_CITY = "";

class FlightMap {
private:
    unordered_map<string, vector<string>> flightMap;
    unordered_map<string, bool> visitedCities;

public:
    void insertFlightData(std::string city, std::string adjCity);
    void displayFlightMap();
    void displayAllCities();
    void displayAdjacentCities(std::string city);
    void markVisited(std::string city);
    void unvisitAll();
    bool isVisited(std::string city);
    std::string getNextCity(std::string city);
    bool isPath(std::string originCity, std::string destinationCity);
};

void FlightMap::insertFlightData(std::string city, std::string adjCity) {
    flightMap[city].push_back(adjCity);
}

void FlightMap::displayAdjacentCities(std::string city) {
    cout << "City " << city << " has flights to: ";
    for (const auto& adjCity : flightMap[city]) {
        cout << adjCity << " ";
    }
    cout << endl;
}

void FlightMap::displayAllCities() {
    cout << "All cities: ";
    for (const auto& entry : flightMap) {
        cout << entry.first << " ";
    }
    cout << endl;
}

void FlightMap::displayFlightMap() {
    for (const auto& entry : flightMap) {
        displayAdjacentCities(entry.first);
    }
}

std::string FlightMap::getNextCity(std::string city) {
    for (const auto& adjCity : flightMap[city]) {
        if (!isVisited(adjCity)) {
            return adjCity;
        }
    }
    return NO_CITY;
}

bool FlightMap::isVisited(std::string city) {
    return visitedCities[city];
}

void FlightMap::markVisited(std::string city) {
    visitedCities[city] = true;
}

void FlightMap::unvisitAll() {
    for (auto& entry : visitedCities) {
        entry.second = false;
    }
}

bool FlightMap::isPath(std::string originCity, std::string destinationCity) {
    unvisitAll();
    markVisited(originCity);

    OurStack<string> aStack;
    aStack.push(originCity);

    while (!aStack.isEmpty()) {
        string currentCity = aStack.peek();

        if (currentCity == destinationCity) {
            return true;
        }

        string nextCity = getNextCity(currentCity);

        if (nextCity == NO_CITY) {
            aStack.pop();
        }
        else {
            markVisited(nextCity);
            aStack.push(nextCity);
        }
    }

    return false;
}

int main() {
    FlightMap flightMap;

    string data[][2] = {
        {"A", "B"}, {"A", "C"},
        {"B", "D"}, {"B", "H"},
        {"C", "B"}, {"C", "D"}, {"C", "E"},
        {"D", "E"}, {"D", "H"}, {"D", "F"},
        {"E", "I"},
        {"F", "I"}, {"F", "G"},
        {"G", "C"},
        {"H", "G"},
        {"I", "C"}
    };

    for (int i = 0; i < 16; ++i) {
        flightMap.insertFlightData(data[i][0], data[i][1]);
    }

    flightMap.displayFlightMap();
    flightMap.displayAllCities();

    string testData[][2] = {
        {"A", "B"}, {"A", "D"},
        {"C", "G"}, {"B", "I"},
        {"F", "A"}
    };

    for (int i = 0; i < 5; ++i) {
        bool result = flightMap.isPath(testData[i][0], testData[i][1]);
        cout << "Testing path from " << testData[i][0] << " to " << testData[i][1] << ": " << result << endl;
    }

    return 0;
}


///*
// * csc326 homework3
// *
// * The FlightMap is from Chapter 5 page 176
// *
// * This problem is a modified version of chapter 6 Programming Problem 11.
// * Implement the FlightMap and use given stack solution
// *
// * 1. You will need to copy 'OurStack' class that we do in class here
// * 2. Many of the functions below are empty
// * 2.1 You might add new helper functions
// * 2.2 You might not use all functions depends on how your logic is
// * 2.3 Complete all necessary functions
// * 3. There are existing test data you should check the output
// * 4. All data loops are hardcoded size, if you add or remove testData, you will need to change the for loop size
// */
//
//#include "StackInterface.h"
//#include <string>
//#include <iostream>
//#include "OurStack.cpp""
//
// /**
//  * You can copy OurStack here or include ourstack
//  * Copy OurStack here
//  *
//  * You also can optionally use ArrayBag to write the logic for cities map
//  */
//static std::string NO_CITY = "";
//
//class FlightMap {
//private:
//
//    /**
//     * define your internal storage here that can hold the flight and city information
//     */
//    OurStack<std::string> visitedCities;
//
//public:
//    void insertFlightData(std::string city, std::string adjCity);
//
//    void displayFlightMap();
//
//    void displayAllCities();
//
//    void displayAdjacentCities(std::string city);
//
//    void markVisited(std::string city);
//
//    void unvisitAll();
//
//    bool isVisited(std::string city);
//    // Returns the next unvisited city, if any, that is adjacent to a given city.
//    // Returns a sentinel value if no unvisited adjacent city was found.
//
//    std::string getNextCity(std::string city);
//
//    // Tests whether a sequence of flights exists between two cities.
//
//    bool isPath(std::string originCity, std::string destinationCity);
//
//};
//
//void FlightMap::insertFlightData(std::string city, std::string adjCity) {
//    std::cout << "insert city=" << city << " destination=" << adjCity << std::endl;
//}
//
//void FlightMap::displayAdjacentCities(std::string city) {
//
//}
//
//void FlightMap::displayAllCities() {}
//
//void FlightMap::displayFlightMap() {}
//
//std::string FlightMap::getNextCity(std::string city) {
//    /***
//     * if no more adjacent city return NO_CITY
//     */
//    return NO_CITY;
//}
//
//bool FlightMap::isVisited(std::string city) {
//    return false;
//}
//
//void FlightMap::markVisited(std::string city) {
//
//}
//
//void FlightMap::unvisitAll() {}
//
//bool FlightMap::isPath(std::string originCity, std::string destinationCity) {
//
//    /**
//     * once we have OurStack, init here by calling new
//     */
//    StackInterface<std::string>* aStack = nullptr;
//
//    unvisitAll(); // Clear marks on all cities
//    // Push origin city onto aStack and mark it as visited
//    aStack->push(originCity);
//    markVisited(originCity);
//
//    std::string topCity = aStack->peek();
//    while (!aStack->isEmpty() && (topCity != destinationCity)) {
//        // The stack contains a directed path from the origin city
//        // at the bottom of the stack to the city at the top of
//        // the stack
//
//        // Find an unvisited city adjacent to the city on the
//        // top of the stack
//        std::string nextCity = getNextCity(topCity);
//
//        if (nextCity == NO_CITY)
//            aStack->pop(); // No city found; backtrack
//        else // Visit city
//        {
//            aStack->push(nextCity);
//            markVisited(nextCity);
//        } // end if
//
//        if (!aStack->isEmpty())
//            topCity = aStack->peek();
//    } // end while
//
//    bool result = !aStack->isEmpty();
//    delete aStack;
//    return result;
//
//} // end isPath
//
//
//
//int main() {
//    /*
//     * this map is based of figure 5-6
//     */
//    std::string data[][2] = {
//            "A", "B",
//            "A", "C",
//
//            "B", "D",
//            "B", "H",
//
//            "C", "B",
//            "C", "D",
//            "C", "E",
//
//            "D", "E",
//            "D", "H",
//            "D", "F",
//
//            "E", "I",
//
//            "F", "I",
//            "F", "G",
//
//            "G", "C",
//            "H", "G",
//            "I", "C"
//
//    };
//
//    FlightMap flightMap;
//
//    for (int i = 0; i < 16; i++) {
//        std::string* cityData = data[i];
//        flightMap.insertFlightData(*cityData, *(cityData + 1));
//    }
//
//    flightMap.displayFlightMap();
//    flightMap.displayAllCities();
//
//
//    std::string testData[][2] = {
//            "A", "B",
//            "A", "D",
//            "C", "G",
//            "B", "I",
//            "F", "A"
//
//    };
//
//    for (int i = 0; i < 5; i++) {
//        std::string* testCase = testData[i];
//        std::cout << "testing city=" << *testCase
//            << " destination=" << *(testCase + 1)
//            << " isPath=" <<
//            flightMap.isPath(*testCase, *(testCase + 1))
//            << std::endl;
//
//    }
//}
///**
//* insert city=A destination=B
//insert city=A destination=C
//insert city=B destination=D
//insert city=B destination=H
//insert city=C destination=B
//insert city=C destination=D
//insert city=C destination=E
//insert city=D destination=E
//insert city=D destination=H
//insert city=D destination=F
//insert city=E destination=I
//insert city=F destination=I
//insert city=F destination=G
//insert city=G destination=C
//insert city=H destination=G
//insert city=I destination=C
//Adjacent cities to A are: B C
//Adjacent cities to B are: D H
//Adjacent cities to C are: B D E
//Adjacent cities to D are: E H F
//Adjacent cities to E are: I
//Adjacent cities to F are: I G
//Adjacent cities to G are: C
//Adjacent cities to H are: G
//Adjacent cities to I are: C
//displayAllCities
//A B C D E F G H I
//testing city=A destination=B isPath=1
//testing city=A destination=D isPath=1
//testing city=C destination=G isPath=1
//testing city=B destination=I isPath=1
//testing city=F destination=A isPath=0
//*/

