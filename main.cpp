#include <iostream>
#include <string>
#include <map>
using namespace std;
// 名称，数量

class Item{
public:
    string name;
    int count=0;

    Item(){}
    Item(string n,int c){
        name=n;
        count=c;
    }
    ~Item(){}
};

void Add(map<string,Item> &shelf);
void Delete(map<string,Item> &shelf);
void ShowItemList(map<string,Item> &shelf);
void SearchItemInfo(map<string,Item> &shelf);

int main() {
    map<string,Item> shelf;
    cout<<" 欢迎来到物品交换系统!"<<endl;
    cout<<" 添加物品请输入1\n 取用物品请输入2\n 显示物品列表请输入3\n 查找物品的信息请输入4\n 退出系统请输入0\n";
    cout<<"-----------------------------------------"<<endl;
    string input;
    while (cin>>input){
        if(input=="1"){
            Add(shelf);
        }
        if(input=="2"){
            Delete(shelf);
        }
        if(input=="3"){
            ShowItemList(shelf);
        }
        if(input=="4"){
            SearchItemInfo(shelf);
        }
        if(input=="0"){
            return 0;
        }
        cout<<"------------------------------------"<<endl;
        cout<<" 添加物品请输入1\n 取用物品请输入2\n 显示物品列表请输入3\n 查找物品的信息请输入4\n 退出系统请输入0\n";
        cout<<"------------------------------------"<<endl;
    }

    return 0;
}

void Add(map<string,Item> &shelf){
    string name;
    int count;
    cout<<"请输入物品名称"<<endl;
    cin>>name;
    cout<<"请输入物品数量"<<endl;
    cin>>count;
    if(shelf.count(name)==0) {
        Item item(name, count);

        shelf.emplace(name, item);
    }else{
        auto itr=shelf.find(name);
        (itr->second.count)+=count;
    }
    return;
}

void Delete(map<string,Item> &shelf){
    string name;
    int count;
    cout<<"请输入物品名称"<<endl;
    cin>>name;
    cout<<"请输入物品数量"<<endl;
    cin>>count;
    if(shelf.count(name)==0) {
        cout<<"您所需要的物品不存在"<<endl;
    }else{
        auto itr=shelf.find(name);
        if(itr->second.count>=count){
            (itr->second.count)-=count;
            cout<<"取用成功"<<endl;
            if(itr->second.count==count){
                shelf.erase(itr);
            }
        }else{
            cout<<"数量不足，取用失败"<<endl;
        }
    }
    return;
}

void ShowItemList(map<string,Item> &shelf){
    cout<<"---现有物品列表---"<<endl;
    cout<<"名称\t数量"<<endl;
    auto itr=shelf.begin();
    for(;itr!=shelf.end();itr++){
        cout<<itr->first<<'\t'<<itr->second.count<<endl;
    }

    return;
}

void SearchItemInfo(map<string,Item> &shelf){
    string name;
    cout<<"请输入物品名称"<<endl;
    cin>>name;
    if(shelf.count(name)==0) {
        cout<<"您所需要的物品不存在"<<endl;
    }else{
        auto itr=shelf.find(name);
        cout<<"您查找的物品名称为："<<name<<" ，数量为："<<itr->second.count<<"个"<<endl;
    }
    return;
}