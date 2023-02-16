#include <iostream>

using namespace std;

int * apply_all(int * arr1, size_t arr1_size, int * arr2, size_t arr2_size);
void print(const int *const arr, size_t size);

int main(){
    const size_t arr1_size {5};
    const size_t arr2_size {3};

   int arr1[] {1, 2, 3, 4, 5};
   int arr2[] {10, 20, 30};

   cout<<"Array 1 : ";
   print(arr1, arr1_size);

   cout<<"Array 2 : ";
   print(arr2, arr2_size);

   int * result = apply_all(arr1, 5, arr2, 3);

   constexpr size_t result_size {arr1_size * arr2_size};

   cout<<"Resultant Array : ";
   print(result, result_size);

   delete [] result;
   return 0;
}

int * apply_all(int * arr1, size_t arr1_size, int * arr2, size_t arr2_size){

    int * overallArray {nullptr};
    overallArray = new int[arr1_size * arr2_size];
    int k=0;
    for(size_t i={0}; i<arr2_size;i++){
        for(size_t j{0};j<arr1_size;j++){
            overallArray[k] = arr2[i] * arr1[j];
            k++;
        }
    }
    return overallArray;
    
}

void print(const int *const arr, size_t size){
    cout<<"[ ";
    for(size_t i{0};i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
}

