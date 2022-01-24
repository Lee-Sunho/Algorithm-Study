def solution(N, stage):
    answer = []
    people = len(stage)

    user = 0
    fail_rate = []
    for i in range(1, N + 1):
        cnt = stage.count(i)
        if cnt == 0:
            fail_rate.append((i, 0))
        else:    
            fail_rate.append((i, cnt / (people - user)))
        user += cnt

    fail_rate.sort(reverse = True, key = lambda x: x[1])
    for i in fail_rate:
        answer.append(i[0])

    return answer