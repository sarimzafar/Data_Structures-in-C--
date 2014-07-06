#include "DynamicStack.hpp"
#include <iostream>

using namespace std;

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
	items_=new StackItem[16];
	size_=0;capacity_=16;init_capacity_=capacity_;
	
}

DynamicStack::DynamicStack(unsigned int capacity)
{
	if(capacity==0)
		DynamicStack();
	else
		{
			items_=new StackItem[capacity];
			init_capacity_=capacity_=capacity;
			size_=0;
		}	
}

DynamicStack::~DynamicStack()
{
	if(!empty())
		delete [] items_;
		
}

bool DynamicStack::empty() const
{
	return(size_==0);
}

int DynamicStack::size() const
{
	return(size_);
}

void DynamicStack::push(StackItem value)
{
	if(size_==capacity_)
		{
			StackItem* newItems=new StackItem[2*capacity_];			
			//DynamicStack(2*capacity_);
			
			for(int i=0;i<capacity_;i++)
				{
					newItems[i]=items_[i];
				}
			delete [] items_;
			items_=newItems;
			capacity_*=2;
		}
		items_[size_]=value;size_++;	
}

StackItem DynamicStack::pop()
{
	if(empty())
		return EMPTY_STACK;
	else
		{
			StackItem temp=items_[size_-1];
			size_--;
			if(size_<=capacity_/4 && capacity_/2>=init_capacity_)
				{
					StackItem* newItems_=new StackItem[capacity_/2];
					//DynamicStack(capacity/2);
					for(int i=0;i<capacity_;i++)
						newItems_[i]=items_[i];
					delete [] items_;
					items_=newItems_;
					capacity_/=2;
				}
		return temp;
		}
}

StackItem DynamicStack::peek() const
{
	if(!empty())
		return (items_[size_-1]);
	else
		return EMPTY_STACK;
}

void DynamicStack::print() const
{
	if(!empty())
	{
		for(int i=0;i<size_;i++)
		cout<<items_[i];
	}
	else
		cout<<"EMPTY"<<endl;
}
