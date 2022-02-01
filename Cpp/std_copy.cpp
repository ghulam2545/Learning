#include <iostream>
#include <iterator>
#include <string>
#include <vector>

namespace Copy {

    /**
     * This example shows how to use the copy() algorithm to copy the
     * contents of one built-in array/container to another.
     *
     * @param InputItr begin iterator of original conatiner
     * @param OutputItr end iterator of original conatiner
     * @return end iterator of resulting container
     *
     */
    template <typename InputItr, typename OutputItr>
    OutputItr copy(InputItr _begin, InputItr _end, OutputItr d_begin) {
        while (_begin != _end) {
            *d_begin = *_begin;  // assigning in destination container
            ++d_begin;
            ++_begin;
        }
        return d_begin;
    }

}  // namespace Copy

using std::cout;

int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    int len = 6;
    int ans[len];

    Copy::copy(a, a + 6, ans);

    for (auto& e : ans) {
        cout << e << " ";
    }
    cout << "\n";

    std::vector<std::string> aa = {"abc", "def", "ghi"};

    // size of resulting container should be known
    std::vector<std::string> _ans(3);

    Copy::copy(aa.begin(), aa.end(), _ans.begin());

    for (auto& e : _ans) {
        cout << e << " ";
    }

    return 0;
}