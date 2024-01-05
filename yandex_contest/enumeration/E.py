def gen_parentheses_v2(parentheses_count, str_, left, right):
    if left < parentheses_count:
        for i in range(parentheses_count, max(left, right+1) - 1, -1):  
            gen_parentheses_v2(parentheses_count,
                               str_ + (i-left)*"(" + ")",
                               i,
                               right + 1)
    else:
        print(str_ + (parentheses_count-right)*")" + "\n")


gen_parentheses_v2(4, "", 0, 0)