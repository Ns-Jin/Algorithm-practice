from sys import stdin

def is_broken_num(num, nums):
    for i in range(len(nums)):
        if num == nums[i]:
            return True
    
    return False

def find_possible_big_num(nums):    #다음에 올 고정 숫자들 찾기
    num = 0
    for i in range(10):
        if not is_broken_num(i, nums):
            num = i
    
    return num

def find_possible_small_num(nums): 
    for i in range(10):
        if not is_broken_num(i, nums):
            return i

    return i

def find_not_zero_small_num(nums): 
    for i in range(10):
        if not is_broken_num(i, nums) and not i == 0:
            return i

    return i

n = int(stdin.readline())
m = int(stdin.readline())
if m>0:
    broken_nums = list(map(int, stdin.readline().split()))
n_digit = len(str(n))
n_list = list(map(int, str(n)))

min_count = abs(n - 100)  #case1) +,-로만 이동할때 경우, 다 고장

if m == 0:    #case2) 다 멀쩡하면 타겟채널 직접 입력해서 이동
    if min_count > n_digit:
        min_count = n_digit
        
elif m < 10:
    if m == 9:
        if not is_broken_num(0,broken_nums):  #case3) 0 만 살아있을때
            if n < 50:
                if min_count > n+1:
                    min_count = n+1
    else:
        if n_digit > 1:   #case4) 자리수가 1 작은 채널로 이동후 +,- 조정
            small_digit_channel = 0
            possible_big_num = find_possible_big_num(broken_nums)
            
            for i in range(n_digit-1):
                small_digit_channel = small_digit_channel*10 + possible_big_num
            
            small_digit_count = n_digit - 1 + n - small_digit_channel
            if min_count > small_digit_count:
                min_count = small_digit_count

        #case5) 자리수가 1 큰 채널로 이동후 +,- 조정
        big_digit_channel = 0
        possible_small_num = find_possible_small_num(broken_nums)
        for i in range(n_digit+1):
            if i == 0:
                big_digit_channel = find_not_zero_small_num(broken_nums)
            else:
                big_digit_channel = big_digit_channel*10 + possible_small_num
        big_digit_count = n_digit + 1 + big_digit_channel - n
        
        if min_count > big_digit_count:
            min_count = big_digit_count

        #case6) 같은 자리수 내의 인접한 채널로 이동후 +,-조정
        find_broken = False  #타겟채널 처음으로 고장난 버튼을 찾았을때 확인 변수
        is_big_channel = True
        possible_big_num = find_possible_big_num(broken_nums)
        possible_small_num = find_possible_small_num(broken_nums)
        target_channel = []
        temp_target_channel = []
        for i in range(n_digit):
            if find_broken:
                if is_big_channel:
                    target_channel.append(possible_small_num)
                else:
                    target_channel.append(possible_big_num)
            
            else:
                if is_broken_num(n_list[i], broken_nums):  #처음 고장난 버튼 찾았을때
                    find_broken = True
                    not_broken_nums = []
                    gaps = []
                    for j in range(10):
                        if not is_broken_num(j, broken_nums):
                            not_broken_nums.append(j)
                            gaps.append(abs(j-n_list[i]))
                    min_nums = []
                    min_gap = min(gaps)
                    for j in range(len(not_broken_nums)):
                        if abs(n_list[i] - not_broken_nums[j]) == min_gap:
                            min_nums.append(not_broken_nums[j])
                    if min_nums:
                        length = len(min_nums)
                        if length == 1:
                            if i == 0 and min_nums[0] == 0:
                                break
                            target_channel.append(min_nums[0])
                            if min_nums[0] < n_list[i]:
                                is_big_channel = False
                            else:
                                is_big_channel = True
                        else:
                            if i == 0 and min_nums[0] == 0:
                                target_channel.append(min_nums[1])
                                is_big_channel = True
                            else:
                                target_channel.append(min_nums[0])
                                is_big_channel = False
                                temp_target_channel = target_channel[:i]
                                temp_target_channel.append(min_nums[1])
                                for j in range(n_digit-i-1):
                                    temp_target_channel.append(possible_small_num)
                else:       #번호가 안망가졌을떄
                    target_channel.append(n_list[i])
        
        if target_channel:           
            tc = ''.join(str(x) for x in target_channel)
            if temp_target_channel:
                ttc = ''.join(str(x) for x in temp_target_channel)
                if abs(int(tc) - n) < abs(int(ttc) - n):
                    count = n_digit + abs(int(tc) - n)
                else:
                    count = n_digit + abs(int(ttc) - n)
            else:
                count = n_digit + abs(int(tc) - n)
            if min_count > count:
                min_count = count

print(min_count)