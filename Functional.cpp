#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <functional>
using namespace std;

template <typename Collection, typename Algo>
Collection filter(Collection c, Algo a) {
	using func = function<bool(typename Collection::value_type)>;
	Collection res;
	remove_copy_if(begin(c), end(c), back_inserter(res), not1(func(a)));
	return res;
}

template <typename Collection, typename Algo>
Collection map(Collection c, Algo a) {
	using func = function<typename Collection::value_type(typename Collection::value_type)>;
	Collection res;
	transform(begin(c), end(c), back_inserter(res), func(a));
	return res;
}

template <typename Collection, typename Result, typename Algo>
Result reduce(Collection c, Result r, Algo a) {
	return accumulate(begin(c), end(c), r, a);
}


int main() {
	vector<int> vec = { 1,2,3,4,5,6,7 };

	function<bool(int)> is_even = [](int x) {return x % 2 == 0; };
	function<int(int)> add_2 = [](int x) {return x + 2; };
	function<int(int, int)> addition = [](int a, int b) {return a + b; };

	auto res = filter(vec, is_even);
	cout << "Filter Result : " << endl;
	for (auto x : res)
		cout << x << " ";
	cout << endl;
	res = map(vec, add_2);
	cout << "Map Result : " << endl;
	for (auto x : res)
		cout << x << " ";
	cout << endl;
	auto res1 = reduce(vec, 0, addition);
	cout << "Reduction Result : " << res1 << endl;
}
