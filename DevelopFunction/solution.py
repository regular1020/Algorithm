def solution(progresses, speeds):
    answer = []
    while len(progresses) > 0:
        count = 0
        for i in range(len(progresses)):
            progresses[i] += speeds[i]
        while True:
            if len(progresses) == 0:
                answer.append(count)
                break
            tmp_prog = progresses.pop(0)
            tmp_spd = speeds.pop(0)
            if tmp_prog >= 100:
                count += 1
            else:
                progresses.insert(0, tmp_prog)
                speeds.insert(0, tmp_spd)
                if count > 0:
                    answer.append(count)
                break
    return answer


if __name__ == '__main__':
    length = int(input())
    progs = []
    spds = []
    for i in range(length):
        prog = int(input())
        progs.append(prog)
        spd = int(input())
        spds.append(spd)
    print(solution(progs, spds))
