#include "../src/CodeGenerator.hpp" 
#include <gtest/gtest.h>

TEST(CodeGeneratorTest, GenerateNewTemporary) {
    CodeGenerator cg;
    // verificar si empieza en 0
    EXPECT_EQ(cg.newTemp(), "t0");
    EXPECT_EQ(cg.newTemp(), "t1");
}

TEST(CodeGeneratorTest, GenerateNewLabel) {
    CodeGenerator cg;
    EXPECT_EQ(cg.newLabel(), "L0");
    EXPECT_EQ(cg.newLabel(), "L1");
}