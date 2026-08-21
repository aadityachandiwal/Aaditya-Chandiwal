/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
   
    *returnSize = numsSize;
    
   
    int* result = (int*)malloc(numsSize * sizeof(int));
    if (result == NULL) {
        return NULL; 
    }
    int currentSum = 0;
    for (int i = 0; i < numsSize; i++) {
        currentSum += nums[i];
        result[i] = currentSum;
    }
    
    return result;
}
