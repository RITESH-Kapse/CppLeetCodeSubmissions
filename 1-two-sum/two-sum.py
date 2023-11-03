class Solution:
  def twoSum(self, nums: List[int], target: int) -> List[int]:

    #   flag=True
    #   if 2 <= len(nums) <= 100000:
    #       flag = False
    #   if (-9 ** 10) <= target <= (9 ** 10):
    #       flag = False
    #   for i in range(len(nums)):
    #       for j in range(len(nums)-1):
    #           if(nums[i] + nums[j+1] == target) and  not flag and ((-9 ** 10) <= nums[i] <= (9 ** 10)):
    #               return [i,j+1]
    #           else:
    #               pass

    #nums -> list
    #target -> integer

     result = []

     size = len(nums)

     for i in range(0,size):
         for j in range(i+1,size):
             if nums[i] + nums[j] ==target:
                 result.append(i)
                 result.append(j)
                 
                 
     return result