//
// Created by wonma on 2019-06-30.
//

/*
############################################################################
############################################################################
############################################################################
############################### Fail #######################################
############################################################################
############################################################################
############################################################################
*/

#ifndef ALGORITHM_1377_BUBBLESORT_H
#define ALGORITHM_1377_BUBBLESORT_H

#include <iostream>


using namespace std;

int swapNumber = 0;

int compare(const void* a, const void* b)
{
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if (num1 > num2) {
        swapNumber++;
        return -1;
    }

    if (num1 < num2) {
        swapNumber++;
        return 1;
    }

    return 0;
}


// �������� �־��� ���� ��Ʈ�� �������� ��Ʈ�̴�.
void solve_1377(){

    int n;
    cin >> n;
    int* a = new int[n + 1];

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    // quick sort
    qsort(a, n, sizeof(int), compare);

    cout << swapNumber;

}

#endif //ALGORITHM_1377_BUBBLESORT_H