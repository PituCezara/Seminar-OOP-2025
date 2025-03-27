//
// Created by Cezara on 27.03.2025.
//

#include "DSM.h"
#include <vector>
#include <string>
#include <stdexcept>

// alocă matricea și o inițializează cu 0
DSM::DSM(const int count) {
    capacity = count;
    currentSize = 0;
    adjMatrix = new float*[capacity];
    for (int i = 0; i < capacity; ++i) {
        adjMatrix[i] = new float[capacity];
        for (int j = 0; j < capacity; ++j)
            adjMatrix[i][j] = 0;
    }
}

// setează numele nodurilor și creează matricea
DSM::DSM(std::vector<std::string> names) {
    nodeNames = std::move(names);
    capacity = nodeNames.size();
    currentSize = 0;
    adjMatrix = new float*[capacity];
    for (int i = 0; i < capacity; ++i) {
        adjMatrix[i] = new float[capacity];
        for (int j = 0; j < capacity; ++j)
            adjMatrix[i][j] = 0;
    }
}

// Constructor de copiere - creează o copie completă a unui obiect DSM existent
DSM::DSM(const DSM& other) {
    nodeNames = other.nodeNames;
    capacity = other.capacity;
    currentSize = other.currentSize;
    adjMatrix = new float*[capacity];
    for (int i = 0; i < capacity; ++i) {
        adjMatrix[i] = new float[capacity];
        for (int j = 0; j < capacity; ++j) {
            adjMatrix[i][j] = other.adjMatrix[i][j];
        }
    }
}

// Returnează numărul de noduri (adica dimensiunea actuală)
int DSM::size() const {
    return nodeNames.size();
}

// Returnează numele nodului de la un anumit index
std::string DSM::get_name(int index) const {
    if (...)
        throw std::domain_error("Elementname nicht gefunden");
    return nodeNames[index];
}

// Setează numele unui nod la un anumit index
void DSM::set_element_name(int index, std::string name) {
    if (index < 0 || index >= size())
        return;
    nodeNames[index] = std::move(name);
}

// Caută indexul unui nod după nume
int DSM::get_index(const std::string& name) const {
    for (int i = 0; i < size(); ++i) {
        if (nodeNames[i] == name)
            return i;
    }
    return -1;
}

// Mărește dimensiunea matricei, păstrând valorile existente
void DSM::ensure_size(int new_size) {
    if (new_size > capacity) {
        float** newMatrix = new float*[new_size];
        for (int i = 0; i < new_size; ++i) {
            newMatrix[i] = new float[new_size];
            for (int j = 0; j < new_size; ++j) {
                if (i < capacity && j < capacity)
                    newMatrix[i][j] = adjMatrix[i][j];
                else
                    newMatrix[i][j] = 0;
            }
        }
        for (int i = 0; i < capacity; ++i) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
        adjMatrix = newMatrix;
        nodeNames.resize(new_size);
        capacity = new_size;
    }
}

// Adaugă o legătură de la 'from' la 'to' cu o greutate dată
void DSM::add_link(std::string from, std::string to, float weight) {
    int from_idx = get_index(from);
    int to_idx = get_index(to);
    adjMatrix[from_idx][to_idx] = weight;
}

// Șterge legătura de la 'from' la 'to'
void DSM::delete_link(std::string from, std::string to) {
    int from_idx = get_index(from);
    int to_idx = get_index(to);
    adjMatrix[from_idx][to_idx] = 0;
}

// Verifică dacă există o legătură între două noduri
bool DSM::have_link(std::string from, std::string to) const {
    int from_idx = get_index(from);
    int to_idx = get_index(to);
    return from_idx != -1 && to_idx != -1 && adjMatrix[from_idx][to_idx] != 0;
}

// Returnează greutatea legăturii între două noduri
float DSM::link_weight(std::string from, std::string to) const {
    int from_idx = get_index(from);
    int to_idx = get_index(to);

    return adjMatrix[from_idx][to_idx];
}

// Numără câte legături vin spre un anumit nod
int DSM::count_to_links(std::string name) const {
    int idx = get_index(name);
    int count = 0;
    for (int i = 0; i < currentSize; ++i) {
        if (adjMatrix[i][idx] != 0.0f)
            count++;
    }
    return count;
}

// Numără câte legături pleacă dintr-un anumit nod
int DSM::count_from_links(std::string name) const {
    int idx = get_index(name);
    if (idx == -1)
        throw std::domain_error("Elementname nicht gefunden");
    int count = 0;
    for (int j = 0; j < currentSize; ++j) {
        if (adjMatrix[idx][j] != 0.0f)
            count++;
    }
    return count;
}

// Numără totalul tuturor legăturilor existente
int DSM::count_all_links() const {
    int count = 0;
    for (int i = 0; i < currentSize; ++i) {
        for (int j = 0; j < currentSize; ++j) {
            if (adjMatrix[i][j] != 0.0f)
                count++;
        }
    }
    return count;
}

// Destructor - eliberează memoria alocată dinamic
DSM::~DSM() {
    for (int i = 0; i < capacity; ++i) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}
