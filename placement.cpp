#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>
#include <bits/stdc++.h>

using namespace std;
int main()

{
    string str;
    vector<string>msg;
    ifstream file("CP.txt");
    while(getline(file,str,' '))
    {
        msg.push_back(str);
    }
    sort(msg.begin(),msg.end());
    file.close();

    ofstream fout("output.txt");
    for(int i=0;i<msg.size();i++)

        fout<<msg[i]<< " "<<endl;

  string word;
  cout<<"Enter which word you wanna count : ";
  getline(cin,word);
   int freq;
     freq=count(msg.begin(),msg.end(),word);
 cout<<"The word "<<word<<" occurs "<<freq<<" times" ;


//        string readFile1( string "output.txt" );                                            // @JLBorges : direct from stream buffer
//{
//   ifstream file( "output.txt");
//   return {
//        istreambuf_iterator<char>(file),
//         {
//         }
//         };

//word=string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
//for(int i=0;i<msg.size();i++
//{
//
//    freq=count(msg.begin(),msg.end(),word)
//}
cout<<endl;
cout<<"Enter word  :";
string text;
getline(cin,text);

if(count(msg.begin(),msg.end(),text)>0)
cout<<"Word present ";


//}
return 0;
}








