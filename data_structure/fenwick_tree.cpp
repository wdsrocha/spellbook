#include "../template.h"

template <typename T>
class FenwickTree {
private:
	int n;
	vector <T> tree;
public:
	FenwickTree(const vector <T>& a) {
		this->n = (int)a.size();
		this->tree = vector <T>(n);
		for (int i = 1; i <= this->n; i++)
			this->update(i, a[i]);
	}

	void update(int i, T x) {
		while (i <= this->n) {
			this->tree[i] += x;
			i += (i & (-i));
		}
	}

	T query(int i) {
		T sum = 0;
		while (i > 0) {
			sum += this->tree[i];
			i -= (i & (-i));
		}
		return sum;
	}
};
