#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;

template<typename T>
void printVector(const vector<T>& nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

template<typename T>
void printVectorOfVector(const vector<vector<T>>& nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums[i].size(); j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}

struct ListNode {
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x) :val(x), next(nullptr) {}
    ListNode(int x, ListNode* p) :val(x), next(p) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};

int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void Test_search() {
    cout << "704. 二分查找" << endl;
    vector<int> nums;
    int num;
    cout << "\ninput array" << endl;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    cout << "\ninput target" << endl;
    int target;
    cin >> target;
    cout <<"res:"<< search(nums, target) << endl;
}

int removeElement(vector<int>& nums, int val) {
    int slow = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == val)
            continue;
        else {
            nums[slow] = nums[i];
            slow++;
        }
    }
    return slow;
}

void Test_removeElement() {
    cout << "27. 移除元素" << endl;
    vector<int> nums;
    int num;
    cout << "\ninput array" << endl;
    while (cin >> num) {
        if (cin.peek() == '\n')
            break;
        nums.push_back(num);
    }
    cout << "\ninput target" << endl;
    int target;
    cin >> target;
    cout << "res:" << removeElement(nums, target) << endl;
}


vector<int> sortedSquares(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    vector<int> res(nums.size(),0);
    for (int i = res.size() - 1; i >= 0; i--) {
        int lval = nums[left] * nums[left];
        int rval = nums[right] * nums[right];
        if (lval >= rval)
        {
            res[i] = lval;
            left++;
        }
        else {
            res[i] = rval;
            right--;
        }
    }
    return res;
}

void Test_sortedSquares() {
    cout << "977. 有序数组的平方" << endl;
    vector<int> nums;
    int num;
    cout << "\ninput array" << endl;
    while (cin >> num) {
        if (cin.peek() == '\n')
            break;
        nums.push_back(num);
    }
    vector<int> res = sortedSquares(nums);
    printVector(res);
}

int minSubArrayLen(int target, vector<int>& nums) {
    int slow = 0; 
    int fast = 0;
    int size = INT_MAX;
    int sum = 0;
    while (fast < nums.size())
    {
        sum += nums[fast];
        fast++;
        while (sum >= target) {
            size = min(size, fast - slow);
            sum -= nums[slow];
            slow++;
        }
    }
    return size==INT_MAX?0:size;
}

void Test_minSubArrayLen() {
    cout << "209. 长度最小的子数组素" << endl;
    vector<int> nums;
    int num;
    cout << "\ninput array" << endl;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    cout << "\ninput target" << endl;
    int target;
    cin >> target;
    cout << "res:" << minSubArrayLen(target, nums) << endl;
}

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> grid(n, vector<int>(n, 0));
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int num = 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++)
            grid[top][i] = num++;
        top++;

        for (int j = top; j <= bottom; j++)
            grid[j][right] = num++;
        right--;

        if (left <= right) {
            for (int i = right; i >= left; i--)
                grid[bottom][i] = num++;
            bottom--;
        }

        if (top <= bottom) {
            for (int j = bottom; j >= top; j--)
                grid[j][left] = num++;
            left++;
        }
    }
    return grid;
}

void Test_generateMatrix() {
    cout << "59. 螺旋矩阵 II" << endl;
    cout << "\ninput target" << endl;
    int target;
    cin >> target;
    vector<vector<int>> res = generateMatrix(target);
    printVectorOfVector(res);
}

ListNode* inputCreateListNode() {
    cout << "\ninput the array:" << endl;
    ListNode* dummyNode = new ListNode(0);
    ListNode* p = dummyNode;
    int num;
    while (cin >> num) {
        ListNode* node = new ListNode(num);
        p->next = node;
        p = p->next;
        if (cin.peek() == '\n')
        {
            break;
        }
    }
    return dummyNode->next;
}

ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummyNode = new ListNode(0);
    dummyNode->next = head;
    ListNode* p = dummyNode;
    while (p->next != nullptr) {
        if (p->next->val == val) {
            ListNode* temp = p->next;
            p->next = p->next->next;
            delete temp;
        }
        else {
            p = p->next;
        }
    }
    return dummyNode->next;
}

void printListNode(ListNode* head)
{
    cout << "\nthe ListNode vals are:" << endl;
    ListNode* p = head;
    while (p != nullptr)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

void Test_removeElements()
{
    ListNode* node = inputCreateListNode();
    cout << "\ninput the val that need delete:" << endl;
    int val;
    cin >> val;
    ListNode* res = removeElements(node, val);
    printListNode(res);
}



class MyLinkedList {
public:
    MyLinkedList() {
        dummyNode = new ListNode(0);
    }

    int get(int index) {
        if (index < 0) return -1;
        ListNode* p = dummyNode;
        int time = index;
        while (time > 0 && p->next != nullptr)
        {
            p = p->next;
            time--;
        }

        if (time > 0 || p->next == nullptr) {
            return -1;
        }
        else {
            return p->next->val;
        }
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        ListNode* p = dummyNode;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = new ListNode(val);
    }

    void addAtIndex(int index, int val) {
        ListNode* p = dummyNode;
        int time = index;
        while (time > 0 && p != nullptr)
        {
            p = p->next;
            time--;
        }
        if (time > 0 || p == nullptr) {
            return;
        }
        ListNode* newnode = new ListNode(val);
        ListNode* temp = p->next;
        p->next = newnode;
        newnode->next = temp;
    }

    void deleteAtIndex(int index) {
        if (index < 0) return;
        ListNode* p = dummyNode;
        int time = index;
        while (time > 0 && p->next != nullptr)
        {
            p = p->next;
            time--;
        }
        if (time > 0|| p->next ==nullptr) {
            return;
        }
        else
        {
            ListNode* temp = p->next;
            p->next = p->next->next;
            delete temp;
        }
    }

    ListNode* dummyNode = nullptr;
};

void Test_MyLinkedList()
{
    MyLinkedList myLinkedList;
    myLinkedList.addAtHead(1);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
    int res = myLinkedList.get(1);    // 返回 2
    cout << ((res == 2) ? "TRUE" : "FALSE" )<< endl;
    myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1->3
    int res2 = myLinkedList.get(1);   // 返回 3
    cout << ((res2 == 3) ? "TRUE" : "FALSE") << endl;
}

ListNode* reverseList(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* p = head;
    while (p != nullptr)
    {
        ListNode* temp = p->next;
        p->next = pre;
        pre = p;
        p = temp;
    }
    return pre;
}

void Test_reverseList()
{
    ListNode* node = inputCreateListNode();
    ListNode* res = reverseList(node);
    printListNode(res);
}

ListNode* swapNode(ListNode* begin, ListNode* end)
{
    ListNode* pre = nullptr;
    ListNode* p = begin;
    while (p != end)
    {
        ListNode* temp = p->next;
        p->next = pre;
        pre = p;
        p = temp;
    }
    return pre;
}

ListNode* swapPairs(ListNode* head) {
    ListNode* dummyNode = new ListNode(0);
    ListNode* p = head;
    int k = 2;
    for (int i = k; i > 0; i--)
    {
        if (p == nullptr)
            return head;
        p = p->next;
    }
    ListNode* end = p;
    ListNode* newstar = swapNode(head, end);
    head->next = swapPairs(end);
    return newstar;
}

void Test_swapPairs()
{
    ListNode* nodes = inputCreateListNode();
    ListNode* res = swapPairs(nodes);
    printListNode(res);
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummyNode = new ListNode(0);
    dummyNode->next = head;
    ListNode* fast = dummyNode;
    ListNode* slow = dummyNode;
    while (n-- && fast != nullptr) {
        fast = fast->next;
    }
    fast = fast->next;
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    return dummyNode->next;
}


void Test_removeNthFromEnd()
{
    ListNode* nodes = inputCreateListNode();
    cout << "\ninput the target:" << endl;
    int target;
    cin >> target;
    ListNode* res = removeNthFromEnd(nodes,target);
    printListNode(res);
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* p1 = headA;
    ListNode* p2 = headB;
    if (p1 == nullptr || p2 == nullptr)
        return nullptr;
    while (p1 != p2) {
        if (p1 == nullptr) {
            p1 = headB;
        }
        else {
            p1 = p1->next;
        }
        if (p2 == nullptr) {
            p2 = headA;
        }
        else {
            p2 = p2->next;
        }
    }
    return p1;
}

void Test_getIntersectionNode()
{
    ListNode p1(1); 
    ListNode p2(2); p1.next = &p2;
    ListNode p3(3); p2.next = &p3;
    ListNode p4(4); p3.next = &p4;

    ListNode n1(9);
    ListNode n2(8); n1.next = &n2;
    n2.next = &p2;
    ListNode* res = getIntersectionNode(&p1, &n1);
    cout << "res:" << res->val << endl;
}

ListNode* detectCycle(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            ListNode* p = head;
            while (p != slow)
            {
                p = p->next;
                slow = slow->next;
            }
            return p;
        }
    }
    return nullptr;
}

void Test_detectCycle()
{
    ListNode p1(1);
    ListNode p2(2); p1.next = &p2;
    ListNode p3(3); p2.next = &p3;
    ListNode p4(4); p3.next = &p4;
    ListNode p5(5); p4.next = &p5;
    ListNode p6(6); p5.next = &p6;
    p6.next = &p3;
    ListNode* res = detectCycle(&p1);
    cout << "res:" << res->val << endl;
}

bool isAnagram(string s, string t) {
    vector<int> map(26, 0);
    for (char c : t)
        map[c-'a']++;
    for (char c : s)
    {
        map[c - 'a']--;
        if (map[c - 'a'] < 0)
            return false;
    }
    for (int num : map)
    {
        if (num > 0)
            return false;
    }
    return true;
}

void Test_isAnagram()
{
    string c;
    cout << "\ninput string c:" << endl;
    cin >> c;
    cout << "\ninput string s:" << endl;
    string s;
    cin >> s;
    bool res = isAnagram(c, s);
    cout<<((res == true)? "TRUE" : "FALSE")<< endl;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> myset;
    unordered_set<int> temp;
    for (int num : nums1)
        myset.insert(num);
    for (int num : nums2)
    {
        if (myset.count(num))
            temp.insert(num);
    }
    vector<int> res(temp.begin(), temp.end());
    return res;
}

void Test_intersection()
{
    vector<int> nums1;
    int num;
    cout << "\ninput array1 : " << endl;
    while (cin >> num) {
        nums1.push_back(num);
        if (cin.peek() == '\n')
            break;
    }

    vector<int> nums2;
    cout << "\ninput array2 : " << endl;
    while (cin >> num) {
        nums2.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    vector<int> res = intersection(nums1, nums2);
    printVector(res);
}

bool isHappy(int n) {
    unordered_set<int> record;
    while (n != 1 && !record.count(n)) {
        record.insert(n);
        int num = 0;
        while (n > 0) {
            int temp = n % 10;
            n /= 10;
            num += temp * temp;
        }
        n = num;
    }
    return n == 1;
}

void Test_isHappy()
{
    int num;
    cout << "\ninput target: " << endl;
    cin >> num;
    bool res = isHappy(num);
    cout << ((res == true) ? "TRUE" : "FALSE") << endl;
}

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> record;
    for (int i = 0; i < nums.size(); i++)
    {
        int val = target - nums[i];
        if (record.count(val))
        {
            return { record[val], i };
        }
        else {
            record[nums[i]] = i;
        }
    }
    return {};
}

void Test_twoSum()
{
    vector<int> nums;
    int num;
    cout << "\ninput array : " << endl;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    cout << "\ninput target : " << endl;
    int target;
    cin >> target;
    vector<int> res = twoSum(nums, target);
    printVector(res);
}

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    unordered_map<int, int> record;
    for (int i : nums1)
    {
        for (int j : nums2)
        {
            record[i + j]++;
        }
    }
    int res = 0;
    for (int i : nums3)
    {
        for (int j : nums4)
        {
            int target = -i - j;
            if (record.count(target))
                res += record[target];
        }
    }
    return res;
}

void Test_fourSumCount()
{
    vector<int> nums1;
    int num;
    cout << "\ninput array1 : " << endl;
    while (cin >> num) {
        nums1.push_back(num);
        if (cin.peek() == '\n')
            break;
    }

    vector<int> nums2;
    cout << "\ninput array2 : " << endl;
    while (cin >> num) {
        nums2.push_back(num);
        if (cin.peek() == '\n')
            break;
    }

    vector<int> nums3;
    cout << "\ninput array3 : " << endl;
    while (cin >> num) {
        nums3.push_back(num);
        if (cin.peek() == '\n')
            break;
    }

    vector<int> nums4;
    cout << "\ninput array4 : " << endl;
    while (cin >> num) {
        nums4.push_back(num);
        if (cin.peek() == '\n')
            break;
    }

    int res = fourSumCount(nums1, nums2, nums3, nums4);
    cout << "The res is:" << res << endl;
}

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> map;
    for (char c : magazine)
        map[c]++;
    for (char c : ransomNote)
    {
        if (map.count(c)&&map[c]>0)
        {
            map[c]--;
        }
        else {
            return false;
        }
    }
    return true;
}

void Test_canConstruct()
{
    string c;
    cout << "\ninput string c:" << endl;
    cin >> c;
    cout << "\ninput string s:" << endl;
    string s;
    cin >> s;
    bool res = canConstruct(c, s);
    cout << ((res == true) ? "TRUE" : "FALSE") << endl;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i - 1 >= 0 && nums[i] == nums[i - 1])
            continue;
        int left = i + 1; int right = nums.size() - 1;
        int target = -nums[i];
        while (left < right)
        {
            if (nums[left] + nums[right] > target)
            {
                right--;
            }
            else if (nums[left] + nums[right] < target) {
                left++;
            }
            else {
                res.push_back({ nums[i], nums[left], nums[right] });
                while (left < right && nums[left] == nums[left + 1]) { left++; }
                while (left < right && nums[right] == nums[right - 1]) { right--; }
                left++;
                right--;
            }
        }
    }
    return res;
}

void Test_threeSum()
{
    vector<int> nums;
    int num;
    cout << "\ninput array : " << endl;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    vector<vector<int>> res = threeSum(nums);
    printVectorOfVector(res);
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (j > i+1 && nums[j] == nums[j - 1])
                continue;
            int left = j + 1, right = nums.size() - 1;
            long long val = (long long)target - nums[i] - nums[j];
            while (left < right)
            {
                long long sum = (long long)nums[left] + nums[right];
                if (sum > val)
                    right--;
                else if (sum < val)
                    left++;
                else {
                    res.push_back({nums[i],nums[j],nums[left],nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) { left++; }
                    while (left < right && nums[right] == nums[right - 1]) { right--; }
                    left++;
                    right--;
                }
            }
        }
    }
    return res;
}

