#pragma once
#include <iostream>
#include <assert.h>
using namespace std;
namespace Algo {
	template<class T>
	class Stack
	{

	public:
		
		void push(T* E) {
			Node* newNode = new Node();
			assert(newNode != 0);//débug
			//tru catch mode release 
			newNode->data = E;
			newNode->next = this->head;
			this->head = newNode;
		}
		void pop() {
			assert(!this->empty());
			Node* supp = this->head;
			this->head = this->head->next;
			delete supp;
			supp = 0;
		}
		bool empty() const {
			bool res = (this->head == 0);
			return res;
		}
		T* top() const {
			assert(!this->empty());
			return this->head->data;
		}
		static Stack* creator() {
			Stack* S = new Stack();
			assert(S);
			return S;
		}
		static void garbage(Stack* S) {
			if (S)
				delete S;
		}
	private:
		class Node* head;
		Stack() {
			this->head = 0;
		}
		~Stack() {
			while (this->head)
			{
				this->pop();
			}
			delete this->head;
			this->head = 0;
		}
		
	};
};
namespace Algo {
	template<class T>
	class Node
	{
	private:
		T* data;
		Node* next;
	public:
		
		/*T* getData()const {
			return this->data;
		}
		void setData(T* s) {
			this->data = s;
		}*/
	};
};
