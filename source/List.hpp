#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP

#include <cstddef>

//List.hpp

template <typename T>
struct List;

//Struct ListNode includes a pointer at the previous and next element and an object with the type T
template <typename T>
struct ListNode
{
//Default constructor
  ListNode():
	m_value(),
	m_prev(nullptr),
	m_next(nullptr) {}

//Custom constructor
  ListNode(T const& v, ListNode* prev, ListNode* next):
	m_value(v),
	m_prev(prev),
	m_next(next) {}

	T m_value;		//value
	ListNode* m_prev;	//previous
	ListNode* m_next;	//next
};

//End of a list = nullptr
template <typename T>
struct ListIterator
{
  typedef ListIterator<T> Self;

  typedef T value_type;
  typedef T* pointer;
  typedef T& reference;
  typedef ptrdiff_t diffrence_type;
  typedef std::forward_iterator_tag iterator_category;

  friend class List<T>;

  ListIterator() : m_node(nullptr){}
  ListIterator(ListNode<T>* n) : m_node(n) {}

//returns the value
  reference operator*() const
	{
	  return m_node->m_value;	
	}
//returns the place of m_value
  pointer operator->() const
	{
	  return &(m_node->m_value);
	}
//iterator +1, orginal
  Self& operator++()
  {
  	*this = next();
	return *this; //iterator points at the next orignial node
  }

//value, before it+1
  Self operator++(int)
  {
	Self tmp= *this;
	++(*this);
	return tmp; //iterator
  }
//node same value as x?
  bool operator==(const Self& x) const
  {
  	return m_node == x.m_node;
  }
//node diffrent value
  bool operator!=(const Self& x) const
  {
	return m_node != x.m_node;
  }
//next
  Self next() const
  {
	if(m_node)	//if node
	  return ListIterator(m_node->m_next);
	else		//list ends
	  return ListIterator(nullptr);
  } 
//previous
  Self previous() const
  {
  if(m_node)
	return ListIterator(m_node->m_prev);
  else
	return ListIterator(nullptr)
  }

  private:
  //The Node the iterator is pointing to
	ListNode<T>* m_node = nullptr;
};

template <typename T>
struct ListConstIterator
{
  friend class List <T>;
	
  public:
  ListNode<T>*m_node = nullptr;
};

template <typename T>
class List
{
public:
  typedef T value_type;
  typedef T* pointer;
  typedef const T* const_pointer
  typedef T& reference;
  typedef const T& const_reference;
  typedef ListIterator<T> iterator;
  typedef ListConstIterator<T> const_interator;

  friend class ListIterator<T>;
  friend class ListConstIterator<T>;

//Default Constructor, empty list
  List():
	m_size{0},
	m_first{nullptr},
	m_last{nullptr} {}

//Copy Constructor
  List<T>(List<T> const& thelist):
  m_size(0),
  m_first(nullptr),
  m_last(nullptr) 
  {
	for(auto i = thelist.begin(); it != thelist.end(); i++)
	{
	  push_back(*i);
	}
  }

//Move Constructor
  List<T>(List<T> && thelist) :
  //adapt thelist 
  m_size(thelist.m_size),
  m_first(thelist.m_first),
  m_last(thelist.m_last)
  {
	thelist.m_first = nullptr;
	thelist.m_last = nullptr;
	thelist.m_size = 0;
  }
//Destructor?
  ~List(){clear();}
	
  bool empty() const;
  {
	return m_size == 0;	//check if empty
  }

  std::size_t size() const;
  {
	return m_size;	//returns size
  }

  T const&  front() const
  {
	return m_first->m_value;
  }
	
  T& front
  {
	return m_first->m_value;
  }

  T const& back() const
  {
	return m_last->m_value;
  }
	
  T& back
  {
	return m_last->m_value;
  }

//4.8
  void insert(T const& a, iterator const& p)
  {
  iterator i = begin();
	while(i != p) i++;

	T temp = *i;
	*i = a;
	i++;

	while(i!=end())
	{
	  T temp2 = *i;
	  *i = temp;
	  temp = temp2;
	  i++;
	}

	push_back(temp);
  }

//4.9
  void reverse()
  {
  List<T> rev{*this}; //copy der liste
	clear(); //macht ganze Liste leer
 
	for(iterator i = rev.begin(); i!=rev.end(); ++i)
	  push_front(*i);
  }

//Insert a new element at the beginnning of the list, right before its current first element
  void push_front(T const& e)
  {
	if(m_size == 0)
	{
	  m_first = new ListNode<T>{e, nullptr, nullptr};
	  m_last = m_first;
	}

	else
	{
	  m_first = new ListNode<T>{e, nullptr, m_first};
	  m_first -> m_next -> m_prev = m_first;
	}
		++m_size;
  }

//Insert a new element at the beginning of the list, right after its current last element
  void push_back(T const& h)
  {
	if(m_size == 0)
	{
	  m_last = new ListNode<T>{h, nullptr, nullptr};
	  m_first = m_last;
	}

	else
	{
	  m_last = new ListNode<T>{h, m_last, nullptr};
	  m_last -> m_prev -> m_next = m_last;
	}
	  ++m_size;
  }

//Delete the first element of the list 
  void pop_front()
  {
	if(m_size == 1)
	{
	  assert(m_first != nullptr);
	  delete m_first;
	  m_first = nullptr;
	  m_size = 0;
	}

	else if(m_size >= 1)
	{
	  assert(m_first != nullptr);
	  delete m_first;
	  m_first = m_first-> m_next;
	  -- m_size;
	}
  }

//Delete the last element of the list
  void pop_back()
  {
	if(m_size == 1)
	{
	  assert(m_last != nullptr);
	  delete m_last;
	  m_last = nullptr;
	  m_size = 0;
	}

	else if(m_size >= 1)
	{
	  assert(m_last != nullptr);
	  delete m_last;
	  m_last = m_last-> m_prev;
	  --m_size;
	}
  }

//4.5
  iterator begin() const
  {
  return m_first; //returns iterator at the first node
  }

  iterator end() const
  {
  return ListIterator<T>{};
  }

//clear list
  void clear()
  {
	while(m_size > 0)
		pop_back();
  }

	private:
	std::size_t m_size = 0;
	ListNode<T>* m_first = nullptr;
	ListNode<T>* m_last = nullptr;

};

//4.6
template<typename T>
bool operator == (List<T> const& xs, List<T> const& ys)
{
	
  if(xs.size() != ys.size()) //same size?
	return false;

  else
  {

	ListIterator<T> x = xs.begin(); 
	ListIterator<T> y = ys.begin();

	while(x != xs.end() and y!=ys.end())
	{
	  if(*x != *y)
		return false;

			x++;
			y++;
	}
	return true;
  }
}

template<typename T>
bool operator != (List<T> const& xs, List<T> const& ys)
{
  return !(xs == ys);
}
		
#endif //#define BUW_LIST_HPP

