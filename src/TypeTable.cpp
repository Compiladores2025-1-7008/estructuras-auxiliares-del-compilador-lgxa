#include "TypeTable.hpp"
#include <iostream>

int TypeTable::addBasicType(const std::string& name, int size) {
    TypeEntry entry;
    entry.id = lastId++;
    entry.kind = TypeKind::BASIC;
    entry.name = name;
    entry.size = size;
    entry.elements = 1;
    types.push_back(entry);
    return entry.id;
}

int TypeTable::addArrayType(int baseTypeId, int elements) {
    TypeEntry entry;
    entry.id = lastId++;
    entry.kind = TypeKind::ARRAY;
    entry.name = "array"; 
    entry.elements = elements;
    entry.baseTypeId = baseTypeId;
    
    // eel tamaño es el del tipo base * número de elementos
    int baseSize = getSize(baseTypeId);
    entry.size = baseSize * elements;
    
    types.push_back(entry);
    return entry.id;
}

int TypeTable::addStructType(const std::string &name, SymbolTable* fields) {
    TypeEntry entry;
    entry.id = lastId++;
    entry.kind = TypeKind::STRUCT;
    entry.name = name;
    entry.structFields = fields;
    // ll tamaño de la estructura dependería de la suma de sus campos, 
    // pero por ahora lo dejaremos en 0 o se calcularía externamente.
    entry.size = 0; 
    types.push_back(entry);
    return entry.id;
}

const TypeEntry& TypeTable::get(int id) const {
    // validar rangos en un caso mas real
    return types[id];
}

int TypeTable::getSize(int id) const {
    return types[id].size;
}

int TypeTable::getNumElements(int id) const {
    return types[id].elements;
}

int TypeTable::getBaseType(int id) const {
    return types[id].baseTypeId;
}

SymbolTable* TypeTable::getStructFields(int id) const {
    return types[id].structFields;
}

void TypeTable::print() const {
    std::cout << "--- Type Table ---\n";
    for (const auto& t : types) {
        std::cout << "ID: " << t.id << " Name: " << t.name 
                  << " Size: " << t.size << "\n";
    }
}