void Test_fourSum()
{
    vector<int> nums;
    int num;
    cout << "\ninput array : " << endl;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    cout << "\ninput target : " << endl;
    int target;
    cin >> target;
    vector<vector<int>> res = fourSum(nums, target);
    printVectorOfVector(res);
}

void reverseString(vector<char>& s) {
    int left = 0;
    int right = s.size() - 1;
    while (left <= right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

void Test_reverseString()
{
    char c;
    cout << "\ninput string:" << endl;
    vector<char> s;
    while (cin >> c) {
        s.push_back(c);
        if (cin.peek() == '\n')
            break;
    }
    reverseString(s);
    printVector(s);
}

string reverseStr(string s, int k) {
    int n = s.size();
    for (int i = 0; i < n; i += 2 * k)
    {
        reverse(s.begin() + i, s.begin() + min(i + k, n));
    }
    return s;
}

void Test_reverseStr()
{
    string c;
    cout << "\ninput string:" << endl;
    cin >> c;
    int target;
    cout << "\ninput target:" << endl;
    cin >> target;
    string s = reverseStr(c,target);
    cout << s << endl;
}

string reverseWords(string s) {
    string res;
    string word;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            if (!word.empty()) {
                reverse(word.begin(), word.end());
                if (!res.empty())
                    res += ' ';
                res += word;
                word.clear();
            }
        }
        else {
            word += s[i];
        }
    }
    if (!word.empty()) {
        reverse(word.begin(), word.end());
        if (!res.empty())
            res += ' ';
        res += word;
    }
    return res;
}

void Test_reverseWords()
{
    string c;
    cout << "\ninput string:" << endl;
    getline(cin, c);
    string res = reverseWords(c);
    cout << endl;
    cout << "res : " << res << endl;
}

int strStr(string haystack, string needle) {
    if (needle.empty())
        return 0;
    if (needle.size() > haystack.size())
        return -1;
    for (int i = 0; i <= haystack.size() - needle.size(); i++)
    {
        bool iftrue = true;
        for (int j = 0; j < needle.size(); j++)
        {
            if (haystack[i + j] != needle[j])
            {
                iftrue = false;
                break;
            }
        }
        if (iftrue)
            return i;
    }
    return -1;
}

void getnext(vector<int>& next, const string& s)
{
    int j = 0;
    next[0] = 0;
    for (int i = 0; i < s.size(); i++)
    {
        while (j > 0 && next[i] != next[j])
            j = next[j - 1];
        if (s[i] == s[j])
            j++;
        next[i] = j;
    }
}

int strStr_KMP(string haystack, string needle) {
    if (needle.empty())
        return 0;
    vector<int> next(needle.size());
    getnext(next, needle);
    int j = 0;
    for (int i = 0; i < haystack.size(); i++)
    {
        while (j > 0 && haystack[i] != needle[j])
            j = next[j - 1];
        if (haystack[i] == needle[j])
            j++;
        if (j == needle.size())
            return (i - needle.size() + 1);
    }
    return -1;
}

void Test_strStr()
{
    string c1;
    cout << "\ninput string1:" << endl;
    cin >> c1;

    string c2;
    cout << "\ninput string2:" << endl;
    cin >> c2;

    int res = strStr_KMP(c1, c2);
    cout << res << endl;
}

void getnext2(vector<int>& next, const string& s) {
    int j = 0;
    for (int i = 1; i < s.size(); i++) {
        while (j > 0 && s[i] != s[j]) {
            j = next[j - 1];
        }
        if (s[i] == s[j])
            j++;
        next[i] = j;
    }
}

bool repeatedSubstringPattern(string s) {
    if (s.empty())
        return false;
    vector<int> next(s.size(), 0);
    getnext2(next, s);
    int size = s.size();
    if (next[size - 1] > 0 && (size % (size - next[size - 1])) == 0)
        return true;
    return false;
}

void Test_repeatedSubstringPattern()
{
    string c1;
    cout << "\ninput string:" << endl;
    cin >> c1;
    bool res = repeatedSubstringPattern(c1);
    cout << ((res == true) ? "TRUE" : "FALSE") << endl;
}

class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        sta1.push(x);
    }

    int pop() {
        if (sta2.empty())
        {
            while (!sta1.empty())
            {
                int temp = sta1.top();
                sta1.pop();
                sta2.push(temp);
            }
        }
        int res = sta2.top();
        sta2.pop();
        return res;
    }

    int peek() {
        int res = this->pop();
        sta2.push(res);
        return res;
    }

    bool empty() {
        return sta1.empty() && sta2.empty();
    }

private:
    stack<int> sta1;
    stack<int> sta2; 
};

void Test_MyQueue()
{
    MyQueue myque;
    myque.push(1);
    myque.push(2);
    int res1 = myque.peek();
    int res2 = myque.pop();
    bool res3 = myque.empty();
    cout << res1 << endl;
    cout << res2 << endl;
    cout << res3 << endl;
}

class MyStack {
public:
    MyStack() { }

    void push(int x) {
        que.push(x);
    }

    int pop() {
        int n = que.size() - 1;
        while (n--) {
            int temp = que.front();
            que.push(temp);
            que.pop();
        }
        int res = que.front();
        que.pop();
        return res;
    }

    int top() {
        int n = que.size() - 1;
        while (n--) {
            int temp = que.front();
            que.push(temp);
            que.pop();
        }
        int res = que.front();
        que.push(res);
        que.pop();
        return res;
    }

    bool empty() { return que.empty(); }

private:
    queue<int> que;
};

void Test_MyStack()
{
    MyStack mysta;
    mysta.push(1);
    mysta.push(2);
    int res1 = mysta.top();
    int res2 = mysta.pop();
    bool res3 = mysta.empty();
    cout << res1 << endl;
    cout << res2 << endl;
    cout << res3 << endl;
}

bool isValid(string s) {
    stack<char> sta;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[')
            sta.push(c);
        else if (sta.empty()) {
            return false;
        }
        else if (c == ')' && sta.top() == '(') {
            sta.pop();
        }
        else if (c == ']' && sta.top() == '[') {
            sta.pop();
        }
        else if (c == '}' && sta.top() == '{') {
            sta.pop();
        }
        else {
            return false;
        }
    }
    return sta.empty();
}

void Test_isValid() {
    string c1;
    cout << "\ninput string (eg: ((({[]}))):" << endl;
    cin >> c1;
    bool res = isValid(c1);
    cout << ((res == true) ? "TRUE" : "FALSE") << endl;
}

string removeDuplicates(string s) {
    stack<char> sta;
    for (int i = 0; i < s.size(); i++)
    {
        if (sta.empty() || sta.top() != s[i])
            sta.push(s[i]);
        else {
            sta.pop();
        }
    }
    string res;
    while (!sta.empty())
    {
        res += sta.top();
        sta.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

void Test_removeDuplicates()
{
    string c1;
    cout << "\ninput string" << endl;
    cin >> c1;
    string res = removeDuplicates(c1);
    cout << res << endl;
}

int evalRPN(vector<string>& tokens) {
    stack<int> val;
    for (string s : tokens)
    {
        if (s == "+")
        {
            int val1 = val.top(); val.pop();
            int val2 = val.top(); val.pop();
            val.push(val2 + val1);

        }
        else if (s == "-")
        {
            int val1 = val.top(); val.pop();
            int val2 = val.top(); val.pop();
            val.push(val2 - val1);
        }
        else if (s == "*")
        {
            int val1 = val.top(); val.pop();
            int val2 = val.top(); val.pop();
            val.push(val2 * val1);
        }
        else if (s == "/")
        {
            int val1 = val.top(); val.pop();
            int val2 = val.top(); val.pop();
            val.push(val2 / val1);
        }
        else {
            int num = stoi(s);
            val.push(num);
        }
    }
    return val.top();
}

void Test_evalRPN() {
    string s;
    cout << "\ninput string:" << endl;
    vector<string> str;
    while (cin >> s) {
        str.push_back(s);
        if (cin.peek() == '\n')
            break;
    }
    int res = evalRPN(str);
    cout << res << endl;
}

class Danqueue {
public:
    void push(int num) {
        while (!que.empty()&&que.back() < num)
        {
            que.pop_back();
        }
        que.push_back(num);
    }

    void pop(int num) {
        if (!que.empty() && que.front() == num)
            que.pop_front();
    }

    int top() {
        return que.front();
    }
private:
    deque<int> que;
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    Danqueue que;
    vector<int> res;
    for(int i = 0; i<k; i++)
    {
        que.push(nums[i]);
    }
    res.push_back(que.top());
    for (int i = k; i < nums.size(); i++)
    {
        que.push(nums[i]);
        que.pop(nums[i - k]);
        res.push_back(que.top());
    }
    return res;
}

void Test_maxSlidingWindow()
{
    vector<int> nums;
    int num;
    cout << "\ninput array : " << endl;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    cout << "\ninput k : " << endl;
    int k;
    cin >> k;
    vector<int> res = maxSlidingWindow(nums, k);
    printVector(res);
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    for (int num : nums)
        map[num]++;
    auto big = [](pair<int, int>& a, pair<int, int>& b){
        return a.second < b.second;};
    priority_queue<pair<int, int>, vector<pair<int, int>>,decltype(big)> myque(big);
    for (pair<int, int> p : map)
        myque.push(p);
    vector<int> res;
    while (k--)
    {
        int num = myque.top().first;
        myque.pop();
        res.push_back(num);
    }
    return res;
}

void Test_topKFrequent()
{
    vector<int> nums;
    int num;
    cout << "\ninput array : " << endl;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    cout << "\ninput k : " << endl;
    int k;
    cin >> k;
    vector<int> res = topKFrequent(nums, k);
    printVector(res);
}

void preorderfind(TreeNode* root, vector<int>& res)
{
    if (root == nullptr)
        return;
    res.push_back(root->val);
    preorderfind(root->left, res);
    preorderfind(root->right, res);
    return;
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    preorderfind(root, res);
    return res;
}

void inorderfind(TreeNode* root, vector<int>& res)
{
    if (root == nullptr)
        return;
    inorderfind(root->left, res);
    res.push_back(root->val);
    inorderfind(root->right, res);
    return;
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    inorderfind(root, res);
    return res;
}

void postorderfind(TreeNode* root, vector<int>& res)
{
    if (root == nullptr)
        return;
    postorderfind(root->left, res);
    postorderfind(root->right, res);
    res.push_back(root->val);
    return;
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    postorderfind(root, res);
    return res;
}

TreeNode* createSampleTreeNode()
{
    /*       0
    *       / \
    *      1   2
    *     /\   /\
    *    3  4 5  6
    */
    TreeNode* root = new TreeNode(0);
    TreeNode* l1 = new TreeNode(1); TreeNode* r1 = new TreeNode(2); root->left = l1; root->right = r1;
    TreeNode* l12 = new TreeNode(3); TreeNode* r12 = new TreeNode(4); l1->left = l12; l1->right = r12;
    TreeNode* l13 = new TreeNode(5); TreeNode* r13 = new TreeNode(6); r1->left = l13; r1->right = r13;
    return root;
}

void Test_preorderTraversal(){
    TreeNode* root = createSampleTreeNode();
    cout << "input 1-前序、2-中序、3-后序" << endl;
    int num;
    cin >> num;
    vector<int> res;
    if(num==1)
        res = preorderTraversal(root);
    else if(num==2)
        res = inorderTraversal(root);
    else if(num==3)
        res = postorderTraversal(root);
    printVector(res);
}

vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> que;
    vector<vector<int>> res;
    if (root == nullptr)
        return res;
    que.push(root);
    while (!que.empty()) {
        int n = que.size();
        vector<int> temp;
        while (n--)
        {
            TreeNode* node = que.front(); que.pop();
            temp.push_back(node->val);
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
        res.push_back(temp);
    }
    return res;
}

void Test_levelOrder()
{
    TreeNode* root = createSampleTreeNode();
    vector<vector<int>> res = levelOrder(root);
    printVectorOfVector(res);
}

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr)
        return nullptr;
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}

void Test_invertTree()
{
    TreeNode* root = createSampleTreeNode();
    TreeNode* res = invertTree(root);
    vector<vector<int>> tree = levelOrder(res);
    printVectorOfVector(tree);
}

bool issymmetric(TreeNode* lnode, TreeNode* rnode) {
    if (lnode == nullptr && rnode == nullptr)
        return true;
    else if (lnode == nullptr || rnode == nullptr)
        return false;
    else if (lnode->val != rnode->val)
        return false;
    bool leftb = issymmetric(lnode->left, rnode->right);
    bool rightb = issymmetric(lnode->right, rnode->left);
    return leftb && rightb;
}

bool isSymmetric(TreeNode* root) {
    if (root == nullptr)
        return false;
    return issymmetric(root->left, root->right);
}

void Test_isSymmetric()
{
    TreeNode* root = createSampleTreeNode();
    bool res = isSymmetric(root);
    cout << ((res == true) ? "TRUE" : "FALSE") << endl;
}

