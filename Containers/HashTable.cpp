#include <iostream>
#include <vector>

// marsenne twister hash
int mHash(int value, int prime = 15485867, int a = 4321, int b = 1234){
	long long lPrime = (long long) prime;
	long long lA = (long long) a;
	long long lB = (long long) b;

	long long hash = lA * lPrime + lB;
	return hash%prime;
}
	

class HashTable{
private:
	// a percentage of size of the table for the maximum size (defined below)
	float threshold;
	
	// maximum number of elements in table before calling resize()
	int maxSize;

	// total number of elements in the hashTable
	int size;
	vector<LinkedHashEntry *> table;

	// resizes the HashTable when it is too full
	void resize();

public:
	const int DEFAULT_HASHTABLE_SIZE = 128;
	const int DEFAULT_HASHTABLE_MAXSIZE = 96;
	const float DEFAULT_HASHTABLE_THRESHOLD = 0.75f;


	// default constructor with no arguments
	HashTable(): threshold(DEFAULT_HASHTABLE_THRESHOLD), \
	  maxSize(DEFAULT_MAXSIZE), tableSize(DEFAULT_HASHTABLE_SIZE), size(0), \
	  table(new vector<LinkedHashEntry*>(tableSize,nullptr){}
	
	// set threshold percentage for maximum number of elements
	void setThreshold(float threshold);
	
	// is value in the HashTable?
	int count(int value);
	
	// insert value into HashTable
	bool insert(int value);
	
	// remove value from HashTable
	bool remove(int value);
	
	// destructor
	~HashTable();

}

// set a new threshold percentage for maximum number of elements
void HashTable::setThreshold(float threshold){
	// bounds checks
	if (threshold<0 || threshold >1) throw -1;
	this->threshold = threshold;
	maxSize = (int) (tableSize * threshold);
}

// resizes HashTable to a table double the previous size
void HashTable::resize(){
	// double the size of the table and calculate the new threshold
	int oldTableSize = table.size();
	maxSize = (int) ((oldTableSize * 2) * threshold);

	// make a copy of the existing table
	vector<LinkedHashEntry*> oldTable = table;

	// reset existing table to a blank table and reset the number of elements
	table = new vector<LinkedHashEntry*>(oldTableSize*2,nullptr);
	size = 0;

	// reinsert all the values in the copy into the new table
	for (int hash = 0; hash < oldTableSize; hash++){
		if (oldTable[hash]){
			LinkedHashEntry* entry = oldTable[hash];
			// while the entry exists, insert it into the new table and move on
			while (entry){
				insert(entry->val);
				entry = entry->next;
			}
		}
	}
	return;
}

// returns 0 if value is not in hash table, otherwise returns 1
int HashTable::count(int value){
	// compute the hash
	int hash = (mHash(value)%tableSize);
	// if bucket is empty, value is not found
	if (!table[hash]) return 0;
	// otherwise crawl through the bucket to see if the entry is there
	else{
		LinkedHash* entry = table[hash];
		while (entry && entry->val!=value) entry = entry->next;
		if (!entry) return 0;
		else return 1;
	}	
}


// inserts value into hash table; returns false if value was already in table
bool HashTable::insert(int value){
	// compute hash
	int hash = (mHash(value)%tableSize);
	// if the bucket does not exist, create a new LinkedHash
	if (!table[hash]){
		table[hash] = new LinkedHash(value);
		// increment number of elements
		size++;
	} 
	// otherwise, crawl through the bucket
	else{
		LinkedHash* entry = table[hash];
		while(entry->next){
			// if we found an already existing value, return false
			if (entry->val = value) return false;
			entry = entry->next;
		}
		if (entry->val = value) return false;
		// otherwise, create a LinkedHash and insert it at the end
		else{
			entry->next = new LinkedHash(value);
			// increment number of elements
			size++;
		}
	}
	// if the size exceeds the maximum size, resize
	if (size >= maxSize) resize();
	return true;
}

// removes a value from hash table; returns false if value was not found
bool HashTable::remove(int value){
	// compute hash
	int hash = (mHash(key)%tableSize);

	if (table[hash]){
		// make 2 pointers to nodes to hold 2 consecutive nodes while crawling
		LinkedHash* prev = nullptr;
		LinkedHash* entry = table[hash];
		// crawl along the chain until we find the entry or reach the end
		while (entry->next && entry->val != value){
			prev = entry;
			entry = entry->next;
		}
		if (entry->val = value){
			// if the entry was the first entry in the bucket, delete it and
			// make its successor the first entry in the bucket
			if (!prev){
				LinkedHash* next = entry->next;
				delete entry;
				table[hash] = next;
			}
			// if the entry is in the middle, delete it and join the chain
			else{
				LinkedHash* next = entry->next;
				delete entry;
				prev->next = next;
			}
			// decrement number of elements
			size--;
			return true;
		}
		else return false;
	}
	else return false;
}

HashMap::~HashMap(){}
