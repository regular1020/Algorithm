
tc = int(input())
for c in range(tc):
    line_len = int(input())
    line = input().split()
    postfix_stack = []
    postfix = []
    for i in range(line_len):
        if (line[i] == "("):
            postfix_stack.append(line[i])
        elif (line[i] == ")"):
            while (postfix_stack[len(postfix_stack)-1] != "("):
                token = postfix_stack.pop()
                postfix.append(token)
            postfix_stack.pop()
        elif (line[i] == "*"):
            postfix_stack.append(line[i])
        elif (line[i] == "+" or line[i] == "-"):
            while (len(postfix_stack) > 0):
                token = postfix_stack[len(postfix_stack)-1]
                if (token == "("):
                    break
                else:
                    token = postfix_stack.pop()
                    postfix.append(token)
            postfix_stack.append(line[i])
        else:
            postfix.append(line[i])
    while (len(postfix_stack) > 0):
        token = postfix_stack.pop()
        postfix.append(token)
    calculate_stack = []
    for token in postfix:
        if (token == "+"):
            num2 = int(calculate_stack.pop())
            num1 = int(calculate_stack.pop())
            calculate_stack.append(num1 + num2)
        elif (token == "-"):
            num2 = int(calculate_stack.pop())
            num1 = int(calculate_stack.pop())
            calculate_stack.append(num1 - num2)
        elif (token == "*"):
            num2 = int(calculate_stack.pop())
            num1 = int(calculate_stack.pop())
            calculate_stack.append(num1 * num2)
        else:
            calculate_stack.append(token)
    print(calculate_stack[0])