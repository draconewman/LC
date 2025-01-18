# Daily Temperatures

from typing import List

class Solution:
    def dailyTemperatures(self, tem: List[int]) -> List[int]:
        ans = [0] * len(tem)  # Initialize the answer list with zeros
        stack = []  # Stack to store indices of temperatures

        for i, t in enumerate(tem):
            # Check if the current temperature is warmer than the temperature at the top of the stack
            while stack and tem[stack[-1]] < t:
                prev = stack.pop()  # Get the index of the previous temperature
                ans[prev] = i - prev  # Calculate the difference in days
            stack.append(i)  # Push the current index onto the stack

        return ans

# Example usage
if __name__ == "__main__":
    solution = Solution()
    temperatures = [73, 74, 75, 71, 69, 72, 76, 73]
    result = solution.dailyTemperatures(temperatures)
    print(result)  # Output: [1, 1, 4, 2, 1, 1, 0, 0]