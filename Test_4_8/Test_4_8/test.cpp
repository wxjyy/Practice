#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<list>
using namespace std;

//void main()
//{
//	int ar[] = { 1, 2, 3, 4, 5 };
//	list<int> list1;
//	list<int> list2(10); //10个默认值0
//	list<int> list3(10, 5);
//	list<int> list4(ar, ar + 5);
//	list<int> list5(list4);
//	list<int> list6(list5.begin(), list5.end());
//	for (auto & e : list2)//e一旦在list里就打印e
//		cout << e << " ";
//	cout << endl;
//
//	//list4.push_back(6);
//	//list4.push_front(10);
//	//list4.insert(list4.begin(), 5, 100);
//	list3.insert(list3.begin(), ar + 1, ar + 3);
//
//	list<int>::iterator it = list3.begin();
//	while (it != list3.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	cout << list4.front() << endl;
//	cout << list4.back() << endl;
//
//}

//namespace bit
//{
//	template<class _Ty>
//	class list;
//
//	template<class _Ty>
//	class List_iterator;
//
//	//结点
//	template<class _Ty>
//	class Node
//	{
//		friend class list<_Ty>;
//		friend class List_iterator<_Ty>;
//	public:
//		//构造函数
//		Node() :_val(_Ty()), _prev(nullptr), _next(nullptr)
//		{}
//		Node(const _Ty &val, Node* prev = nullptr, Node* next = nullptr)
//			:_val(val), _prev(prev), _next(next)
//		{}
//		//析构函数
//		~Node()
//		{}
//	private:
//		Node* _prev;
//		Node* _next;
//		_Ty _val;
//	};
//
//	//迭代器
//	template<class _Ty>
//	class List_iterator
//	{
//		typedef List_iterator<_Ty> self;
//	public:
//		List_iterator(Node<_Ty> *_P) :_Ptr(_P)
//		{}
//	public:
//		bool operator!=(const self &it)
//		{
//			return (_Ptr != it._Ptr);
//		}
//		_Ty& operator*()
//		{
//			return _Ptr->_val;
//		}
//		self& operator++()
//		{
//			_Ptr = _Ptr->_next;
//			return *this;
//		}
//		self operator++(int)
//		{
//			self tmp = *this;
//			++*this;
//			return tmp;
//		}
//	public:
//		Node<_Ty>*& _Mynode()
//		{
//			return _Ptr;
//		}
//	private:
//		Node<_Ty> *_Ptr;
//	};
//
//	//list容器
//	template<class _Ty>
//	class list
//	{
//	public:
//		typedef List_iterator<_Ty> iterator;
//	public:
//		list() :_Size(0)
//		{
//			CreateHead();
//		}
//		list(int n, const _Ty &x = _Ty())
//		{
//			CreateHead();
//			while (n--)
//			{
//				insert(begin(), x);
//			}
//		}
//		list(iterator _first, iterator _last)
//		{
//			CreateHead();
//			while (_first != _last)
//			{
//				push_back(*_first);
//				++_first;
//			}
//		}
//		list(list &it)
//		{
//			CreateHead();
//			list<_Ty> tmp = list(it.begin(), it.end());
//			swap(_Head, tmp._Head);
//			_Size = it._Size;
//		}
//		list<_Ty> operator=(list<_Ty> &it)
//		{
//			if (this != &it)
//			{
//				list<_Ty> tmp(it.begin(), it.end());
//				swap(_Head, tmp._Head);
//			}
//			return *this;
//		}
//		~list()
//		{
//			clear();
//			delete _Head;
//			_Head = nullptr;
//		}
//	public:
//		iterator begin()//第一个节点
//		{
//			return iterator(_Head->_next);
//		}
//		iterator end()//最后一个节点的下一个
//		{
//			return iterator(_Head);
//		}
//	public:
//		size_t size()const
//		{
//			return _Size;
//		}
//		bool empty()const
//		{
//			return _Size == 0;
//		}
//		_Ty& front()
//		{
//			return *begin();
//		}
//		_Ty& back()
//		{
//			return *--end();
//		}
//	public:
//		void push_back(const _Ty &x)
//		{
//			//Node<_Ty>* _S = new Node<_Ty>(x);
//			//_S->_prev = _Head->_prev;
//			//_S->_next = _Head;
//			//_S->_prev->_next = _S;
//			//_S->_next->_prev = _S;
//			//_Size++;
//			insert(end(), x);
//		}
//		void clear()
//		{
//			erase(begin(), end());
//		}
//
//	public:
//		iterator insert(iterator _P, const _Ty &x)
//		{
//			Node<_Ty> *_S = new Node<_Ty>(x);
//			Node<_Ty> *cur = _P._Mynode();
//			_S->_next = cur;
//			_S->_prev = cur->_prev;
//			_S->_prev->_next = _S;
//			_S->_next->_prev = _S;
//			_Size++;
//			return iterator(_S);//返回新插入结点的迭代器
//		}
//		iterator erase(iterator _P)
//		{
//			Node<_Ty> *cur = _P._Mynode();
//			Node<_Ty> *next_node = cur->_next;
//			cur->_prev->_next = cur->_next;
//			cur->_next->_prev = cur->_prev;
//			delete cur;
//			_Size--;
//			return iterator(next_node);
//		}
//		iterator erase(iterator _first, iterator _last)
//		{
//			while (_first != _last)
//			{
//				_first = erase(_first);
//			}
//			return iterator(_last);
//		}
//	protected:
//		void CreateHead()
//		{
//			_Head = new Node<_Ty>;
//			_Head->_next = _Head;
//			_Head->_prev = _Head;
//		}
//	private:
//		Node<_Ty> *_Head;
//		size_t _Size;
//	};
//};
//
//void main()
//{
//	bit::list<int> mylist;
//	mylist.push_back(1);
//	mylist.push_back(2);
//	mylist.push_back(3);
//	mylist.push_back(4);
//	mylist.push_back(5);
//	bit::list<int> mylist1;
//	mylist1 = mylist;
//
//
//	mylist.insert(mylist.begin(), 6);
//	mylist.erase(mylist.begin());
//	mylist.clear();
//
//
//	bit::list<int>::iterator it = mylist1.begin();
//	while (it != mylist1.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}

