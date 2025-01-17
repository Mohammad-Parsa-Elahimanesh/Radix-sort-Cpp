/// In the name of Allah the most beneficent the most merciful
#include <bits/stdc++.h>
using namespace std;

template<const bool negative = true, const int BITS = 9, typename _Iterator>
inline void radix_sort(_Iterator _first, _Iterator _last, const bool reverse = false) {
	typedef typename iterator_traits<_Iterator>::value_type value_type;
	if(negative) {
		if(!reverse) {
			_Iterator _middle = partition(_first, _last, [](value_type a) -> bool {return a<0;});	
			for(auto it = _first; it != _middle; it++)*it *= -1;
			radix_sort<false>(_first, _middle, true);
			for(auto it = _first; it != _middle; it++)*it *= -1;
			radix_sort<false>(_middle, _last);
		} else {
			_Iterator _middle = partition(_first, _last, [](value_type a) -> bool {return a>=0;});	
			radix_sort<false>(_first, _middle, true);
			for(auto it = _middle; it != _last; it++)*it *= -1;
			radix_sort<false>(_middle, _last);
			for(auto it = _middle; it != _last; it++)*it *= -1;
		}
		return;
	}
	constexpr int PART = (1<<BITS);
	constexpr int FULL = (1<<BITS)-1;
	int shift = 0;
	auto MAX = *max_element(_first, _last);
	vector<value_type> P[PART];
	while(log2(MAX) >= shift) {
		for(auto it = _first; it != _last; it++)P[(((*it)>>shift)&FULL)^(reverse?FULL:0)].push_back(*it);
		auto it = _first;
		for(int i = 0; i < PART; i++) {
			for(auto u: P[i]) *it++ = u;
			P[i].clear();
		}
		shift += BITS;
	}
}
