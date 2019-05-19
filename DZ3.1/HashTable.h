#pragma once
template<class T>
class HashTable {
public:
	HashTable();
	~HashTable();
	std::vector<T> table;
	bool Has(T& key) const;
	bool Add(const T& key);
	bool Delete(const T& key);
	unsigned Hash(std::string key, int tableSize);
	void print();
private:

	std::vector<int> tableValue;
	int DefaultSize;
	int GrowFactor;
	unsigned collisionDestroy(unsigned hashNow, int tableSize, int probingNumber);
	int keysCount;
	bool has(unsigned hash, const T& key);
	//int add(const string& key, unsigned hash, int tableSize);
	void growTable();

};