//模拟实现list类，并完成测试

namespace bite

{

	// List的节点类

	template<class T>

	struct ListNode

	{
		ListNode(const T& val = T()); _pPre(nullptr), _pNext(nullptr), _val(val)
		{}

		ListNode<T>* _pPre;
		ListNode<T>* _pNext;
		T _val;
	};


	//List的迭代器类

	template<class T, class Ref, class Ptr>
	class ListIterator
	{
		typedef ListNode<T>* PNode;
		typedef ListIterator<T, Ref, Ptr> Self;

	public:
		ListIterator(PNode pNode = nullptr) :_pNode(pNode)
		{}

		ListIterator(const Self& l) :pNode(l._pNode)
		{}

		T& operator*()
		{
			return _pNode->val;
		}
			
		T* operator->()
		{
			return &(operator*());
		}

		Self& operator++()
		{
			_pNode = _pNode->_pNext;
			return *this;
		}

		Self operator++(int)
		{
			Self temp(*this);
			_pNode = _pNode->_pNext;
			return temp;
		}

		Self& operator--()
		{
			_pNode = _pNode->_pPre;
			return *this;
		}

		Self operator--(int)
		{
			Self temp(*this);
			_pNode = _pNode->_pPre;
			return temp;
		}

		bool operator!=(const Self& l)
		{
			return _pNode != l._pNode;
		}
		bool operator==(const Self& l)
		{
			return _pNode == l._pNode;
		}
	private:
		PNode _pNode;

	};


	//list类

	template<class T>

	class list

	{

		typedef ListNode<T> Node;

		typedef Node* PNode;

	public:

		typedef ListIterator<T, T&, T*> iterator;

		typedef ListIterator<T, const T&, const T&> const_iterator;

	public:

		///////////////////////////////////////////////////////////////

		// List的构造

		list()
		{
			CreateHead();
		}
		list(int n, const T& value = T())
		{
			CreateHead();
			while (n--)
			{
				push_back(value);
			}
		}

		template <class Iterator>

		list(Iterator first, Iterator last)
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		list(const list<T>& l)
		{
			CreateHead();
			list<T> temp(l.cbegin(), l.cend());
			this->swap(temp);
		}

		list<T>& operator=(const list<T> l)
		{
			if (this != &l)
			{
				this->swap(l);
			}
			return *this;
		}

		~list()
		{
			clear();
			delete _pHead;
			_pHead = nullptr;
		}

		///////////////////////////////////////////////////////////////

		// List Iterator

		iterator begin()
		{
			return iterator(_pHead->_pNext);
		}

		iterator end()
		{
			return iterator(_pHead);
		}

		const_iterator begin()
		{
			return const_iterator(_pHead->_pNext);
		}

		const_iterator end()
		{
			return const_iterator(_pHead);
		}


		///////////////////////////////////////////////////////////////

		// List Capacity

		size_t size()const
		{
			iterator last = end();
			iterator first = begin();
			return last._pNode - first._pNode;
		}

		bool empty()const
		{
			return size() == 0;
		}


		////////////////////////////////////////////////////////////

		// List Access

		T& front()
		{
			return *begin();
		}

		const T& front()const
		{
			return *begin();
		}

		T& back()
		{
			return *--end();
		}

		const T& back()const
		{
			return *--end();
		}


		////////////////////////////////////////////////////////////

		// List Modify

		void push_back(const T& val){ insert(end(), val); }

		void pop_back(){ erase(--end()); }

		void push_front(const T& val){ insert(begin(), val); }

		void pop_front(){ erase(begin()); }

		// 在pos位置前插入值为val的节点

		iterator insert(iterator pos, const T& val)
		{
			PNode pNewNode = new Node(val);
			PNode pCur = pos._pNode;
			pNewNode->_pPre = pCur->_pPre;
			pNewNode->_pNext = pCur;
			pNewNode->_pPre->_pNext = pNewNode;
			pCur->_pPre = pNewNode;
			return iterator(pNewNode);
		}

		// 删除pos位置的节点，返回该节点的下一个位置

		iterator erase(iterator pos)
		{
			PNode pDel = pos._pNode;
			PNode pRet = pDel->_pNext;
			pDel->_pPre->_pNext = pDel->_pNext;
			pDel->_pNext->_pPre = pDel->_pPre;
			delete pDel;
			return iterator(pRet);
		}

		void clear()
		{
			while (_pHead != end())
			{
				_pHead = erase(_pHead);
			}
		}

		void swap(List<T>& l)
		{
			List<T> tmp = _pHead;
			_pHead = l._pHead;
			l._pHead = tmp;
		}

	private:

		void CreateHead()
		{
			_pHead = new Node;
			_pHead->_pPre = _pHead;
			_pHead->_pNext = _pHead;
		}   private:
		PNode _pHead;
	};

};