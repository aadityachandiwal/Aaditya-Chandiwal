void moveZeroes(int* nums, int numsSize) {
    int lastNonZeroFoundAt = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[lastNonZeroFoundAt] = nums[i];
            lastNonZeroFoundAt++;
        }
    }
    
    for (int i = lastNonZeroFoundAt; i < numsSize; i++) {
        nums[i] = 0;
    }
}
