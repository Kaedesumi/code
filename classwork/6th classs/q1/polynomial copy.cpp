#include <vector>
#include <iostream>
using namespace std;

struct Item{  
    int exp;  // 指数 
    int coef; // 系数 
};

// TODO: 实现 input
void input(vector<Item>& f) {
    int exp, coef;

    while (cin >> exp >> coef) {
        if (exp < 0) {
            break;
        }

        f.push_back({exp, coef});
    }
}

// TODO: 实现 output

void output(const vector<Item>& f) {
    if (f.empty()) {
        cout << 0 << endl;
        return;
    }

    bool first = true;

    for (const auto& item : f) {
        if (!first && item.coef > 0) {
            cout << "+";
        }

        if (item.exp == 0) {
            cout << item.coef;
        } else {
            if (item.coef == 1) {
                cout << "x^" << item.exp;
            } else if (item.coef == -1) {
                cout << "-x^" << item.exp;
            } else {
                cout << item.coef << "x^" << item.exp;
            }
        }

        first = false;
    }

    cout << endl;
}

// TODO: 实现 add

void add(const vector<Item>& f1,
         const vector<Item>& f2,
         vector<Item>& f3) {

    int i = 0;
    int j = 0;

    while (i < f1.size() && j < f2.size()) {

        if (f1[i].exp > f2[j].exp) {
            f3.push_back(f1[i]);
            i++;
        }
        else if (f1[i].exp < f2[j].exp) {
            f3.push_back(f2[j]);
            j++;
        }
        else {
            int sum = f1[i].coef + f2[j].coef;

            if (sum != 0) {
                f3.push_back({f1[i].exp, sum});
            }

            i++;
            j++;
        }
    }

    while (i < f1.size()) {
        f3.push_back(f1[i]);
        i++;
    }

    while (j < f2.size()) {
        f3.push_back(f2[j]);
        j++;
    }
}

// TODO: 实现 multiply

void multiply(const vector<Item>& f1,
              const vector<Item>& f2,
              vector<Item>& f4) {

    vector<Item> temp;

    for (const auto& a : f1) {
        for (const auto& b : f2) {
            temp.push_back({
                a.exp + b.exp,
                a.coef * b.coef
            });
        }
    }

    for (int i = 0; i < temp.size(); i++) {
        for (int j = i + 1; j < temp.size(); j++) {
            if (temp[i].exp < temp[j].exp) {
                swap(temp[i], temp[j]);
            }
        }
    }

    for (const auto& item : temp) {
        if (!f4.empty() && f4.back().exp == item.exp) {
            f4.back().coef += item.coef;

            if (f4.back().coef == 0) {
                f4.pop_back();
            }
        } else {
            if (item.coef != 0) {
                f4.push_back(item);
            }
        }
    }
}

int main() {
    vector <Item> f1,f2,f3,f4; // 4 个多项式 
    input(f1);  // 建立多项式 f1：按多项式的每一项，分别输入指数和系数，指数为负数结束  
    input(f2); 
    add(f1,f2,f3);  // 实现：f3=f1+f2  
    multiply(f1,f2,f4);   // 实现：f4=f1*f2 
    output(f3);  // 显示多项式 f3，如：2x^4+2x^3+4x^2+3x+10 
    output(f4);
}