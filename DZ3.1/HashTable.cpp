#include "pch.h"
#include "HashTable.h"

const int DefaultHashTableSize = 8;
const int MaxAlpha = 3;
const int GlobalGrowFactor = 2;

template<class T>
void HashTable<T>::print() {
	for (int i = 0; i < table.size(); i++) {
		if (tableValue[i] > 0)
			std::cout << i << " = " << tableValue[i] << ":" << table[i] << std::endl;
	}
	//cout << std::endl;
}

template<class T>
HashTable<T>::HashTable() : keysCount(0) {
	GrowFactor = GlobalGrowFactor;
	DefaultSize = DefaultHashTableSize;
	table.resize(DefaultSize);
	tableValue.resize(DefaultHashTableSize, 0);
}

template<class T>
HashTable<T>::~HashTable() {

}

template<class T>
unsigned HashTable<T>::Hash(std::string key, int tableSize) {
	unsigned hash = 0;
	for (int i = 0; i < key.length(); i++)
		hash = (3 * hash + (unsigned)key[i]) % tableSize;
	return hash;
}

template<class T>
unsigned HashTable<T>::collisionDestroy(unsigned hashNow, int tableSize, int probingNumber) {
	//return (hashNow + 1)%tableSize;
	return (hashNow + probingNumber % tableSize) % tableSize;//return (hashNow + (int)pow(probingNumber, 2)) % tableSize;
}

template <class T>
void HashTable<T>::growTable() {
	int newTableSize = table.size() * GrowFactor;
	std::vector<T> newTable(newTableSize);
	std::vector<int> newTableValue(newTableSize, 0);
	for (int i = 0; i < table.size(); i++) {
		if (tableValue[i] > 0) {
			unsigned newHash = Hash(table[i], newTableSize);
			int probingNumber = 0;
			while (newTableValue[newHash] > 0) {
				probingNumber++;
				//newTableValue[newHash] = 1;
				newHash = collisionDestroy(newHash, newTableSize, probingNumber);
			}
			newTable[newHash] = table[i];
			newTableValue[newHash] = 1;
		}
	}
	table = newTable;
	tableValue = newTableValue;
}

template<class T>
bool HashTable<T>::has(unsigned hash, const T & key) {
	int probingNumber = 0;
	while (tableValue[hash] != 0) {
		if (probingNumber > table.size())
			break;
		if (key == table[hash] && tableValue[hash] != -1)
			return true;
		probingNumber++;
		hash = collisionDestroy(hash, table.size(), probingNumber);
	}
	//cout << hash << std::endl;
	return false;
}

/*
template<class T>
int HashTable<T>::add(const string & key, unsigned hash, int tableSize) {
	int probingNumber = 0;
	while (tableValue[hash] != 0 && tableValue[hash] != -1) {
		probingNumber++;
		//tableValue[hash]=1;
		hash = collisionDestroy(hash, tableSize, probingNumber);
	}
	table[hash] = key;
	tableValue[hash]=1;
	keysCount++;
	//cout << probingNumber << std::endl;
	return hash;
}
*/

template<class T>
bool HashTable<T>::Has(T & key) const {
	int hash = Hash(key, table.size());
	return has(hash, key);
}

template<class T>
bool HashTable<T>::Add(const T & key) {
	unsigned hash = Hash(key, table.size());
	if (4 * (keysCount + 1) > 3 * table.size())
		growTable();
	int probingNumber = 0;
	int freePlace = -1;
	while (tableValue[hash] != 0) {
		if (tableValue[hash] == -1 && freePlace == -1)
			freePlace = hash;
		if (key == table[hash] && tableValue[hash] != -1)
			return false;
		if (probingNumber > table.size())
			break;
		probingNumber++;
		hash = collisionDestroy(hash, table.size(), probingNumber);
	}

	if (freePlace != -1) {
		table[freePlace] = key;
		tableValue[freePlace] = 1;
		keysCount++;
		return true;
	}
	table[hash] = key;
	tableValue[hash] = 1;
	keysCount++;
	return true;
}

template<class T>
bool HashTable<T>::Delete(const T & key) {
	unsigned hash = Hash(key, table.size());
	int probingNumber = 0;
	while (tableValue[hash] != 0) {
		if (probingNumber > table.size())
			return false;
		if (key == table[hash] && tableValue[hash] != -1) {
			keysCount--;
			tableValue[hash] = -1;
			return true;
		}
		probingNumber++;
		hash = collisionDestroy(hash, table.size(), probingNumber);
	}
	return false;
}

