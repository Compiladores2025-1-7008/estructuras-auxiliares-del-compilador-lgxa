#pragma once
#include <vector>
#include <memory>
#include "SymbolTable.hpp" 

class SymbolTableStack {
private:
    // Este ahora almacena unique_ptr a objetos SymbolTable, no a punteros de tablas, lo tuve que cambiar
    std::vector<std::unique_ptr<SymbolTable>> stack;

public:
    // crea nuevo ámbito
    void pushScope();

    // sale de un ámbito 
    void popScope();

    // sale del ámbito y retorna el puntero a la tabla (
    SymbolTable* popSymbolTable();

    // insertar solo en tope
    bool insertTop(const SymbolEntry &entry);

    // insertar solo en la base (ámbito global)
    bool insertBase(const SymbolEntry &entry);

    // buscar solo en tope
    SymbolEntry* lookupTop(const std::string &id);

    // buscar solo en la base
    SymbolEntry* lookupBase(const std::string &id);

    SymbolTable* currentScope();
    SymbolTable* globalScope();
    size_t levels() const { return stack.size(); }
};