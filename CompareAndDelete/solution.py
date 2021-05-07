def solution(s):
    answer = 0
    stack = []
    for i in range(len(s)):
        if len(stack) != 0:
            tmp = stack.pop()
            if tmp != s[i]:
                stack.append(tmp)
                stack.append(s[i])
        else:
            stack.append(s[i])
    if len(stack) == 0:
        answer = 1
    return answer


if __name__ == '__main__':
    sent = input()
    ans = solution(sent)
    print(ans)