int maxDepth(TreeNode* root) {
    if (root == nullptr)
        return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

void Test_maxDepth()
{
    TreeNode* root = createSampleTreeNode();
    int res = maxDepth(root);
    cout << res << endl;
}

int minDepth(TreeNode* root) {
    queue<TreeNode*> que;
    vector<vector<int>> res;
    if (root == nullptr)
        return 0;
    que.push(root);
    int deepth = 0;
    while (!que.empty()) {
        int n = que.size();
        vector<int> temp;
        deepth++;
        while (n--) {
            TreeNode* node = que.front();
            que.pop();
            temp.push_back(node->val);
            if (node->left == nullptr && node->right == nullptr)
                return deepth;
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
        }
    }
    return deepth;
}

void Test_minDepth()
{
    TreeNode* root = createSampleTreeNode();
    int res = minDepth(root);
    cout << res << endl;
}

int countNodes(TreeNode* root) {
    if (root == nullptr)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

void Test_countNodes()
{
    TreeNode* root = createSampleTreeNode();
    int res = countNodes(root);
    cout << res << endl;
}

int findisBalanced(TreeNode* root) {
    if (root == nullptr)
        return 0;
    int left = findisBalanced(root->left);
    if (left == -1)
        return -1;
    int right = findisBalanced(root->right);
    if (right == -1)
        return -1;
    if (abs(left - right) > 1)
        return -1;
    return max(left, right) + 1;
}

bool isBalanced(TreeNode* root) {
    if (findisBalanced(root) == -1)
        return false;
    return true;
}

void Test_isBalanced()
{
    TreeNode* root = createSampleTreeNode();
    bool res = isBalanced(root);
    cout << ((res == true) ? "TRUE" : "FALSE") << endl;
}

void dfs_binaryTreePaths(vector<string>& res, TreeNode* root,
    vector<int>& path) {
    if (root == nullptr)
        return;
    path.push_back(root->val);
    if (root->left == nullptr && root->right == nullptr) {
        string temp;
        int size = path.size();
        for (int i = 0; i < size - 1; i++) {
            temp += to_string(path[i]);
            temp += "->";
        }
        temp += to_string(path[size - 1]);
        res.push_back(temp);
        return;
    }

    if (root->left) {
        dfs_binaryTreePaths(res, root->left, path);
        path.pop_back();
    }
    if (root->right) {
        dfs_binaryTreePaths(res, root->right, path);
        path.pop_back();
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    vector<int> path;
    dfs_binaryTreePaths(res, root, path);
    return res;
}

void Test_binaryTreePaths()
{
    TreeNode* root = createSampleTreeNode();
    vector<string> res = binaryTreePaths(root);
    printVector(res);
}

int sumOfLeftLeavesres = 0;
int sumOfLeftLeaves(TreeNode* root) {
    if (root == nullptr)
        return sumOfLeftLeavesres;
    if (root->left != nullptr && root->left->left == nullptr &&root->left->right == nullptr)
        sumOfLeftLeavesres += root->left->val;
    sumOfLeftLeaves(root->left);
    sumOfLeftLeaves(root->right);
    return sumOfLeftLeavesres;
}

void Test_sumOfLeftLeaves()
{
    TreeNode* root = createSampleTreeNode();
    int res = sumOfLeftLeaves(root);
    cout << "The res is : " << res << endl;
}

int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> que;
    if (root == nullptr)
        return 0;
    que.push(root);
    int LEFT_VAL;
    while (!que.empty()) {
        int n = que.size();
        for (int i = 0; i < n; i++) {
            TreeNode* node = que.front();
            que.pop();
            if (i==0)
                LEFT_VAL = node->val;
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
        }
    }
    return LEFT_VAL;
}

void Test_findBottomLeftValue()
{
    TreeNode* root = createSampleTreeNode();
    int res = findBottomLeftValue(root);
    cout << "The res is : " << res << endl;
}

bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr)
        return false;
    int num = targetSum - root->val;
    if (root->left == nullptr && root->right == nullptr && num == 0)
        return true;
    bool leftb = hasPathSum(root->left, num);
    bool rightb = hasPathSum(root->right, num);
    return leftb || rightb;
}

void Test_hasPathSum() {
    TreeNode* root = createSampleTreeNode();
    bool res = hasPathSum(root,7);
    cout << ((res == true) ? "TRUE" : "FALSE") << endl;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = postorder.size();
    if (n == 0)
        return nullptr;
    int rootval = postorder[n - 1];
    TreeNode* root = new TreeNode(rootval);
    postorder.resize(n - 1);
    int rootidx;
    for (int i = 0; i < inorder.size(); i++) {
        if (inorder[i] == rootval) {
            rootidx = i;
            break;
        }
    }
    vector<int> leftinorder(inorder.begin(), inorder.begin() + rootidx);
    vector<int> rightinorder(inorder.begin() + rootidx + 1, inorder.end());
    vector<int> leftpostorder(postorder.begin(),
        postorder.begin() + leftinorder.size());
    vector<int> rightpostorder(postorder.begin() + leftinorder.size(),
        postorder.end());
    root->left = buildTree(leftinorder, leftpostorder);
    root->right = buildTree(rightinorder, rightpostorder);
    return root;
}

void Test_buildTree()
{
    vector<int> inorder = { 9,3,15,20,7 };
    vector<int> postorder = { 9,15,7,20,3 };
    TreeNode* root = buildTree(inorder, postorder);
    vector<vector<int>> res = levelOrder(root);
    printVectorOfVector(res);
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    if (nums.empty())
        return nullptr;
    int rootval = INT_MIN;
    int rootidx = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > rootval)
        {
            rootval = nums[i];
            rootidx = i;
        }
    }
    TreeNode* root = new TreeNode(rootval);
    vector<int> leftnums(nums.begin(), nums.begin() + rootidx);
    vector<int> rightnums(nums.begin() + rootidx +1, nums.end());
    root->left = constructMaximumBinaryTree(leftnums);
    root->right = constructMaximumBinaryTree(rightnums);
    return root;
}

void Test_constructMaximumBinaryTree()
{
    int num;
    vector<int> nums;
    cout << "\ninput array" << endl;
    while (cin >> num) {
        if (cin.peek() == '\n')
            break;
        nums.push_back(num);
    }
    TreeNode* root = constructMaximumBinaryTree(nums);
    vector<vector<int>> res = levelOrder(root);
    printVectorOfVector(res);
}

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr) return root2;//root1为空
    if (root2 == nullptr) return root1;//root2为空

    root1->val += root2->val;//都不为空
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
}

void Test_mergeTrees()
{
    TreeNode* root1 = createSampleTreeNode();
    TreeNode* root2 = createSampleTreeNode();
    TreeNode* root = mergeTrees(root1, root2);
    vector<vector<int>> res = levelOrder(root);
    printVectorOfVector(res);
}

TreeNode* searchBST(TreeNode* root, int val) {
    if (root == nullptr || root->val == val)
        return root;
    TreeNode* res = nullptr;
    if (val > root->val)
        res = searchBST(root->right, val);
    else if (val < root->val)
        res = searchBST(root->left, val);
    return res;
}

void Test_searchBST() {
    int num;
    vector<int> nums;
    cout << "\ninput array" << endl;
    while (cin >> num) {
        if (cin.peek() == '\n')
            break;
        nums.push_back(num);
    }
    TreeNode* root = constructMaximumBinaryTree(nums);
    cout << "\ninput val" << endl;
    int val;
    cin >> val;
    TreeNode* res = searchBST(root, val);
    vector<vector<int>> outres = levelOrder(root);
    printVectorOfVector(outres);
}

TreeNode* pre_isValidBST = nullptr;
bool isValidBST(TreeNode* root) {
    if (root == nullptr)
        return true;
    bool leftb = isValidBST(root->left);
    if (pre_isValidBST != nullptr) {
        if (pre_isValidBST->val >= root->val)
            return false;
    }
    pre_isValidBST = root;
    bool rightb = isValidBST(root->right);
    return leftb && rightb;
}

void Test_isValidBST()
{
    int num;
    vector<int> nums;
    cout << "\ninput array" << endl;
    while (cin >> num) {
        if (cin.peek() == '\n')
            break;
        nums.push_back(num);
    }
    TreeNode* root = constructMaximumBinaryTree(nums);
    bool res = isValidBST(root);
    cout << ((res == true) ? "TRUE" : "FALSE") << endl;
}

TreeNode* pre_getMinimumDifference = nullptr;
int min_val = INT_MAX;
int getMinimumDifference(TreeNode* root) {
    if (root == nullptr)
        return true;
    getMinimumDifference(root->left);
    if (pre_getMinimumDifference != nullptr) {
        int val = abs(pre_getMinimumDifference->val - root->val);
        min_val = min(min_val, val);
    }
    pre_getMinimumDifference = root;
    getMinimumDifference(root->right);
    return min_val;
}

void Test_getMinimumDifference()
{
    int num;
    vector<int> nums;
    cout << "\ninput array" << endl;
    while (cin >> num) {
        if (cin.peek() == '\n')
            break;
        nums.push_back(num);
    }
    TreeNode* root = constructMaximumBinaryTree(nums);
    int res = getMinimumDifference(root);
    cout << "Res:" << res << endl;
}

void findModeBFS(TreeNode* root, vector<int>& res, TreeNode*& prenode, int& count, int& maxcount)
{
    if (root == nullptr) return;
    findModeBFS(root->left, res, prenode, count, maxcount);
    if (prenode != nullptr&&prenode->val==root->val)
        count++;
    else
        count = 1;
    if (count > maxcount) {
        res.clear();
        res.push_back(root->val);
        maxcount = count;}
    else if (count == maxcount)
        res.push_back(root->val);
    prenode = root;
    findModeBFS(root->right, res, prenode, count, maxcount);
    return;
}

vector<int> findMode(TreeNode* root) {
    vector<int> res;
    TreeNode* prenode = nullptr;
    int maxcount = 0;
    int count = 0;
    findModeBFS(root, res, prenode, count, maxcount);
    return res;
}

void Test_findMode()
{
    /*       0
    *       / \
    *      1   2
    *     /\   /\
    *    3  4 5  6
    */
    TreeNode* root = new TreeNode(1);
    TreeNode* r1 = new TreeNode(2); root->right = r1;
    TreeNode* l13 = new TreeNode(2); TreeNode* r13 = new TreeNode(3); r1->left = l13; r1->right = r13;
    vector<int> res = findMode(root);
    printVector(res);
}



TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == p || root == q || root==nullptr)
        return root;
    TreeNode* leftn = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightn = lowestCommonAncestor(root->right, p, q);
    if (leftn != nullptr && rightn != nullptr)
        return root;
    else if (leftn != nullptr && rightn == nullptr)
        return leftn;
    else if (leftn == nullptr && rightn != nullptr)
        return rightn;
    else 
        return nullptr;
}

void Test_lowestCommonAncestor()
{
    TreeNode* root = createSampleTreeNode();
    TreeNode* res = lowestCommonAncestor(root, root->left->left, root->left->right);
    cout << res->val << endl;
}

TreeNode* lowestCommonAncestor_searchTree(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root->val < p->val && root->val < q->val)
        return lowestCommonAncestor(root->right, p, q);
    else if (root->val > p->val && root->val > q->val)
        return lowestCommonAncestor(root->left, p, q);
    return root;
}

void Test_lowestCommonAncestor_searchTree()
{
    TreeNode* root = new TreeNode(6);
    TreeNode* l1 = new TreeNode(2); TreeNode* r1 = new TreeNode(8); root->left = l1; root->right = r1;
    TreeNode* l12 = new TreeNode(0); TreeNode* r12 = new TreeNode(4); l1->left = l12; l1->right = r12;
    TreeNode* l13 = new TreeNode(7); TreeNode* r13 = new TreeNode(9); r1->left = l13; r1->right = r13;
    TreeNode* res = lowestCommonAncestor_searchTree(root, root->left->right, root->right->left);
    cout <<"res: " << res->val << endl;
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) {
        TreeNode* node = new TreeNode(val);
        return node;
    }

    if (val > root->val)
        root->right = insertIntoBST(root->right, val);
    else if (val < root->val)
        root->left = insertIntoBST(root->left, val);
    return root;
}

void Test_insertIntoBST()
{
    TreeNode* root = new TreeNode(6);
    TreeNode* l1 = new TreeNode(2); TreeNode* r1 = new TreeNode(8); root->left = l1; root->right = r1;
    TreeNode* l12 = new TreeNode(0); TreeNode* r12 = new TreeNode(4); l1->left = l12; l1->right = r12;
    TreeNode* l13 = new TreeNode(7); TreeNode* r13 = new TreeNode(9); r1->left = l13; r1->right = r13;
    TreeNode* res = insertIntoBST(root, 11);
    vector<vector<int>> restree = levelOrder(root);
    printVectorOfVector(restree);
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr)
        return root;
    else if (root->val == key)
    {
        if (root->left == nullptr && root->right == nullptr) {
            delete root; return nullptr;
        }
        else if (root->left == nullptr && root->right != nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }else if (root->left != nullptr && root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        else {
            TreeNode* cur = root->right;
            while (cur->left!=nullptr)
                cur = cur->left;
            cur->left = root->left;
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
    }

    if (root->val > key)
        root->left = deleteNode(root->left, key);
    else if (root->val < key)
        root->right = deleteNode(root->right, key);
    return root;
}

void Test_deleteNode()
{
    TreeNode* root = new TreeNode(6);
    TreeNode* l1 = new TreeNode(2); TreeNode* r1 = new TreeNode(8); root->left = l1; root->right = r1;
    TreeNode* l12 = new TreeNode(0); TreeNode* r12 = new TreeNode(4); l1->left = l12; l1->right = r12;
    TreeNode* l13 = new TreeNode(7); TreeNode* r13 = new TreeNode(9); r1->left = l13; r1->right = r13;
    TreeNode* res = deleteNode(root, 7);
    vector<vector<int>> restree = levelOrder(res);
    printVectorOfVector(restree);
}

TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (root == nullptr) return root;
    if (root->val > high) return trimBST(root->left, low, high);
    if (root->val < low) return trimBST(root->right, low, high);
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}

void Test_trimBST()
{
    TreeNode* root = new TreeNode(6);
    TreeNode* l1 = new TreeNode(2); TreeNode* r1 = new TreeNode(8); root->left = l1; root->right = r1;
    TreeNode* l12 = new TreeNode(0); TreeNode* r12 = new TreeNode(4); l1->left = l12; l1->right = r12;
    TreeNode* l13 = new TreeNode(7); TreeNode* r13 = new TreeNode(9); r1->left = l13; r1->right = r13;
    TreeNode* res = trimBST(root, 2, 8);
    vector<vector<int>> restree = levelOrder(res);
    printVectorOfVector(restree);
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    int n = nums.size();
    if (n == 0)
        return nullptr;
    int mid = n / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    vector<int> leftnums(nums.begin(), nums.begin() + mid);
    root->left = sortedArrayToBST(leftnums);

    vector<int> rightnums(nums.begin() + mid + 1, nums.end());
    root->right = sortedArrayToBST(rightnums);
    return root;
}

