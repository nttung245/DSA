#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int left,
           int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back
    // into arr[left..right]
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sotred
void mergesotr(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergesotr(arr, left, mid);
    mergesotr(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int quantity;
    cin >> quantity;

    int element;
    vector<int> my_vector;

    for (int i = 0; i < quantity; i++)
    {
        cin >> element;
        my_vector.push_back(element);
    }

    mergesotr(my_vector, 0, quantity - 1);

    if (my_vector[0] != 0)
    {
        cout << 0;
        exit(0);
    }

    for (int i = 0; i < quantity - 1; i++)
    {
        if (my_vector[i + 1] - my_vector[i] > 1)
        {
            cout << my_vector[i] + 1;
            exit(0);
        }
    }
    cout << my_vector[quantity - 1] + 1;
    return 0;
}