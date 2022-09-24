#include <iostream>
#include <string>
#include <map>
using namespace std;
// ���ƣ�����

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
    cout<<" ��ӭ������Ʒ����ϵͳ!"<<endl;
    cout<<" �����Ʒ������1\n ȡ����Ʒ������2\n ��ʾ��Ʒ�б�������3\n ������Ʒ����Ϣ������4\n �˳�ϵͳ������0\n";
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
        cout<<" �����Ʒ������1\n ȡ����Ʒ������2\n ��ʾ��Ʒ�б�������3\n ������Ʒ����Ϣ������4\n �˳�ϵͳ������0\n";
        cout<<"------------------------------------"<<endl;
    }

    return 0;
}

void Add(map<string,Item> &shelf){
    string name;
    int count;
    cout<<"��������Ʒ����"<<endl;
    cin>>name;
    cout<<"��������Ʒ����"<<endl;
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
    cout<<"��������Ʒ����"<<endl;
    cin>>name;
    cout<<"��������Ʒ����"<<endl;
    cin>>count;
    if(shelf.count(name)==0) {
        cout<<"������Ҫ����Ʒ������"<<endl;
    }else{
        auto itr=shelf.find(name);
        if(itr->second.count>=count){
            (itr->second.count)-=count;
            cout<<"ȡ�óɹ�"<<endl;
            if(itr->second.count==count){
                shelf.erase(itr);
            }
        }else{
            cout<<"�������㣬ȡ��ʧ��"<<endl;
        }
    }
    return;
}

void ShowItemList(map<string,Item> &shelf){
    cout<<"---������Ʒ�б�---"<<endl;
    cout<<"����\t����"<<endl;
    auto itr=shelf.begin();
    for(;itr!=shelf.end();itr++){
        cout<<itr->first<<'\t'<<itr->second.count<<endl;
    }

    return;
}

void SearchItemInfo(map<string,Item> &shelf){
    string name;
    cout<<"��������Ʒ����"<<endl;
    cin>>name;
    if(shelf.count(name)==0) {
        cout<<"������Ҫ����Ʒ������"<<endl;
    }else{
        auto itr=shelf.find(name);
        cout<<"�����ҵ���Ʒ����Ϊ��"<<name<<" ������Ϊ��"<<itr->second.count<<"��"<<endl;
    }
    return;
}