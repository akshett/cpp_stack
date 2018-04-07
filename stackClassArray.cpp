#include <iostream>

template<class T>
class StackArray
{
	private:
		T *elem_arr;
		int size;
		int capacity;

		void resize_arr(int cap)
		{
			if (size >= cap)
				return;
			T *temp_arr = new T[cap];
			for (int i = 0; i < size; ++i)
				temp_arr[i] = elem_arr[i];
			delete[] elem_arr;
			elem_arr = temp_arr;
			capacity = cap;
		}

	public:
		StackArray() : elem_arr(new T[1]), size(0), capacity(1)
		{
		}

		void push(T m_val)
		{
			if (size >= capacity)
				resize_arr(2*capacity);
			elem_arr[size++] = m_val;
		}

		T pop()
		{
			if (size > 0 && size < capacity/4)
				resize_arr(capacity/2);
			T popped_elem = elem_arr[size--];
			return popped_elem;
		}

		bool isEmpty()
		{
			return (size == 0);
		}

		void iterArray()
		{
			for (int i = 0; i < size; ++i)
				std::cout << elem_arr[i] << '\n';
		}

		int count()
		{
			return size;
		}

		~StackArray()
		{
			delete[] elem_arr;
		}


};


int main()
{
	StackArray<int> sa;
	std::cout << "Initialized new stack node, Is it empty?" << '\n';
	std::cout << sa.isEmpty() << '\n';
	std::cout << "Size of new stack node: " << '\n';
	std::cout << sa.count() << '\n';


	sa.push(4);
	int a = 9;
	sa.push(a);
	sa.push(a);
	sa.push(32);
	std::cout << "Size of recent stack node: " << '\n';
	std::cout << sa.count() << '\n';
	std::cout << "Popping an element out" << '\n';
	std::cout << sa.pop() << '\n';
	std::cout << "Size of stack node now: " << '\n';
	std::cout << sa.count() << '\n';

	sa.pop();
	sa.pop();
	//sa.pop();
	//sa.pop();
	//sa.pop();
	//sa.pop();
	std::cout << "Is the stack node empty now? " << '\n';
	std::cout << sa.isEmpty() << '\n';
	std::cout << "Size of stack node now " << '\n';
	std::cout << sa.count() << '\n';

	return 0;
}
