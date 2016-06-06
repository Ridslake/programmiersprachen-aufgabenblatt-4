#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include "List.hpp"

template <typename T>
List<T> reverse(List<T> const& l)
{
	List<T> n{l}; //kopie von l
	n.reverse();
	return n;
}

TEST_CASE("Empty","[empty]")
{
	List<int> list1;
	REQUIRE(list1.empty()==true);
}

TEST_CASE("Size","[Size]")
{
	List<int> list1;
	REQUIRE(list1.size()==0);
}

TEST_CASE("push_front", "[pu_fr]")
{
	List<int> list1;
	list1.push_front(11);
	REQUIRE(11 == list1.front());

	List<int> list2;
	list2.push_front(11);
	list2.push_front(22);
	REQUIRE(22 == list2.front());
}


TEST_CASE("push_back", "[pu_ba]")
{
	List<int> list1;
	list1.push_back(12);
	REQUIRE(12 == list1.back());

	List<int> list2;
	list2.push_back(12);
	list2.push_back(24);
	REQUIRE(24 == list2.back());
}


TEST_CASE("pop_front", "[po_fr]")
{
	List<int> list1;
	list1.push_front(11);
	list1.pop_front();
	REQUIRE(true == list1.empty());

	list1.push_back(11);
	list1.push_back(22);
	list1.pop_front();
	REQUIRE(list1.front() == 22);	
}

TEST_CASE("pop_back", "[po_ba]")
{
	List<int> list{};
	list.push_back(12);
	list.pop_back();
	REQUIRE(true == list.empty());

	list.push_back(12);
	list.push_back(24);
	list.pop_back();
	REQUIRE(list.front() == 12);
}

TEST_CASE("Clear","[clear]")
{
	List<int> list;
	list.push_front(45);
	list.push_front(54);
	list.clear();
	REQUIRE(list.empty() == true);
}

TEST_CASE("should be an empty range after default construction","[iterators]")
{
	List<int> list;
	auto b = list.begin();
	auto e = list.end();
	REQUIRE( b == e);
}

TEST_CASE("provide acces to the first element with begin","[iterators]")
{
	List<int> list;
	list.push_front(42);
	REQUIRE( 42 == *list.begin());
}

TEST_CASE("equal_or_nah","[eon]")
{
	List<int> list1;
	list1.push_front(30);
	list1.push_front(12);
	list1.push_front(42);

	List <int> list4;
	list2.push_front(30);
	list2.push_front(12);
	list2.push_front(42);
	REQUIRE(list3 == list4);
}

TEST_CASE("different or not","[different or not]")
{
	List<int> list;
	list.push_front(30);
	list.push_front(12);
	list.push_front(18);

	List <int> list2;
	list2.push_front(30);
	list2.push_front(12);
	list2.push_front(42);
	REQUIRE(list3 != list4);
}

TEST_CASE("copy constructor","[constructor]")
{
	List<int> list;
	list.push_front (1);
	list.push_front (2);
	list.push_front (3);
	list.push_front (4);
	List<int> list2{list};
	REQUIRE(list == list2);
}

TEST_CASE("insert","[insert]")
{
	List<int> list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	list.push_front(5);
	list.push_front(6);

	ListIterator<int> i = list.begin();
	i++;
	i++;

	list.insert(100,i);

	REQUIRE(list.size() == 7);
	REQUIRE(*list.begin() == 6);
}

TEST_CASE("reverses the sequence of the list", "[reverse]")
{  
  List<int> list; 
  list.push_back(1); 
  list.push_back(2); 
  list.push_back(3); 
  list.push_back(4); 
  list.push_back(5);
  list.push_back(6);

  list.reverse();
  ListIterator<int> i = list.begin();
  REQUIRE(6 == *i);
  ++i;
  REQUIRE(5 == *i);
  ++i;
  REQUIRE(4 == *i);
  ++i; 
  REQUIRE(3 == *i);
  ++i;
  REQUIRE(2 == *i);
  ++i; 
  REQUIRE(1 == *i);

  reverse(list);
  ListIterator<int> it = list.begin();
  REQUIRE(6 == *it);
  ++it;
  REQUIRE(5 == *it);
  ++it;
  REQUIRE(4 == *it);
  ++it; 
  REQUIRE(3 == *it);
  ++it;
  REQUIRE(2 == *it);
  ++it; 
  REQUIRE(1 == *it);
}


TEST_CASE("move constructor","[constructor]")
{
	List<int> list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	List<int> list2(std::move(list));
	REQUIRE( 0 == list.size());
	REQUIRE(list.empty());
	REQUIRE(4 == list2.size());
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc,argv);
}
