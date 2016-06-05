#define CATCH_CONFIG_RUNNER
#include "List.hpp"

//Check if the container has no elements
TEST_CASE("Empty", "[empty]")
{
  List<int> list;
  Require(list.empty()==true);
}
//Check size
TEST_CASE("Size","[size]")
{
  List<int> list1;
  Require(list1.size()==0);
}

//Check push_front
TEST_CASE("push_front", "[pu_fr]")
{
  List<int> list;
  list.push_front(11);
  REQUIRE(11 == list.front());

  list.push_front(22);
  REQUIRE(22 == list.front());	
}

//Check push_back
TEST_CASE("push_back", "[pu_ba]")
{
 List<int> list;
 list.push_back(12);
 REQUIRE(12 == list.back());

 list.push_back(24);
 REQUIRE(24 == list.back());
}

//Check pop_front
TEST_CASE("pop_front", "[po_fr]")
{
  List<int> list{};
  list.push_back(42);
  list.pop_front();
  REQUIRE(true == list.empty());

  list.push_back(69);
  list.push_back(96);
  list.pop_front();
  REQUIRE(list.front() == 96);	
}

//Check pop_back
TEST_CASE("pop_back", "[po_ba]")
{
  List<int> list{};
  list.push_back(42);
  list.pop_back();
  REQUIRE(true == list.empty());

  list.push_back(69);
  list.push_back(96);
  list.pop_back();
  REQUIRE(list.front() == 69);
}

//Check clear
TEST_CASE("clear","[cl]")
{
  List<int> list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);
  list.clear();
  REQUIRE(list.empty() == true);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc,argv);
}
