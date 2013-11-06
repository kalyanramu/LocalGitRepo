#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	ifstream infile;
	infile.open("C:/Users/kvemishe/Downloads/Test.txt");
	string line;
	getline(infile,line);
	std::stringstream linestream(line);

	int Vertex, num;
	std::string str1,str2;
	int iter=0;
	std::string sub;
	do
	{
		linestream >> sub;
		if (iter++ ==0)
		{
			Vertex = std::stoi(sub);
			cout << Vertex << "--";
		}
		else
		{
			std::stringstream s1(sub);
			s1 >> num;
			cout << num << ",";
			s1.ignore(); //Ignore ","
			s1>> num;
			cout << num;
		}
	} while(linestream);
	cout << endl;
	infile.close();
	return 0;
}