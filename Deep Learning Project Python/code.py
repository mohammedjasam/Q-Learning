import sys
import random
from decimal import Decimal

"""__________________GLOBAL VARIABLES__________________"""

# Q-Learning
Alpha = 0.2 # Learning rate (FIXED NOW)
DiscountFactor = 0.7 # Considers discounted rewards after time t
States = 100
Actions = 4 # Top, Left, Down, Right
Q = [] # 2D Array to store States and their Actions

# Map
H = 10 # Height of the Map
W = 10 # Width of the Map
Map = [] # The 2D array to store the Map of the basement
DonutPresentOnMap = False # Bool value to keep track of the presence of donut
Walls = [] # Stores the location of all the Walls!
Tiles = [[1, 3], [2, 7], [3, 4], [5, 2], [6, 5], [6, 7], [7, 2]]

# Tinny Tim
X = 4 # Initial X Coordinate
Y = 4 # Initial Y Coordinate

REWARD_GAINED = 0
"""__________________END OF GLOBAL VARIABLES__________________"""






"""__________________INITIALIZATIONS___________________"""

# Initializing the Q_MATRIX with default values, following Super Optimistic Method!
for i in range(States):
    GridActions = []
    for j in range(Actions):
        GridActions.append(1000) # Adding 1000 to each action
    Q.append(GridActions) # Adding the Actions List to the original Q Matrix

# Creating the Map of the Basement!
for i in range(H):
    MapColumns = []
    for i in range(W):
        MapColumns.append(" ")
    Map.append(MapColumns)

## Setting the outer boundaries in the Map
for i in range(W):
    Map[0][i] = "W"
    Walls.append([0, i])

for i in range(W):
    Map[9][i] = "W"
    Walls.append([9, i])

for i in range(H):
    Map[i][0] = "W"
    Walls.append([i, 0])

for i in range(H):
    Map[i][9] = "W"
    Walls.append([i, 9])

## Setting the inner boundaries in the MapColumns
Map[2][2] = "W";
Map[3][2] = "W";
Map[4][2] = "W";
Map[2][4] = "W";
Map[2][5] = "W";
Map[2][6] = "W";
Map[4][6] = "W";
Map[5][6] = "W";
Map[6][6] = "W";
Map[6][4] = "W";
Map[7][4] = "W";
Map[8][4] = "W";

Walls.append([2,2])
Walls.append([3,2])
Walls.append([4,2])
Walls.append([2,4])
Walls.append([2,5])
Walls.append([2,6])
Walls.append([4,6])
Walls.append([5,6])
Walls.append([6,6])
Walls.append([6,4])
Walls.append([7,4])
Walls.append([8,4])

# Dropping Tim into the Map!
Map[X][Y] = "T"

"""__________________END OF INITIALIZATIONS___________________"""








"""__________________TINNY-TIM MODULES___________________"""
# This function checks for Donut and returns reward if its found by Tinny Tim
def CheckForDonut():
    global Map, DonutPresentOnMap
    r = 0
    if Map[X][Y] == 'D':
        DonutPresentOnMap = False
        r = 10
    return r

# This function checks for falling tiles and returns reward
def CheckForFallingTiles():
    global Map, X, Y
    r = 0

    if [X, Y] in Tiles:
        TileProbability = random.randint(0, 1)
        if TileProbability:
            r = -10

    return r

# This move checks if Tinny Tim will hit walls, if so he gets reward and stays where he is!
def CheckForLegalMove(Xt, Yt):
    global Map, X, Y
    r = 0

    if Map[Xt][Yt] == 'W':
        r = -1
        Xt = X
        Yt = Y
    else:
        if not(Map[X][Y] == 'D'):
            Map[X][Y] = " "
        X = Xt
        Y = Yt
    return r

# Moves Tinny Tim Top By 1 Grid
def MoveTop():
    global Map, X, Y
    Xt = X - 1
    Yt = Y
    return CheckForLegalMove(Xt, Yt)

# Moves Tinny Tim Left By 1 Grid
def MoveLeft():
    global Map, X, Y
    Xt = X
    Yt = Y - 1
    return CheckForLegalMove(Xt, Yt)

# Moves Tinny Tim Down By 1 Grid
def MoveDown():
    global Map, X, Y
    Xt = X + 1
    Yt = Y
    return CheckForLegalMove(Xt, Yt)

# Moves Tinny Tim Right By 1 Grid
def MoveRight():
    global Map, X, Y
    Xt = X
    Yt = Y + 1
    return CheckForLegalMove(Xt, Yt)

