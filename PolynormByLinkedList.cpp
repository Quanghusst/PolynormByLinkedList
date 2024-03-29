#include <iostream>
#include "LinkedList.h"
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
        for (int i = 0; i < size; i++)
        {
            out << h.heso[i];
            if(i == 1) out << "x";
            else if(i != 0 ) out << "x^" << i;
            if(i == size - 1) return out;
            else out << " + ";
        }
        return out;
    }
    friend Polynorm operator +( Polynorm &a,  Polynorm &b){
        Polynorm sum;
        int size;
        a.heso.size() > b.heso.size() ? size = a.heso.size() : size = b.heso.size();
        for (int i = 0; i < size; i++)
        {
            double coefA = (i < a.heso.size()) ? a.heso[i] : 0;
            double coefB = (i < b.heso.size()) ? b.heso[i] : 0;
            sum.heso.pushBack(coefA + coefB);
        }
        return sum;
    }
};
int main () 
{
    Polynorm da_thuc_1({1.1, 1.1, 1.1});
    Polynorm da_thuc_2 = da_thuc_1 + da_thuc_1;
    cout << da_thuc_2;
    return 0;

}