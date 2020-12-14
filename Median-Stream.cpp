https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/2nd/submissions/

/*Idea of Median - arrange elements in increasing order and find mid element(odd number of elements) or find avg of two mid(even number of elements). 

example -    1 2 3 4 5 6  median = (3+4)/2    ||      1 2 3 4 5   median = 5  

i.e. we care for the mid elements of the array and to find them we use min heap and max heap. Aim of algorithm is to use maxheap and minheap to store elements and instead of storing all elements in both heaps we will store one half in maxheap and another half in minheap.
*/
 

#include<bits/stdc++.h>

using namespace std;

#define si(x) scanf("%d",&x)

 

priority_queue<int> maxheap;

priority_queue<int,vector<int>,greater<int> > minheap;

 

int main()

{

 int n,num,med;

 si(n);

 for(int i=1;i<=n;i++)

 {

   si(num);

   if(i == 1)

   {

     med = num;

     maxheap.push(num);

     printf("%d\n",med);

   }

   else

   {

     if(maxheap.size() == minheap.size())

     {

       if(num < med)

       {

         maxheap.push(num);

         med = maxheap.top();

       }

       else

       {

         minheap.push(num);

         med = minheap.top();

       }

     }

     else if(maxheap.size() > minheap.size())

     {

       if(num < med)

       {

         minheap.push(maxheap.top());

         maxheap.pop();

         maxheap.push(num);

       }

       else

         minheap.push(num);

       med = ( maxheap.top() + minheap.top() )/ 2;

     }

     else if(maxheap.size() < minheap.size())

     {

       if(num > med)

       {

         maxheap.push(minheap.top());

         minheap.pop();

         minheap.push(num);

       }

       else

         maxheap.push(num);

       med = ( maxheap.top() + minheap.top() )/ 2;

     }

     printf("%d\n",med);

   }

 }

 return 0;

}
