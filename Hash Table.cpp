#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main()
{
    unordered_map<string,int> mymap;

    //inserting element
    pair<string,int> p;
    p.first="abc";
    p.second=3;
    mymap.insert(p);

    mymap["def"]=2;//like array

    //find or access elements just like in array with square brackets;
    cout<<mymap["def"]<<endl;
    cout<<mymap.at("abc")<<endl;

    cout<<"Size="<<mymap.size()<<endl;//return size(key value pairs) in map

    //accessing a element not present
    //cout<<mymap.at("ghi")<<endl; // throws error
    cout<<mymap["ghi"]<<endl;//creates a key with given value and a default value 0 which is returned

    cout<<"Size="<<mymap.size()<<endl;

    //to check whether a key is present or not
    if(mymap.count("ghi")==1)
    {
        cout<<"Element is present"<<endl;
    }
    else
    {
        cout<<"Element is not present"<<endl;
    }

    //updating elements;
    mymap["def"]=200;

    //remove element
    mymap.erase("ghi");
    if(mymap.count("ghi")==1)
    {
        cout<<"Element is present"<<endl;
    }
    else
    {
        cout<<"Element is not present"<<endl;
    }
    cout<<"Size="<<mymap.size()<<endl;

    return 0;
}
