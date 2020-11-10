#include<iostream>
#include<set>
#include<cstdlib>
#include <ctime>
#include<iterator>
#include<unordered_set>
#include<fstream>
#include<iomanip>
using std::cout; using std::cin; using std::endl;using std::fixed;
int main()
{
    std::ofstream oss("data_set.txt");
    
    std::multiset<int> ordered_set;
    std::unordered_multiset<int> unordered_set;
    double time=0.0;
    int n=10;
    int delay;
    while(time<3.0)
    {
        if(n<=10000)
        {
            delay=10000;
        }
        else
        {
            delay=1;
        }
        oss<<n<<" ";
        std::clock_t start=std::clock();
        for(int d=0;d<delay;d++)
        {
            for(int i=0;i<n;i++)
            {
                int item=std::rand()%100;
                ordered_set.insert(item);
            }
            ordered_set.clear();
        }
        std::clock_t tot_time=std::clock()-start;
        double result=((double) tot_time) / (double) CLOCKS_PER_SEC;
        double seconds=result/(double)delay;

        std::clock_t start2=std::clock();
        for(int d=0;d<delay;d++)
        {
            for(int i=0;i<n;i++)
            {
                int item=std::rand()%100;
                unordered_set.insert(item);
            }
             unordered_set.clear();
        }
        std::clock_t tot_time2=std::clock()-start2;
        double result2=((double) tot_time2) / (double) CLOCKS_PER_SEC;
        double seconds2=result2/(double)delay;

        oss<<fixed<<seconds<<" "<<seconds2<<endl;

        
       
        time=std::max(seconds,seconds2);
        n=n*10;

    }
}
