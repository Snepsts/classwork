#include <set>

using std::set;

template<class T>
set<T> Union(const set<T>& A, const set<T>& B){
	set<T> C = A;
	for(auto b : B)
		C.insert(b);
	return C;
}

template<class T>
set<T> operator+(const set<T>& A, const set<T>& B){
	return(Union(A, B));
}

template<class T>
set<T> Intersection(const set<T>& A, const set<T>& B){
	set<T> C;
	for(auto b : B){
		if(A.find(b) != A.end())
			C.insert(b);
	}
	return C;
}

template<class T>
set<T> operator*(const set<T>& A, const set<T>& B){
	return (Intersection(A, B));}

template<class T>
set<T> Minus(const set<T>& A, const set<T>& B){
	set<T> C;
	for(auto a : A){
		if(B.find(a) == B.end())
			C.insert(a);
	}
	return C;
}

template<class T>
set<T> operator-(const set<T>& A, const set<T>& B){
	return (Minus(A, B));
}

template<class T>
set<T> Symdif(const set<T>& A, const set<T>& B){
	set<T> C = Minus(A, B);
	set<T> D = Minus(B, A);
	return (Union(C, D));
}

template<class T>
set<T> operator^(const set<T>& A, const set<T>& B){
	return (Symdif(A, B));
}

template<class T>
bool In(const set<T>& A, const T& item){
	if(A.find(item) == A.end())
		return false;
	else
		return true;
}

template<class T>
bool operator%(const set<T>& A, const T& item){
	return In(A, item);
}

template<class T>
bool Subset(const set<T>& A, const set<T>& B){
	for(auto b : B){
		if(A.find(b) == A.end())
			return false;
	}

	return true;
}

template<class T>
bool ProperSubset(const set<T>& A, const set<T>& B){
	for(auto b : B){
		if(A.find(b) == A.end())
			return false; //if there are any members in B that aren't in A, it's not a subset
	}

	for(auto a : A){
		if(B.find(a) == B.end())
			return true; //if there is at least one member in A that is not in B, it's a proper subset
	}

	return false; //If we reached here they're both the same sets, thus not proper subsets
}
