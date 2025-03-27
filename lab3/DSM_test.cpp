#include "DSM.h"
#include <iostream>
#include <cassert>
using namespace std;

int main() {

    DSM dsm1(3);
    dsm1.set_element_name(0, "A");
    dsm1.set_element_name(1, "B");
    dsm1.set_element_name(2, "C");
    assert(dsm1.get_name(1) == "B");


    DSM dsm2({"X", "Y"});
    assert(dsm2.size() == 2);
    assert(dsm2.get_name(0) == "X");
    assert(dsm2.get_name(1) == "Y");


    dsm2.add_link("X", "Y", 2.5);
    assert(dsm2.have_link("X", "Y"));
    assert(dsm2.link_weight("X", "Y") == 2.5f);


    dsm2.add_link("Y", "X", 1.1);
    assert(dsm2.have_link("Y", "X"));
    assert(dsm2.link_weight("Y", "X") == 1.1f);


    assert(dsm2.count_to_links("X") == 1);
    assert(dsm2.count_from_links("X") == 1);
    assert(dsm2.count_all_links() == 2);


    dsm2.delete_link("X", "Y");
    assert(!dsm2.have_link("X", "Y"));
    assert(dsm2.count_all_links() == 1);


    int prev_size = dsm2.size();
    dsm2.add_link("A", "B", 3.0);
    assert(dsm2.size() == prev_size + 2);
    assert(dsm2.have_link("A", "B"));
    assert(dsm2.link_weight("A", "B") == 3.0f);

    cout << "Alle Tests erfolgreich bestanden!" << endl;
    return 0;
}
