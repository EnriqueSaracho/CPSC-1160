/* h Files
Lecture 12
Header file: Line.h
*/
#include "Line.h"

using namespace std;

int main()
{
    Line l1(0, 2, 1, 4);
    Line l2(2, 4, 3, 6);
    cout << ((l2 == l1) ? "Are" : "Aren't") << " same lenth" << endl;
    cout << l1;
    l1 = l1 + 3;
    cout << l1;
    l1 = 4 + l1;
    cout << l1;
    l1 = l1 * 2;
    cout << l1;
    cout << ((l2 == l1) ? "Are" : "Aren't") << " same lenth" << endl;
    l1 = -l1;
    cout << l1;
}