void Test_sortedArrayToBST()
{
    vector<int> nums;
    int num;
    cout << "\ninput array" << endl;
    while (cin >> num) {
        if (cin.peek() == '\n')
            break;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    TreeNode* root = sortedArrayToBST(nums);
    vector<vector<int>> restree = levelOrder(root);
    printVectorOfVector(restree);
}

int presum_convertBST = 0;
TreeNode* convertBST(TreeNode* root) {
    if (root == nullptr)
        return root;
    root->right = convertBST(root->right);
    root->val += presum_convertBST;
    presum_convertBST = root->val;
    root->left = convertBST(root->left);
    return root;
}

void Test_convertBST()
{
    vector<int> nums;
    int num;
    cout << "\ninput array" << endl;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    sort(nums.begin(), nums.end());
    TreeNode* root = sortedArrayToBST(nums);
    TreeNode* res = convertBST(root);
    vector<vector<int>> restree = levelOrder(root);
    printVectorOfVector(restree);
}

void combine_dfs(vector<vector<int>>& res, vector<int>& path, int n, int k, int staridx) {
    if (path.size() == k) {
        res.push_back(path);
        return;
    }
    for (int i = staridx; i <= n; i++)
    {
        path.push_back(i);
        combine_dfs(res, path, n, k, i+1);
        path.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> path;
    combine_dfs(res, path, n, k, 1);
    return res;
}

void Test_combine()
{
    int n, k;
    cout << "input n, k :" << endl;
    cin >> n >> k;
    vector<vector<int>> res = combine(n, k);
    cout << endl;
    printVectorOfVector(res);
}

void combinationSum3_dfs(vector<vector<int>>& res, vector<int>& path, int k,
    int n, int star) {
    if (n == 0 && path.size() == k) {
        res.push_back(path);
        return;
    }
    for (int i = star; i <= 9; i++) {
        if (n - i < 0)
            break;
        path.push_back(i);
        int num = n - i;
        combinationSum3_dfs(res, path, k, num, i + 1);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> path;
    combinationSum3_dfs(res, path, k, n, 1);
    return res;
}

void Test_combinationSum3()
{
    int n, k;
    cout << "input n, k :" << endl;
    cin >> n >> k;
    vector<vector<int>> res = combinationSum3(n, k);
    cout << endl;
    printVectorOfVector(res);
}

unordered_map<char, string> phoneNum = {
    {'1', ""},    {'2', "abc"},  {'3', "def"}, {'4', "ghi"},  {'5', "jkl"},
    {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}, {'0', ""} };

void letterCombinations_dfs(string digits, vector<string>& res,
    string& path) {
    if (path.size() == digits.size()) {
        res.push_back(path);
        return;
    }
    int n = path.size();
    for (char c : phoneNum[digits[n]]) {
        path += c;
        letterCombinations_dfs(digits, res, path);
        path.resize(n);
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> res;
    if (digits.empty())
        return res;
    string path;
    letterCombinations_dfs(digits, res, path);
    return res;
}

void Test_letterCombinations()
{
    string input;
    cout << "input phone num:" << endl;
    cin >> input;
    vector<string> res = letterCombinations(input);
    printVector(res);
}

void combinationSum_dfs(vector<int>& candidates, int target,
    vector<vector<int>>& res, vector<int>& path, int idx) {
    if (target == 0) {
        res.push_back(path);
        return;
    }
    for (int i = idx; i < candidates.size(); i++) {
        if (target - candidates[i] < 0)
            break;
        path.push_back(candidates[i]);
        combinationSum_dfs(candidates, (target - candidates[i]), res, path, i);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> path;
    combinationSum_dfs(candidates, target, res, path, 0);
    return res;
}

void Test_combinationSum()
{
    vector<int> nums;
    int num;
    cout << "\ninput array" << endl;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    cout << "\ninput target" << endl;
    int target;
    cin >> target;
    vector<vector<int>> res = combinationSum(nums, target);
    printVectorOfVector(res);
}

void combinationSum2_dfs(vector<int>& candidates, int target,
    vector<vector<int>>& res, vector<int>& path,
    int idx) {
    if (target == 0) {
        res.push_back(path);
        return;
    }
    for (int i = idx; i < candidates.size(); i++) {
        if (target - candidates[i] < 0)
            break;
        if (i > idx && candidates[i] == candidates[i - 1])
            continue;
        path.push_back(candidates[i]);
        combinationSum2_dfs(candidates, (target - candidates[i]), res, path,
            i + 1);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> path;
    combinationSum2_dfs(candidates, target, res, path, 0);
    return res;
}

void Test_combinationSum2()
{
    vector<int> nums;
    int num;
    cout << "\ninput array" << endl;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    cout << "\ninput target" << endl;
    int target;
    cin >> target;
    vector<vector<int>> res = combinationSum2(nums, target);
    printVectorOfVector(res);
}

bool partition_if(const string& s) {
    int left = 0, right = s.size() - 1;
    while (left <= right) {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

void partition_dfs(string s, vector<vector<string>>& res,
    vector<string>& path, int idx) {
    if (idx == s.size()) {
        res.push_back(path);
        return;
    }
    for (int i = idx; i < s.size(); i++) {
        string temp = s.substr(idx, i - idx + 1);
        if (partition_if(temp)) {
            path.push_back(temp);
            partition_dfs(s, res, path, i + 1);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> path;
    partition_dfs(s, res, path, 0);
    return res;
}

void Test_partition()
{
    string res;
    cout << "input string" << endl;
    cin >> res;
    vector<vector<string>> resstr = partition(res);
    printVectorOfVector(resstr);
}

bool isvalid_IP(const string& temp) {
    if (temp.empty() || temp.size() > 3) return false;
    if (temp.size() >= 2 && temp[0] == '0') return false; // 处理前导零
    int num = 0;
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] > '9' || temp[i] < '0') { return false; }
        num = num * 10 + (temp[i] - '0');
        if (num > 255) { return false; }
    }
    return true;
}

void restoreIpAddresses_dfs(const string& s, vector<string>& res, string& path,
    int times, int staridx) {
    if (times == 4 && staridx == s.size()) {
        res.push_back(path);
        return;
    }

    for (int i = staridx; i < s.size(); i++) {
        string temp = s.substr(staridx, i - staridx + 1);
        if (isvalid_IP(temp)) {
            int n = path.size();
            path += temp;
            if (times < 3) {
                path += '.';
            }
            restoreIpAddresses_dfs(s, res, path, times + 1, i + 1);
            path.resize(n);
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    string path;
    restoreIpAddresses_dfs(s, res, path, 0, 0);
    return res;
}

void Test_restoreIpAddresses()
{
    string res;
    cout << "input string" << endl;
    cin >> res;
    vector<string> resstr = restoreIpAddresses(res);
    printVector(resstr);

}

void subsets_dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, int start)
{
    res.push_back(path);
    for (int i = start; i < nums.size(); i++)
    {
        path.push_back(nums[i]);
        subsets_dfs(nums, res, path, i+1);
        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    subsets_dfs(nums, res, path,0);
    return res;
}

void Test_subsets()
{
    vector<int> nums;
    int num;
    cout << "\ninput array" << endl;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    vector<vector<int>> res = subsets(nums);
    printVectorOfVector(res);
}

void subsetsWithDup_dfs(vector<vector<int>>& res, vector<int>& path,
    vector<int>& nums, int start) {
    res.push_back(path);
    for (int i = start; i < nums.size(); i++) {
        if (i > start && nums[i] == nums[i - 1])
            continue;
        path.push_back(nums[i]);
        subsetsWithDup_dfs(res, path, nums, i + 1);
        path.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> path;
    subsetsWithDup_dfs(res, path, nums, 0);
    return res;
}

void Test_subsetsWithDup()
{
    vector<int> nums;
    int num;
    cout << "\ninput array" << endl;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    vector<vector<int>> res = subsetsWithDup(nums);
    printVectorOfVector(res);
}

void findSubsequences_dfs2(vector<vector<int>>& res, vector<int>& path,
    vector<int>& nums, int star) {
    if (path.size() >= 2)
        res.push_back(path);
    unordered_set<int> used;
    for (int i = star; i < nums.size(); i++) {
        if (!path.empty() && nums[i] < path.back())
            continue;
        if (used.count(nums[i]))
            continue;
        path.push_back(nums[i]);
        used.insert(nums[i]);
        findSubsequences_dfs2(res, path, nums, i + 1);
        path.pop_back();
    }
}

vector<vector<int>> findSubsequences2(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    findSubsequences_dfs2(res, path, nums, 0);
    return res;
}

void Test_subsetsWithDup2()
{
    vector<int> nums;
    int num;
    cout << "\ninput array" << endl;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    vector<vector<int>> res = findSubsequences2(nums);
    printVectorOfVector(res);
}

void permute_dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, vector<bool>& visited) {
    if (path.size() == nums.size())
    {
        res.push_back(path); 
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (visited[i] == true)
            continue;
        path.push_back(nums[i]);
        visited[i] = true;
        permute_dfs(nums, res, path, visited);
        path.pop_back();
        visited[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> visited(nums.size(), false);
    permute_dfs(nums, res, path, visited);
    return res;
}

void Test_permute()
{
    vector<int> nums;
    int num;
    cout << "\ninput array" << endl;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    vector<vector<int>> res = permute(nums);
    printVectorOfVector(res);
}

void permuteUnique_dfs(vector<int>& nums, vector<vector<int>>& res,
    vector<int>& path, vector<bool>& visited) {
    if (path.size() == nums.size()) {
        res.push_back(path);
        return;
    }
    unordered_set<int> used;
    for (int i = 0; i < nums.size(); i++) {
        if (visited[i] == true)
            continue;
        if (used.count(nums[i]))
            continue;
        path.push_back(nums[i]);
        visited[i] = true;
        used.insert(nums[i]);
        permuteUnique_dfs(nums, res, path, visited);
        path.pop_back();
        visited[i] = false;
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> visited(nums.size(), false);
    permuteUnique_dfs(nums, res, path, visited);
    return res;
}

void Test_permuteUnique()
{
    vector<int> nums;
    int num;
    cout << "\ninput array" << endl;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    vector<vector<int>> res = permuteUnique(nums);
    printVectorOfVector(res);
}

bool ifQueen(vector<string>& temp, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (temp[i][col] == 'Q')
            return false;
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (temp[i][j] == 'Q')
            return false;
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < temp.size();
        i--, j++) {
        if (temp[i][j] == 'Q')
            return false;
    }
    return true;
}

void find(vector<vector<string>>& res, vector<string>& temp, int row) {
    if (row == temp.size()) {
        res.push_back(temp);
        return;
    }
    for (int j = 0; j < temp.size(); j++) {
        temp[row][j] = 'Q';
        if (ifQueen(temp, row, j)) {
            find(res, temp, row + 1);
        }
        temp[row][j] = '.';
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> temp(n, string(n, '.'));
    find(res, temp, 0);
    return res;
}

void Test_solveNQueens() {
    cout << "input n:" << endl;
    int n;
    cin >> n;
    vector<vector<string>> res = solveNQueens(n);
    printVectorOfVector(res);
}

bool if_solveSudoku(vector<vector<char>>& board, int x, int y, char c)
{
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i][y] == c)
            return false;
    }
    for (int j = 0; j < board[0].size(); j++)
    {
        if (board[x][j] == c)
            return false;
    }
    int starx = (x / 3) * 3;
    int stary = (y / 3) * 3;
    for (int i = starx; i < starx + 3; i++)
    {
        for (int j = stary; j < stary + 3; j++)
        {
            if (board[i][j] == c)
                return false;
        }
    }
    return true;
}

bool find_solveSudoku(vector<vector<char>>& board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (if_solveSudoku(board, i, j, c))
                    {
                        board[i][j] = c;
                        if (find_solveSudoku(board))
                            return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    find_solveSudoku(board);
}

void Test_solveSudoku()
{
    vector<vector<char>> board = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    solveSudoku(board);
    printVectorOfVector(board);
}

int findContentChildren(vector<int>& g, vector<int>& s) {
    if (g.empty() || s.empty())
        return 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int res = 0;
    int p = s.size() - 1;
    for (int i = g.size() - 1; i >= 0 && p >= 0; i--) {
        if (g[i] <= s[p]) {
            res++;
            p--;
        }
    }
    return res;
}

void Test_findContentChildren()
{
    vector<int> nums1;
    vector<int> nums2;
    int num;
    cout << "\ninput array1" << endl;
    while (cin >> num) {
        nums1.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    cout << "\ninput array2" << endl;
    while (cin >> num) {
        nums2.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    int res = findContentChildren(nums1, nums2);
    cout << res << endl;
}

int wiggleMaxLength(vector<int>& nums) {
    vector<vector<int>> dp(nums.size(), vector<int>(2,0));
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[i - 1]) {//升
            dp[i][0] = dp[i-1][1]+1;//升序列
            dp[i][1] = dp[i-1][1];//降序列
        }
        else if (nums[i] < nums[i - 1]) {//降
            dp[i][0] = dp[i-1][0];//升序列
            dp[i][1] = dp[i - 1][0]+1;//降序列
        }
        else {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
        }
    }
    return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1])+1;
}

int wiggleMaxLength2(vector<int>& nums) {
    int res = 1;
    int p_diff = 0;
    int c_diff = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        c_diff = nums[i] - nums[i-1];
        if ((c_diff > 0 && p_diff <= 0) || (c_diff < 0 && p_diff >= 0))
        {
            res++;
            p_diff = c_diff;
        }
    }
    return res;
}

void Test_wiggleMaxLength()
{
    vector<int> nums;
    int num;
    cout << "\ninput array1" << endl;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    int res = wiggleMaxLength(nums);
    cout << res << endl;
}

int maxSubArray(vector<int>& nums) {
    int sum = 0;
    int res = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        res = max(res, sum);
        if (sum < 0)
            sum = 0;
    }
    return res;
}

int maxSubArray2(vector<int>& nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = max(nums[i], dp[i - 1] + nums[i]);
    }
    int res = INT_MIN;
    for (int num : dp)
        res = max(res, num);
    return res;
}

int maxSubArray_DP(vector<int>& nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int res = dp[0];
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        res = max(res, dp[i]);
    }
    return res;
}


void Test_maxSubArray()
{
    vector<int> nums;
    int num;
    cout << "input array:" << endl;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    int res = maxSubArray(nums);
    cout << "res:" << res << endl;
}

int maxProfit(vector<int>& prices) {
    int res = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > prices[i - 1])
        {
            res += (prices[i] - prices[i - 1]);
        }
    }
    return res;
}

int maxProfit2(vector<int>& prices) {
    if (prices.size() <= 1)
        return 0;
    vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
    dp[0][0] = 0;//没有
    dp[0][1] = -prices[0];//有
    for (int i = 1; i < prices.size(); i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp[prices.size() - 1][0];
}

void Test_maxProfit()
{
    vector<int> nums;
    int num;
    cout << "input array:" << endl;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    int res = maxProfit(nums);
    cout << "res:" << res << endl;
}

bool canJump(vector<int>& nums) {
    int maxval = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        maxval = max(maxval, i + nums[i]);
        if (maxval <= i)
            return false;
    }
    return true;
}

void Test_canJump()
{
    vector<int> nums;
    int num;
    cout << "input array:" << endl;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    bool res = canJump(nums);
    string resstr = (res == true) ? "TRUE" : "FALSE";
    cout << resstr << endl;
}

int jump(vector<int>& nums) {
    int maxval = 0;
    int res = 0;
    int curdis = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        maxval = max(maxval, nums[i] + i);
        if (curdis <= i) {
            curdis = maxval;
            res++;
        }
    }
    return res;
}

void Test_jump()
{
    vector<int> nums;
    int num;
    cout << "input array:" << endl;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    int res = jump(nums);
    cout << "Res:" << res << endl;
}

int largestSumAfterKNegations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end(),
        [](int a, int b) { return abs(a) > abs(b); });
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < 0 && k > 0) {
            nums[i] *= -1;
            k--;
        }
    }
    if (k % 2 == 1)
        nums[nums.size() - 1] *= -1;
    int res = 0;
    for (int num : nums)
        res += num;
    return res;
}

