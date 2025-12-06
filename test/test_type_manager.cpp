#include "../src/TypeManager.hpp"
#include "../src/TypeTable.hpp" // este es necesario para pasar TT
#include <gtest/gtest.h>

TEST(TypeManagerTest, MaxType) {
    TypeTable tt;
    // agregamos tipos para que tengan ID 0 y 1
    // id 0: char (prioridad 1)
    tt.addBasicType("char", 1); 
    // id 1: int (prioridad 2)
    tt.addBasicType("int", 4);  

    TypeManager tm;
    // maxType entre char(0) e int(1) debe ser int(1)
    EXPECT_EQ(tm.maxType(tt, 0, 1), 1);
}

TEST(TypeManagerTest, MinType) {
    TypeTable tt;
    tt.addBasicType("char", 1);
    tt.addBasicType("int", 4);

    TypeManager tm;
    // minType entre char(0) e int(1) debe ser char(0)
    EXPECT_EQ(tm.minType(tt, 0, 1), 0);
}

TEST(TypeManagerTest, Ampliar) {
    TypeManager tm;
    EXPECT_EQ(tm.ampliar(0, 0, 1), 1);
}

TEST(TypeManagerTest, Reducir) {
    TypeManager tm;
    EXPECT_EQ(tm.reducir(0, 1, 0), 0);
}