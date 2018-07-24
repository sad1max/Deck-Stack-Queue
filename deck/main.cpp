#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct eldeck{
    int val;
    eldeck *next, *prev;
};

class deck{
public:
    eldeck *left;
    eldeck *right;
    int cnt;
    deck(){
        left = NULL;
        right = NULL;
        cnt = 0;
    };
    void d_push_front(int val){
        if(cnt == 0){
            eldeck *tmp = new eldeck;
            tmp->prev = NULL;
            tmp->next = NULL;
            tmp->val = val;
            left = right = tmp;
            cnt++;
        }else{
            eldeck *tmp = new eldeck;
            tmp->prev = NULL;
            tmp->next = left;
            tmp->val = val;
            left->prev = tmp;
            left = tmp;
            cnt++;
        }
        cout << "ok" << endl;
    }
    void d_push_back(int val){
        if(cnt == 0){
            eldeck *tmp = new eldeck;
            tmp->prev = NULL;
            tmp->next = NULL;
            tmp->val = val;
            left = right = tmp;
            cnt++;
        }else{
            eldeck *tmp = new eldeck;
            tmp->prev = right;
            tmp->next = NULL;
            tmp->val = val;
            right->next = tmp;
            right = tmp;
            cnt++;
        }
        cout << "ok" << endl;
    }
    void d_pop_front(){
        cout << left->val << endl;;
        if(cnt == 1){
            delete left;
            left = right = NULL;
            cnt--;
        }else if(cnt == 2){
            delete left;
            right->prev = NULL;
            left = right;
            cnt--;
        }else{
            eldeck *tmp = left->next;
            delete left;
            tmp->prev = NULL;
            left = tmp;
            cnt--;
        }
    }
    void d_pop_back(){
        cout << right->val << endl;
        if(cnt == 1){
            delete right;
            right = left = NULL;
            cnt--;
        }else if(cnt == 2){
            delete right;
            left->next = NULL;
            right = left;
            cnt--;
        }else{
            eldeck *tmp = right->prev;
            delete right;
            right = tmp;
            tmp->next = NULL;
            cnt--;
        }
    }
    void d_front(){
        cout << left->val << endl;
    }
    void d_back(){
        cout << right->val << endl;
    }
    void d_size(){
        cout << cnt << endl;
    }
    void d_clear(){
        cnt = 0;
        left = NULL;
        right = NULL;
        cout << "ok" << endl;
    }
};

int main(){
    string s = "0";
    int val;
    deck A;
    while(s != "exit"){
        cin >> s;
        if(s == "push_front"){
            cin >> val;
            A.d_push_front(val);
        }
        if(s == "push_back"){
            cin >> val;
            A.d_push_back(val);
        }
        if(s == "pop_front")
            A.d_pop_front();
        if(s == "pop_back")
            A.d_pop_back();
        if(s == "front")
            A.d_front();
        if(s == "back")
            A.d_back();
        if(s == "size")
            A.d_size();
        if(s == "clear")
            A.d_clear();
    }
    cout << "bye" << endl;
}