void Test_largestSumAfterKNegations()
{
    vector<int> nums;
    int num;
    cout << "input array:" << endl;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    int target;
    cout << "input target:" << endl;
    cin >> target;
    int res = largestSumAfterKNegations(nums, target);
    cout << "Res: " << res << endl;
}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    vector<int> diff(gas.size());
    int sum = 0;
    for (int i = 0; i < gas.size(); i++) {
        diff[i] = gas[i] - cost[i];
        sum += diff[i];
    }
    if (sum < 0)
        return -1;
    int sum2 = 0;
    int res = 0;
    for (int i = 0; i < diff.size(); i++)
    {
        sum2 += diff[i];
        if (sum2 < 0)
        {
            sum2 = 0;
            res = i + 1;
        }
    }
    return res;
}

void Test_canCompleteCircuit()
{
    vector<int> nums1;
    vector<int> nums2;
    int num;
    cout << "\ninput array1" << endl;
    while (cin >> num) {
        nums1.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    cout << "\ninput array2" << endl;
    while (cin >> num) {
        nums2.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    int res = canCompleteCircuit(nums1, nums2);
    cout << "Res:" << res << endl;
}

int candy(vector<int>& ratings) {
    vector<int> candy(ratings.size(), 1);
    for (int i = 1; i < ratings.size(); i++) {
        if (ratings[i] > ratings[i - 1])
            candy[i] = candy[i - 1] + 1;
    }
    for (int i = ratings.size() - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1])
            candy[i] = candy[i + 1] + 1;
    }
    int res = 0;
    for (int num : candy)
        res += num;
    return res;
}

void Test_candy()
{
    vector<int> nums;
    int num;
    cout << "input array:" << endl;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    int res = candy(nums);
    cout << "\nRes:" << res << endl;
}

bool lemonadeChange(vector<int>& bills) {
    unordered_map<int, int> record;
    record[5] = 0;
    record[10] = 0;
    record[20] = 0;
    for (int bill : bills)
    {
        if (bill == 5)
            record[5]++;
        else if (bill == 10)
        {
            if (record[5] > 0)
            {
                record[5]--;
                record[10]++;
            }
            else {
                return false;
            }
        }
        else if (bill == 20)
        {
            if (record[5] > 0 && record[10]>0)
            {
                record[5]--;
                record[10]--;
                record[20]++;
            }
            else if (record[5] >= 3)
            {
                record[5] -= 3;
                record[20]++;
            }
            else {
                return false;
            }
        }
    }
    return true;
}

void Test_lemonadeChange()
{
    vector<int> nums;
    int num;
    cout << "input array:" << endl;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    bool res = lemonadeChange(nums);
    string resstr = (res == true) ? "TRUE" : "FALSE";
    cout << resstr << endl;
}

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](vector<int>&a, vector<int>&b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    });
    vector<vector<int>> que;
    for (int i = 0; i<people.size(); i++)
    {
        int position = people[i][1];
        que.insert(que.begin() + position, people[i]);
    }
    return que;
}

void Test_reconstructQueue()
{
    int m;
    cout << "input row" << endl;
    cin >> m;
    cout << "\ninput num" << endl;
    vector<vector<int>> nums(m,vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> nums[i][j];
        }
    }
    cout << "\nres:" << endl;
    vector<vector<int>> res = reconstructQueue(nums);
    printVectorOfVector(res);
}

int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {return a[1] < b[1]; });
    int res = 1;
    int end = points[0][1];
    for (int i = 1; i < points.size(); i++)
    {
        if (points[i][0] > end)
        {
            res++;
            end = points[i][1];
        }
    }
    return res;
}

void Test_findMinArrowShots()
{
    int m;
    cout << "input row" << endl;
    cin >> m;
    cout << "\ninput num" << endl;
    vector<vector<int>> nums(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> nums[i][j];
        }
    }
    int res = findMinArrowShots(nums);
    cout << "\nres:" << res << endl;
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {return a[1] < b[1]; });
    int res = 1;
    int end = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] >= end)
        {
            res++;
            end = intervals[i][1];
        }
    }
    return intervals.size()-res;
}

void Test_eraseOverlapIntervals()
{
    int m;
    cout << "input row" << endl;
    cin >> m;
    cout << "\ninput num" << endl;
    vector<vector<int>> nums(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> nums[i][j];
        }
    }
    int res = eraseOverlapIntervals(nums);
    cout << "\nres:" << res << endl;
}

vector<int> partitionLabels(string s) {
    unordered_map<char, int> record;
    for (int i = 0; i < s.size(); i++) {
        record[s[i]] = i;
    }

    vector<int> res;
    int start = 0;
    int maxval = INT_MIN;
    for (int i = 0; i < s.size(); i++) {
        maxval = max(maxval, record[s[i]]);
        if (i == maxval) {
            res.push_back(maxval - start + 1);
            start = i + 1;
        }
    }
    return res;
}

void Test_partitionLabels()
{
    string s;
    cout << "input string: " << endl;
    cin >> s;
    vector<int> res = partitionLabels(s);
    printVector(res);
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {return a[0] < b[0]; });
    vector<vector<int>> res;
    int start = intervals[0][0];
    int end = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] > end) {
            res.push_back({ start, end });
            start = intervals[i][0];
            end = intervals[i][1];
        }
        else {
            end = max(end, intervals[i][1]);
        }
    }res.push_back({ start,end });
    return res;
}

void Test_merge()
{
    int m;
    cout << "input row" << endl;
    cin >> m;
    cout << "\ninput num" << endl;
    vector<vector<int>> nums(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> nums[i][j];
        }
    }
    cout << "\nRes:" << endl;
    vector<vector<int>> res = merge(nums);
    printVectorOfVector(res);
}

int monotoneIncreasingDigits(int n) {
    if (n < 10)
        return n;
    string num = to_string(n);
    int flag = num.size();
    for (int i = num.size() - 2; i >= 0; i--)
    {
        if (num[i] > num[i + 1])
        {
            flag = i+1;
            num[i]--;
        }
    }
    for (int i = flag; i < num.size(); i++)
        num[i] = '9';
    return stoi(num);
}

void Test_monotoneIncreasingDigits()
{
    int num;
    cout << "input num" << endl;
    cin >> num;
    int res = monotoneIncreasingDigits(num);
    cout << "\nRes:" << res <<endl;
}

int fib(int n) {
    if (n == 0 || n == 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

void Test_fib() {
    int num;
    cout << "input num:" << endl;
    cin >> num;
    int res = fib(num);
    cout << "Res: " << res << endl;;
}

int climbStairs(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

void Test_climbStairs()
{
    int num;
    cout << "input num:" << endl;
    cin >> num;
    int res = climbStairs(num);
    cout << "Res: " << res << endl;;
}

int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size() + 1);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= cost.size(); i++)
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    return dp[cost.size()];
}

void Test_minCostClimbingStairs()
{
    vector<int> nums;
    int num;
    cout << "input array:" << endl;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    int res = minCostClimbingStairs(nums);
    cout << "Res: " << res << endl;
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
        dp[i][0] = 1;
    for (int j = 0; j < n; j++)
        dp[0][j] = 1;
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
    return dp[m - 1][n - 1];
}

void Test_uniquePaths()
{
    int m, n;
    cout << "input m, n: " << endl;
    cin >> m >> n;
    int res = uniquePaths(m, n);
    cout << "Res: " << res << endl;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
    for (int i = 0; i < dp.size(); i++)
    {
        if (obstacleGrid[i][0] == 0)
            dp[i][0] = 1;
        else
            break;
    }
    for (int j = 0; j < dp[0].size(); j++)
    {
        if (obstacleGrid[0][j] == 0)
            dp[0][j] = 1;
        else
            break;
    }
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            if (obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
            else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
}

void Test_uniquePathsWithObstacles()
{
    int m, n;
    cout << "input row, col" << endl;
    cin >> m >> n;
    cout << "\ninput num" << endl;
    vector<vector<int>> nums(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> nums[i][j];
        }
    }
    int res = uniquePathsWithObstacles(nums);
    cout << "\nRes: " << res << endl;
}

int integerBreak(int n) {
    vector<int> dp(n + 1);
    dp[2] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i-1; j++)
        {
            dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
        }
    }return dp[n];
}

void Test_integerBreak()
{
    int num;
    cout << "input num:" << endl;
    cin >> num;
    int res = integerBreak(num);
    cout << "Res："<< res << endl;
}

int numTrees(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            dp[i] += dp[j-1] * dp[i-j];
    }
    return dp[n];
}

void Test_numTrees() {
    int num;
    cout << "input num:" << endl;
    cin >> num;
    int res = numTrees(num);
    cout << "Res：" << res << endl;
}

int bag01(vector<int> weights, vector<int> value, int size)
{
    vector<vector<int>> dp(weights.size(), vector<int>(size + 1, 0));
    for (int j = weights[0]; j <= size; j++)
        dp[0][j] = value[0];
    for (int i = 1; i < weights.size(); i++)
    {
        for (int j = 0; j <= size; j++)
        {
            if (j < weights[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i]]+value[i]);
        }
    }
    return dp[weights.size() - 1][size];
}

void Test_bag01()
{
    int n, bagweight;
    cout << "input n, bagsize:" << endl;
    cin >> n >> bagweight;
    vector<int> weight(n, 0); 
    vector<int> value(n, 0);  
    cout << "\ninput weights:" << endl;
    for (int i = 0; i < n; ++i) 
        cin >> weight[i];
    cout << "\ninput values:" << endl;
    for (int j = 0; j < n; ++j)
        cin >> value[j];
    int res = bag01(weight, value, bagweight);
    cout << "\nRes：" << res << endl;
}

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int num : nums)
        sum += num;
    if (sum % 2 == 1)
        return false;
    sum /= 2;
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j <= sum; j++) {
            if (j < nums[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
        }
    }
    return dp[n - 1][sum];
}

bool canPartition2(vector<int>& nums) {
    int sum = 0;
    for (int num : nums)
        sum += num;
    if (sum % 2 == 1)
        return false;
    sum /= 2;
    vector<bool> dp(sum+1, false);
    dp[0] = true;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = sum; j >= nums[i]; j--)
        {
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }
    return dp[sum];
}

void Test_canPartition()
{
    vector<int> nums;
    int num;
    cout << "input array:" << endl;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    bool res = canPartition(nums);
    string resstr = (res == true) ? "TRUE" : "FALSE";
    cout << resstr << endl;
}

int lastStoneWeightII(vector<int>& stones) {
    int sum = 0;
    for (int stone : stones)
        sum += stone;
    int target = sum / 2;
    vector<int> dp(target + 1, 0);
    for (int stone : stones)
    {
        for (int j = target; j >= stone; j--)
        {
            dp[j] = max(dp[j], dp[j - stone] + stone);
        }
    }
    return (sum - dp[target]) - dp[target];
}

int lastStoneWeightII2(vector<int>& stones) {
    int sum = 0;
    for (int stone : stones)
        sum += stone;
    int target = sum / 2;
    vector<vector<int>> dp(stones.size(), vector<int>(target + 1, 0));
    for (int j = stones[0]; j <= target; j++)
        dp[0][j] = stones[0];
    for (int i = 1; i<stones.size(); i++)
    {
        for (int j = 0; j<=target; j++)
        {
            if (j < stones[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]]+stones[i]);
        }
    }
    return (sum - dp[stones.size()-1][target]) - dp[stones.size() - 1][target];
}

void Test_lastStoneWeightII()
{
    vector<int> nums;
    int num;
    cout << "input array:" << endl;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    int res = lastStoneWeightII(nums);
    cout << "\nRes：" << res << endl;
}

int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for (int num : nums)
        sum += num;
    if (abs(target) > sum||(target+sum)%2==1)
        return 0;
    int bagsize = (target + sum) / 2;
    vector<int> dp(bagsize + 1, 0);
    dp[0] = 1;
    for (int num : nums)
    {
        for (int j = bagsize; j >= num; j--)
            dp[j] = dp[j] + dp[j - num];
    }
    return dp[bagsize];
}

void Test_findTargetSumWays()
{
    vector<int> nums;
    int num;
    cout << "input array:" << endl;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    int target;
    cout << "\ninput target:" << endl;
    cin >> target;
    int res = findTargetSumWays(nums, target);
    cout << "\nRes: " << res << endl;
}

int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (string str : strs)
    {
        int zeronum = 0, onenum = 0;
        for (char c : str)
        {
            if (c == '0')
                zeronum++;
            else
                onenum++;
        }

        for (int i = m; i >= zeronum; i--)
        {
            for (int j = n; j >= onenum; j--)
            {
                dp[i][j] = max(dp[i][j], dp[i - zeronum][j - onenum] + 1);
            }
        }
    }
    return dp[m][n];
}

void Test_findMaxForm()
{
    int strsnum;
    cout << "\ninput strings num:" << endl;
    cin >> strsnum;
    vector<string> strs;
    cout << "\ninput string:" << endl;
    string str;
    for (int i = 0; i < strsnum; i++)
    {
        cin >> str;
        strs.push_back(str);
    }
    int m, n;
    cout << "\ninput m, n:" << endl;
    cin >> m >> n;
    int res = findMaxForm(strs, m, n);
    cout << "Res:" << res << endl;
}

int bag_multi(vector<int>& weights, vector<int>& values, int bagsize)
{
    vector<vector<int>> dp(values.size(), vector<int>(bagsize+1, 0));
    for (int j = weights[0]; j <= bagsize; j++) {
        dp[0][j] = dp[0][j - weights[0]] + values[0];
    }
    for (int i = 1; i < values.size(); i++)
    {
        for (int j = 0; j <= bagsize; j++)
        {
            if (j < weights[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - weights[i]] + values[i]);
        }
    }
    return dp[values.size() - 1][bagsize];
}

