#nums = [1, 3, 5, 2, 4]
#print(len(nums))

#str = "some text"
#x = len(str)
#print(x)

#x ="abc"
#x *= 2
#print(len(x))

#nums = [1, 2, 3]
#nums.append(4)
#print(nums)

#words = ["Python", "fun"]
#words.insert(1, "is")
#print(words)

#nums = [9, 8, 7, 6, 5]
#nums.append(4)
#nums.insert(2, 11)
#print(len(nums))

#letters = ['p', 'q', 'r', 's', 'p', 'u']
#print(letters.index('r'))
#print(letters.index('p'))
#print(letters.index('q'))

#x = [2, 4, 5, 7, 4]
#y = x.index(4)
#print(y)

#x = [1, 8, 42, 3]
#print(min(x))
#print(max(x))

#list = [8, 4, 2, 6]
#list.remove(2)
#print(len(list)+list.count(6))

nums = [2,4,8,9,5]
nums.insert(1, 3)
nums.remove(9)
nums.insert(0, nums.count(8))
print(nums[3])