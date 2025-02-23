for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    val = 0
    for num in a:
        if num >= 2:
            val += 1
    if val >= 2:
        print("Grundy")
    elif (n-1)%3 == 0 or (val == 1 and (n%3 == 0)): # Sprague has can either 0 the pile or 1 the pile
        print("Sprague")
    else:
        print("Grundy")