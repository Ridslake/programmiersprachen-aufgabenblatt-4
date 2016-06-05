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

//iterator +1, not or.
  Self operator++(int)
  {
	Self tmp= *this;
	++(*this);
	return tmp; //iterator
  }

  bool operator==(const Self& x) const {}
  bool operator!=(const Sekf& x) const {}
  Self next() const
  {
	if(m_node)
	  return ListIterator(m_node->m_next);
	else
	  return ListIterator(nullptr);
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
	//not implemented yet
	private
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
  List<T>(List<T> const& inlist):
	
	
	bool empty() const;
	{
	  return m_size == 0;	//check empty
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

  void clear()
  {
	for(int i = 0; i <= m_size; ++i)
  }

	private:
	std::size_t m_size = 0;
	ListNode<T>* m_first = nullptr;
	ListNode<T>* m_last = nullptr;

};

#endif //#define BUW_LIST_HPP

