#include <catch2/catch.hpp> // NOTE: assuming intalled via package manager.
#include <iostream>
#include "../include/DataSet.hpp"
TEST_CASE("DataSet - file extensions")
{
    std::string fileName1 = "fakename.csv";
    std::string fileName2 = "fakenamecsv";
    std::string fileName3 = "fakename";
    std::string fileName4 = "fakename.csv2";
    REQUIRE_NOTHROW(DataSet{fileName1});
    REQUIRE_THROWS(DataSet{fileName2});
    REQUIRE_THROWS(DataSet{fileName3});
    REQUIRE_THROWS(DataSet{fileName4});
}

TEST_CASE("DataSet - get data - correct data")
{
    std::vector<std::string> row1{"Yes", "No", "No",  "Yes",    "Some",
                                  "$$$", "No", "Yes", "French", "0-10"};
    std::vector<std::string> row2{"Yes", "No", "No", "Yes",  "Full",
                                  "$",   "No", "No", "Thai", "30-60"};
    std::vector<std::string> row3{"No", "Yes", "No", "No",     "Some",
                                  "$",  "No",  "No", "Burger", "0-10"};
    std::vector<std::string> row4{"Yes", "No",  "Yes", "Yes",  "Full",
                                  "$",   "Yes", "No",  "Thai", "10-30"};
    std::vector<std::string> row5{"Yes", "No", "Yes", "No",     "Full",
                                  "$$$", "No", "Yes", "French", ">60"};
    std::vector<std::string> row6{"No", "Yes", "No",  "Yes",     "Some",
                                  "$$", "Yes", "Yes", "Italian", "0-10"};
    std::vector<std::string> row7{"No", "Yes", "No", "No",     "None",
                                  "$",  "Yes", "No", "Burger", "0-10"};
    std::vector<std::string> row8{"No", "No",  "No",  "Yes",  "Some",
                                  "$$", "Yes", "Yes", "Thai", "0-10"};
    std::vector<std::string> row9{"No", "Yes", "Yes", "No",     "Full",
                                  "$",  "Yes", "No",  "Burger", ">60"};
    std::vector<std::string> row10{"Yes", "Yes", "Yes", "Yes",     "Full",
                                   "$$$", "No",  "Yes", "Italian", "10-30"};
    std::vector<std::string> row11{"No", "No", "No", "No",   "None",
                                   "$",  "No", "No", "Thai", "0-10"};
    std::vector<std::string> row12{"Yes", "Yes", "Yes", "Yes",    "Full",
                                   "$",   "No",  "No",  "Burger", "30-60"};
    std::vector<std::vector<std::string>> rows{row1, row2,  row3,  row4,
                                               row5, row6,  row7,  row8,
                                               row9, row10, row11, row12};
    std::vector<std::string> outputs{"Yes", "No",  "Yes", "Yes", "No", "Yes",
                                     "No",  "Yes", "No",  "No",  "No", "Yes"};
    std::vector<std::string> labels{"Alt",  "Bar",   "Fri",     "Hun",
                                    "Pat",  "Price", "Rain",    "Res",
                                    "Type", "Est",   "WillWait"};

    // Ensure a bad path throws an error
    std::string badPath = "..datasets/restaurant.csv";
    REQUIRE_THROWS(DataSet{badPath}.getData());

    std::string path = "datasets/restaurant.csv";
    DataSet ds{path};
    REQUIRE_NOTHROW(ds.getData());
    auto examples = ds.getExamples();
    REQUIRE(!examples.empty());

    for (int i = 1; i < (int)examples.size(); i++)
    {
        auto example = examples[i - 1];
        // Ensure that examples are the correct name, from 1 to n
        REQUIRE(example.getExampleName() == ("x" + std::to_string(i)));
        REQUIRE(example.getAttributes() == rows[i - 1]);
    }
}
