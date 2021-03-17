#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_vector(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}  
int main(){
    vector<int> v = {1, 2, 5, 2, 4 ,3, 6};
    cout << "only using remove: \n";
    remove(v.begin(),v.end(), 2);
    print_vector(v);
    v.clear();
    cout << "using erase-remove idiom: \n";
    v = {1, 2, 5, 2, 4 ,3, 6};
    v.erase(remove(v.begin(), v.end(), 2),v.end());
    print_vector(v);
}