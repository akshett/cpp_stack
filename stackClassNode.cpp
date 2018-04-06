#include <iostream>
#include <cassert>

template<class T>
class StackNode
{
	private:
		struct Node
		{
			T val;
			Node *next;
		};
		Node *first;
		int size;
	
	public:
		StackNode():size(0)
		{
		}

		void push(T m_val)
		{
			Node *n = new Node;
			n->val = m_val;
			//if (!isEmpty())
			n->next = first;
			first = n;
			size++;
		}

		T pop()
		{
			assert(!isEmpty() && "The stack is empty, nothing to pop out");
			if (!isEmpty())
			{
				Node *pop = first;
				first = first->next;
				size--;
				T popped_val = pop->val;
				delete pop;
				return popped_val;
			}
		}

		bool isEmpty()
		{
			return (size == 0);
		}

		void iterPrint()
		{
			Node *it = first;
			while(it!=nullptr)
			{
				std::cout << it->val << " ";
				it = it->next;
			}
			std::cout << "\n";
		}

		int count()
		{
			return size;
		}

		~StackNode()
		{
			Node *it = first;
			while(it != nullptr)
			{
				Node *next = it->next;
				delete it;
				it = next;
			}
		}
};

int main()
{
	StackNode<int> sn;
	std::cout << "Initialized new stack node, Is it empty?" << '\n';
	std::cout << sn.isEmpty() << '\n';
	std::cout << "Size of new stack node: " << '\n';
	std::cout << sn.count() << '\n';


	sn.push(4);
	int a = 9;
	sn.push(a);
	sn.push(a);
	sn.push(32);
	sn.iterPrint();
	std::cout << "Size of recent stack node: " << '\n';
	std::cout << sn.count() << '\n';
	std::cout << "Popping an element out" << '\n';
	std::cout << sn.pop() << '\n';
	std::cout << "Size of stack node now: " << '\n';
	std::cout << sn.count() << '\n';

	sn.pop();
	sn.pop();
	//sn.pop();
	//sn.pop();
	//sn.pop();
	//sn.pop();
	std::cout << "Is the stack node empty now? " << '\n';
	std::cout << sn.isEmpty() << '\n';
	std::cout << "Size of stack node now " << '\n';
	std::cout << sn.count() << '\n';

	return 0;
}
