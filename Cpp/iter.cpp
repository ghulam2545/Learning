#include <iostream>
using namespace std;

namespace gh {
    // helper
    template <class T>
    struct node {
        T m_value;
        node<T>* m_next;
    };

    template <class T>
    T* copy(const T* in, const T* in_end, T* out, T* out_end) {
        while (in != in_end && out != out_end) {
            *in++ = *out++;
        }

        return out;
    }

    template <class T>
    node<T>* copy(const node<T>* in, const node<T>* in_end, node<T>* out, node<T>* out_end) {
        while (in != in_end && out != out_end) {
            in->m_value = out->m_value;
            in = in->m_next;
            out = out->m_next;
        }

        return out;
    }

    template <class T>
    ostream& copy(const T* in, const T* in_end, ostream& out) {
        while (in != in_end && out) {
            out << *in++;
        }

        return out;
    }

    template <class InIter, class OutIter>
    OutIter copy(const InIter& in, const InIter& in_end, OutIter& out, OutIter& out_end) {
        //
        return out;
    }
}

int main() { return 0; }