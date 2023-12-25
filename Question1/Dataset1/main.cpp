#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>v1 = {1,1,9,1,3,0,2,7,9,4};
   long long int n;
   cout << "Enter size: " << endl;
   cin >> n;
   ofstream outputFile;
   string fileName = "../../Dataset/DataSet1/Dataset-" + to_string(n) + ".csv";
   outputFile.open(fileName, ios::app); 
   if (!outputFile.is_open()) 
   {
        cerr << "Error opening file!" << endl;
        return 1;
    }
   for (auto i = 0; i < n; i++)
   {
    v1 = {1,1,9,1,3,0,2,7,9,4};
    random_device rd,rnd;
    mt19937 give(rd());
    uniform_int_distribution<int>gen(1,10);
    shuffle(v1.begin(),v1.end(),give);
    v1.resize(gen(rnd));
    for (auto& i : v1)
    {
        outputFile << i;
    }
    outputFile << "," << endl;
}
    outputFile.close();
    return 0;
}