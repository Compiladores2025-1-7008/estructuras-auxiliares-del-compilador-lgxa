#include "TypeManager.hpp"

// maxType: Retorna el tipo de mayor jerarquía
int TypeManager::maxType(const TypeTable &TT, int t1, int t2) {
    // Usa la función priority definida en el header
    if (priority(TT, t1) >= priority(TT, t2)) return t1;
    return t2;
}

// minType: Retorna el tipo de menor jerarquía
int TypeManager::minType(const TypeTable &TT, int t1, int t2) {
    if (priority(TT, t1) <= priority(TT, t2)) return t1;
    return t2;
}

int TypeManager::ampliar(int dir, int tipo1, int tipo2) {
    // Si los tipos son iguales, retorna el tipo original
    if (tipo1 == tipo2) return tipo1;
    // Si ampliamos, la expresión resultante tiene el tipo mayor (tipo2)
    return tipo2;
}

int TypeManager::reducir(int dir, int tipo1, int tipo2) {
    if (tipo1 == tipo2) return tipo1;
    
    return tipo2;
}