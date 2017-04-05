#include "./../template.h"

// exemple using pair <int, int>
struct Hash {
	size_t operator()(const ii& param) const {
		int hashing = param.fi ^ (param.se << 32);
		return hash <int>()(hashing);
	}
};

signed main()
{
	// With those two extra lines, unordered_map become about 10
	// times faster. You can replace 32768 with another suitable
	// power of two, it dependes on number of inserts you will do.
	unordered_map <ii, int, Hash> my_unordered_map;
	my_unordered_map.reserve(32768);
	my_unordered_map.max_load_factor(0.25);

	return 0;
}
