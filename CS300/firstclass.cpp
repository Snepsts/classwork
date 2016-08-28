#include <iostream>

//can use char* argv[] instead of char** argv
//instead of using "using namespace std;" can use "using std::cout;"

int main(int argc, char** argv)
{
    std::cout << "Written by Michael Ranciglio"
              << " Compiled on " << __DATE__
              << " at " << __TIME__ << '\n';

    std::cout << "Hello, World!\n";

    return 0;
}
