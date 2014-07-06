#include "CircularQueue.hpp"
#include <iostream>
using namespace std;

typedef CircularQueue::QueueItem QueueItem;  // for simplicity
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
	items_=new QueueItem[16];
	size_=0;
	head_=tail_=0;
	capacity_=16;
	
	for(int i=0;i<capacity_;i++)
		items_[i]=0;
}

CircularQueue::~CircularQueue()
{
	if(head_!=tail_)	
			delete [] items_;
		
	size_=0; head_=tail_=0;
}

bool CircularQueue::empty() const
{   
	if(head_==tail_)
		return true;
	return false;
}

bool CircularQueue::full() const
{
	if((tail_+1)%capacity_==head_)
	//if(size_==capacity_)
		return true;
	return false; 
}

int CircularQueue::size() const
{ 
	return size_;
}

bool CircularQueue::enqueue(QueueItem value)
{
	if(!full())
		{
			items_[tail_]=value;
			tail_=(tail_+1)%capacity_;
			size_+=1;
			
			return true;
		}
	else
		return false;
}

QueueItem CircularQueue::dequeue()
{
		if(!empty())
	{
		QueueItem temp=items_[head_];
		head_=(head_+1)%capacity_;
		size_--;
		return(temp);
	}
	else
		return EMPTY_QUEUE;
		
}

QueueItem CircularQueue::peek() const
{
	if(empty())
		return EMPTY_QUEUE;
	else
		return items_[head_];
}

void CircularQueue::print() const
{
	if(!empty())
		{
			int count=0;
			QueueItem visitor=head_;
			while(visitor!=tail_)
				{
					cout<<" "<<items_[visitor]<<endl;
					visitor=(visitor+1)%capacity_;
					count++;
				}
			cout<<"C="<<count<<endl;
			//cout<<size_<<endl;
		}
	else
		cout<<"EMPTY"; 
}
