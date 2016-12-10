def blocks(param):
    '''
    Do the thing.
    '''
    instructions = open(param, 'r')
    for line in instructions:
        go = line.rstrip()
    instructions.close()
    set = go.split(", ")
    position = [0, 0]
    turn = 0 # if 0, the axis affected is X, if 1 is Y
    axisX = 1 # 1 if movement will be oriented towards +, -1 if not
    axisY = 1
    for s in set:
        direction = s[0]
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
        move = int(s[1:])
        if(turn == 0):
            move *= axisX
        else:
            move *= axisY
        count = 0
        while(abs(count) < abs(move + 1)):
            count = abs(count) + 1
            if(move < 0):
                count *= -1
            position[turn] += count
            path.append(position)
        turn = switch_turn(turn)
    distance = abs(position[0]) + abs(position[1])
    return distance

def switch_turn(axis):
    '''
    Switch turn.
    '''
    if axis == True:
        return 1
    else:
        return 0
