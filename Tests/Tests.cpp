#include <gtest/gtest.h>
#include <iostream>
#include "../Classes/Neighborhood.h"
#include "../Classes/TravelPoint.h"
#include "../Classes/Travel.h"
#include "../Parser/TravelParser.h"


class DataClassesTest : public ::testing::Test {
  protected:
    using data_t = int;
    data_t temp = 5;
};

TEST(ExampleTestxdxd, example){
  ASSERT_TRUE(5==5);
  std::cout << "Example 1 " << std::endl;
}

TEST(ExampleTestxdxd, example2){
  ASSERT_TRUE(5==5);
  std::cout << "Example 1 " << std::endl;
}

TEST_F(DataClassesTest, emptyFirstTest) {
  data_t temp2 = 5;
  EXPECT_EQ(temp, temp2);
  ASSERT_EQ(temp, temp2);
  ASSERT_TRUE(temp2 == 5);
  std::cout << "Test test" << std::endl;
  // ASSERT_TRUE(node != nullptr);
}

class ParserTests : public ::testing::Test {
  protected:
    using data_t = int;
    using TP = TravelParser;
};

TEST_F(ParserTests, correctFileExistance) {
  TP tp = TP("./../green_tripdata_2015-01.csv");
  std::vector<Travel *> travels = tp.getTravels();
  data_t travelNumber = travels.size();
  EXPECT_GT(travelNumber, 0);
  EXPECT_NO_THROW({
      TP tp = TP("./../green_tripdata_2015-01.csv");
  });
}

TEST_F(ParserTests, nonExistantOrEmptyFile) {
  EXPECT_THROW({
      TP tp = TP("./../badfile.csvv");
  }, std::invalid_argument);
}
// class QuadTreeParamTest : public ::testing::TestWithParam<std::size_t> {
//   protected:
//     using data_t = int;
//     using point_t = Point<data_t, 2>;
//     QuadTree<QuadNode<point_t>, Rectangle<point_t>, point_t> tree;
// };

// TEST_P(QuadTreeParamTest, randomRangeTest) {
//   const std::size_t num_points = GetParam();
//   const std::size_t min=0, max=1000;

//   std::vector<point_t> points;
//   for(std::size_t I=0;I<num_points;I++)
//     points.push_back(point_t({genRandomNumber<int>(min, max), genRandomNumber<int>(min, max)}));

//   for(auto& p : points){
//     tree.insert(p);
//   }

//   Rectangle<point_t> region({{200, 200}}, {{600, 600}});

//   auto result = tree.range(region);

//   EXPECT_NE(result.size(), 0);
// }

// INSTANTIATE_TEST_CASE_P(
//         JustAName,
//         QuadTreeParamTest,
//         ::testing::Values( 10, 100, 1000, 10000));

