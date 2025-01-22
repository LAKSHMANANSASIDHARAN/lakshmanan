//Partition Array According to Given Pivot.
//Input: nums = [9,12,5,10,14,3,10], pivot = 10
//Output: [9,5,3,10,10,12,14]
// This problem shows that we need to arrange all element in array . We are not going to sort instead of that they have given the pivot element that element will be in given 
//array . The elements less that pivot should be before the pivot and the greater should be after the pivot .
// For this problem Im going to use Two pointer Algorithm.
 vector<int> pivotArray(vector<int>& arr, int pivot) {
          int j=-1;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == pivot) {
            j = i;            // First we need to find the pivot element in the array and keep that element index and break the loop 
            break;
        }
    }

    int i = 0;

    
    while (i < arr.size()) {
        if (arr[i] < arr[j] && i > j) {  // if arr[i] is less than arr[j] and index i is greater that j ,then we can swap and make j=i and i=0
            swap(arr[i], arr[j]);    
            j = i;  
            i = 0;  // because we need check aging the array [doing like this we can avoid another loop.]
        } else if (arr[i] > arr[j] && i < j) {
            swap(arr[i], arr[j]);// if arr[i] is greater than arr[j] and index i is lesser that j ,then we can swap and make j=i and i=0
            j = i;
            i = j + 1; // change the i as j+1 because this time we no need to recheck the array . 
        } else if (arr[i] == arr[j] && i != j) {
           
                swap(arr[j + 1], arr[i]); // if array contian two same element " that should be pivot" In this case we need to keep that element next or first pivot element.
            
            i++;
        } else {  //otherwise i will be incremented.
            i++;
        }
    }
    return arr; // return the modified array.
    } 
