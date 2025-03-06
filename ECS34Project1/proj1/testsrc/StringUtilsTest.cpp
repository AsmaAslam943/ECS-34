#include <gtest/gtest.h>
#include "StringUtils.h"
//NOTE: I used my 32C Professor's notes to reference the EXPECT_EQ 
TEST(StringUtilsTest, SliceTest){
    std::string result = StringUtils::Slice("Asma Aslam", 5,10);
    EXPECT_EQ(result, "Aslam");
}

TEST(StringUtilsTest, Capitalize){
    std:: string result = StringUtils::Capitalize("america");
    EXPECT_EQ(result, "America");
}

TEST(StringUtilsTest, Upper){
    std:: string result = StringUtils::Upper("AMErica");
    EXPECT_EQ(result,"AME");
}

TEST(StringUtilsTest, Lower){
    std:: string result = StringUtils::Lower("Asma");
    EXPECT_EQ(result, "sma"); 
}

TEST(StringUtilsTest, LStrip){
    std:: string result = StringUtils::LStrip("  kitkat");
    EXPECT_EQ(result, "kitkat");
}

TEST(StringUtilsTest, RStrip){
    std:: string result = StringUtils::RStrip("kitkat  ");
    EXPECT_EQ(result,"kitkat");
}

TEST(StringUtilsTest, Strip){
    std:: string result = StringUtils::Strip("  kitkat   ");
    EXPECT_EQ(result,"kitkat");
}

TEST(StringUtilsTest, Center){
    std:: string result = StringUtils::Center("kitkat",10);
    EXPECT_EQ(result,"  kitkat  ");
}

TEST(StringUtilsTest, LJust){
    std:: string result = StringUtils::LJust("kitkat", 10);
    EXPECT_EQ(result, "kitkat    ");
}

TEST(StringUtilsTest, RJust){
    std:: string result = StringUtils::RJust("kitkat", 10);
    EXPECT_EQ(result, "    kitkat");
}

TEST(StringUtilsTest, Replace){
    std:: string result = StringUtils::Replace("kittycat", "cat", "dog");
    EXPECT_EQ(result, "kittydog");
}

TEST(StringUtilsTest, Split){
    std:: vector<std:: string> w = StringUtils::Split("My favorite drinks are iced coffees");
    std:: vector<std:: string> result = {"My", "favorite", "drinks", "are", "iced", "coffees"};
    EXPECT_EQ(result, w);
}

TEST(StringUtilsTest, Join){
    std:: vector<std:: string> ch = {"dog","cat"};
    std::string result = StringUtils::Join("", ch);
    EXPECT_EQ(result, ch);
}

TEST(StringUtilsTest, ExpandTabs){
    std::string result = StringUtils::ExpandTabs("  fatcat", 4);
    EXPECT_EQ(result, "    fatcat");
}

TEST(StringUtilsTest, EditDistance){
    EXPECT_EQ(StringUtils::EditDistance("stringer", "linger"),2);
    EXPECT_EQ(StringUtils::EditDistance("fat","cat"), 1);
}
