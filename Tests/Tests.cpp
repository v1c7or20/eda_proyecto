#include <gtest/gtest.h>
#include <iostream>

// spatial
#include "../Classes/Spatial/Point.h"
#include "../Classes/Spatial/Rectangle.h"
#include "../Classes/Spatial/Entry.h"
#include "../Classes/Spatial/RNode.cpp"
#include "../Classes/Spatial/RTree.cpp"

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
  EXPECT_NO_THROW({
      TP tp = TP("./../green_tripdata_2015-01.csv");
  });
}


TEST_F(ParserTests, fileSizeMoreThan0) {
  TP tp = TP("./../green_tripdata_2015-01.csv");
  std::vector<Travel *> travels = tp.getTravels();
  data_t travelNumber = travels.size();
  EXPECT_GT(travelNumber, 0);
}

TEST_F(ParserTests, nonExistantOrEmptyFile) {
  EXPECT_THROW({
      TP tp = TP("./../badfile.csvv");
  }, std::invalid_argument);
}

class RTreeTests : public ::testing::Test {
  protected:
    using data_t = int;
    using point_t = Point<int, 2>;
    using rectangle_t = Rectangle<point_t>;
    using rnode_t = RNode<point_t, int>;
    using rtree_t = RTree<point_t, int, 4, 2>;
    rtree_t rtree;
};

TEST_F(RTreeTests, emptyPointSearch) {
  point_t queryp({1,1});
  auto result = rtree.search(queryp).size();
  EXPECT_EQ(result, 0);
}

TEST_F(RTreeTests, emptyRectPointSearch) {
  point_t queryP({1,1});
  point_t queryP2({2,2});
  auto result = rtree.search(queryP, queryP2).size();
  EXPECT_EQ(result,  0);
}

TEST_F(RTreeTests, emptyRectangleSearch) {
  rectangle_t queryR(point_t({1,1}), point_t({2,2}));
  auto result = rtree.search(queryR).size();
  EXPECT_EQ(result, 0);
}

TEST_F(RTreeTests, insertOne) {
  point_t P1({1,1});
  rtree.insert(P1,1);
  auto root = rtree.getRoot();
  ASSERT_TRUE(root->isLeaf());
  EXPECT_EQ(root->size(), 1);

  auto entry = root->getEntry(0);
  auto data = entry->getData();
  auto rect = entry->getRectangle();

  EXPECT_EQ(data, 1);
  EXPECT_EQ(rect.getArea(), 0);
}

TEST_F(RTreeTests, insertMultipleNoSplit){
  point_t P1({1, 1}), P2({2, 11}), P3({6, 10});
  rtree.insert(P1, 1);
  rtree.insert(P2, 2);
  rtree.insert(P3, 3);
  auto root = rtree.getRoot();
  ASSERT_TRUE(root->isLeaf());
  EXPECT_EQ(root->size(), 3);
  auto entry = root->getEntry(0);

  for(int i = 0; i < 3; ++i){
    entry = root->getEntry(i);
    EXPECT_EQ(entry->getData(), i+1);
  }
}

TEST_F(RTreeTests, insertMultipleWithSplit) {
  const int x = 0, y = 1;
  point_t P1({1, 1}), P2({2, 11}), P3({6, 10}), P4({1, 9}), P5({1, 13});
  rtree.insert(P1, 1);
  rtree.insert(P2, 2);
  rtree.insert(P3, 3);
	rtree.insert(P4, 4);
	rtree.insert(P5, 5);

  auto root = rtree.getRoot();
  ASSERT_FALSE(root->isLeaf());
  EXPECT_EQ(root->size(), 2);

  auto entry = root->getEntry(0);
  rectangle_t r1 = entry->getRectangle();
  auto _x = r1._min.get(x);
  auto _y = r1._min.get(y);
  EXPECT_EQ(_x, 1);
  EXPECT_EQ(_y, 1);
  _x = r1._max.get(x);
  _y = r1._max.get(y);
  EXPECT_EQ(_x, 1);
  EXPECT_EQ(_y, 13);

  entry = root->getEntry(1);
  r1 = entry->getRectangle();
  _x = r1._min.get(x);
  _y = r1._min.get(y);
  EXPECT_EQ(_x, 2);
  EXPECT_EQ(_y, 10);
  _x = r1._max.get(x);
  _y = r1._max.get(y);
  EXPECT_EQ(_x, 6);
  EXPECT_EQ(_y, 11);
  
/*
  for(int i = 0; i < 3; ++i){
    entry = root->getEntry(i);
    EXPECT_EQ(entry->getData(), i+1);
  }
}*/
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

