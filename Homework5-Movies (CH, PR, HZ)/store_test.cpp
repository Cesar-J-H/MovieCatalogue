#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <cassert>
#include "Store.h"

void testStore1() {
    std::cout << "Start testStore1" << std::endl;
    // Should do something more, but lets just read files
    // since each implementation will
    std::string cfile = "testcommands-1.txt";
    std::stringstream out;
    std::ifstream fs(cfile);
    assert(fs.is_open());
    char command_type;
    std::string discard;
    while (fs >> command_type) {
        out << command_type;
        getline(fs, discard);
    }
    fs.close();
    std::string result = "IHHBRIBBIH";
    assert(out.str() == result);
    std::cout << "End testStore1" << std::endl;
}

void testStore2() {
    std::cout << "Start testStore2" << std::endl;
    Store blockbuster;
    std::ifstream customer_text("data4customers.txt");
    blockbuster.fillCustomerDB(customer_text);
    blockbuster.getCustomerCount();
    blockbuster.getCustomerInfo(8888);
    std::cout << "End testStore2" << std::endl;
}
void testStore3() {
    std::cout << "-----Start Testing Build Movies Catalog------" << std::endl;
    Store blockbuster;
    std::ifstream movies_text("data4movies.txt");
    blockbuster.fillMovieCatalog(movies_text);
    movies_text.close();
    blockbuster.displayInventory();
    std::cout << "------  End testStore3-------" << std::endl;
}

void testStoreFinal() {
    std::cout << "=====================================" << std::endl;
    std::cout << "Start testStoreFinal" << std::endl;
    Store blockbuster;
    std::ifstream movies_text("data4movies.txt");
    std::ifstream cust_text("data4customers.txt");
    std::ifstream command_text("data4commands.txt");
    blockbuster.fillMovieCatalog(movies_text);
    blockbuster.fillCustomerDB(cust_text);
    blockbuster.executeCommands(command_text);
    movies_text.close();
    std::cout << "End testStoreFinal" << std::endl;
    std::cout << "=====================================" << std::endl;
}

void testAll() {
    testStore1();
    testStore2();
    testStore3();
    testStoreFinal();
}
