#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

int main() {

    // =========================================================
    // 1. VECTOR
    // =========================================================
    vector<int> v = {5, 2, 8, 1, 3};

    v.push_back(10);
    v.pop_back();

    cout << "Vector: ";
    for (int x : v)
        cout << x << " ";
    cout << "\n";

    cout << "Size: " << v.size() << "\n";
    cout << "First: " << v.front() << "\n";
    cout << "Last: " << v.back() << "\n";
    cout << "Element at index 2: " << v[2] << "\n";


    // =========================================================
    // 2. LIST
    // =========================================================
    list<int> l = {10, 20, 30};

    l.push_front(5);
    l.push_back(40);
    l.pop_front();
    l.pop_back();

    cout << "\nList: ";
    for (int x : l)
        cout << x << " ";
    cout << "\n";


    // =========================================================
    // 3. DEQUE
    // =========================================================
    deque<int> d = {2, 3, 4};

    d.push_front(1);
    d.push_back(5);
    d.pop_front();
    d.pop_back();

    cout << "\nDeque: ";
    for (int x : d)
        cout << x << " ";
    cout << "\n";


    // =========================================================
    // 4. STACK
    // LIFO = Last In First Out
    // =========================================================
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "\nStack top: " << st.top() << "\n";

    st.pop();

    cout << "Stack top after pop: " << st.top() << "\n";


    // =========================================================
    // 5. QUEUE
    // FIFO = First In First Out
    // =========================================================
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "\nQueue front: " << q.front() << "\n";
    cout << "Queue back: " << q.back() << "\n";

    q.pop();

    cout << "Queue front after pop: " << q.front() << "\n";


    // =========================================================
    // 6. PRIORITY QUEUE
    // Default = MAX HEAP
    // =========================================================
    priority_queue<int> pq;

    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(30);

    cout << "\nPriority Queue top: " << pq.top() << "\n";

    // Min heap
    priority_queue<int, vector<int>, greater<int>> minPQ;

    minPQ.push(10);
    minPQ.push(50);
    minPQ.push(20);
    minPQ.push(30);

    cout << "Min Priority Queue top: " << minPQ.top() << "\n";


    // =========================================================
    // 7. SET
    // Sorted + Unique
    // =========================================================
    set<int> s;

    s.insert(30);
    s.insert(10);
    s.insert(20);
    s.insert(10); // Duplicate ignored

    cout << "\nSet: ";
    for (int x : s)
        cout << x << " ";
    cout << "\n";

    cout << "Find 20: "
         << (s.find(20) != s.end() ? "Found" : "Not Found")
         << "\n";

    s.erase(20);


    // =========================================================
    // 8. MULTISET
    // Sorted + Duplicates Allowed
    // =========================================================
    multiset<int> ms = {10, 20, 10, 30, 20};

    cout << "\nMultiset: ";
    for (int x : ms)
        cout << x << " ";
    cout << "\n";

    cout << "Count of 10: " << ms.count(10) << "\n";


    // =========================================================
    // 9. MAP
    // Key -> Value
    // Sorted by key
    // =========================================================
    map<string, int> mp;

    mp["Alice"] = 90;
    mp["Bob"] = 80;
    mp["Charlie"] = 95;

    cout << "\nMap:\n";

    for (auto pair : mp)
        cout << pair.first << " -> " << pair.second << "\n";

    cout << "Alice's marks: " << mp["Alice"] << "\n";


    // =========================================================
    // 10. MULTIMAP
    // Multiple values can have same key
    // =========================================================
    multimap<string, int> mmap;

    mmap.insert({"A", 10});
    mmap.insert({"A", 20});
    mmap.insert({"B", 30});

    cout << "\nMultimap:\n";

    for (auto pair : mmap)
        cout << pair.first << " -> " << pair.second << "\n";


    // =========================================================
    // 11. UNORDERED SET
    // Unique elements
    // No sorting
    // =========================================================
    unordered_set<int> us;

    us.insert(10);
    us.insert(20);
    us.insert(10);

    cout << "\nUnordered Set: ";
    for (int x : us)
        cout << x << " ";
    cout << "\n";


    // =========================================================
    // 12. UNORDERED MAP
    // Key -> Value
    // Hash table
    // =========================================================
    unordered_map<string, int> ump;

    ump["Apple"] = 10;
    ump["Banana"] = 20;
    ump["Mango"] = 30;

    cout << "\nUnordered Map:\n";

    for (auto pair : ump)
        cout << pair.first << " -> " << pair.second << "\n";


    // =========================================================
    // 13. SORT
    // =========================================================
    vector<int> a = {5, 1, 4, 2, 3};

    sort(a.begin(), a.end());

    cout << "\nSorted: ";
    for (int x : a)
        cout << x << " ";
    cout << "\n";


    // Descending order
    sort(a.begin(), a.end(), greater<int>());

    cout << "Descending: ";
    for (int x : a)
        cout << x << " ";
    cout << "\n";


    // =========================================================
    // 14. REVERSE
    // =========================================================
    reverse(a.begin(), a.end());

    cout << "Reversed: ";
    for (int x : a)
        cout << x << " ";
    cout << "\n";


    // =========================================================
    // 15. FIND
    // =========================================================
    auto it = find(a.begin(), a.end(), 3);

    if (it != a.end())
        cout << "\n3 Found\n";
    else
        cout << "\n3 Not Found\n";


    // =========================================================
    // 16. COUNT
    // =========================================================
    vector<int> nums = {1, 2, 2, 3, 2, 4};

    cout << "Number of 2s: "
         << count(nums.begin(), nums.end(), 2)
         << "\n";


    // =========================================================
    // 17. MAX / MIN ELEMENT
    // =========================================================
    cout << "Maximum: "
         << *max_element(nums.begin(), nums.end())
         << "\n";

    cout << "Minimum: "
         << *min_element(nums.begin(), nums.end())
         << "\n";


    // =========================================================
    // 18. ACCUMULATE
    // Sum of elements
    // =========================================================
    int sum = accumulate(nums.begin(), nums.end(), 0);

    cout << "Sum: " << sum << "\n";


    // =========================================================
    // 19. BINARY SEARCH
    // IMPORTANT: Array must be sorted
    // =========================================================
    sort(nums.begin(), nums.end());

    if (binary_search(nums.begin(), nums.end(), 3))
        cout << "3 exists\n";
    else
        cout << "3 does not exist\n";


    // =========================================================
    // 20. LOWER_BOUND
    // First position >= value
    // =========================================================
    vector<int> b = {1, 2, 4, 4, 5, 7};

    auto lb = lower_bound(b.begin(), b.end(), 4);

    cout << "Lower bound of 4: "
         << (lb - b.begin())
         << "\n";


    // =========================================================
    // 21. UPPER_BOUND
    // First position > value
    // =========================================================
    auto ub = upper_bound(b.begin(), b.end(), 4);

    cout << "Upper bound of 4: "
         << (ub - b.begin())
         << "\n";


    // =========================================================
    // 22. SWAP
    // =========================================================
    int x = 10;
    int y = 20;

    swap(x, y);

    cout << "\nAfter swap:\n";
    cout << "x = " << x << "\n";
    cout << "y = " << y << "\n";


    // =========================================================
    // 23. ITERATORS
    // =========================================================
    vector<int> nums2 = {10, 20, 30};

    cout << "\nUsing iterator: ";

    for (vector<int>::iterator i = nums2.begin();
         i != nums2.end();
         ++i) {

        cout << *i << " ";
    }

    cout << "\n";


    // =========================================================
    // 24. AUTO
    // =========================================================
    for (auto i = nums2.begin(); i != nums2.end(); ++i)
        cout << *i << " ";

    cout << "\n";


    // =========================================================
    // 25. PAIR
    // =========================================================
    pair<string, int> person;

    person.first = "Nobita";
    person.second = 100;

    cout << "\nPair:\n";
    cout << person.first << " -> "
         << person.second << "\n";


    // =========================================================
    // 26. VECTOR OF PAIRS
    // =========================================================
    vector<pair<string, int>> students = {
        {"A", 90},
        {"B", 80},
        {"C", 95}
    };

    cout << "\nStudents:\n";

    for (auto p : students)
        cout << p.first << " -> " << p.second << "\n";


    // =========================================================
    // 27. EMPLACE
    // =========================================================
    vector<int> ev;

    ev.emplace_back(10);
    ev.emplace_back(20);
    ev.emplace_back(30);

    cout << "\nEmplace Vector: ";

    for (auto value : ev)
        cout << value << " ";

    cout << "\n";


    // =========================================================
    // 28. EMPTY
    // =========================================================
    vector<int> emptyVector;

    if (emptyVector.empty())
        cout << "\nVector is empty\n";


    // =========================================================
    // 29. CLEAR
    // =========================================================
    vector<int> cv = {1, 2, 3, 4};

    cv.clear();

    cout << "Vector size after clear: "
         << cv.size() << "\n";


    // =========================================================
    // 30. UNIQUE
    // Removes consecutive duplicates
    // =========================================================
    vector<int> uniqueNums = {
        1, 1, 2, 2, 3, 3, 4
    };

    uniqueNums.erase(
        unique(uniqueNums.begin(), uniqueNums.end()),
        uniqueNums.end()
    );

    cout << "\nUnique values: ";

    for (int value : uniqueNums)
        cout << value << " ";

    cout << "\n";


    return 0;
}