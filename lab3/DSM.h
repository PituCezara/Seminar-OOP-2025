//
// Created by Cezara on 27.03.2025.
//

#ifndef DSM_H
#define DSM_H
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

class DSM {
private:
    std::vector<std::string> nodeNames;                 // Numele nodurilor
    float** adjMatrix;                                  // Matricea de adiacență alocată dinamic
    int capacity;                                       // Capacitatea maximă
    int currentSize;                                    // Numărul actual de elemente

    int get_index(const std::string& name) const;       // Returnează indexul unui element după nume
    void ensure_size(int new_size);                     // Asigură că matricea și vectorul au dimensiunea dorită

public:
    DSM(const int count);                               // Constructor cu număr de elemente
    DSM(std::vector<std::string> names);                // Constructor cu vector de nume
    DSM(const DSM& other);                              // Constructor de copiere

    int size() const;                                   // Returnează numărul de elemente din matrice
    std::string get_name(int index) const;              // Returnează numele de la o anumită poziție
    void set_element_name(int index, std::string name); // Setează numele unui element

    void add_link(std::string from_element, std::string to_element, float weight); // Adaugă sau actualizează o legătură
    void delete_link(std::string from_element, std::string to_element);            // Șterge o legătură

    bool have_link(std::string from_element, std::string to_element) const;        // Verifică dacă există o legătură
    float link_weight(std::string from_element, std::string to_element) const;     // Returnează greutatea unei legături
    int count_to_links(std::string element_name) const;                            // Numărul de legături către un element
    int count_from_links(std::string element_name) const;                          // Numărul de legături de la un element
    int count_all_links() const;                                                   // Numărul total de legături

    ~DSM(); // Destructor
};

#endif //DSM_H