int bag_multi2(vector<int>& weights, vector<int>& values, int bagsize)
{
    vector<int> dp(bagsize + 1, 0);
    for (int i = 0; i < values.size(); i++)
    {
        for (int j = weights[i]; j <= bagsize; j++)
        {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }
    return dp[bagsize];
}

void Test_bag_multi()
{
    int n, bagsize;
    cout << "input types and weight:" << endl;
    cin >> n >> bagsize;
    vector<int> weights(n, 0);
    vector<int> values(n, 0);
    cout << "\ninput weight and value:" << endl;
    for (int i = 0; i < n; i++)
    {
        int weight, value;
        cin >> weight >> value;
        weights[i] = weight;
        values[i] = value;
    }
    int res = bag_multi2(weights, values, bagsize);
    cout << "\nRes: " << res << endl;
}

int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < coins.size(); i++) {
        for (int j = coins[i]; j <= amount; j++) {
            if (dp[j] < INT_MAX - dp[j - coins[i]])
                dp[j] = dp[j] + dp[j - coins[i]];
        }
    }
    return dp[amount];
}

int change2(int amount, vector<int>& coins) {
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));
    for (int i = 0; i < coins.size(); i++)
        dp[i][0] = 1;
    for (int j = coins[0]; j <= amount; j++)
    {
        dp[0][j] += dp[0][j - coins[0]];
    }
    for (int i = 1; i < coins.size(); i++) {
        for (int j = 0; j <= amount; j++) {
            if (j < coins[i])
                dp[i][j] = dp[i - 1][j];
            else if (dp[i - 1][j] < INT_MAX - dp[i][j - coins[i]])
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
        }
    }
    return dp[coins.size() - 1][amount];
}

void Test_change()
{
    vector<int> nums;
    int num;
    cout << "input array:" << endl;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    int target;
    cout << "\ninput target:" << endl;
    cin >> target;
    int res = change(target, nums);
    cout << "\nRes: " << res << endl;
}

int combinationSum4(vector<int>& nums, int target) {
    vector<long long> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= target; i++) { // 遍历背包
        for (int j = 0; j < nums.size(); j++) { // 遍历物品
            if (i - nums[j] >= 0 && dp[i] < LLONG_MAX - dp[i - nums[j]]) {
                dp[i] += dp[i - nums[j]];
            }
        }
    }
    return dp[target];
}

void Test_combinationSum4()
{
    vector<int> nums;
    int num;
    cout << "input array:" << endl;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    int target;
    cout << "\ninput target:" << endl;
    cin >> target;
    int res = combinationSum4(nums,target);
    cout << "\nRes: " << res << endl;
}

int climbstairs2(int n, int m) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(i-j>=0)
                dp[i] += dp[i - j];
        }
    }
    return dp[n];
}

void Test_climbstairs2()
{
    int m, n;
    cout << "inuput n, m:"<<endl;
    cin >> n >> m;
    int res = climbstairs2(n, m);
    cout << "\nRes: " << res << endl;
}

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 0; i < coins.size(); i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }
    return dp[amount] == (amount + 1) ? -1 : dp[amount];
}

void Test_coinChange() {
    vector<int> nums;
    int num;
    cout << "input array:" << endl;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    int target;
    cout << "\ninput target:" << endl;
    cin >> target;
    int res = coinChange(nums, target);
    cout << "\nRes: " << res << endl;
}

int numSquares(int n) {
    vector<int> dp(n + 1, n + 1);
    dp[0] = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        for (int j = 1; j <= n; j++) {
            int num = j - i * i;
            if (num >= 0)
                dp[j] = min(dp[j], dp[num] + 1);
        }
    }
    return dp[n] == (n + 1) ? -1 : dp[n];
}

void Test_numSquares()
{
    int target;
    cout << "\ninput target:" << endl;
    cin >> target;
    int res = numSquares(target);
    cout << "\nRes: " << res << endl;
}

bool wordBreak(string s, vector<string>& wordDict) {
    vector<int> dp(s.size() + 1, false);
    dp[0] = true;
    unordered_set<string> set(wordDict.begin(), wordDict.end());
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j < i; j++) {
            string temp = s.substr(j, i - j);
            if (set.count(temp)&&dp[j]==true)
                dp[i] = true;
        }
    }
    return dp[s.size()];
}

void Test_wordBreak() {
    string s;
    cout << "input target string:" << endl;
    cin >> s;
    vector<string> wordDict;
    string temp;
    cout << "\ninput next strings:" << endl;
    while (cin >> temp) {
        wordDict.push_back(temp);
        if (cin.peek() == '\n')
            break;
    }
    bool res = wordBreak(s, wordDict);
    string resstr = (res == true) ? "TRUE" : "FALSE";
    cout << resstr << endl;
}

int rob(vector<int>& nums) {
    vector<int> dp(nums.size() + 1, 0);
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 2; i <= nums.size(); i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }
    return dp[nums.size()];
}

void Test_rob()
{
    vector<int> nums;
    int num;
    cout << "input array:" << endl;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    int res = rob(nums);
    cout << "\nRes: " << res << endl;
}

int rob2(vector<int>& nums) {
    if (nums.size() <= 1)
        return nums[0];
    vector<int> dp(nums.size() + 1, 0);
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 2; i < nums.size(); i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }

    vector<int> dp2(nums.size() + 1, 0);
    dp2[0] = 0;
    dp2[1] = 0;
    dp2[2] = nums[1];
    for (int i = 3; i <= nums.size(); i++) {
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i - 1]);
    }

    return max(dp[nums.size() - 1], dp2[nums.size()]);
}

void Test_rob2() {
    vector<int> nums;
    int num;
    cout << "input array:" << endl;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    int res = rob2(nums);
    cout << "\nRes: " << res << endl;
}

vector<int> dfs_rob3(TreeNode* root) {
    if (root == nullptr)
        return { 0,0 };
    vector<int> left = dfs_rob3(root->left);
    vector<int> right = dfs_rob3(root->right);
    int rob = root->val + left[1] + right[1];
    int unrob = max(left[0], left[1]) + max(right[0], right[1]);
    return { rob,unrob };
}

int rob3(TreeNode* root) {
    vector<int> res = dfs_rob3(root);
    return max(res[0], res[1]);
}

int maxProfit_2(vector<int>& prices) {
    vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
    dp[0][0] = 0;          // 没有股票
    dp[0][1] = -prices[0]; // 有股票
    for (int i = 1; i < prices.size(); i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp[prices.size() - 1][0];
}

void Test_maxProfit_2() {
    vector<int> nums;
    int num;
    cout << "input array:" << endl;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    int res = maxProfit_2(nums);
    cout << "\nres:" << res << endl;
}

int maxProfit_3(vector<int>& prices) {
    int km = 2;
    vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(km + 1, vector<int>(2, 0)));
    for (int k = 0; k <= km; k++) { // i = 0的时候
        dp[0][k][0] = 0;            // 没有股票
        dp[0][k][1] = -prices[0];   // 有股票
    }
    for (int i = 1; i < prices.size(); i++) {
        for (int k = 1; k <= km; k++) {
            dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
            dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
        }
    }
    return dp[prices.size() - 1][km][0];
}

int maxProfit_4(int k, vector<int>& prices) {
    int km = k;
    vector<vector<vector<int>>> dp(
        prices.size(), vector<vector<int>>(km + 1, vector<int>(2, 0)));
    for (int k = 0; k <= km; k++) { // i = 0的时候
        dp[0][k][0] = 0;            // 没有股票
        dp[0][k][1] = -prices[0];   // 有股票
    }
    for (int i = 1; i < prices.size(); i++) {
        for (int k = 1; k <= km; k++) {
            dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
            dp[i][k][1] =
                max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
        }
    }
    return dp[prices.size() - 1][km][0];
}

void Test_maxProfit_3() {
    vector<int> nums;
    int num;
    cout << "input array:" << endl;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    int res = maxProfit_3(nums);
    cout << "\nres:" << res << endl;
}

int maxProfit_icetime(vector<int>& prices) {
    if (prices.size() <= 1) return 0;
    vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
    dp[0][0] = 0;          // 没有股票
    dp[0][1] = -prices[0]; // 有股票
    dp[1][0] = max(dp[0][0], dp[0][1] + prices[1]);
    dp[1][1] = max(dp[0][1], -prices[1]);
    for (int i = 2; i < prices.size(); i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
    }
    return dp[prices.size() - 1][0];
}

void Test_maxProfit_icetime() {
    vector<int> nums;
    int num;
    cout << "input array:" << endl;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    int res = maxProfit_icetime(nums);
    cout << "\nres:" << res << endl;
}

int maxProfit_fee(vector<int>& prices, int fee) {
    vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
    dp[0][0] = 0;          // 没有股票
    dp[0][1] = -prices[0]-fee; // 有股票
    for (int i = 1; i < prices.size(); i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]-fee);
    }
    return dp[prices.size() - 1][0];
}

void Test_maxProfit_fee() {
    vector<int> nums;
    int num;
    cout << "input array:" << endl;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    int target;
    cout << "\ninput target:" << endl;
    cin >> target;
    int res = maxProfit_fee(nums, target);
    cout << "\nres:" << res << endl;
}

int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    int res = 1;
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }
    return res;
}

void Test_lengthOfLIS()
{
    vector<int> nums;
    int num;
    cout << "input array:" << endl;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    int res = lengthOfLIS(nums);
    cout << "\nres:" << res << endl;
}

int findLengthOfLCIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    int res = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[i - 1])
            dp[i] = dp[i - 1] + 1;
        res = max(res, dp[i]);
    }
    return res;
}

void Test_findLengthOfLCIS() {
    vector<int> nums;
    int num;
    cout << "input array:" << endl;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    int res = findLengthOfLCIS(nums);
    cout << "\nres:" << res << endl;
}

int findLength(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size()+1, 0));
    int res = 0;
    for (int i = 1; i <= nums1.size(); i++)
    {
        for (int j = 1; j <= nums2.size(); j++)
        {
            if (nums1[i-1] == nums2[j-1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            res = max(res, dp[i][j]);
        }
    }
    return res;
}

void Test_findLength() {
    vector<int> nums1;
    int num;
    cout << "\ninput array1 : " << endl;
    while (cin >> num) {
        nums1.push_back(num);
        if (cin.peek() == '\n')
            break;
    }

    vector<int> nums2;
    cout << "\ninput array2 : " << endl;
    while (cin >> num) {
        nums2.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    int res = findLength(nums1, nums2);
    cout << "\nres:" << res << endl;
}

int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    int res = 0;
    for (int i = 1; i <= text1.size(); i++)
    {
        for (int j = 1; j <= text2.size(); j++)
        {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[text1.size()][text2.size()];
}

void Test_longestCommonSubsequence()
{
    string text1;
    cout << "\ninput array1 : " << endl;
    cin >> text1;

    string text2;
    cout << "\ninput array2 : " << endl;
    cin >> text2;

    int res = longestCommonSubsequence(text1, text2);
    cout << "\nres:" << res << endl;
}

int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
    int res = 0;
    for (int i = 1; i <= nums1.size(); i++)
    {
        for (int j = 1; j <= nums2.size(); j++)
        {
            if (nums1[i - 1] == nums2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[nums1.size()][nums2.size()];
}

void Test_maxUncrossedLines()
{
    vector<int> nums1;
    int num;
    cout << "\ninput array1 : " << endl;
    while (cin >> num) {
        nums1.push_back(num);
        if (cin.peek() == '\n')
            break;
    }

    vector<int> nums2;
    cout << "\ninput array2 : " << endl;
    while (cin >> num) {
        nums2.push_back(num);
        if (cin.peek() == '\n')
            break;
    }

    int res = maxUncrossedLines(nums1, nums2);
    cout << "\nRes:" << res << endl;
}

bool isSubsequence(string s, string t) {
    if (s.empty())
        return true;
    int p1 = 0;
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == s[p1])
            p1++;
        if (p1 == s.size())
            return true;
    }
    return false;
}

void Test_isSubsequence()
{
    string text1;
    cout << "\ninput array1 : " << endl;
    cin >> text1;

    string text2;
    cout << "\ninput array2 : " << endl;
    cin >> text2;

    int res = isSubsequence(text1, text2);
    string resstr = (res == true) ? "TRUE" : "FALSE";
    cout << "\n" << resstr << endl;
}

int numDistinct(string s, string t) {
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    for (int i = 0; i < s.size(); i++) dp[i][0] = 1;
    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 1; j <= t.size(); j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }return dp[s.size()][t.size()];
}

void Test_numDistinct()
{
    string text1;
    cout << "\ninput array1 : " << endl;
    cin >> text1;

    string text2;
    cout << "\ninput array2 : " << endl;
    cin >> text2;

    int res = numDistinct(text1, text2);
    cout << res << endl;
}

int minDistance(string word1, string word2) {//只有一个删
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    for (int i = 0; i <= word1.size(); i++)
        dp[i][0] = i;
    for (int j = 0; j <= word2.size(); j++)
        dp[0][j] = j;
    for (int i = 1; i <= word1.size(); i++) {
        for (int j = 1; j <= word2.size(); j++) {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
        }
    }
    return dp[word1.size()][word2.size()];
}

void Test_minDistance()
{
    string text1;
    cout << "\ninput array1 : " << endl;
    cin >> text1;

    string text2;
    cout << "\ninput array2 : " << endl;
    cin >> text2;

    int res = minDistance(text1, text2);
    cout << "\nRes:" << res << endl;
}

int minDistance2(string word1, string word2) {//可删，可加，可替换
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    for (int i = 0; i <= word1.size(); i++)
        dp[i][0] = i;
    for (int j = 0; j <= word2.size(); j++)
        dp[0][j] = j;
    for (int i = 1; i <= word1.size(); i++) {
        for (int j = 1; j <= word2.size(); j++) {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
        }
    }
    return dp[word1.size()][word2.size()];
}

void Test_minDistance2()
{
    string text1;
    cout << "\ninput array1 : " << endl;
    cin >> text1;

    string text2;
    cout << "\ninput array2 : " << endl;
    cin >> text2;

    int res = minDistance2(text1, text2);
    cout << "\nRes:" << res << endl;
}

int countSubstrings(string s) {
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    int res = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        for (int j = i; j < s.size(); j++)
        {
            if (s[i] == s[j])
            {
                if (j - i <= 1 || dp[i + 1][j - 1] == true)
                {
                    res++;
                    dp[i][j] = true;
                }
            }
        }
    }return res;
}

int find_countSubstrings2(string s, int i, int j) {
    int res = 0;
    while (i >= 0 && j <= s.size() - 1 && s[i] == s[j]) {
        i--; j++; res++;
    }
    return res;
}

int countSubstrings2(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        res += find_countSubstrings2(s, i, i);
        res += find_countSubstrings2(s, i, i+1);
    }
    return res;
}

