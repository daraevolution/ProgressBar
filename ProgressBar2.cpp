#include <iostream>
#include <chrono>   // for expresssing duration
#include <thread>   // for threads

using namespace std;

class ProgressBar
{

public:
	
	/*
	The param speed is for the progress bar run
	more fast or slow.
	The recommended values are: From 0.01 to 0.05
	*/
	void showBar(float speed)
	{
		float progress = 0.0;
		while (progress < 1.0) 
		{
			int barWidth = 70;
			   std::cout << "[";
			   int pos = barWidth * progress;
			   for (int i = 0; i < barWidth; ++i) 
			   {
				   if (i < pos) std::cout << "=";
				   else if (i == pos) std::cout << ">";
				   else std::cout << " ";
			   }
			std::cout << "] " << int(progress * 100.0) << " %\r";
			std::cout.flush();    
			progress += speed; // for demonstration only
			this_thread::sleep_for(chrono::milliseconds(1000));
		}
	}

};
     
int main() 
{
	ProgressBar pb;
	pb.showBar(0.04);
    std::cout << std::endl;    
    return 0;
}
