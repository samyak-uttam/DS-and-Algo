#include<bits/stdc++.h>
using namespace std;

// Least Recently Used Cache
// Easy Implementation
class LRUCache
{
private:
	list<int> q;
	unordered_map<int, int> mp;
	int cap;
public:
	LRUCache(int cap)
	{
		this->cap = cap;
	}

	int get(int key)
	{
		if (mp[key] == 0)
			return -1;
		list<int>::iterator x = find(begin(q), end(q), key);
		q.erase(x);
		q.push_front(key);
		return mp[key];
	}

	void set(int key, int value)
	{
		if (mp[key] != 0)
		{
			mp[key] = value;
			list<int>::iterator x = find(begin(q), end(q), key);
			q.erase(x);
			q.push_front(key);
			return;
		}
		if (q.size() >= cap)
		{
			mp[q.back()] = 0;
			q.pop_back();
		}
		q.push_front(key);
		mp[key] = value;
	}
};


// Efficient Implementation, O(1) for get and set
class LRUCacheEff
{
private:
	list<pair<int, int>> cache;
	unordered_map < int, list<pair<int, int>>::iterator> mp;
	int capacity;

	void refreshCache(int key, int value)
	{
		cache.erase(mp[key]);
		cache.push_front({key, value});
		mp[key] = cache.begin();
	}

public:
	LRUCacheEff(int capacity)
	{
		this->capacity = capacity;
	}

	int get(int key)
	{
		if (mp.find(key) == mp.end())
			return -1;
		refreshCache(key, mp[key]->second);
		return mp[key]->second;
	}

	void set(int key, int value)
	{
		if (mp.find(key) != mp.end())
			refreshCache(key, value);
		else
		{
			if (cache.size() >= capacity)
			{
				mp.erase(cache.back().first);
				cache.pop_back();
			}
			cache.push_front({key, value});
			mp[key] = cache.begin();
		}
	}
};

int main()
{
	LRUCacheEff cache(4);

	cache.set(1, 1);
	cache.set(2, 2);
	cout << cache.get(1) << "\n";
	cache.set(3, 3);
	cout << cache.get(2) << "\n";
	cache.set(4, 4);
	cout << cache.get(1) << "\n";
	cout << cache.get(3) << "\n";
	cout << cache.get(4) << "\n";

	return 0;
}