void Test_countSubstrings() {
    string text2;
    cout << "\ninput array2 : " << endl;
    cin >> text2;

    int res = countSubstrings2(text2);
    cout << "\nRes:" << res << endl;
}

int longestPalindromeSubseq(string s) {
    string s1 = s;
    string s2 = s;
    reverse(s2.begin(), s2.end());
    vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, 0));
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 1; j <= s.size(); j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[s.size()][s.size()];
}

void Test_longestPalindromeSubseq()
{
    string text2;
    cout << "\ninput array2 : " << endl;
    cin >> text2;

    int res = longestPalindromeSubseq(text2);
    cout << "\nRes:" << res << endl;
}


vector<vector<int>> dirs = { {-1,0} ,{1,0},{0,-1},{0,1} };

void islandNumbers(int x, int y, vector<vector<int>>& island) {
    if (island[x][y] == 0)
        return;
    island[x][y] = 0;
    for (vector<int> dir : dirs) {
        int newx = x + dir[0];
        int newy = y + dir[1];
        if (newx >= 0 && newx < island.size() && newy >= 0 && newy < island[0].size()&&island[newx][newy]==1) {
            islandNumbers(newx, newy, island);
        }
    }
}

void Test_islandNumbers() {
    cout << "\nInput n, m :" << endl;
    int n, m;
    cin >> n >> m;
    cout << "\nInput island :" << endl;
    vector<vector<int>> island(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> island[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (island[i][j] == 1) {
                res++;
                islandNumbers(i, j, island);
            }        
        }
    }

    cout << "\nRes: " << res << endl;
}

int max_islandSize = 0;
int islandsize = 0;
void islandSize(int x, int y, vector<vector<int>>& island) {
    if (island[x][y] == 0)
        return;
    island[x][y] = 0;
    islandsize++;
    max_islandSize = max(max_islandSize, islandsize);
    for (vector<int> dir : dirs) {
        int newx = x + dir[0];
        int newy = y + dir[1];
        if (newx >= 0 && newx < island.size() && newy >= 0 && newy < island[0].size() && island[newx][newy] == 1) {
            islandSize(newx, newy, island);
        }
    }
}

void Test_islandSize() {
    cout << "\nInput n, m :" << endl;
    int n, m;
    cin >> n >> m;
    cout << "\nInput island :" << endl;
    vector<vector<int>> island(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> island[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (island[i][j] == 1) {
                islandsize = 0;
                islandSize(i, j, island);
            }
        }
    }

    cout << "\nRes: " << max_islandSize << endl;
}

int islandisolatedSize_res = 0;
void islandisolatedSize(int x, int y, vector<vector<int>>& island) {
    if (island[x][y] == 0)
        return;
    island[x][y] = 0;
    islandisolatedSize_res++;
    for (vector<int> dir : dirs) {
        int newx = x + dir[0];
        int newy = y + dir[1];
        if (newx >= 0 && newx < island.size() && newy >= 0 && newy < island[0].size() && island[newx][newy] == 1) {
            islandisolatedSize(newx, newy, island);
        }
    }
}

void setZero(int x, int y, vector<vector<int>>& island) {
    if (island[x][y] == 0)
        return;
    island[x][y] = 0;
    for (vector<int> dir : dirs) {
        int newx = x + dir[0];
        int newy = y + dir[1];
        if (newx >= 0 && newx < island.size() && newy >= 0 && newy < island[0].size() && island[newx][newy] == 1) {
            setZero(newx, newy, island);
        }
    }
}

void Test_islandisolatedSize() {
    cout << "\nInput n, m :" << endl;
    int n, m;
    cin >> n >> m;
    cout << "\nInput island :" << endl;
    vector<vector<int>> island(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> island[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        if (island[i][0] == 1)
            setZero(i,0,island);
        if (island[i][m-1] == 1)
            setZero(i, m-1, island);
    }

    for (int j = 0; j < m; j++) {
        if (island[0][j] == 1)
            setZero(0, j, island);
        if (island[n-1][j] == 1)
            setZero(n - 1,j,island);
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (island[i][j] == 1) {
                islandisolatedSize(i, j, island);
            }
        }
    }

    cout << "\nRes: " << islandisolatedSize_res << endl;
}


void setTwo(int x, int y, vector<vector<int>>& island) {
    if (island[x][y] == 0)
        return;
    island[x][y] = 2;
    for (vector<int> dir : dirs) {
        int newx = x + dir[0];
        int newy = y + dir[1];
        if (newx >= 0 && newx < island.size() && newy >= 0 && newy < island[0].size() && island[newx][newy] == 1) {
            setTwo(newx, newy, island);
        }
    }
}

void setZero2(int x, int y, vector<vector<int>>& island) {
    if (island[x][y] == 0)
        return;
    island[x][y] = 0;
    for (vector<int> dir : dirs) {
        int newx = x + dir[0];
        int newy = y + dir[1];
        if (newx >= 0 && newx < island.size() && newy >= 0 && newy < island[0].size() && island[newx][newy] == 1) {
            setZero2(newx, newy, island);
        }
    }
}

void Test_sunkenIsland() {
    cout << "\nInput n, m :" << endl;
    int n, m;
    cin >> n >> m;
    cout << "\nInput island :" << endl;
    vector<vector<int>> island(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> island[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        if (island[i][0] == 1)
            setTwo(i, 0, island);
        if (island[i][m - 1] == 1)
            setTwo(i, m - 1, island);
    }

    for (int j = 0; j < m; j++) {
        if (island[0][j] == 1)
            setTwo(0, j, island);
        if (island[n - 1][j] == 1)
            setTwo(n - 1, j, island);
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (island[i][j] == 1) {
                setZero2(i, j, island);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (island[i][j] == 2) {
                island[i][j]=1;
            }
        }
    }
    cout << endl;
    printVectorOfVector(island);
}



void river_dfs(vector<vector<int>>& island, vector<vector<bool>>& visited, int x, int y) {
    if (visited[x][y]) return;
    visited[x][y] = true;
    for (vector<int> dir : dirs) {
        int newx = x + dir[0];
        int newy = y + dir[1];
        if (newx >= 0 && newx < island.size() && newy >= 0 && newy < island[0].size()) {
            if (island[newx][newy] > island[x][y])
                river_dfs(island, visited, newx, newy);
        }
    }
}

void Test_river() {
    cout << "\nInput n, m :" << endl;
    int n, m;
    cin >> n >> m;
    cout << "\nInput island :" << endl;
    vector<vector<int>> island(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> island[i][j];
        }
    }

    vector<vector<int>> riverRes;
    vector<vector<bool>> firstfind(n, vector<bool>(m, 0));
    vector<vector<bool>> secondfind(n, vector<bool>(m, 0));
    for (int i = 0; i < n; i++) {
        river_dfs(island, firstfind, i, 0);
        river_dfs(island, secondfind, i, m-1);
    }
    for (int j = 0; j < m; j++) {
        river_dfs(island, firstfind, 0, j);
        river_dfs(island, secondfind, n-1, j);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (firstfind[i][j]==true&&secondfind[i][j]==true) {
                riverRes.push_back({i,j});
            }
        }
    }
    printVectorOfVector(riverRes);
}

int area_island = 0;
void island_dfs(vector<vector<int>>& island, vector<vector<bool>>& visited, int x, int y, int mark) {
    if (visited[x][y]) return;
    visited[x][y] = true;
    island[x][y] = mark;
    area_island++;
    for (vector<int> dir : dirs) {
        int newx = x + dir[0];
        int newy = y + dir[1];
        if (newx >= 0 && newx < island.size() && newy >= 0 && newy < island[0].size() && island[newx][newy] == 1) {
            island_dfs(island, visited, newx, newy, mark);
        }
    }
}

void BuildIsland() {
    cout << "\nInput n, m :" << endl;
    int n, m;
    cin >> n >> m;
    cout << "\nInput island :" << endl;
    vector<vector<int>> island(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> island[i][j];
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    unordered_map<int, int> areaIsland;
    int mark = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && island[i][j] == 1) {
                area_island = 0;
                island_dfs(island, visited, i, j, mark);
                areaIsland[mark] = area_island;
                mark++;
            }
        }
    }
    int res = 0;
    unordered_set<int> record;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (island[i][j] == 0) {
                record.clear();
                int count = 1;
                for (vector<int> dir : dirs) {
                    int newx = i + dir[0];
                    int newy = j + dir[1];
                    if (newx >= 0 && newx < island.size() && newy >= 0 && newy < island[0].size()&&!record.count(island[newx][newy])) {
                        count += areaIsland[island[newx][newy]];
                        record.insert(island[newx][newy]);
                    }
                }
                res = max(res, count);
            }
        }
    }
    cout << res << endl;
}

void PerimeterIsland() {
    cout << "\nInput n, m :" << endl;
    int n, m;
    cin >> n >> m;
    cout << "\nInput island :" << endl;
    vector<vector<int>> island(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> island[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (island[i][j] == 1) {
                for (vector<int> dir : dirs) {
                    int newx = i + dir[0];
                    int newy = j + dir[1];
                    if (newx < 0 || newx >= island.size() || newy < 0 || newy >= island[0].size() || island[newx][newy]==0) {
                        res++;
                    }
                }
            }
        }
    }
    cout << res << endl;
}

bool needOneChar(string str, string aimstr) {
    if (str.size() != aimstr.size())
        return false;
    int count = 0; 
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != aimstr[i])
            count++;
        if (count >= 2)
            return false;
    }
    return count == 1;
}

void Test_StringSol() {
    int n;
    cout << "input strings num:" << endl;
    cin >> n;
    string beginstr, endstr;
    cout << "input begin string and end string:" << endl;
    cin >> beginstr >> endstr;
    vector<string> strs(n+1);
    cout << "input strings:" << endl;
    for (int i = 0; i < n; i++) {
        cin>>strs[i];
    }

    strs.push_back(endstr);
    unordered_set<string> visited;
    visited.insert(beginstr);
    queue<pair<string, int>> que;
    que.push({beginstr, 1});
    int res = 0;
    while (!que.empty()) {
        string aimstr= que.front().first;
        int path = que.front().second;
        que.pop();
        if (aimstr == endstr) {
            res = path;
            break;
        }
        for (string str : strs) {
            if (!visited.count(str) && needOneChar(str, aimstr)) {
                que.push({ str,(path + 1) });
                visited.insert(str);
            }
        }
    }
    cout << res << endl;
}


void Test_graphConnected() {
    int p, l;
    cin >> p >> l;
    vector<list<int>> graph(p+1);
    for (int i = 0; i < l; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    vector<bool> visited(p+1,false);
    queue<int> que;
    que.push(1);
    visited[1] = true;
    while (!que.empty()) {
        int node = que.front();
        que.pop();
        for (int num : graph[node]) {
            if (!visited[num]) {
                visited[num] = true;
                que.push(num);
            }
        }
    }
    bool flag = false;
    for (int i = 1; i < visited.size(); i++) {
        if (visited[i] == false)
        {
            flag = true; break;
        }
    }
    cout << (flag == true ? -1 : 1) << endl;
}

class UFnode {
public:
    UFnode(int size) :parent(size) {
        for (int i = 0; i < parent.size(); i++)
            parent[i] = i;
    }

    int find(int num) {
        return num == parent[num] ? num : parent[num] = find(parent[num]);
    }

    bool ifconnect(int u, int v) {
        int val1 = find(u);
        int val2 = find(v);
        return val1 == val2;
    }

    void join(int u, int v) {
        int val1 = find(u);
        int val2 = find(v);
        if (val1 == val2) return;
        parent[val2] = val1;
    }

private:
    vector<int> parent;
};

void Test_findPath() {
    int p, l;
    cin >> p >> l;
    UFnode myuf(p + 1);
    for (int i = 0; i < l; i++) {
        int a, b;
        cin >> a >> b;
        myuf.join(a, b);
    }
    int star, end;
    cin >> star >> end;
    bool res = myuf.ifconnect(star, end);
    cout << (res == true ? 1 : 0 )<< endl;
}

void Test_outLine() {
    int n;
    cin >> n;
    UFnode myuf(n + 1);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (myuf.ifconnect(a, b)==true)
            cout << a << ' ' << b << endl;
        else
            myuf.join(a, b);
    }
}

void Test_findTrea() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v + 1, vector<int>(v + 1, INT_MAX-1));
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }
    vector<int> minDis(v+1, INT_MAX - 1);
    vector<int> visited(v + 1, false);
    for (int i = 1; i < v; i++) {
        int cur = -1;
        int minval = INT_MAX;
        for (int j = 1; j <= v; j++) {
            if (!visited[j] && minDis[j] < minval) {
                minval = minDis[j];
                cur = j;
            }
        }
        visited[cur] = true;
        for (int j = 1; j <= v; j++) {
            if (!visited[j] && graph[cur][j] < minDis[j])
                minDis[j] = graph[cur][j];
        }
    }
    int res = 0;
    for (int i = 2; i <= v; i++) {
        res += minDis[i];
    }
    cout << res << endl;
}

class ufnode {
public:
    ufnode(int size) :father(size) {
        for (int i = 0; i < size; i++)
            father[i] = i;
    }

    int find(int u) {
        return u == father[u] ? u : father[u] = find(father[u]);
    }

    bool ifconn(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }

    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return;
        father[v] = u;
    }

private:
    vector<int> father;
};

struct edge {
    int x, y, val;
};
void Test_findTrea2() {
    int v, e;
    cin >> v >> e;
    vector<edge> edges;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({ a,b,c });
    }
    sort(edges.begin(), edges.end(), [](edge& a, edge& b) {return a.val < b.val; });
    ufnode myuf(v + 1);
    int res = 0;
    for (edge a : edges) {
        if (!myuf.ifconn(a.x, a.y))
        {
            res += a.val;
            myuf.join(a.x, a.y);
        }
    }
    cout << res << endl;
}

void TopoSort() {
    int n, m;
    cin >> n >> m;
    vector<int> indegree(n);
    unordered_map<int, vector<int>> record;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        indegree[b]++;
        record[a].push_back(b);
    }
    queue<int> que;
    for (int i = 0; i < indegree.size(); i++) {
        if (indegree[i] == 0)
            que.push(i);
    }
    vector<int> res;
    while (!que.empty()) {
        int node = que.front();
        res.push_back(node);
        que.pop();
        for (int num : record[node]) {
            indegree[num]--;
            if(indegree[num]==0)
                que.push(num);
        }
    }
    if (res.size() != n)
        cout << -1 << endl;
    else {
        for (int i = 0; i < res.size()-1; i++) {
            cout << res[i] << " ";
        }cout << res[n - 1] << endl;
    }
}

