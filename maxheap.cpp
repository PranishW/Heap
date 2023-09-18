// Max Heap Data structure
#include<bits/stdc++.h>
using namespace std;
class Heap
{
	vector<int> arr;
	public:
		Heap();
		void insert(int);
		void display();
		void del();
};
Heap::Heap()
{
	arr.push_back(-1);
}
void Heap::insert(int val)
{
	arr.push_back(val);
	int i = arr.size()-1;
	while(i>1)
	{
		int parent = i/2;
		if(arr[parent]<arr[i])
		{
			swap(arr[parent],arr[i]);
			i = parent;
		}
		else
			return;
	}
}
void Heap::display()
{
	for(int i=1;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
void Heap::del()
{
	if(arr.size()==1)
	{
		cout<<"Nothing to delete"<<endl;
		return;
	}
	arr[1] = arr[arr.size()-1];
	arr.pop_back();
	int i=1;
	while(i<arr.size())
	{
		int left = 2*i,right=2*i+1;
		if(left<arr.size() and arr[left]>arr[i])
		{
			swap(arr[left],arr[i]);
			i = left;
		}
		else if(right<arr.size() and arr[right]>arr[i])
		{
			swap(arr[right],arr[i]);
			i = right;
		}
		else
			return;
	}
}
void heapify(int arr[],int n,int i) // function to build array into heap
{
	int top = i;
	int left = 2*i,right = 2*i+1;
	if(left<=n and arr[top]<arr[left])
		top = left;
	if(right<=n and arr[top]<arr[right])
		top = right;
	if(top!=i)
	{
		swap(arr[top],arr[i]);
		heapify(arr,n,top);
	}	
}
void heapsort(int arr[],int n)
{
	int t=n;
	while(t>1)
	{
		// step1 : swap(firstnode,lastnode)
		swap(arr[1],arr[t]);
		t--;
		// bring firstnode to its right position in heap
		heapify(arr,t,1);
	}
}
int main()
{
	Heap hp;
	hp.insert(50);
	hp.insert(55);
	hp.insert(53);
	hp.insert(52);
	hp.insert(54);
	hp.display();
	hp.del();
	hp.display();
	int array[6] = {-1,70,60,55,45,50};
	int n = 5;
	for(int i=1;i<=n;i++)
		cout<<array[i]<<" ";
	cout<<endl;
	for(int i=n/2;i>0;i--)
		heapify(array,n,i);
	for(int i=1;i<=n;i++)
		cout<<array[i]<<" ";
	cout<<endl;
	cout<<"sorting heap using heap sort :-"<<endl;
	heapsort(array,n);
	for(int i=1;i<=n;i++)
		cout<<array[i]<<" ";
	cout<<endl;
	// Priority Queue to implement min and max heap (default max heap)
	priority_queue<int> pq;   // maxheap
	cout<<"is max heap empty? "<<pq.empty()<<endl;
	pq.push(1);
	pq.push(5);
	pq.push(3);
	pq.push(11);
	pq.push(2);
	cout<<pq.top()<<" "<<pq.size()<<endl;
	pq.pop();
	cout<<pq.top()<<" "<<pq.size()<<endl;
	return 0;
}