# This function moves Tinny Tim based on the policy map
def MoveTim():
    global Map, X, Y

    Reward = 0

    S = 10 * X + Y # State before moving
    Directions = [0, 1, 2, 3]

    MaxQValue, Action = getStateProperties(Q[S])

    CorrectMove = random.randint(0, 100)

    if CorrectMove < 82:
        A = Action
    else:
        Directions.remove(Action)
        NewMove = random.randint(0, 2)
        # print("New Move is : " + str(NewMove))
        A = Directions[NewMove]

    # Moving Tim!
    if A == 0:
        Reward += MoveTop()
    elif A == 1:
        Reward += MoveLeft()
    elif A == 2:
        Reward += MoveDown()
    elif A == 3:
        Reward += MoveRight()

    Reward += CheckForDonut()

    Map[X][Y] = "T"
    Reward += CheckForFallingTiles()

    S_Dash = 10 * X + Y  # State after moving

    UpdateQMatrix(S, S_Dash, A, Reward)

"""__________________END OF TINNY-TIM MODULES___________________"""







"""__________________Q-LEARNING MODULES___________________"""

# This function updates the Q-Matrix based on New and Old State and Actions along with Rewards, Alpha and Discount Factor
def UpdateQMatrix(S, S_Dash, A, Reward):
    global REWARD_GAINED
    REWARD_GAINED += Reward

    global Q
    MaxQValue, Action = getStateProperties(Q[S_Dash])
    Q[S][A] = Q[S][A] + Alpha * (Reward + DiscountFactor * MaxQValue - Q[S][A])

# This function returns the properties of the State requested!
def getStateProperties(State):
    MaxQValue = -sys.maxsize # Sets the value of MaxQValue to highest possible negative value!
    Action = -1

    for i in range(len(State)):
        if MaxQValue < State[i]:
            MaxQValue = State[i]
            Action = i
    return MaxQValue, Action
"""__________________END OF Q-LEARNING MODULES___________________"""








"""__________________MAP MODULES___________________"""
# Spawn at corners
def CornerDrop(x, y):
    global Map

    Map[x][y] = 'D'


# This function Spawns Donut with a probability of 0.25 on the map in on of the four corners
def SpawnDonut():
    global DonutPresentOnMap
    if DonutPresentOnMap == False: # IF there is no donut on Map
        Probability = random.randint(0, 100)

        if Probability < 25:
            MapCorners = {0 : [1, 1], 1 : [1, 8], 2 : [8, 1], 3 : [8, 8]} # Dict with Possible corners on the map
            CornerProb = random.randint(0, 3) # Choosing which corner to spawn the donut at

            Location = MapCorners[CornerProb]
            CornerDrop(Location[0], Location[1]) # This function spwans the donut on map
            DonutPresentOnMap = True


"""__________________END OF MAP MODULES___________________"""









"""__________________OUTPUT MODULES___________________"""

# This function prints the Map on the screen
def PrintMap():
    for i in range(H):
        for j in range(W):
            print(Map[i][j] + "   ", end='')
        print("\n")

# This function prints the Q values for each state and its actions
def PrintQ():
    for i in range(States):
        for j in range(Actions):
            print(str(round(Q[i][j], 7)) + "   ", end='')
        print()

# This function will extract the best action for the state to print the policy
def PrintPolicy():
    for i in range(H):
        for j in range(W):
            if [i,j] not in Walls:
                S = 10 * i + j
                MaxQValue, Action = getStateProperties(Q[S])
                ActionMap = {0 : "^", 1 : "<", 2 : "v", 3 : ">"} # Top, Left, Down, Right
                print(ActionMap[Action] + "   ", end='')
            else:
                print("W" + "   ", end='')
        print("\n")

# This function pulls out the expected reward of each cell in the grid
def PrintExpectedReward():
    for i in range(States):
        if i % 10 == 0:
            print()
        MaxQValue, Action = getStateProperties(Q[i])

        print(MaxQValue)
"""__________________END OF OUTPUT MODULES___________________"""









"""_______________________MAIN MODULE________________________"""

def main():
    iterations = 0

    while(True):
        # print(DonutPresentOnMap)
        SpawnDonut() # This functions spawns donut with 0.25 prob in 1 of 4 corners
        MoveTim() # This function moves TinnyTim based on the Policy
        c = 0
        if (iterations % 1000000 == 0):
            print( str(iterations) + "  iterations completed!")
            PrintMap()
            print("\n\n")
            PrintPolicy()
            print("\n\n")
            # PrintQ()
            PrintExpectedReward()
            c += 1
            if c % 10 == 0:
                break
        iterations +=1 # Incrementing the i value!
        # print(REWARD_GAINED)

"""_______________________END OF MAIN MODULE________________________"""








""" THIS IS WHERE THE EXECUTION BEGINDS """
main() # Calls  the main function which runs the whole program!
