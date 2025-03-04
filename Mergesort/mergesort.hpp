#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

// Implement mergesort algorithm here.
void merge(vector<int> &A, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    // Merge temp arrays back into A[left...right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // if any, Copy remaining elements of L[]
    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    // if any,Copy remaining elements of R[]
    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}

void Mergesort(vector<int> &A, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Recursively sort first and second halves
        Mergesort(A, left, mid);
        Mergesort(A, mid + 1, right);

        // Merge the sorted halves
        merge(A, left, mid, right);
    }
}