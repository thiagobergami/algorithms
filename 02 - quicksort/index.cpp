#include <iostream>
#include <vector>

using namespace std;

vector<int> quicksort(vector<int> my_array)
{

    if (my_array.size() < 2)
    {
        return my_array;
    }
    else
    {
        int pivot = my_array[0];
        vector<int> smallest;
        vector<int> biggest;
        for (int i = 1; i < my_array.size(); ++i)
        {
            if (my_array[i] <= pivot)
            {
                smallest.push_back(my_array[i]);
            }
            else
            {
                biggest.push_back(my_array[i]);
            }
        }
        smallest = quicksort(smallest);
        biggest = quicksort(biggest);
        
        vector<int> sum;

        sum.insert(sum.end(), smallest.begin(), smallest.end());
        sum.push_back(pivot);
        sum.insert(sum.end(), biggest.begin(), biggest.end());

        return sum;
    }
}

int main()
{
    vector<int> quicksort_array{10, 7, 8, 9, 1, 5};

    for (const int number : quicksort_array)
    {
        cout << number << ", ";
    }
    cout << "\n\n";
    vector<int> sorted_array = quicksort(quicksort_array);

    for (const int number : sorted_array)
    {
        cout << number << ", ";
    }
    cout << "\n\n";

    return 0;
}