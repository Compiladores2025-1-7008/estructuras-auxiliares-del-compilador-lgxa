#include "SymbolTable.hpp"
#include <iostream>

bool SymbolTable::insert(const SymbolEntry &entry) {
    if (table.find(entry.id) != table.end()) {
        return false; 
    }
    table[entry.id] = entry;
    return true;
}

int SymbolTable::getType(const std::string &id) {
    auto it = table.find(id);
    if (it != table.end()) return it->second.typeId;
    return -1; 
}

int SymbolTable::getAddress(const std::string &id) {
    auto it = table.find(id);
    if (it != table.end()) return it->second.address;
    return -1;
}

Category SymbolTable::getCategory(const std::string &id) {
    auto it = table.find(id);
    if (it != table.end()) return it->second.category;
    // retorno por defecto si no existe
    return Category::VAR; 
}

std::vector<int> SymbolTable::getParams(const std::string &id) {
    auto it = table.find(id);
    if (it != table.end()) return it->second.params;
    return {};
}

void SymbolTable::print() const {
    std::cout << "--- Symbol Table ---\n";
    for (const auto& pair : table) {
        std::cout << "ID: " << pair.first << " Addr: " << pair.second.address << "\n";
    }
}