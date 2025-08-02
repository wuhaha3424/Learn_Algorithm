#include<iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> inputNums() {
	vector<int> nums;
	int num;
	while (cin >> num) {
		nums.push_back(num);
		if (num == '\n')
			break;
	}
	return nums;
}


template<typename T>
void printVector(const vector<T>& nums) {
	for (int i = 0; i < nums.size()-1; i++) {
		cout << nums[i] << " ";
	}
	cout << nums[nums.size() - 1] << endl;
}

template<typename T>
void ChoiceSort(vector<T>& nums) {
	int sortindex = 0;
	while (sortindex < nums.size()) {
		int mindex = sortindex;
		for (int i = sortindex + 1; i < nums.size(); i++) {
			if (nums[i] < nums[mindex])
				mindex = i;
		}
		T temp = nums[mindex];
		nums[mindex] = nums[sortindex];
		nums[sortindex] = temp;
		sortindex++;
	}
}

template<typename T>
void BubbleSort(vector<T>& nums) {
	int maxindex = nums.size()-1;
	while (maxindex >= 0) {
		bool swapped = false;
		for (int i = 0; i < maxindex ; i++) {
			if (nums[i] > nums[i+1]) {
				T temp = nums[i];
				nums[i] = nums[i+1];
				nums[i+1] = temp;
				swapped = true;
			}
		}
		if (!swapped) break;
		maxindex--;
	}
}

template<typename T>
void InsertSort(vector<T>& nums) {
	int sortindex = 1;//>sortindex是未排序的，小于的是已排序的
	while (sortindex < nums.size()) {
		T needInsert = nums[sortindex];
		int j = sortindex - 1;
		while(j>=0&&nums[j]>needInsert){
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = needInsert;
		sortindex++;
	}
}

template<typename T>
int findMid(vector<T>& nums, int begin, int end) {
	int refer = nums[end];
	int j = begin-1;
	for (int i = begin; i <=end-1; i++) {
		if (nums[i] < refer) {
			j++;
			swap(nums[i], nums[j]);
		}
	}
	swap(nums[j + 1], nums[end]);
	return j + 1;
}

template<typename T>
void fastsort(vector<T>& nums, int begin, int end) {
	if (begin >= end) return;
	int mid = findMid(nums, begin, end);
	fastsort(nums, begin, mid - 1);
	fastsort(nums, mid + 1, end);
}

template<typename T>
void FastSort(vector<T>& nums) {
	fastsort(nums, 0, nums.size() - 1);
}

template<typename T>
void Merge(vector<T>& nums, int begin, int end, int mid) {
	int leftsize = mid - begin + 1;
	int rightsize = end - mid;
	vector<T> L(leftsize), R(rightsize);
	for (int i = 0; i < leftsize; i++) L[i] = nums[begin + i];
	for (int i = 0; i < rightsize; i++) R[i] = nums[mid + 1 + i];
	int l = 0, r = 0, p = begin;
	while (l < leftsize && r < rightsize) {
		if (L[l] < R[r])
			nums[p++] = L[l++];
		else
			nums[p++] = R[r++];
	}
	while(l<leftsize)
		nums[p++] = L[l++];
	while(r<rightsize)
		nums[p++] = R[r++];
}

template<typename T>
void Mergesort(vector<T>& nums, int begin, int end) {
	if (begin >= end) return;
	int mid = begin + (end - begin) / 2;
	Mergesort(nums, begin, mid);
	Mergesort(nums, mid+1, end);
	Merge(nums, begin, end, mid);
}

template<typename T>
void MergeSort(vector<T>& nums) {
	Mergesort(nums, 0, nums.size() - 1);
}

template<typename T>
void HeapSort(vector<T>& nums) {
	priority_queue<T, vector<T>> heap;
	for (int i = 0; i < nums.size(); i++) {
		heap.push(nums[i]);
	}
	for (int i = nums.size() - 1; i >= 0; i--) {
		nums[i] = heap.top();
		heap.pop();
	}
}

int main() {
	/* 输入数组 */
	//vector<int> nums = inputNums();
	vector<int> nums = {2,5,1,3,1,5,1,7,4,8,5,9,2};
	vector<char> nums2 = {'a','d','q','a','r','z','f'};

	/* 输入排序算法 */
	//ChoiceSort(nums); //选择排序
	//BubbleSort(nums);	//冒泡排序
	//InsertSort(nums);	//插入排序
	//FastSort(nums);	//快速排序
	//MergeSort(nums);	//归并排序
	HeapSort(nums);		//堆排序

	/* 打印排序后数组 */
	printVector(nums);
}