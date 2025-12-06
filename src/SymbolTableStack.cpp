#include "SymbolTableStack.hpp"

void SymbolTableStack::pushScope() {
    // ahora make_unique no lleva 'new' adentro
    stack.push_back(std::make_unique<SymbolTable>());
}

void SymbolTableStack::popScope() {
    if (!stack.empty()) {
        stack.pop_back();
    }
}

SymbolTable* SymbolTableStack::popSymbolTable() {
    if (stack.empty()) return nullptr;
    
    // release() libera la propiedad del puntero para que no se borre
    SymbolTable* t = stack.back().release();
    stack.pop_back();
    return t;
}

bool SymbolTableStack::insertTop(const SymbolEntry &entry) {
    if (stack.empty()) return false;
    return stack.back()->insert(entry);
}

bool SymbolTableStack::insertBase(const SymbolEntry &entry) {
    if (stack.empty()) return false;
    return stack.front()->insert(entry);
}

SymbolEntry* SymbolTableStack::lookupTop(const std::string &id) {
    if (stack.empty()) return nullptr;
    return const_cast<SymbolEntry*>(stack.back()->lookup(id));
}

SymbolEntry* SymbolTableStack::lookupBase(const std::string &id) {
    if (stack.empty()) return nullptr;
    return const_cast<SymbolEntry*>(stack.front()->lookup(id));
}

SymbolTable* SymbolTableStack::currentScope() {
    if (stack.empty()) return nullptr;
    return stack.back().get();
}

SymbolTable* SymbolTableStack::globalScope() {
    if (stack.empty()) return nullptr;
    return stack.front().get();
}