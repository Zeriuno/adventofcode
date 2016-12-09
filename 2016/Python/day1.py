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
    turn = True
    axisX = 1
    axisY = 1
    for s in set:
        direction = s[0]
        if(turn == True):
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
        if(turn):
            move *= axisX
            position[0] += move
        else:
            move *= axisY
            position[1] += move
        turn = switch_turn(turn)
    distance = abs(position[0]) + abs(position[1])
    return distance

def switch_turn(axis):
    '''
    Switch turn.
    '''
    if axis == True:
        return False
    else:
        return True
