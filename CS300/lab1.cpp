#include <iostream>
#include <string>
#include <iterator>

using std::cout;
using std::string;

int main()
{
    string st = "Six sick slick slim sycamore saplings";

    //1st way
    cout << "1. ";
    for (int i = 0; i < st.size(); i++)
        cout << st[i];
    cout << '\n';

    //2nd way
    cout << "2. ";
    for (string::size_type i = 0; i < st.size(); i++)
        cout << st[i];
    cout << '\n';

    //3rd way
    cout << "3. ";
    for (string::iterator sit = st.begin(); sit != st.end(); sit++)
        cout << *sit;
    cout << '\n';

    //4th way
    cout << "4. ";
    for (string::const_iterator csit = st.cbegin(); csit != st.cend(); csit++)
        cout << *csit;
    cout << '\n';

    //5th way
    cout << "5. ";
    for (string::reverse_iterator rsit = st.rend(); rsit != st.rbegin() - 1; rsit--)
        cout << *rsit;
    cout << '\n';

    //6th way
    cout << "6. ";
    for (string::const_reverse_iterator crsit = st.crend(); crsit != st.crbegin() - 1; crsit--)
        cout << *crsit;
    cout << '\n';

    //7th way
    cout << "7. ";
    for (string::iterator sit = begin(st); sit != end(st); sit++)
        cout << *sit;
    cout << '\n';

    //8th way (part 1)
    cout << "8.1. ";
    for (auto i = 0; i < st.size(); i++)
        cout << st[i];
    cout << '\n';

    //8th way (part 2)
    cout << "8.2. ";
    for (auto sit = st.begin(); sit != st.end(); sit++)
        cout << *sit;
    cout << '\n';

    //8th way (part 3)
    cout << "8.3. ";
    for (auto csit = st.cbegin(); csit != st.cend(); csit++)
        cout << *csit;
    cout << '\n';

    //8th way (part 4)
    cout << "8.4. ";
    for (auto rsit = st.rend(); rsit != st.rbegin() - 1; rsit--)
        cout << *rsit;
    cout << '\n';

    //8th way (part 5 )
    cout << "8.5. ";
    for (auto crsit = st.crend(); crsit != st.crbegin() - 1; crsit--)
        cout << *crsit;
    cout << '\n';

    //8th way (part 6)
    cout << "8.6. ";
    for (auto sit = begin(st); sit != end(st); sit++)
        cout << *sit;
    cout << '\n';

    //9th way
    cout << "9. ";
    for (char i : st)
        cout << i;
    cout << '\n';

    return 0;
}
