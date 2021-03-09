#include<iostream>
#include<vector>
using namespace std;

void bubble_sort(vector<int>& v){
    bool swapped;
    int n = v.size();
    // i is the ending index at each round
    for(int i = n-2; i >= 0; i--){
        swapped = false;
        for(int j = 0; j <= i; j++){
            if(v[j] > v[j+1]){
                swap(v[j], v[j+1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

void print_v(vector<int> v){
    for(auto a:v){
        cout << a << " ";
    }
    cout << endl;
}

int partition(vector<int>& v, int low, int high){
    int pivot = v[high];
    int i = low - 1; //[0, low] are smaller than pivot
    for(int j = low; j < high; j++){
        // if a[j] >= pivot, do nothing, just increment j
        //until we find a smaller element a[j], i++, swap with a[i] (to the left smaller part) 
        if(v[j] < pivot){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[high]);
    return i+1;
}

void quick_sort(vector<int>& v, int low, int high){
    //cout << "low: " << low << " high: " << high << endl;
    if(high - low < 1) return; // high - low can be -1, eg: [1,2,3,4,0], after partition: [0,1,2,3,4], pivot index = 0, quick_sort(v, 0, 0-1)
    int pi = partition(v, low, high);
    quick_sort(v, low, pi-1);
    quick_sort(v, pi+1, high);
}

void merge_sort(vector<int>& v, int l, int r){
    if(r - l < 1) return;
    //divide
    int m = l + (r-l)/2;
    merge_sort(v, l, m);
    merge_sort(v, m+1, r);
    //conquer
    vector<int> temp(v.begin()+l, v.begin()+m+1);
    int i = l;
    int j = m+1;
    int k = 0;
    //if additional copy is used, then the whole array already sorted
    while(k <= m-l){
        // If all elements in right half is used, copy the rest of additional array to the right-most
        if(j > r){
            while(k<= m-l){
                v[i++] = temp[k++];
            }
            break;
        }
        if(temp[k] < v[j]){
            v[i++] = temp[k++];
        } else{
            v[i++] = v[j++];
        }
    }
    return;
}


int main(){
    //vector<int> v = {1, 8, 4, 6, 7, 3, 2};
    vector<int> v ={1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0};
    //bubble_sort(v);
    //merge_sort(v, 0, v.size()-1);
    quick_sort(v, 0, v.size()-1);
    print_v(v);
}