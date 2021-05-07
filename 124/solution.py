def solution(n):
    list = ["4", "1", "2"]
    answer = ''
    while n>0:
        answer = list[n % 3] + answer
        if n%3 == 0:
            n = n-1
        n = n//3
    return answer


if __name__ == '__main__':
    num = int(input())
    print(solution(num))