void Test_DirMinValuePath() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 0; i < m; i++) {
        int a, b, v;
        cin >> a >> b >> v;
        graph[a][b] = v;
    }
    vector<int> minDist(n + 1, INT_MAX);
    vector<int> visited(n + 1, false);
    minDist[1] = 0;

    for (int k = 1; k <= n; k++) {
        int minval = INT_MAX;
        int cur = -1;
        for (int j = 1; j <= n; j++) {
            if (!visited[j]&&minDist[j] < minval) {
                minval = minDist[j];
                cur = j;
            }
        }
        if (cur == -1) break;
        visited[cur] = true;
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && graph[cur][i] != INT_MAX && graph[cur][i] + minDist[cur] < minDist[i])
                minDist[i] = graph[cur][i] + minDist[cur];
        }
    }
    cout << (minDist[n] == INT_MAX ? -1 : minDist[n]) << endl;
}

struct edge2 {
    int to, val;
    edge2(int t, int v):to(t), val(v){}
};
void Test_DirMinValuePath2() {
    int n, m;
    cin >> n >> m;
    vector<list<edge2>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, v;
        cin >> a >> b >> v;
        graph[a].push_back(edge2(b,v));
    }
    
    auto duibi = [](pair<int, int>& a, pair<int, int>& b) { return a.second > b.second; };
    priority_queue <pair<int, int>, vector<pair<int, int>>, decltype(duibi)> pq(duibi);

    vector<int> minDist(n + 1, INT_MAX);
    vector<int> visited(n + 1, false);
    minDist[1] = 0;

    pq.push({ 1,0 });
    while (!pq.empty()) {
        int node = pq.top().first;
        int value = pq.top().second;
        pq.pop();
        if (visited[node] == true) continue;
        visited[node] = true;

        for (edge2& temp : graph[node]) {
            if (!visited[temp.to] && minDist[node] + temp.val < minDist[temp.to]) {
                minDist[temp.to] = minDist[node] + temp.val;
                pq.push({ temp.to,minDist[temp.to] });
            }
        }
    }
    cout << (minDist[n] == INT_MAX ? -1 : minDist[n]) << endl;
}

void Test_BF1() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph;
    for (int i = 0; i < m; i++) {
        int s, t, v;
        cin >> s >> t >> v;
        graph.push_back({s,t,v});
    }
    vector<int> minDist(n + 1, INT_MAX);
    minDist[1] = 0;
    for (int i = 0; i < n; i++) {
        for (vector<int>& side : graph) {
            int star = side[0];
            int end  = side[1];
            int val  = side[2];
            if (minDist[star] != INT_MAX && minDist[star] + val < minDist[end])
                minDist[end] = minDist[star] + val;
        }
    }
    if (minDist[n] == INT_MAX) cout << "unconnected" << endl;
    else  cout << minDist[n] << endl;
}

void Test_BF2() {
    int n, m;
    cin >> n >> m;
    vector<list<edge2>> graph(n+1);
    for (int i = 0; i < m; i++) {
        int s, t, v;
        cin >> s >> t >> v;
        graph[s].push_back(edge2(t,v));
    }

    queue<int> que;
    vector<int> visited(n + 1, false);
    vector<int> minDist(n + 1, INT_MAX);
    que.push(1);
    visited[1] = true;
    minDist[1] = 0;

    while (!que.empty()) {
        int node = que.front(); que.pop();
        visited[node] = false;
        for (edge2& temp : graph[node]) {
            int to  = temp.to;
            int val = temp.val;
            if (minDist[to] > minDist[node] + val) {
                minDist[to] = minDist[node] + val;
                if (visited[to] == false) {
                    que.push(to);
                    visited[to] = true;
                }
            }
        }
    }
    if (minDist[n] == INT_MAX) cout << "unconnected" << endl;
    else  cout << minDist[n] << endl;
}

void Test_BF1_circle_bool() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph;
    for (int i = 0; i < m; i++) {
        int s, t, v;
        cin >> s >> t >> v;
        graph.push_back({ s,t,v });
    }
    vector<int> minDist(n + 1, INT_MAX);
    minDist[1] = 0;
    bool cirFLAG = false;
    for (int i = 0; i <= n; i++) {
        for (vector<int>& side : graph) {
            int star = side[0];
            int end = side[1];
            int val = side[2];
            if (i < n && minDist[star] != INT_MAX && minDist[star] + val < minDist[end])
                minDist[end] = minDist[star] + val;
            else if (i == n && minDist[star] != INT_MAX && minDist[star] + val < minDist[end])
                cirFLAG = true;
        }
    }
    if(cirFLAG==true) cout << "circle" << endl;
    else if (minDist[n] == INT_MAX) cout << "unconnected" << endl;
}

void Test_BF1_circle_cal() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph;
    for (int i = 0; i < m; i++) {
        int s, t, v;
        cin >> s >> t >> v;
        graph.push_back({ s,t,v });
    }
    int src, dst, k;
    cin >> src >> dst >> k;
    vector<int> minDist(n + 1, INT_MAX);
    minDist[src] = 0;
    for (int i = 1; i <= k+1; i++) {
        vector<int> minDist_copy = minDist;
        for (vector<int>& side : graph) {
            int star = side[0];
            int end = side[1];
            int val = side[2];
            if (minDist_copy[star] != INT_MAX && minDist_copy[star] + val < minDist[end])
                minDist[end] = minDist_copy[star] + val;
        }
    }
    if (minDist[dst] == INT_MAX) cout << "unconnected" << endl;
    else  cout << minDist[dst] << endl;
}

void Test_Floyd_duoyuan() {
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> graph(n + 1, vector<vector<int>>(n + 1, vector<int>(n+1,10005)));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b][0] = c;
        graph[b][a][0] = c;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                graph[i][j][k] = min(graph[i][j][k - 1], graph[i][k][k - 1] + graph[k][j][k - 1]);
            }
        }
    }
    int q;
    cin >> q;
    int star, end;
    for (int i = 0; i < q; i++) {
        cin >> star >> end;
        if (graph[star][end][n] == 10005)
            cout << -1 << endl;
        else
            cout << graph[star][end][n] << endl;
    }
}

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> res(n);
    stack<int> sta;
    for (int i = n - 1; i >= 0; i--) {
        while (!sta.empty() && temperatures[i] >= temperatures[sta.top()])
            sta.pop();
        res[i] = sta.empty() ? 0 : (sta.top() - i);
        sta.push(i);
    }
    return res;
}

void Test_dailyTemperatures() {
    vector<int> nums;
    int num;
    cout << "\ninput array" << endl;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    vector<int> res = dailyTemperatures(nums);
    printVector(res);
}

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n = nums2.size();
    unordered_map<int, int> map;
    stack<int> sta;
    for (int i = n - 1; i >= 0; i--) {
        while (!sta.empty() && nums2[i] >= sta.top())
            sta.pop();
        map[nums2[i]] = sta.empty() ? -1 : sta.top();
        sta.push(nums2[i]);
    }
    vector<int> res;
    for (int num : nums1)
        res.push_back(map[num]);
    return res;
}

void Test_nextGreaterElement() {
    vector<int> nums1;
    int num;
    cout << "\ninput array1" << endl;
    while (cin >> num) {
        nums1.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    vector<int> nums2;
    cout << "\ninput array2" << endl;
    while (cin >> num) {
        nums2.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    vector<int> res = nextGreaterElement(nums1, nums2);
    printVector(res);
}

vector<int> nextGreaterElements2(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);
    stack<int> sta;
    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!sta.empty() && nums[i % n] >= sta.top())
            sta.pop();
        res[i % n] = sta.empty() ? -1 : sta.top();
        sta.push(nums[i % n]);
    }
    return res;
}

void nextGreaterElements2() {
    vector<int> nums;
    int num;
    cout << "\ninput array" << endl;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    vector<int> res = nextGreaterElements2(nums);
    printVector(res);
}

int trap1(vector<int>& height) {
    int n = height.size();
    vector<int> left(n,0);
    vector<int> right(n,0);
    left[0] = height[0]; right[n - 1] = height[n - 1];
    for (int i = 1; i < n; i++)
        left[i] = max(height[i], left[i - 1]);
    for (int i = n-2; i >= 0; i--)
        right[i] = max(height[i], right[i + 1]);
    int res = 0;
    for (int i = 1; i < n - 1; i++) {
        res += min(left[i], right[i]) - height[i];
    }
    return res;
}

int trap2(vector<int>& height) {
    int n = height.size();
    stack<int> sta;
    int res = 0;
    for (int i = 0; i < n; i++) {
        while (!sta.empty() && height[i] > height[sta.top()]) {
            int idx = sta.top(); sta.pop();
            if (sta.empty()) break;
            int leftidx = sta.top();
            int heightdiff = min(height[leftidx], height[i]) - height[idx];
            int width = i - leftidx - 1;
            res += heightdiff * width;
        }
        sta.push(i);
    }return res;
}

void Test_trap() {
    vector<int> nums;
    int num;
    cout << "\ninput array" << endl;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    int res = trap2(nums);
    cout<<"Res:" << res << endl;
}

int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0);
    heights.insert(heights.begin(), 0);
    int n = heights.size();
    stack<int> sta;
    int res = 0;
    for (int i = 0; i < n; i++) {
        while (!sta.empty() && heights[i] < heights[sta.top()]) {
            int idx = sta.top(); sta.pop();
            int width = (i - sta.top() - 1);
            int high = heights[idx];
            res = max(res, high * width);
        }
        sta.push(i);
    }
    return res;
}

void Test_largestRectangleArea() {
    vector<int> nums;
    int num;
    cout << "\ninput array" << endl;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
    int res = largestRectangleArea(nums);
    cout << "Res:" << res << endl;
}

int main()
{
    //Test_search();
    //Test_removeElement();
    //Test_sortedSquares();
    //Test_minSubArrayLen();
    //Test_generateMatrix();
    //Test_removeElements();
    //Test_MyLinkedList();
    //Test_reverseList();
    //Test_swapPairs();
    //Test_removeNthFromEnd(); 
    //Test_getIntersectionNode();
    //Test_detectCycle();
    //Test_isAnagram();
    //Test_intersection();
    //Test_isHappy();
    //Test_twoSum();
    //Test_fourSumCount();
    //Test_canConstruct();
    //Test_threeSum();
    //Test_fourSum();
    //Test_reverseString();
    //Test_reverseStr();
    //Test_reverseWords();
    //Test_strStr();
    //Test_repeatedSubstringPattern();
    //Test_MyQueue();
    //Test_MyStack();
    //Test_isValid();
    //Test_removeDuplicates();
    //Test_evalRPN();
    //Test_maxSlidingWindow();
    //Test_topKFrequent();
    //Test_preorderTraversal();
    //Test_levelOrder();
    //Test_invertTree();
    //Test_isSymmetric();
    //Test_maxDepth();
    //Test_minDepth();
    //Test_countNodes();
    //Test_isBalanced();
    //Test_binaryTreePaths();
    //Test_sumOfLeftLeaves();
    //Test_findBottomLeftValue();
    //Test_hasPathSum();
    //Test_buildTree();
    //Test_constructMaximumBinaryTree();
    //Test_mergeTrees();
    //Test_searchBST();
    //Test_isValidBST();
    //Test_getMinimumDifference();
    //Test_findMode();
    //Test_lowestCommonAncestor();
    //Test_lowestCommonAncestor_searchTree();
    //Test_insertIntoBST();
    //Test_deleteNode();
    //Test_trimBST();
    //Test_sortedArrayToBST();
    //Test_convertBST();
    //Test_combine();
    //Test_combinationSum3();
    //Test_letterCombinations();
    //Test_combinationSum();
    //Test_combinationSum2();
    //Test_partition();
    //Test_restoreIpAddresses();
    //Test_subsets();
    //Test_subsetsWithDup();
    //Test_subsetsWithDup2();
    //Test_permute();
    //Test_permuteUnique();
    //Test_solveNQueens();
    //Test_solveSudoku();
    //Test_findContentChildren();
    //Test_wiggleMaxLength();
    //Test_maxSubArray();
    //Test_maxProfit();
    //Test_canJump();
    //Test_jump();
    //Test_largestSumAfterKNegations();
    //Test_canCompleteCircuit();
    //Test_candy();
    //Test_lemonadeChange();
    //Test_reconstructQueue();
    //Test_findMinArrowShots();
    //Test_eraseOverlapIntervals();
    //Test_partitionLabels();
    //Test_merge();
    //Test_monotoneIncreasingDigits();
    //Test_fib();
    //Test_climbStairs();
    //Test_minCostClimbingStairs();
    //Test_uniquePaths();
    //Test_uniquePathsWithObstacles();
    //Test_integerBreak();
    //Test_numTrees();
    //Test_bag01();
    //Test_canPartition();
    //Test_lastStoneWeightII();
    //Test_findTargetSumWays();
    //Test_findMaxForm();
    //Test_bag_multi();
    //Test_change();
    //Test_combinationSum4();
    //Test_climbstairs2();
    //Test_coinChange();
    //Test_numSquares();
    //Test_wordBreak();
    //Test_rob();
    //Test_rob2();
    //Test_maxProfit_2();
    //Test_maxProfit_3();
    //Test_maxProfit_icetime();
    //Test_maxProfit_fee();
    //Test_lengthOfLIS();
    //Test_findLengthOfLCIS();
    //Test_findLength();
    //Test_longestCommonSubsequence();
    //Test_maxUncrossedLines();
    //Test_isSubsequence();
    //Test_numDistinct();
    //Test_minDistance();
    //Test_minDistance2();
    //Test_countSubstrings();
    //Test_longestPalindromeSubseq();
    //Test_islandNumbers();
    //Test_islandSize();
    //Test_islandisolatedSize();
    //Test_sunkenIsland();
    //Test_river();
    //BuildIsland();
    //PerimeterIsland();
    //Test_StringSol();
    //Test_graphConnected();
    //Test_findPath();
    //Test_outLine();
    //Test_findTrea();
    //Test_findTrea2();
    //TopoSort();
    //Test_DirMinValuePath();
    //Test_DirMinValuePath2();
    //Test_BF1();
    //Test_BF2();
    //Test_BF1_circle_bool();
    //Test_BF1_circle_cal();
    //Test_Floyd_duoyuan();
    //Test_dailyTemperatures();
    //Test_nextGreaterElement();
    //nextGreaterElements2();
    //Test_trap();
    //Test_largestRectangleArea();
}