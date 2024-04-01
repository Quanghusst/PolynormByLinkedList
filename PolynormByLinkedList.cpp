#include <iostream>
#include "D:\0.C++\ThuVienTaoSan\LinkedList.h"
using namespace std;
class Polynorm{
    LinkedList<double> heso;
public:
    Polynorm(){} // constructor mặc định
    Polynorm(const LinkedList<double> &heso): heso(heso){}
    ~Polynorm(){heso.clear();}
    // kiểu hệ số 0 thì ứng với bậc 0, hệ số 1 tương ứng với bậc 1
    friend ostream &operator << (ostream &out,const Polynorm &h){
        const int size = h.heso.size();
        Node<double> * current = h.heso.getHead();
        int i = 0;
        while (current != nullptr)
        {
            out << current->info;
            if(i == 1) out << 'x';
            else if(i != 0 ) out << "x^" << i;
            if(i == size - 1) return out;
            else out << " + ";
            current = current->next;
            i++;
        }
        return out;
    }
    friend Polynorm operator +(const Polynorm &a, const Polynorm &b){
        Polynorm sum;
        Node<double> * current = nullptr;
        Node<double> * currentA =  a.heso.getHead();
        Node<double> * currentB =  b.heso.getHead();
        a.heso.size() > b.heso.size() ? current = currentA : current = currentB;
        int i = 0;
        while (current != nullptr)
        {
            double coefA = (i < a.heso.size()) ? currentA->info : 0;
            double coefB = (i < b.heso.size()) ? currentB->info : 0;
            sum.heso.pushBack(coefA + coefB);
            current = current->next;
            currentA = currentA->next;
            currentB = currentB->next;
            i++;
        }
        return sum;
    }
};
int main () 
{
    Polynorm da_thuc_1({4, 5, 6});
    Polynorm da_thuc_3({1, 2, 3});
    Polynorm da_thuc_2 = da_thuc_1 + da_thuc_3;
    cout << da_thuc_1 << endl;
    cout << da_thuc_3 << endl;
    cout << da_thuc_2 << endl;
    return 0;

}