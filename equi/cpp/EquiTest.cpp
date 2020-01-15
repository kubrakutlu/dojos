#include <gtest/gtest.h>

int equi(int inputArr[], int arrayLen)
{
    // Find equilibrium index of inputArr
    int sumAll = 0; // Total sum of the array
    int sumLeft = 0; // Sum of the elements on the left hand side of equilibrium index

    if (arrayLen==0) //Empty array
        return -1;
    else
    {
        // Calculate total sum of the array
        for (int i = 0; i < arrayLen; i++)
            sumAll += inputArr[i];

        /* Equilibrium state is found by subtracting left sum from total sum, then
        comparing this remainder sum to left sum. */
        for (int i = 0; i < arrayLen; i++)
        {
            sumAll -= inputArr[i]; // Remainder sum is equal to right sum for index i
            // Check equilibrium state.
            if (sumLeft == sumAll)
                return i;

            sumLeft += inputArr[i]; // Update left sum
        }

        // Return -1 in case of no equilibrium index found
        return -1;
    }
}

TEST(EquiTest, EmptyArrayReturnsZero)
{
    const int arrayLen = 0;
    int inputArr[arrayLen] = {};
    int equiIndex = equi(inputArr, arrayLen);
    int expectedEquiIndex = -1;
    ASSERT_EQ(expectedEquiIndex, equiIndex);
}
