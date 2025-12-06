#include "../src/SymbolTable.hpp"
#include <gtest/gtest.h>

TEST(SymbolTableTest, InsertAndRetrieveSymbol) {
    SymbolTable ts;

    SymbolEntry entry;
    entry.id = "x";
    entry.typeId = 1;
    entry.category = Category::VAR;
    entry.address = 100;
    
    ts.insert(entry);
    
    // usar lookup que devuelve puntero
    auto sym = ts.lookup("x");

    ASSERT_TRUE(sym != nullptr);
    EXPECT_EQ(sym->typeId, 1);
    EXPECT_EQ(sym->address, 100);
    EXPECT_EQ(sym->category, Category::VAR);
    EXPECT_TRUE(sym->params.empty());
}

TEST(SymbolTableTest, FunctionSymbol) {
    SymbolTable ts;
    
    SymbolEntry entry;
    entry.id = "sum";
    entry.typeId = 3;
    entry.category = Category::FUNCTION;
    entry.address = 200;
    entry.params = {1, 2};

    ts.insert(entry);

    auto sym = ts.lookup("sum");
    ASSERT_TRUE(sym != nullptr);
    EXPECT_EQ(sym->params.size(), 2);
}