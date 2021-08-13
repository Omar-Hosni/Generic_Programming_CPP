#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

template <typename T>
T minimum(T a, T b){
return (a < b) ? a:b;
}

template <typename T1, typename T2>
void func(T1 a, T2 b){
cout<<a<<", "<<b<<endl;
}


struct Person{
string name;
int age;

bool operator<(const Person &rhs)const{
return this->age < rhs.age;
}
};

ostream &operator<<(ostream &os, const Person &p){
os<<p.name;
return os;
}

template <typename T>
void my_swap(T &a, T &b){
T temp = a;
a = b;
b = temp;
}

template <typename T>
class Item{
private:
    string name;
    T value;

public:
    Item(string name, T value): name{name}, value{value} {}
    string get_name() const {return name;}
    T get_value() const{return value;}
};

template <typename T1, typename T2>
struct myPair{
T1 first;
T2 second;
};

//class of array - template of array
template <typename T, int N>
class Array{
int size{N};
T values[N];

friend ostream &operator<<(ostream &os, const Array<T,N> &arr){
os<<"[";
for(const auto &val: arr.values){
    os<<val<<" ";
    os<<"]"<<endl;
    return os;
}
}

public:
    Array() = default;
    Array(T init_val){
          for(auto &item: values)
            item = init_val;
          }

    void fill(T val){
    for(auto &item: values){
        item = val;
    }
    }

    int get_size()const{
    return size;
    }

    T &operator[](int index){
    return values[index];
    }

};

int main(){

int x = 100;
int y = 200;

my_swap(x,y);
cout<<"x is equal to: "<<x<<endl;
cout<<"y is equal to: "<<y<<endl;

cout<<"Template Typename"<<endl;
cout<<minimum<int>(5,10)<<endl;
cout<<minimum<char>('a','b')<<endl;
cout<<minimum<double>(12.5, 19.4)<<endl;

cout<<"\n";

cout<<"Template Classes/Structures"<<endl;
Person p1 {"Curly",50};
Person p2 {"Meero",18};

Person p3 = minimum(p1,p2); //we cant do operation on objects unless we create a Template Class
cout<<p3.name<<" is younger"<<endl;

swap(p1,p2);

cout<<"after exchange p1 name is: "<<p1.name<<endl;
cout<<"after exchange p2 name is: "<<p2.name<<endl;


cout<<"\n";

cout<<"Template Function"<<endl;
//you can either mention the data type or not, both are okay
func<int,int>(55,100);
func<double,double>(32.5,99.1);
func<char,double>('A',1.3);

func(1000,"Testing");
func("hello","get lost");
func(99,100);
func('A','33');


//we created an operator overloading for Person structure to print objects as output
func(p1,p2);

cout<<"Template Class"<<endl;
Item<int> item1 ("Frank",100);
cout<<item1.get_name()<<" "<<item1.get_value()<<endl;

Item<string> item2{"Frank","Meero"};
cout<<item2.get_name()<<" "<<item2.get_value()<<endl;

Item <Item<string>> item3 {"Meero",{"C++","Software Engineer"}};
cout<<item3.get_name()<<" "<<item3.get_value().get_name()<<" "<<item3.get_value().get_value()<<endl;

cout<<"\n";

cout<<"vector of item class"<<endl;

vector<Item<double>> vec {};
vec.push_back(Item<double>{"Omar",18.3});
vec.push_back(Item<double>{"Moe",20.4});

myPair<string,int> pr1 {"Frank",100};
myPair<int,double>pr2{123,55.3};

//Array of template
Array<int,5> nums;
cout<<"The size of nums is "<<nums.get_size()<<endl;
cout<<nums<<endl;

nums.fill(0);
cout<<"The size of nums is "<<nums.get_size()<<endl;
cout<<nums<<endl;

nums[0] = 1000;
nums[3] = 4000;
cout<<nums<<endl;

Array<int,100> nums2{2};
cout<<"the size of nums2 is: "<<nums2.get_size()<<endl;
cout<<nums2<<endl;

Array<string,10> strings{string{"Omar"}};
cout<<"The size of strings is "<<strings.get_size()<<endl;
cout<<strings<<endl;

strings[0] = string{"Ahmad"};
cout<<strings<<endl;

strings.fill(string{"X"});
cout<<strings<<endl;
}
