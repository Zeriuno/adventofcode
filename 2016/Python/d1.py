def blocks(param):
    '''
    Do the thing.
    '''
    instructions = open(param, 'r')
    for line in instructions:
        go = line.rstrip()
    instructions.close()
    set = go.split(", ")
    now = (0, 0)
    turn = 0 # if 0, the axis affected is X, if 1 is Y
    axisX = 1 # 1 if movement will be oriented towards +, -1 if not
    axisY = 1
    path = []
    path.append(now)
    for s in set:
        direction = s[0]  # get the direction
        if(turn == 0):
            if(direction == 'L'):
                if(axisY == 1):
                    axisX = -1
                else:
                    axisX = 1
            elif(direction == 'R'):
                if(axisY == 1):
                    axisX = 1
                else:
                    axisX = -1
            else:
                print("Huston, we got a problem")
        else:
            if(direction == 'L'):
                if(axisX == 1):
                    axisY = 1
                else:
                    axisY = -1
            elif(direction == 'R'):
                if(axisX == 1):
                    axisY = -1
                else:
                    axisY = 1
            else:
                print("Huston, we got a problem")
        move = int(s[1:])  # get the hop
        if(turn == 0):
            move *= axisX
        else:
            move *= axisY
        count = 0
        while(count < abs(move)):  # cover the distance
            count = abs(count) + 1
            if(move < 0):
                if(turn == 0):
                    now = ((now[0] - 1), now[1])
                else:
                    now = (now[0], (now[1] - 1))
            else:
                if(turn == 0):
                    now = ((now[0] + 1), now[1])
                else:
                    now = (now[0], (now[1] + 1))
            if now not in path:
                path.append(now)
            else:
                print("Again in", now, abs(now[0]) + abs(now[1]), " blocks away")
        turn = switch_turn(turn)
    distance = abs(now[0]) + abs(now[1])
    print("End distance = ", distance)

def switch_turn(axis):
    '''
    Switch turn.
    '''
    if axis == 0:
        return 1
    else:
        return 0
