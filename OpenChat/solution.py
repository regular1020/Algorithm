def solution(record):
    answer = []
    user_dict = {}
    for j in range(len(record)):
        user_id = record[j].split(" ")[1]
        print(user_id)
        if len(record[j].split(" ")) == 3:
            user_nick = record[j].split(" ")[2]
            user_dict[user_id] = user_nick
    for k in range(len(record)):
        command = record[k].split(" ")[0]
        if command == "Enter":
            sentence = "님이 들어왔습니다."
        elif command == "Leave":
            sentence = "님이 나갔습니다."
        else:
            continue
        sentence = user_dict[record[k].split(" ")[1]] + sentence
        answer.append(sentence)
    return answer


if __name__ == '__main__':
    sent_list = []
    input_length = int(input())
    for i in range(input_length):
        sent = input()
        sent_list.append(sent)
    print(solution(sent_list))