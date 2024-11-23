#include <iostream>
#include <vector>

using namespace std;

// Function to merge two halves in descending order
void merge(vector<unsigned long> &a, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<unsigned long> L(n1);
    vector<unsigned long> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort function to sort the array in descending order
void mergeSort(vector<unsigned long> &a, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
}

int main()
{
    unsigned long n;
    cin >> n;

    vector<unsigned long> a(n);
    for (unsigned long i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // First sort
    mergeSort(a, 0, n - 1);

    // Modify the array
    for (unsigned long i = 0; i < n; i++)
    {
        a[i] += (i + 2);
    }

    // Second sort
    mergeSort(a, 0, n - 1);

    // Output the first element
    cout << a[0] << endl;

    return 0;
}