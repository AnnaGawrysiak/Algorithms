# Given an array of integers arr and an integer value k, return the total amount of unique,
# contiguous, subarrays that sum to k in arr.

def amount_of_arrays_that_sum_to_k(arr, k):
    sum = 0
    #sums that already have occured:
    already_occured = {}
    already_occured[0] = 1
    counter = 0
    for i in range(len(arr)):
        sum+= arr[i]
        if(arr[i] == k):
            counter +=1
        elif((sum-k) in already_occured):
            counter += already_occured[sum-k]
            already_occured[sum - k] = already_occured[sum-k] +1
        else:
            already_occured[sum] = 1
    return counter

arr = [3, 4, 7, 2, -3, 1, 4, 2]

print(amount_of_arrays_that_sum_to_k(arr, 7))
# answer: 3
