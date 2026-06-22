class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> mp; // value -> index
public:
    RandomizedSet() {
    }

    bool insert(int val) {
        if (mp.count(val))
            return false;

        nums.push_back(val);
        mp[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!mp.count(val))
            return false;

        int idx = mp[val];
        int last = nums.back();

        nums[idx] = last;
        mp[last] = idx;

        nums.pop_back();
        mp.erase(val);

        return true;
    }

    int getRandom() {
        int idx = rand() % nums.size();
        return nums[idx];
    }
};